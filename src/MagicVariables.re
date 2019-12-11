Js.log2("__LOC__:", __LOC__);

Js.log2("__FILE__:", __FILE__);

Js.log2("__MODULE__:", __MODULE__);

Js.log2("__LINE__:", __LINE__);

Js.log2("__POS__:", __POS__);

module InnerModule = {
  Js.log2("__MODULE__ inside InnerModule:", __MODULE__);
};

let coolFunc = () => Js.log({js|你好世界！|js});

coolFunc();

Js.log2("__LOC_OF__:", __LOC_OF__(coolFunc));

Js.log2("__LINE_OF__:", __LINE_OF__(coolFunc));

Js.log2("__POS_OF__:", __POS_OF__(coolFunc));

// Node magic variables:
let filename: string = [%bs.raw "__filename"];
Js.log2("__filename:", filename);

let dirname: string = [%bs.raw "__dirname"];
Js.log2("__dirname:", dirname);
