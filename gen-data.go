// +build ignore

// Generate ROOT file with two different event models
//  1. flat data
//  2. array (slice) data
package main

import (
	"flag"
	//"fmt"
	"log"
	//"math"
	"math/rand"

	"go-hep.org/x/hep/groot"
	"go-hep.org/x/hep/groot/rtree"
)

func main() {
	var (
		fname  = flag.String("f", "homemade-data/data.root", "path to ROOT file to create")
		evtmax = flag.Int64("n", 10000, "number of events to generate")
	)
	flag.Parse()
	generateData(*fname, *evtmax)
}

// Creating the two TTrees in the same file
func generateData(fname string, evtmax int64) {

	// Outputname
	f, err := groot.Create(fname)
	if err != nil {
		log.Fatal("could not create ROOT file %q: %w", fname, err)
	}
	defer f.Close()

	// Floats data
	var eF64 EventFloats
	tF64, err := rtree.NewWriter(f, "F64", rtree.WriteVarsFromStruct(&eF64))
	if err != nil {
		log.Fatal("could not create tree writer: %w", err)
	}
	defer tF64.Close()

	// Slices data
	var eF64s EventSlices
	tF64s, err := rtree.NewWriter(f, "F64s", rtree.WriteVarsFromStruct(&eF64s))
	if err != nil {
		log.Fatal("could not create tree writer: %w", err)
	}
	defer tF64s.Close()

	// Events loop
	for i := int64(0); i < evtmax; i++ {

		// Write floats data
		eF64.GenerateValues()
		_, err = tF64.Write()
		if err != nil {
			log.Fatal("could not write event %d: %w", i, err)
		}

		// Write slices data
		eF64s.GenerateValues(30)
		_, err = tF64s.Write()
		if err != nil {
			log.Fatal("could not write event %d: %w", i, err)
		}

	}

	err = tF64.Close()
	if err != nil {
		log.Fatal("could not close tree writer: %w", err)
	}

	err = tF64s.Close()
	if err != nil {
		log.Fatal("could not close tree writer: %w", err)
	}

	err = f.Close()
	if err != nil {
		log.Fatal("could not close ROOT file: %w", err)
	}

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

func (e *EventFloats) GenerateValues() {
	e.Var1 = rand.Float64()
	e.Var2 = rand.Float64()
	e.Var3 = rand.Float64()
	e.Var4 = rand.Float64()
	e.Var5 = rand.Float64()
	e.Var6 = rand.Float64()
	e.Var7 = rand.Float64()
	e.Var8 = rand.Float64()
	e.Var9 = rand.Float64()
	e.Var10 = rand.Float64()
	e.Var11 = rand.Float64()
	e.Var12 = rand.Float64()
	e.Var13 = rand.Float64()
	e.Var14 = rand.Float64()
	e.Var15 = rand.Float64()
	e.Var16 = rand.Float64()
	e.Var17 = rand.Float64()
	e.Var18 = rand.Float64()
	e.Var19 = rand.Float64()
	e.Var20 = rand.Float64()
	e.Var21 = rand.Float64()
	e.Var22 = rand.Float64()
	e.Var23 = rand.Float64()
	e.Var24 = rand.Float64()
	e.Var25 = rand.Float64()
	e.Var26 = rand.Float64()
	e.Var27 = rand.Float64()
	e.Var28 = rand.Float64()
	e.Var29 = rand.Float64()
	e.Var30 = rand.Float64()
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

func (e *EventSlices) GenerateValues(n int32) {
	e.N = rand.Int31n(n)

	e.Var1 = make([]float64, e.N)
	e.Var2 = make([]float64, e.N)
	e.Var3 = make([]float64, e.N)
	e.Var4 = make([]float64, e.N)
	e.Var5 = make([]float64, e.N)
	e.Var6 = make([]float64, e.N)
	e.Var7 = make([]float64, e.N)
	e.Var8 = make([]float64, e.N)
	e.Var9 = make([]float64, e.N)
	e.Var10 = make([]float64, e.N)
	e.Var11 = make([]float64, e.N)
	e.Var12 = make([]float64, e.N)
	e.Var13 = make([]float64, e.N)
	e.Var14 = make([]float64, e.N)
	e.Var15 = make([]float64, e.N)
	e.Var16 = make([]float64, e.N)
	e.Var17 = make([]float64, e.N)
	e.Var18 = make([]float64, e.N)
	e.Var19 = make([]float64, e.N)
	e.Var20 = make([]float64, e.N)
	e.Var21 = make([]float64, e.N)
	e.Var22 = make([]float64, e.N)
	e.Var23 = make([]float64, e.N)
	e.Var24 = make([]float64, e.N)
	e.Var25 = make([]float64, e.N)
	e.Var26 = make([]float64, e.N)
	e.Var27 = make([]float64, e.N)
	e.Var28 = make([]float64, e.N)
	e.Var29 = make([]float64, e.N)
	e.Var30 = make([]float64, e.N)

	for i := 0; i < int(e.N); i++ {
		e.Var1[i] = rand.Float64()
		e.Var2[i] = rand.Float64()
		e.Var3[i] = rand.Float64()
		e.Var4[i] = rand.Float64()
		e.Var5[i] = rand.Float64()
		e.Var6[i] = rand.Float64()
		e.Var7[i] = rand.Float64()
		e.Var8[i] = rand.Float64()
		e.Var9[i] = rand.Float64()
		e.Var10[i] = rand.Float64()
		e.Var11[i] = rand.Float64()
		e.Var12[i] = rand.Float64()
		e.Var13[i] = rand.Float64()
		e.Var14[i] = rand.Float64()
		e.Var15[i] = rand.Float64()
		e.Var16[i] = rand.Float64()
		e.Var17[i] = rand.Float64()
		e.Var18[i] = rand.Float64()
		e.Var19[i] = rand.Float64()
		e.Var20[i] = rand.Float64()
		e.Var21[i] = rand.Float64()
		e.Var22[i] = rand.Float64()
		e.Var23[i] = rand.Float64()
		e.Var24[i] = rand.Float64()
		e.Var25[i] = rand.Float64()
		e.Var26[i] = rand.Float64()
		e.Var27[i] = rand.Float64()
		e.Var28[i] = rand.Float64()
		e.Var29[i] = rand.Float64()
		e.Var30[i] = rand.Float64()
	}
}
