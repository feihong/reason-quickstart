type vrDisplay;
exception VRDisplayNotAvailable;

[@bs.val] external getVRDisplays_ : 
  unit => Js.Promise.t(array(vrDisplay)) = "navigator.getVRDisplays";

let getVRDisplays = () => {
  let isAvailable: bool = [%bs.raw 
    "typeof(navigator) !== 'undefined' && navigator.getVRDisplays !== undefined"
  ];
  isAvailable ? getVRDisplays_() : Js.Promise.reject(VRDisplayNotAvailable);
};

Js.Promise.(
  getVRDisplays()
  |> then_(displays => {
    displays |. Belt.Array.forEach(Js.log);
    resolve();
  })
  |> catch(err => {
    Js.log2("Failure:", err);
    resolve();
  })
);