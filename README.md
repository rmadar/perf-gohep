# Performances comparison: go-hep *v.s.* ROOT

This repository hosts a couple of small benchmark based on a `TTree` reading
in order to compare performances of [go-hep](https://go-hep.org/) and [ROOT](https://root.cern.ch/).


## Home-made data

In these test, fake data are generated, with 30 branches of either floats or slices (slice size vary between `1` and `n=30`).

One can regenerate the fake data with:

```
$> go run ./gen-data.go
```

The following table shows the time (in milliseconds per 10k events) for different codes, using the exact same input file, both for ROOT and go-hep:

| ROOT | floats  | slices  |  | GO-HEP | floats  | slices |
|:---|---:|---:|---|:---|---:|---:|
| branch  | x  | 22 | | [`839f662`](https://github.com/go-hep/hep/commit/1f253e6bf631b7a947f17c08168272b81839f662) | 4.7 | 45 |   
| reader  | x  |  8 | | [`feb48b1`](https://github.com/go-hep/hep/commit/f6acb63617113ff72668b749065faab99feb48b1) | 3.8 | 59 |

<table>
<tr><th> ROOT </th><th> GO-HEP </th></tr>
<tr><td>

| setup | Floats | Slices |
|:--|--:|--:|
| branch  | x  | 22 |
| reader  | x  |  8 |

</td><td>

| setup | Floats | Slices |
|:--|--:|--:|
| [`839f662`](https://github.com/go-hep/hep/commit/1f253e6bf631b7a947f17c08168272b81839f662) | 4.7 | 45 |
| [`feb48b1`](https://github.com/go-hep/hep/commit/f6acb63617113ff72668b749065faab99feb48b1) | 3.8 | 59 |

</td></tr> </table>


## Realistic data 

In this test, 42 float branches are loaded for 720k events ([contact me](mailto:romain.madar@cern.ch) if you want to access the input file).

**GOHEP** 
 + [839f662](https://github.com/go-hep/hep/commit/1f253e6bf631b7a947f17c08168272b81839f662): 4.5 ms/kEvt (3.3 s for 720 kEvts)
 + [feb48b1](https://github.com/go-hep/hep/commit/f6acb63617113ff72668b749065faab99feb48b1): 5.2 ms/kEvt (3.7 s for 720 kEvts)

**ROOT**
 + 2.6 ms/kEvt (1.9 s for 720 kEvts)


