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
		fname  = flag.String("f", "../data.root", "input file name")
		tname  = flag.String("t", "F64", "input tree name")
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
	dt_ms := float64(dt) / float64(time.Millisecond)
	dt_s := dt_ms / float64(1000)
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

	// Event models
	//var eF64 EventFloats
	var eF64s EventSlices

	// Reader
	var r *rtree.Reader
	if tname == "F64" {
		r, err = rtree.NewReader(t, rtree.ReadVarsFromStruct(&eF64), rtree.WithRange(0, nmax))
	}
	if tname == "F64s" {
		r, err = rtree.NewReader(t, rtree.ReadVarsFromStruct(&eF64s), rtree.WithRange(0, nmax))
	}
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

// Input Event model made of 12 (flat) numbers
type EventFloats struct {
	Var1  float64
	Var2  float64
	Var3  float64
	Var4  float64
	Var5  float64
	Var6  float64
	Var7  float64
	Var8  float64
	Var9  float64
	Var10 float64
	Var11 float64
	Var12 float64
	Var13 float64
	Var14 float64
	Var15 float64
	Var16 float64
	Var17 float64
	Var18 float64
	Var19 float64
	Var20 float64
	Var21 float64
	Var22 float64
	Var23 float64
	Var24 float64
	Var25 float64
	Var26 float64
	Var27 float64
	Var28 float64
	Var29 float64
	Var30 float64
}

// Input event model made of 6 arrays of 2-elements
type EventSlices struct {
	N     int32
	Var1  []float64 `groot:"Var1[N]"`
	Var2  []float64 `groot:"Var2[N]"`
	Var3  []float64 `groot:"Var3[N]"`
	Var4  []float64 `groot:"Var4[N]"`
	Var5  []float64 `groot:"Var5[N]"`
	Var6  []float64 `groot:"Var6[N]"`
	Var7  []float64 `groot:"Var7[N]"`
	Var8  []float64 `groot:"Var8[N]"`
	Var9  []float64 `groot:"Var9[N]"`
	Var10 []float64 `groot:"Var10[N]"`
	Var11 []float64 `groot:"Var11[N]"`
	Var12 []float64 `groot:"Var12[N]"`
	Var13 []float64 `groot:"Var13[N]"`
	Var14 []float64 `groot:"Var14[N]"`
	Var15 []float64 `groot:"Var15[N]"`
	Var16 []float64 `groot:"Var16[N]"`
	Var17 []float64 `groot:"Var17[N]"`
	Var18 []float64 `groot:"Var18[N]"`
	Var19 []float64 `groot:"Var19[N]"`
	Var20 []float64 `groot:"Var20[N]"`
	Var21 []float64 `groot:"Var21[N]"`
	Var22 []float64 `groot:"Var22[N]"`
	Var23 []float64 `groot:"Var23[N]"`
	Var24 []float64 `groot:"Var24[N]"`
	Var25 []float64 `groot:"Var25[N]"`
	Var26 []float64 `groot:"Var26[N]"`
	Var27 []float64 `groot:"Var27[N]"`
	Var28 []float64 `groot:"Var28[N]"`
	Var29 []float64 `groot:"Var29[N]"`
	Var30 []float64 `groot:"Var30[N]"`
}
