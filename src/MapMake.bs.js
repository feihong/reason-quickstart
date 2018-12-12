// Generated by BUCKLESCRIPT VERSION 4.0.11, PLEASE EDIT WITH CARE
'use strict';

var Belt_Id = require("bs-platform/lib/js/belt_Id.js");
var Belt_Map = require("bs-platform/lib/js/belt_Map.js");
var Caml_obj = require("bs-platform/lib/js/caml_obj.js");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");

function cmp(param, param$1) {
  var c = Caml_obj.caml_compare(param[0], param$1[0]);
  if (c !== 0) {
    return c;
  } else {
    return Caml_obj.caml_compare(param[1], param$1[1]);
  }
}

var IntPairs = Belt_Id.MakeComparable(/* module */[/* cmp */cmp]);

function updateValue(maybe) {
  return Belt_Option.map(maybe, (function (x) {
                switch (x) {
                  case "pizza place" : 
                      return "pizzeria";
                  case "taco joint" : 
                      return "tacqueria";
                  default:
                    return x;
                }
              }));
}

var m = Belt_Map.update(Belt_Map.update(Belt_Map.update(Belt_Map.set(Belt_Map.set(Belt_Map.set(Belt_Map.make(IntPairs), /* tuple */[
                          0,
                          0
                        ], "origin"), /* tuple */[
                      10,
                      20
                    ], "pizza place"), /* tuple */[
                  12,
                  15
                ], "taco joint"), /* tuple */[
              10,
              20
            ], updateValue), /* tuple */[
          12,
          15
        ], updateValue), /* tuple */[
      0,
      0
    ], updateValue);

console.log(Belt_Map.toArray(m));

console.log("Empty?", Belt_Map.isEmpty(m));

console.log("At (0,0):", Belt_Map.get(m, /* tuple */[
          0,
          0
        ]));

var x = Belt_Map.get(m, /* tuple */[
      0,
      1
    ]);

if (x !== undefined) {
  console.log("Found", x);
} else {
  console.log("Nothing found");
}

var x$1 = Belt_Map.get(m, /* tuple */[
      10,
      20
    ]);

if (x$1 !== undefined) {
  console.log("Found", x$1);
} else {
  console.log("Nothing found");
}

exports.IntPairs = IntPairs;
exports.updateValue = updateValue;
exports.m = m;
/* IntPairs Not a pure module */
