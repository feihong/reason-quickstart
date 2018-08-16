let players = [%bs.obj [|
  {
    name: "Amy",
    scores: [|1, 2, 3|],
    avatar: {
      url: "https://avtr.com/amy"
    }
  },
  {
    name: "Brolinho",
    scores: [|4, 5, 6|],
    avatar: {
      url: "https://avtr.com/brolinho"
    }
  }
|]
];

/* Js.log(players); */

players
|> Js.Array.forEachi((player, i) => {
  Js.log3("Player", i, player##name);
  Js.log2("First score:", (player##scores)[0]);
  Js.log2("Avatar image:", player##avatar##url);
  Js.log("======");
})
