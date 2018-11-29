let myFunc_ = [%bs.raw
  {|
  function (x) {
    return `${x} is a ${typeof x}`
  }
|}
];

/* Does not work if type is not defined inside external definition: */
/* type t = [@bs.string] [ | `Foo | [@bs.as "bar!"] `Bar | `Baz];
   external myFunc: t => string = "myFunc_"; */

[@bs.val]
external myFunc:
  (
  [@bs.string]
  [ | `Foo | [@bs.as "Bar!"] `Bar | `Baz | [@bs.as "Cowpoke?"] `Cowboy]
  ) =>
  string =
  "myFunc_";

myFunc(`Foo)->Js.log;
myFunc(`Bar)->Js.log;
myFunc(`Baz)->Js.log;
myFunc(`Cowboy)->Js.log;
