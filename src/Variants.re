[@bs.deriving jsConverter]
type fruit =
  | Apple
  | Orange
  | Kiwi
  | Watermelon;

Js.log(fruitToJs(Orange));
Js.log(fruitFromJs(2) == Some(Kiwi));

[@bs.deriving jsConverter]
type veggie = [
  | `Cucumber
  | `Tomato
  | `Eggplant
  | `Cabbage
  | `Lettuce
];

Js.log(veggieToJs(`Lettuce));
Js.log(veggieFromJs("Eggplant") == Some(`Eggplant));