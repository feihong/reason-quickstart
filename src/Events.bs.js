// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var Fs = require("fs");
var Json = require("bs-json/src/Json.js");
var Axios = require("axios");
var Json_decode = require("bs-json/src/Json_decode.js");

function getAccessToken() {
  return Json_decode.field("eventbrite_access_token", Json_decode.string, Json.parseOrRaise(Fs.readFileSync("secrets.json", "utf8")));
}

var cfg = {
  params: {
    token: getAccessToken(/* () */0),
    "location.address": "2100 S Wentworth Ave, Chicago, IL 60616",
    "location.within": "1mi",
    sort_by: "date"
  }
};

Axios.get("https://www.eventbriteapi.com/v3/events/search", cfg).then((function (res) {
        console.log(res.status);
        var text = ( JSON.stringify(res.data, null, 2) );
        Fs.writeFileSync("results.json", text, "utf8");
        return Promise.resolve(true);
      }));

exports.getAccessToken = getAccessToken;
exports.cfg = cfg;
/* cfg Not a pure module */
