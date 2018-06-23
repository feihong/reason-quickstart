[@bs.val] external prettyStringify : (
  Js.Json.t, 
  [@bs.as {json|null|json}] _,
  [@bs.as 2] _,
) => string = "JSON.stringify";

/* [%bs.raw {| {a: 1, b: 2, c: [4,5,6]} |}] 
|> prettyStringify
|> Js.log; */