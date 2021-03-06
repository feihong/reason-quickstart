module type Delta = {
  type t;
  let subtract: (t, t) => t;
  let toString: t => string;
};

module MakeDelta = (D: Delta) => {
  type t = D.t;
  let toMessage = (~current: t, ~previous: t) => {
    let delta = D.subtract(current, previous);
    let sign = compare(current, previous) == 1 ? "+" : "";
    D.toString(current) ++ " (" ++ sign ++ D.toString(delta) ++ ")";
  };
};

module IntDelta =
  MakeDelta({
    type t = int;
    let subtract = (-);
    let toString = string_of_int;
  });

module MoneyDelta =
  MakeDelta({
    type t = float;
    let subtract = (-.);
    let toString = x => "$" ++ Js.Float.toFixedWithPrecision(x, ~digits=2);
  });

IntDelta.toMessage(~current=14, ~previous=15)->Js.log;
MoneyDelta.toMessage(~current=12.35, ~previous=3.11)->Js.log;
