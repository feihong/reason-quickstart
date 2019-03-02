[@bs.obj] external makeProps: (~foo: string=?, ~bar: int=?, unit) => _ = "";

makeProps(~foo="yay", ())->Js.log;
makeProps(~bar=33, ())->Js.log;
makeProps(~foo="yay", ~bar=33, ())->Js.log;
makeProps(~foo=?None, ~bar=?None, ())->Js.log;
