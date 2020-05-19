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
		format = flag.String("d", "F64s", "data format F64s/F64")
		evtmax = flag.Int64("n", -1, "Maximum number of events")
		doCPU  = flag.Bool("cpu", false, "enable CPU profiling")
		nevts int64
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

	if *format == "F64s" { 
		nevts = eventLoopF64s(*fname, *evtmax)
	}

	if *format == "F64" { 
		nevts = eventLoopF64(*fname, *evtmax)
	}
	
	dt := time.Now().Sub(start)
	dt_ms := float64(dt) / float64(time.Millisecond)
	dt_s := dt_ms / float64(1000)
	nkevt := float64(nevts) / 1e3
	fmt.Printf("%.1f ms/kEvt (%.1f s for %.0f kEvts)\n", dt_ms/nkevt, dt_s, nkevt)
}

func eventLoopF64s(fname string, nmax int64) int64 {

	// Open file
	f, err := groot.Open(fname)
	if err != nil {
		log.Fatalf("could not open ROOT file: %+v", err)
	}
	defer f.Close()

	// Get the tree
	o, err := f.Get("F64s")
	if err != nil {
		log.Fatalf("could not retrieve ROOT tree: %+v", err)
	}
	t := o.(rtree.Tree)

	// Event model
	var eF64s EventSlices

	// Reader
	r, err := rtree.NewReader(t, rtree.ReadVarsFromStruct(&eF64s), rtree.WithRange(0, nmax))
	if err != nil {
		log.Fatalf("could not create tree reader: %+v", err)
	}

	// Event loop
	var ievt int64
	err = r.Read(func(ctx rtree.RCtx) error {
		if ctx.Entry%100000 == 0 {
			fmt.Printf("Processing event %v\n", ctx.Entry)
		}
		
		// Dummy sum to use all elements of all slices
		var x1, x2, x3 float64
		for i := range eF64s.Var1 {
			x1 += eF64s.Var1[i] + eF64s.Var2[i] + eF64s.Var3[i] + eF64s.Var4[i] + eF64s.Var4[i] +
				eF64s.Var6[i] + eF64s.Var7[i] + eF64s.Var8[i] + eF64s.Var9[i] + eF64s.Var10[i]
			
			x2 += eF64s.Var11[i] + eF64s.Var12[i] + eF64s.Var13[i] + eF64s.Var14[i] + eF64s.Var14[i] +
				eF64s.Var16[i] + eF64s.Var17[i] + eF64s.Var18[i] + eF64s.Var19[i] + eF64s.Var20[i]
			
			x3 += eF64s.Var21[i] + eF64s.Var22[i] + eF64s.Var23[i] + eF64s.Var24[i] + eF64s.Var24[i] +
				eF64s.Var26[i] + eF64s.Var27[i] + eF64s.Var28[i] + eF64s.Var29[i] + eF64s.Var30[i]
		}
		_, _, _ = x1, x2, x3
		
		ievt++
		return nil
	})

	return ievt
}

// Run the event loop for the float trees
func eventLoopF64(fname string, nmax int64) int64 {

	// Open file
	f, err := groot.Open(fname)
	if err != nil {
		log.Fatalf("could not open ROOT file: %+v", err)
	}
	defer f.Close()

	// Get the tree
	o, err := f.Get("F64")
	if err != nil {
		log.Fatalf("could not retrieve ROOT tree: %+v", err)
	}
	t := o.(rtree.Tree)

	// Event model
	var eF64 EventFloats

	// Reader
	r, err := rtree.NewReader(t, rtree.ReadVarsFromStruct(&eF64), rtree.WithRange(0, nmax))
	if err != nil {
		log.Fatalf("could not create tree reader: %+v", err)
	}

	// Event loop
	var ievt int64
	err = r.Read(func(ctx rtree.RCtx) error {
		if ctx.Entry%100000 == 0 {
			fmt.Printf("Processing event %v\n", ctx.Entry)
		}
		
		// Dummy sum to use all elements
		_ = eF64.Var1 + eF64.Var2 + eF64.Var3 + eF64.Var4 + eF64.Var4 +
			eF64.Var6 + eF64.Var7 + eF64.Var8 + eF64.Var9 + eF64.Var10

		_ = eF64.Var11 + eF64.Var12 + eF64.Var13 + eF64.Var14 + eF64.Var14 +
			eF64.Var16 + eF64.Var17 + eF64.Var18 + eF64.Var19 + eF64.Var20

		_ = eF64.Var21 + eF64.Var22 + eF64.Var23 + eF64.Var24 + eF64.Var24 +
			eF64.Var26 + eF64.Var27 + eF64.Var28 + eF64.Var29 + eF64.Var30
		
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
