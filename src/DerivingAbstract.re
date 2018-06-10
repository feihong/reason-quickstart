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

[@bs.val] external events: array(event) = "response.events";

/* Js.log(events); */

events |> Array.iter(evt => {
    Printf.sprintf("%s (%i guests)", evt |. name, evt |. rsvp_count) |> Js.log;
    Js.log("  " ++ (evt |. description) ++ "\n");
});