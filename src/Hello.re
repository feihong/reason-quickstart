let mesg: string = [%bs.raw {| '你好世界！' |}];
Js.log(mesg);

/* This will just be garbage */
Js.log("你好世界！");
