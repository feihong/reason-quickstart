open Belt;

module CssUnit = {
  type t =
    | Em(int)
    | Rem(int)
    | Px(int)
    | Vw(int)
    | Vh(int);

  let unwrap: t => string =
    v => {
      let (value, suffix) =
        switch (v) {
        | Em(v) => (v, "em")
        | Rem(v) => (v, "rem")
        | Px(v) => (v, "px")
        | Vw(v) => (v, "vw")
        | Vh(v) => (v, "vh")
        };
      string_of_int(value) ++ suffix;
    };

  let unwrapOpt: option(t) => option(string) = Option.map(_, unwrap);
};

[@bs.obj]
external makeProps:
  (
    ~minWidth: string=?,
    ~maxWidth: string=?,
    ~minHeight: string=?,
    ~maxHeight: string=?,
    unit
  ) =>
  _ =
  "";

let make = (~minWidth=?, ~maxWidth=?, ~minHeight=?, ~maxHeight=?, _children) =>
  makeProps(
    ~minWidth=?minWidth->CssUnit.unwrapOpt,
    ~maxWidth=?maxWidth->CssUnit.unwrapOpt,
    ~minHeight=?minHeight->CssUnit.unwrapOpt,
    ~maxHeight=?maxHeight->CssUnit.unwrapOpt,
    (),
  );

make(~minWidth=Em(45), ~minHeight=Rem(105), ())->Js.log;
