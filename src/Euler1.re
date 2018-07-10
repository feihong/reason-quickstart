open Belt;

let compute = () => {
  Array.range(1, 999)
  |. Array.keep(x => 
      switch (x mod 3, x mod 5) {
      | (0, _) | (_, 0) => true
      | _ => false
      })
  |. Array.reduce(0, (+));
};