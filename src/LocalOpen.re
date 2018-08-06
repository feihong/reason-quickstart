
let _ = {
  open Belt;
  [|1, 2, 3|] |. Array.map(x => x + 1) |> Js.log2("Using Belt:");
};

/* Standard lib's Array.map accepts map as second argument */
[|1, 2, 3|] |> Array.map(x => x + 1) |> Js.log2("Using standard lib:");

Belt.(
  Array.range(1, 23)
  /* This is the same as standard lib's Array.filter */
  |. Array.keep(x => x mod 3 == 0)
  |> Js.log2("Again using Belt:") 
);
