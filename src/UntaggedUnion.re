/*
 https://github.com/glennsl/bucklescript-cookbook#untagged-unions
 */
open Belt;

let crazyFunc: string => Js.Json.t = [%raw
  text => {|
  switch(text) {
    case 'string':
      return 'hello world'
    case 'float':
      return 999.999
    case 'int':
      return 42
    case 'true':
      return true
    case 'false':
      return false
    case 'null':
      return null
    default:
      return {name: 'Cassidy', job: 'adventurer'}
  }
|}
];

["string", "float", "int", "true", "false", "null", "whatever"]
->List.map(v =>
  Js.Json.(
    switch (v->crazyFunc->classify) {
    | JSONNumber(n) => `Float(n)
    | JSONString(s) => `String(s)
    | JSONTrue => `Bool(true)
    | JSONFalse => `Bool(false)
    | JSONObject(o) => `Object(o)
    | JSONNull => `Null
    | _ => failwith("Unexpected type")
    }
  )
)
->List.forEach(v => Js.log(v));
