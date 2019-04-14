// Generated by BUCKLESCRIPT VERSION 5.0.2, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var Printf = require("bs-platform/lib/js/printf.js");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");

var response = (
{
  events: [
    {
      name: 'Block Party',
      description: 'Come to a party on my block',
      type: 'party',
      rsvp_count: 7,
      venue: {
        name: 'The Best Block EVAR',
        address: '400-500 N Groob Ln'
      }
    },
    {
      name: 'Harvest Parade',
      description: 'A wonderful parade featuring tomatoes and potatoes',
      type: 'parade',
      rsvp_count: 305
    }
  ]
}
);

var Venue = /* module */Block.localModule([], []);

var $$Event = /* module */Block.localModule([], []);

function getEvents(response) {
  return response.events;
}

Belt_Array.forEach(response.events, (function (evt) {
        Curry._2(Printf.printf(/* Format */Block.simpleVariant("Format", [
                    /* String */Block.variant("String", 2, [
                        /* No_padding */0,
                        /* String_literal */Block.variant("String_literal", 11, [
                            " (",
                            /* Int */Block.variant("Int", 4, [
                                /* Int_i */3,
                                /* No_padding */0,
                                /* No_precision */0,
                                /* String_literal */Block.variant("String_literal", 11, [
                                    " guests)\n",
                                    /* End_of_format */0
                                  ])
                              ])
                          ])
                      ]),
                    "%s (%i guests)\n"
                  ])), evt.name, evt.rsvp_count);
        Curry._1(Printf.printf(/* Format */Block.simpleVariant("Format", [
                    /* String_literal */Block.variant("String_literal", 11, [
                        "  This is a ",
                        /* String */Block.variant("String", 2, [
                            /* No_padding */0,
                            /* String_literal */Block.variant("String_literal", 11, [
                                " event\n",
                                /* End_of_format */0
                              ])
                          ])
                      ]),
                    "  This is a %s event\n"
                  ])), evt.type);
        var match = evt.venue;
        if (match !== undefined) {
          console.log("  " + match.address);
        } else {
          console.log("  Venue is not known");
        }
        console.log("  " + (evt.description + "\n"));
        return /* () */0;
      }));

exports.response = response;
exports.Venue = Venue;
exports.$$Event = $$Event;
exports.getEvents = getEvents;
/* response Not a pure module */
