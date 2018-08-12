// Generated by BUCKLESCRIPT VERSION 4.0.3, PLEASE EDIT WITH CARE
'use strict';

var Caml_array = require("bs-platform/lib/js/caml_array.js");

var players = /* array */[
  {
    name: "Amy",
    scores: /* array */[
      1,
      2,
      3
    ],
    avatar: {
      url: "https://avtr.com/amy"
    }
  },
  {
    name: "Brolinho",
    scores: /* array */[
      4,
      5,
      6
    ],
    avatar: {
      url: "https://avtr.com/brolinho"
    }
  }
];

players.forEach((function (player, i) {
        console.log("Player", i, player.name);
        console.log("First score:", Caml_array.caml_array_get(player.scores, 0));
        console.log("Avatar image:", player.avatar.url);
        console.log("======");
        return /* () */0;
      }));

exports.players = players;
/*  Not a pure module */
