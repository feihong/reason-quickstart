// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';


console.log("__LOC__:", "File \"MagicVariables.re\", line 1, characters 20-27");

console.log("__FILE__:", "MagicVariables.re");

console.log("__MODULE__:", "MagicVariables-HelloReason");

console.log("__LINE__:", 7);

console.log("__POS__:", /* tuple */[
      "MagicVariables.re",
      9,
      20,
      27
    ]);

console.log("__MODULE__ inside InnerModule:", "MagicVariables-HelloReason");

var InnerModule = { };

function coolFunc(param) {
  console.log("你好世界！");
  return /* () */0;
}

console.log("你好世界！");

console.log("__LOC_OF__:", /* tuple */[
      "File \"MagicVariables.re\", line 19, characters 34-42",
      coolFunc
    ]);

console.log("__LINE_OF__:", /* tuple */[
      21,
      coolFunc
    ]);

console.log("__POS_OF__:", /* tuple */[
      /* tuple */[
        "MagicVariables.re",
        23,
        34,
        42
      ],
      coolFunc
    ]);

var filename = __filename;

console.log("__filename:", filename);

var dirname = __dirname;

console.log("__dirname:", dirname);

exports.InnerModule = InnerModule;
exports.coolFunc = coolFunc;
exports.filename = filename;
exports.dirname = dirname;
/*  Not a pure module */
