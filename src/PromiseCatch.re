let evenPromise = num =>
  Js.Promise.make((~resolve, ~reject) =>
    num mod 2 == 0 ?
      resolve(. num) : reject(. Failure("Not an even number"))
  );

/* Easiest way if value is static */
let unusedPromise = Js.Promise.resolve(5);

/* Resolves properly, nothing interesting happens */
Js.Promise.(
  evenPromise(2)
  |> catch(err => {
       Js.log(err);
       /* Must resolve to same type as last then_ call */
       resolve(-1);
     })
);

/* Promise explicitly rejected */
Js.Promise.(
  evenPromise(3)
  |> catch(err => {
       /* Note that type of err is Js.Promise.error, NOT exn! */
       Js.log(err);
       resolve(-1);
     })
);

/* Exception occurs inside promise */
Js.Promise.(
  evenPromise(4)
  |> then_(value => value == 4 ? failwith("exception!") : resolve(value))
  |> catch(err => {
       /* Note that type of err is Js.Promise.error, NOT exn! */
       Js.log(err);
       resolve(-1);
     })
);

/* Coerce to exn inside catch (bad) */
Js.Promise.(
  evenPromise(7)
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
