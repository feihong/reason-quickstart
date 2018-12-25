type state = {
  a: int,
  someInstanceVar: ref(int),
};

/* Now */
let state = {a: 1, someInstanceVar: ref(2)};

/* Emulate `state` access from closure. The read of `state` might be stale by the time it's executed: */
/* fun {state} => fun () => ReasonReact.Update {...state, bla} */
let state2 = {...state, a: 3};

/* but mutation of `state` needs to be reflected in `state2` still! */
state.someInstanceVar := 44;

/* should be 4 */
Js.log(state2.someInstanceVar^);

/* this wouldn't work if we do type state = {a: int, mutable someInstanceVar: int} */
