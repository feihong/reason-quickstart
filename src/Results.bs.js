// Generated by BUCKLESCRIPT VERSION 5.0.2, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var $$String = require("bs-platform/lib/js/string.js");
var Belt_Result = require("bs-platform/lib/js/belt_Result.js");

function handleMessage(mesg) {
  if ($$String.lowercase(mesg).includes("success")) {
    return /* Ok */Block.variant("Ok", 0, [mesg]);
  } else {
    return /* Error */Block.variant("Error", 1, [mesg]);
  }
}

console.log(handleMessage("The launch was a total success!"));

console.log(handleMessage("The rocket crashed and burned!?!"));

console.log("map on Ok:", Belt_Result.map(/* Ok */Block.variant("Ok", 0, ["monkey shine"]), $$String.uppercase));

console.log("map on Error:", Belt_Result.map(/* Error */Block.variant("Error", 1, ["monkey shine"]), $$String.uppercase));

exports.handleMessage = handleMessage;
/*  Not a pure module */
