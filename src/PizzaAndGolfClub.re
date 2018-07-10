/* 
 * Some examples that show the usage of the |> (pizza) and |. (golf club) 
 * operators.
 * 
 * Note that Belt.Array.map isn't the same as Array.map! Argument order is
 * reversed.
 */
open Belt;

let arr = Array.range(1, 10);

Js.log("Using the pizza (reverse application) operator:");

arr 
|> Array.map(_, x => x * 2)
|> Js.log;

Js.log("Using the golf club (fast pipe) operator:");

arr
|. Array.map(x => x + 1)
|. Js.log;
