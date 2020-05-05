# Performances comparison: go-hep *v.s.* ROOT

This repository hots a couple of small benchmark based on a `TTree` reading 
in order to compare performances of [go-hep](https://go-hep.org/) and [ROOT](https://root.cern.ch/).


## Realistic data 

In this test, 42 float branches are loaded for 720k events ([contact me](mailto:romain.madar@cern.ch) if you want to access the input file).

**GOHEP** 
 + *05/05/2020* ([839f662](https://github.com/go-hep/hep/commit/1f253e6bf631b7a947f17c08168272b81839f662)): 4.5 ms/kEvt (3.3 s for 720 kEvts)
 + *02/05/2020* ([feb48b1](https://github.com/go-hep/hep/commit/f6acb63617113ff72668b749065faab99feb48b1)): 5.2 ms/kEvt (3.7 s for 720 kEvts)

**ROOT**
 + 2.6 ms/kEvt (1.9 s for 720 kEvts)


## Home-made data

In these test, fake data are generated, with 30 branches of either floats or slices (slice size vary between 0 and `N`).
