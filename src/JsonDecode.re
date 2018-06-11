/**
 * https://bucklescript.github.io/docs/en/object-deprecated.html
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

type venue = {
  name: string,
  address: string,
};

type event = {
  name: string,
  description: string,
  type_: string,
  rsvp_count: int,
  venue: option(venue),
};

module Decode = {
  let venue = json => 
    Json.Decode.{
      name: json |> field("name", string),
      address: json |> field("address", string),
    };
  
  let event = json =>
    Json.Decode.{
      name: json |> field("name", string),
      description: json |> field("description", string),
      type_: json |> field("type", string),
      rsvp_count: json |> field("rsvp_count", int),
      venue: json |> optional(field("venue", venue)),
    };
};

response##events 
  |> Json.Decode.array(Decode.event)
  |> Array.iter(evt => {
    /* Js.log(evt); */
    Js.log(evt.name);
    switch(evt.venue) {
    | None => Js.log("Venue unknown")
    | Some(venue_) => Js.log("At " ++ venue_.name)
    };
    Js.log("====");
  });