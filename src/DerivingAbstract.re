let response = [%bs.raw {| 
{
    events: [
        {
            name: 'Block Party',
            description: 'Come to a party on my block',
            rsvp_count: 7
        },
        {
            name: 'Harvest Parade',
            description: 'A wonderful parade featuring tomatoes and potatoes',
            rsvp_count: 305
        }
    ]
}    
|}];

[@bs.deriving abstract]
type event = {
    name: string,
    description: string,
    rsvp_count: int,
};

let getEvents = (response) => {
    let events: array(event) = response##events;
    events;
};

/* Js.log(getEvents(response)); */

getEvents(response)
|> Array.iter(evt => {
    Printf.printf("%s (%i guests)\n", evt |. name, evt |. rsvp_count);
    Js.log("  " ++ (evt |. description) ++ "\n");
  });