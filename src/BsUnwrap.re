let polymorphicFunction_ = [%bs.raw
  {|
  function (a, b) {
    return `${a} is a ${typeof a}, ${b} is a ${typeof b}`
  }
|}
];

type strOrInt = [ | `Str(string) | `Int(int)];

/* Note that bs.unwrap must use inline variants, you cannot use strOrInt */

[@bs.val]
external polymorphicFunction:
  (
    [@bs.unwrap] [ | `Str(string) | `Int(int)],
    [@bs.unwrap] [ | `Str(string) | `Int(int)]
  ) =>
  string =
  "polymorphicFunction_";

polymorphicFunction(`Int(45), `Str("cat"))->Js.log;

polymorphicFunction(`Str("dog"), `Int(36))->Js.log;

polymorphicFunction(`Int(45), `Int(55))->Js.log;

polymorphicFunction(`Str("mole"), `Str("rat"))->Js.log;
