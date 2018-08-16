/*

 https://bucklescript.github.io/docs/en/object.html#record-mode

 */
open Belt;

let response = [%bs.raw
  {|
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
|}
];

/* It looks like we are defining a record type, but it's just syntactic sugar,
   and the record type is actually erased. */
module Venue = {
  [@bs.deriving abstract]
  type t = {
    name: string,
    address: string,
  };
};

module Event = {
  [@bs.deriving abstract]
  type t = {
    name: string,
    description: string,
    rsvp_count: int,
    /* "type" is a keyword so you can't use it as a field name */
    [@bs.as "type"]
    type_: string,
    [@bs.optional]
    venue: Venue.t,
  };
};

let getEvents = response => {
  let events: array(Event.t) = response##events;
  events;
};

/* Js.log(getEvents(response)); */

getEvents(response)
->(
    Array.forEach(evt => {
      open Event;
      Printf.printf("%s (%i guests)\n", evt->nameGet, evt->rsvp_countGet);
      Printf.printf("  This is a %s event\n", evt->type_Get);
      switch (evt->venueGet) {
      | None => Js.log("  Venue is not known")
      | Some(v) => Js.log("  " ++ v->Venue.addressGet)
      };
      Js.log("  " ++ evt->descriptionGet ++ "\n");
    })
  );
