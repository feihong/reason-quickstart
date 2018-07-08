let players = [%bs.obj [|
  {
    name: "Amy",
    scores: [|1, 2, 3|]
  },
  {
    name: "Brolinho",
    scores: [|4, 5, 6|],    
  }
|]
];

/* Js.log(players); */

players 
|> Js.Array.forEachi((player, i) => {
  Js.log2(i, player##name);
  Js.log2("First score:", (player##scores)[0]);
})