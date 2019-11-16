// Generated by BUCKLESCRIPT VERSION 5.0.2, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var Block = require("bs-platform/lib/js/block.js");

var title = "Button";

var ButtonDoc = /* module */Block.localModule([
    "title",
    "desc"
  ], [
    title,
    "An interactive widget that executes a handler when you click it"
  ]);

var title$1 = "Text";

var TextDoc = /* module */Block.localModule([
    "title",
    "defaultFont"
  ], [
    title$1,
    "monospace"
  ]);

function printDoc(doc) {
  console.log(doc[/* title */0]);
  return /* () */0;
}

var doc1 = [title];

var doc2 = [title$1];

List.iter(printDoc, /* :: */Block.simpleVariant("::", [
        doc1,
        /* :: */Block.simpleVariant("::", [
            doc2,
            /* [] */0
          ])
      ]));

exports.ButtonDoc = ButtonDoc;
exports.TextDoc = TextDoc;
exports.printDoc = printDoc;
exports.doc1 = doc1;
exports.doc2 = doc2;
/*  Not a pure module */
