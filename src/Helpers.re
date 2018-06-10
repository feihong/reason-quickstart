

[@bs.val] external stringify : (Js.Json.t, Js.Json.t, int) => string = "JSON.stringify";

let prettyStringify = json =>
  stringify(json, Js.Json.null, 2);

/* [%bs.raw {| {a: 1, b: 2, c: [4,5,6]} |}] 
|> prettyStringify
|> Js.log; */