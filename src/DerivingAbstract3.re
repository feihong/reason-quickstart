[@bs.deriving abstract]
type size = {
  w: int,
  h: int,
};

[@bs.deriving abstract]
type jsProps = {
  title: string,
  [@bs.optional]
  menuBar: bool,
  [@bs.optional] [@bs.as "size"]
  size_: size /* name of this field cannot be the same as name of type */
};

let props = jsProps(~title="Woo", ~size_=size(~w=100, ~h=200), ());
Js.log(props);
