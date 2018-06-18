module IntPairs = {
  type t = (int, int);
  let compare = ((x0, y0), (x1, y1)) =>
    switch (Pervasives.compare(x0, x1)) {
    | 0 => Pervasives.compare(y0, y1)
    | c => c
    };
};

module PairsMap = Map.Make(IntPairs);

let m = PairsMap.(
  empty 
  |> add((0, 1), "hello") 
  |> add((1, 0), "world")
);
/* Js.log(m); */
Js.log(m |> PairsMap.find((1, 0)));

switch (m |> PairsMap.find((0, 0))) {
| value => Js.log(value)
| exception Not_found => Js.log("Key was not found")
};