open Belt;

type choices = [ | `Foo | `Bar | `Baz | `Burger];

module Comparable =
  Id.MakeComparable({
    type t = choices;
    let cmp = Pervasives.compare;
  });

let set =
  [|`Foo, `Bar, `Baz, `Burger|]->Set.fromArray(~id=(module Comparable));

Js.log("Full set:");
[`Foo, `Bar, `Baz, `Burger]->List.forEach(e => Js.log2(e, set->Set.has(e)));

let emptySet = Set.make(~id=(module Comparable));

Js.log("Empty set:");
[`Foo, `Bar, `Baz, `Burger]
->List.forEach(e => Js.log2(e, emptySet->Set.has(e)));
