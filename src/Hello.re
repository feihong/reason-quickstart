let mesg: string = [%bs.raw {| '你好世界！' |}];
Js.log(mesg);

/* This will be jibberish */
Js.log("你好世界！");

/* let thing = {"name": "blah"};
Js.log(thing); */

type person = Js.t({
    .
    name: string,
    age: int,
    job: string
  });
/* let john: person = [%bs.obj {name:  "John", age: 34, job: "Cyborg Mechanic"}]; */
let john: person = {"name": "John", "age": 34, "job": "Cyborg Mechnanic"};
Js.log(john);