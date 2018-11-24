let myPromise =
  Js.Promise.make((~resolve, ~reject as _reject) => resolve(. 2));

/* Resolves properly, nothing interesting happens */
Js.Promise.(
  myPromise
  |> then_(value => resolve(value))
  |> catch(err => {
       Js.log(err);
       resolve(0);
     })
);

/* Promise explicitly rejected */
Js.Promise.(
  myPromise
  |> then_(value =>
       value == 2 ? reject(Failure("rejection!")) : resolve(value)
     )
  |> catch(err => {
       /* Note that type of err is Js.Promise.error, NOT exn! */
       Js.log(err);
       resolve(0);
     })
);

/* Exception occurs inside promise */
Js.Promise.(
  myPromise
  |> then_(value => value == 2 ? failwith("exception!") : resolve(value))
  |> catch(err => {
       /* Note that type of err is Js.Promise.error, NOT exn! */
       Js.log(err);
       resolve(0);
     })
);
