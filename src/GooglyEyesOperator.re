/*

 @@ is function composition operator

 */

let add5 = x => x + 5;
let mult2 = x => x * 2;

add5 @@ 4 |> Js.log;

add5 @@ mult2 @@ 4 |> Js.log;

mult2 @@ add5 @@ 4 |> Js.log;

/* This won't work: */
/* let partial = (add5 @@ mult2); */
