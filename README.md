# Performances comparison: go-hep *v.s.* ROOT

This repository hots a samll benchmark based on a `TTree` reading (only) of 720k events,
in order to compare performances of [go-hep](https://go-hep.org/) and [ROOT](https://root.cern.ch/).
In this test 42 branches are loaded.

**Result**
```
go-hep: 5.2 ms/kEvt (3.7 s for 720 kEvts)
ROOT  : 2.6 ms/kEvt (1.9 s for 720 kEvts) 
```

Please [contact me](mailto:romain.madar@cern.ch) if you want to access the input file used in this test.
