module type Doc = {let title: string;};

module ButtonDoc = {
  let title = "Button";
  let desc = "An interactive widget that executes a handler when you click it";
};

module TextDoc = {
  let title = "Text";
  let defaultFont = "monospace";
};

let printDoc = doc => {
  module Doc' = (val doc: Doc);
  Js.log(Doc'.title);
};

let doc1: module Doc = (module ButtonDoc);
let doc2: module Doc = (module TextDoc);

let () = List.iter(printDoc, [doc1, doc2]);
