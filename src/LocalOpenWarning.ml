
(* This generates warning "this open statement shadows the value identifier log (which is later used)" *)
(* let value = let open Js.Math in max_float 1. (log 2. /. log 3.) *)

let value = Js.Math.max_float 1. (log 2. /. log 3.)

let _ = Js.log value

