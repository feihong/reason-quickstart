// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Belt_Array = require("bs-platform/lib/js/belt_Array.js");
var Caml_exceptions = require("bs-platform/lib/js/caml_exceptions.js");

var VRDisplayNotAvailable = Caml_exceptions.create("Externals-HelloReason.VRDisplayNotAvailable");

function getVRDisplays(param) {
  var isAvailable = (typeof(navigator) !== 'undefined' && navigator.getVRDisplays !== undefined);
  if (isAvailable) {
    return navigator.getVRDisplays();
  } else {
    return Promise.reject(VRDisplayNotAvailable);
  }
}

getVRDisplays(/* () */0).then((function (displays) {
          Belt_Array.forEach(displays, (function (prim) {
                  console.log(prim);
                  return /* () */0;
                }));
          return Promise.resolve(/* () */0);
        })).catch((function (err) {
        console.log("Failure:", err);
        return Promise.resolve(/* () */0);
      }));

exports.VRDisplayNotAvailable = VRDisplayNotAvailable;
exports.getVRDisplays = getVRDisplays;
/*  Not a pure module */
