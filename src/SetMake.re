open Belt;

module IntPairs =
  Id.MakeComparable({
    type t = (int, int);
    let cmp = ((x0, y0), (x1, y1)) =>
      switch (Pervasives.compare(x0, x1)) {
      | 0 => Pervasives.compare(y0, y1)
      | c => c
      };
  });

let set = Set.make(~id=(module IntPairs));

set
->Set.add((0, 0))
->Set.add((1, 2))
->Set.add((1, 3))
->Set.add((0, 0))
->Set.remove((1, 2))
->Set.toList
->Js.log;
