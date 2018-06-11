/**
 * https://bucklescript.github.io/docs/en/object.html#record-mode
*/

let response = [%bs.raw {| 
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
|}];

/* It looks like we are defining a record type, but it's just syntactic sugar,
   and the record type is actually erased. */
[@bs.deriving abstract]
type venue = {
  [@bs.as "name"] vname: string,
  address: string,
};

[@bs.deriving abstract]
type event = {
  name: string,
  description: string,
  rsvp_count: int,
  /* "type" is a keyword so you can't use it as a field name */
  [@bs.as "type"] type_: string,
  [@bs.optional] venue: venue,
};

let getEvents = (response) => {
  /* This is an unsafe cast */
  let events: array(event) = response##events;
  events;    
};

/* Js.log(getEvents(response)); */

getEvents(response)
|> Array.iter(evt => {
    Printf.printf("%s (%i guests)\n", evt |. name, evt |. rsvp_count);
    Printf.printf("  This is a %s event\n", evt |. type_);
    switch(evt |. venue) {
    | None => Js.log("  Venue is not known")
    | Some(v) => Js.log("  " ++ (v |. address))
    };
    Js.log("  " ++ (evt |. description) ++ "\n");
  });