# Performances comparison: go-hep *v.s.* ROOT

This repository hosts a couple of small benchmark based on a `TTree` reading
in order to compare performances of [go-hep](https://go-hep.org/) and [ROOT](https://root.cern.ch/).


## Home-made data

In these test, fake data are generated, with 30 branches of either floats or slices
(slice size varies between `1` and `n=30`). The test consists in loading all the branches and computing
three sums (involving all values of all branches). One can regenerate the fake data with:
```
$> go run ./gen-data.go
```

The following table shows the time (**milliseconds per 10k events**) for different codes, using the exact same input file,
both for ROOT (left) and go-hep (middle), as well as the ratio between go-hep and the ROOT branch approach (right):

<table>
<tr><th> Root </th><th> go-hep </th><th> go-hep / branch </th></tr>
<tr><td>

| Method | Floats | Slices |
|:--|--:|--:|
| branch  | 2.4  | 23 |
| reader  | 1.8  | 11 |

</td><td>

| Commit | Floats | Slices |
|:--|--:|--:|
| [`nextcommit`](https://github.com/go-hep/hep/commit/) | x | x |
| [`839f662`](https://github.com/go-hep/hep/commit/1f253e6bf631b7a947f17c08168272b81839f662) | 3.8 | 45 |
| [`feb48b1`](https://github.com/go-hep/hep/commit/f6acb63617113ff72668b749065faab99feb48b1) | 4.7 | 59 |

</td><td>

| go-hep commit | Floats | Slices |
|:--|--:|--:|
| [`nextcommit`](https://github.com/go-hep/hep/commit/) | x | x |
| [`839f662`](https://github.com/go-hep/hep/commit/1f253e6bf631b7a947f17c08168272b81839f662) | 1.6 | 2.0 |
| [`feb48b1`](https://github.com/go-hep/hep/commit/f6acb63617113ff72668b749065faab99feb48b1) | 1.9 | 2.7 |

</td></tr> </table>


## Realistic data 

In this test, 42 float branches are loaded for 720k events ([contact me](mailto:romain.madar@cern.ch) if you want to access the input file).

**GOHEP** 
 + [839f662](https://github.com/go-hep/hep/commit/1f253e6bf631b7a947f17c08168272b81839f662): 4.5 ms/kEvt (3.3 s for 720 kEvts)
 + [feb48b1](https://github.com/go-hep/hep/commit/f6acb63617113ff72668b749065faab99feb48b1): 5.2 ms/kEvt (3.7 s for 720 kEvts)

**ROOT**
 + 2.6 ms/kEvt (1.9 s for 720 kEvts)


