/**
 * https://www.eventbrite.com/developer/v3/endpoints/events/
 * 
 */

let getAccessToken = () =>
    Node.Fs.readFileAsUtf8Sync("secrets.json")
    |> Json.parseOrRaise
    |> Json.Decode.(field("eventbrite_access_token", string));


let params = {
    "token": getAccessToken(),
    "location.address": "2100 S Wentworth Ave, Chicago, IL 60616",
    "location.within": "1mi",
    "sort_by": "date"
};
/* Js.Promise.(
    Axios.getc("https://eventbriteapi.com/v3/events/search", {params})
    |> then_((res) => 
        Js.log(res##data) |> resolve
    )
); */