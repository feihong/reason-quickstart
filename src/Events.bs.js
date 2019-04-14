// Generated by BUCKLESCRIPT VERSION 5.0.2, PLEASE EDIT WITH CARE
'use strict';

var Fs = require("fs");
var Json = require("@glennsl/bs-json/src/Json.bs.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var Axios = require("axios");
var Json_decode = require("@glennsl/bs-json/src/Json_decode.bs.js");

function pagination(json) {
  return /* record */Block.record(["page_count"], [Json_decode.field("page_count", Json_decode.$$int, json)]);
}

function $$event(json) {
  return /* record */Block.record([
            "id",
            "name",
            "description",
            "url",
            "start",
            "venue"
          ], [
            Json_decode.field("id", Json_decode.string, json),
            Json_decode.at(/* :: */Block.simpleVariant("::", [
                      "name",
                      /* :: */Block.simpleVariant("::", [
                          "text",
                          /* [] */0
                        ])
                    ]), Json_decode.string)(json),
            Json_decode.at(/* :: */Block.simpleVariant("::", [
                      "description",
                      /* :: */Block.simpleVariant("::", [
                          "text",
                          /* [] */0
                        ])
                    ]), Json_decode.string)(json),
            Json_decode.field("url", Json_decode.string, json),
            Json_decode.at(/* :: */Block.simpleVariant("::", [
                      "start",
                      /* :: */Block.simpleVariant("::", [
                          "local",
                          /* [] */0
                        ])
                    ]), Json_decode.string)(json),
            undefined
          ]);
}

function page(json) {
  return /* record */Block.record([
            "pagination",
            "events"
          ], [
            Json_decode.field("pagination", pagination, json),
            Json_decode.field("events", (function (param) {
                    return Json_decode.array($$event, param);
                  }), json)
          ]);
}

var Decode = /* module */Block.localModule([
    "pagination",
    "event",
    "page"
  ], [
    pagination,
    $$event,
    page
  ]);

function getAccessToken(param) {
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
          var text = JSON.stringify(res.data, null, 2);
          Fs.writeFileSync("results.json", text, "utf8");
          $$Array.iter((function (evt) {
                  console.log(evt[/* name */1]);
                  return /* () */0;
                }), page(res.data)[/* events */1]);
          return Promise.resolve((function (prim) {
                        return /* () */0;
                      }));
        })).catch((function (_err) {
        console.log("Unexpected error occurred");
        return Promise.resolve((function (prim) {
                      return /* () */0;
                    }));
      }));

exports.Decode = Decode;
exports.getAccessToken = getAccessToken;
exports.cfg = cfg;
/* cfg Not a pure module */
