Js.log2("__LOC__:", __LOC__);

Js.log2("__FILE__:", __FILE__);

Js.log2("__MODULE__:", __MODULE__);

Js.log2("__LINE__:", __LINE__);

module InnerModule = {
  Js.log2("__MODULE__ inside InnerModule:", __MODULE__);
};
