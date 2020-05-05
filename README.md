# Performances comparison: go-hep *v.s.* ROOT

This repository hots a samll benchmark based on a `TTree` reading (only) of 720k events,
in order to compare performances of [go-hep](https://go-hep.org/) and [ROOT](https://root.cern.ch/).
In this test 42 branches are loaded.

---

**GOHEP** 
 + *05/05/2020* ([839f662](https://github.com/go-hep/hep/commit/1f253e6bf631b7a947f17c08168272b81839f662)): 4.5 ms/kEvt (3.3 s for 720 kEvts)
 + *02/05/2020* ([feb48b1](https://github.com/go-hep/hep/commit/f6acb63617113ff72668b749065faab99feb48b1)): 5.2 ms/kEvt (3.7 s for 720 kEvts)

**ROOT**
 + 2.6 ms/kEvt (1.9 s for 720 kEvts)

---

**N.B:** [contact me](mailto:romain.madar@cern.ch) if you want to access the input file used in this test.
