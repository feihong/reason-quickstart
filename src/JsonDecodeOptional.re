/*

 https://bucklescript.github.io/docs/en/object-deprecated.html

 */

let response = [%bs.raw {|
{
  name: 555,
  age: 123
}
|}];

type user = {
  name: option(string),
  age: int,
};

module Decode = {
  let user = json =>
    Json.Decode.{
      name: json |> field("name", optional(string)),
      age: json |> field("age", int),
    };
};

response |> Decode.user |> Js.log;
// prints `[ undefined, 123 ]`, which seems wrong
