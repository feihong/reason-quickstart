let mesg: string = [%bs.raw {| '你好世界！' |}];
Js.log(mesg);

let mesg2 = {js|再见宇宙！|js};
Js.log(mesg2);

/* Use string interpolation */
let mesg3 = {j|Last message: $mesg2|j};
Js.log(mesg3);

/* This will be jibberish */
Js.log("你好世界！");

/* let thing = {"name": "blah"};
   Js.log(thing); */

/* Old API for using JavaScript objects */
type person = {
  .
  "name": string,
  "age": int,
  "job": string,
};
/* let john: person = [%bs.obj {name:  "John", age: 34, job: "Cyborg Mechanic"}]; */
let john: person = {"name": "John", "age": 34, "job": "Cyborg Mechnanic"};
Js.log(john);
