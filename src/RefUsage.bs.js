// Generated by BUCKLESCRIPT VERSION 5.0.2, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");

var state_001 = /* someInstanceVar : record */Block.record(["contents"], [2]);

var state = /* record */Block.record([
    "a",
    "someInstanceVar"
  ], [
    1,
    state_001
  ]);

var state2_001 = state_001;

var state2 = /* record */Block.record([
    "a",
    "someInstanceVar"
  ], [
    3,
    state2_001
  ]);

state_001[0] = 44;

console.log(state2_001[0]);

exports.state = state;
exports.state2 = state2;
/*  Not a pure module */