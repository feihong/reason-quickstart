// Generated by BUCKLESCRIPT VERSION 4.0.11, PLEASE EDIT WITH CARE
'use strict';


var polymorphicFunction_ = (
  function (a, b) {
    return `${a} is a ${typeof a}, ${b} is a ${typeof b}`
  }
);

console.log(polymorphicFunction_(45, "cat"));

console.log(polymorphicFunction_("dog", 36));

console.log(polymorphicFunction_(45, 55));

console.log(polymorphicFunction_("mole", "rat"));

exports.polymorphicFunction_ = polymorphicFunction_;
/* polymorphicFunction_ Not a pure module */
