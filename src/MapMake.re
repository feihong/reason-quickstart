[%%debugger.chrome];

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

let updateValue = maybe =>
  Option.map(maybe, x =>
    switch (x) {
    | "pizza place" => "pizzeria"
    | "taco joint" => "tacqueria"
    | v => v
    }
  );

let m =
  Map.make(~id=(module IntPairs))
  ->Map.set((0, 0), "origin")
  ->Map.set((10, 20), "pizza place")
  ->Map.set((12, 15), "taco joint")
  ->Map.update((10, 20), updateValue)
  ->Map.update((12, 15), updateValue)
  ->Map.update((0, 0), updateValue);

m->Map.toArray->Js.log;

m->Map.isEmpty |> Js.log2("Empty?");

m->Map.get((0, 0)) |> Js.log2("At (0,0):");

m
->Map.get((0, 1))
->(
    x =>
      switch (x) {
      | Some(y) => Js.log2("Found", y)
      | None => Js.log("Nothing found")
      }
  );

m
->Map.get((10, 20))
->(
    x =>
      switch (x) {
      | Some(y) => Js.log2("Found", y)
      | None => Js.log("Nothing found")
      }
  );

/* m |. Map.getExn((0, 1)) |. x =>
         switch(x) {
         | y => Js.log2("Found", y)
         | exc

   ept   ion _   }; */
