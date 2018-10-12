module type DropdownT = {
  let name: string;
  type t;
  let all: array(t);
  let toString: t => string;
};

type component = {
  name: string,
  render: unit => string,
};
let makeComponent = name => {name, render: _ => ""};

module MakeDropdown = (D: DropdownT) => {
  type t = D.t;

  type state = {
    isOpen: bool,
    value: D.t,
  };

  type actions =
    | Toggle
    | Select(t);

  let component = makeComponent(D.name);

  let make = _children => {...component, render: () => "<div />"};
};

type predator =
  | Bear
  | Shark
  | Cheetah
  | Velociraptor;

module PredatorDropdown = MakeDropdown({
  let name = "PredatorDropdown";
  type t = predator;
  let all = [|Bear, Shark, Cheetah, Velociraptor|];
  let toString = fun
  | Bear => "Bear"
  | Shark => "Shark"
  | Cheetah => "Cheetah"
  | Velociraptor => "Velociraptor!";
});
