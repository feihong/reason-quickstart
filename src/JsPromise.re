open Belt;
module P = Js.Promise;

let sleep = ms =>
  P.make((~resolve, ~reject as _reject) => {
    let value = (); /* must use variable here because of how refmt works */
    Js.Global.setTimeout(() => resolve(. value), ms)->ignore;
  });

[1000, 1200, 1500, 2000, 100, 3000, 4000]
->List.map(n => {
    Js.log({j|Will sleep for $n milliseconds...|j});
    sleep(n)
    |> P.then_(_ => Js.log({j|Slept $n milliseconds!|j})->P.resolve)
    |> P.resolve;
  })
->List.toArray
->P.all
->P.then_(_ => Js.log("All done!")->P.resolve, _);
