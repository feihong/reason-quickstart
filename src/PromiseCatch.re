let myPromise = Js.Promise.make((~resolve, ~reject as _) => resolve(. 2));

let unusedPromise = Js.Promise.resolve(5);

/* Resolves properly, nothing interesting happens */
Js.Promise.(
  myPromise
  |> then_(value => resolve(value))
  |> catch(err => {
       Js.log(err);
       /* Must resolve to same type as last then_ call */
       resolve(-1);
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
       resolve(-1);
     })
);

/* Exception occurs inside promise */
Js.Promise.(
  myPromise
  |> then_(value => value == 2 ? failwith("exception!") : resolve(value))
  |> catch(err => {
       /* Note that type of err is Js.Promise.error, NOT exn! */
       Js.log(err);
       resolve(-1);
     })
);

/* Exception occurs inside promise */
Js.Promise.(
  myPromise
  |> then_(value => value == 2 ? failwith("exception!") : resolve(value))
  |> catch(err => {
       /* I'm pretty sure you should never do this */
       let err = (Obj.magic(err) :> exn);
       switch (err) {
       | Failure(mesg) => Js.log("After coercion to exn: " ++ mesg)
       | _ => Js.log("Unknown type of error")
       };
       resolve(-1);
     })
);
