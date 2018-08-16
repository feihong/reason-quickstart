[@bs.deriving abstract]
type jsProps('a) = {
  value: 'a,
  onChange: ('a, int) => unit,
};

[@bs.deriving abstract]
type team = {
  name: string,
  rank: int,
};

let object_: jsProps(team) = [%bs.raw
  {|
  {
    value: {
      name: 'Rolling Rocket Thundernauts',
      rank: 11,
    },
    onChange: (v, n) => {
      console.log('Inside onChange:', v.name, v.rank, n + 1)
    }
  }
|}
];

Js.log(object_);
object_->valueGet->nameGet->Js.log;
let func = object_->onChangeGet;
func(object_->valueGet, 55);
