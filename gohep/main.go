package main

import (
	"flag"
	"fmt"
	"log"
	"os"
	"runtime/pprof"
	"time"

	"go-hep.org/x/hep/groot"
	"go-hep.org/x/hep/groot/rtree"
)

func main() {

	start := time.Now()

	var (
		ipath  = "/home/rmadar/cernbox/ATLAS/Analysis/SM-SpinCorr/data/inputs/root-files/"
		fname  = flag.String("f", ipath+"MC16a.410472.PhPy8EG.DAOD_TOPQ1_truth.root", "input file name")
		tname  = flag.String("t", "truth", "input tree name")
		evtmax = flag.Int64("n", -1, "Maximum number of events")
		doCPU  = flag.Bool("cpu", false, "enable CPU profiling")
	)
	flag.Parse()

	if *doCPU {
		fprof, err := os.Create("prof.cpu")
		if err != nil {
			log.Fatalf("error: %+v", err)
		}
		defer fprof.Close()

		err = pprof.StartCPUProfile(fprof)
		if err != nil {
			log.Fatalf("error: %+v", err)
		}
		defer pprof.StopCPUProfile()
	}

	nevts := eventLoop(*fname, *tname, *evtmax)

	dt := time.Now().Sub(start)
	dt_s := dt.Seconds()
	dt_ms := dt_s / 1000
	nkevt := float64(nevts) / 1e3
	fmt.Printf("%.1f ms/kEvt (%.1f s for %.0f kEvts)\n", dt_ms/nkevt, dt_s, nkevt)
}

func eventLoop(fname, tname string, nmax int64) int64 {

	// Open file
	f, err := groot.Open(fname)
	if err != nil {
		log.Fatalf("could not open ROOT file: %+v", err)
	}
	defer f.Close()

	// Get the tree
	o, err := f.Get(tname)
	if err != nil {
		log.Fatalf("could not retrieve ROOT tree: %+v", err)
	}
	t := o.(rtree.Tree)

	// Variables to read
	var e Event
	rvars := readVariables(&e)

	// Reader
	r, err := rtree.NewReader(t, rvars, rtree.WithRange(0, nmax))
	if err != nil {
		log.Fatalf("could not create tree reader: %+v", err)
	}

	// Event loop
	var ievt int64
	err = r.Read(func(ctx rtree.RCtx) error {
		if ctx.Entry%100000 == 0 {
			fmt.Printf("Processing event %v\n", ctx.Entry)
		}
		ievt++
		return nil
	})

	return ievt
}

// Event
type Event struct {
	Info         EventInfo
	EvtWgt       EventWeight
	Top          ParticleTruth
	AntiTop      ParticleTruth
	Bottom       ParticleTruth
	AntiBottom   ParticleTruth
	Wplus        ParticleTruth
	Wminus       ParticleTruth
	Lepton       ParticleTruth
	AntiLepton   ParticleTruth
	Neutrino     ParticleTruth
	AntiNeutrino ParticleTruth
}

// Event weight
type EventWeight struct {
	MC float32
	PU float32
}

// Information about the events
type EventInfo struct {
	EvtNum int64
	RunNum int32
	Dsid   int32
}

// Truth particle definition
type ParticleTruth struct {
	Pt  float32
	Pl  float32
	Eta float32
	Phi float32
	M   float32
	Pid int32
}

func readVariables(e *Event) []rtree.ReadVar {
	return []rtree.ReadVar{

		// Event information
		{Name: "eventNumber", Value: &e.Info.EvtNum},
		{Name: "runNumber", Value: &e.Info.RunNum},
		{Name: "mcChannelNumber", Value: &e.Info.Dsid},

		// Weights informations
		{Name: "weight_mc", Value: &e.EvtWgt.MC},
		{Name: "weight_pileup", Value: &e.EvtWgt.PU},

		// Top/Anti-top quark
		{Name: "d_t_beforeFSR_pt", Value: &e.Top.Pt},
		{Name: "d_t_beforeFSR_eta", Value: &e.Top.Eta},
		{Name: "d_t_beforeFSR_phi", Value: &e.Top.Phi},
		{Name: "d_t_beforeFSR_m", Value: &e.Top.M},
		{Name: "d_tbar_beforeFSR_pt", Value: &e.AntiTop.Pt},
		{Name: "d_tbar_beforeFSR_eta", Value: &e.AntiTop.Eta},
		{Name: "d_tbar_beforeFSR_phi", Value: &e.AntiTop.Phi},
		{Name: "d_tbar_beforeFSR_m", Value: &e.AntiTop.M},

		// b-quarks
		{Name: "d_b_pt", Value: &e.Bottom.Pt},
		{Name: "d_b_eta", Value: &e.Bottom.Eta},
		{Name: "d_b_phi", Value: &e.Bottom.Phi},
		{Name: "d_b_m", Value: &e.Bottom.M},
		{Name: "d_bbar_pt", Value: &e.AntiBottom.Pt},
		{Name: "d_bbar_eta", Value: &e.AntiBottom.Eta},
		{Name: "d_bbar_phi", Value: &e.AntiBottom.Phi},
		{Name: "d_bbar_m", Value: &e.AntiBottom.M},

		// W-bosons
		{Name: "d_wplus_pt", Value: &e.Wplus.Pt},
		{Name: "d_wplus_eta", Value: &e.Wplus.Eta},
		{Name: "d_wplus_phi", Value: &e.Wplus.Phi},
		{Name: "d_wplus_m", Value: &e.Wplus.M},
		{Name: "d_wminus_pt", Value: &e.Wminus.Pt},
		{Name: "d_wminus_eta", Value: &e.Wminus.Eta},
		{Name: "d_wminus_phi", Value: &e.Wminus.Phi},
		{Name: "d_wminus_m", Value: &e.Wminus.M},

		// Leptons/Anti-lepton
		{Name: "d_l_pt", Value: &e.Lepton.Pt},
		{Name: "d_l_eta", Value: &e.Lepton.Eta},
		{Name: "d_l_phi", Value: &e.Lepton.Phi},
		{Name: "d_lbar_pt", Value: &e.AntiLepton.Pt},
		{Name: "d_lbar_eta", Value: &e.AntiLepton.Eta},
		{Name: "d_lbar_phi", Value: &e.AntiLepton.Phi},

		// Neutrinos/Anti-neutrino
		{Name: "d_nu_pt", Value: &e.Neutrino.Pt},
		{Name: "d_nu_eta", Value: &e.Neutrino.Eta},
		{Name: "d_nu_phi", Value: &e.Neutrino.Phi},
		{Name: "d_nu_m", Value: &e.Neutrino.M},
		{Name: "d_nubar_pt", Value: &e.AntiNeutrino.Pt},
		{Name: "d_nubar_eta", Value: &e.AntiNeutrino.Eta},
		{Name: "d_nubar_phi", Value: &e.AntiNeutrino.Phi},
		{Name: "d_nubar_m", Value: &e.AntiNeutrino.M},
	}
}
