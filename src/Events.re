/**
 * https://www.eventbrite.com/developer/v3/endpoints/events/
 * 
 */

let getAccessToken = () =>
    Node.Fs.readFileAsUtf8Sync("secrets.json")
    |> Json.parseOrRaise
    |> Json.Decode.(field("eventbrite_access_token", string));


let cfg = Axios.makeConfig(
    ~params={
        "token": getAccessToken(),
        "location.address": "2100 S Wentworth Ave, Chicago, IL 60616",
        "location.within": "1mi",
        "sort_by": "date"
    }, 
    ~responseType="text",
    ~transformResponse=Axios.makeResponseTransformer1((a) => a),
    ());
Js.Promise.(
    Axios.getc("https://www.eventbriteapi.com/v3/events/search", cfg)
    |> then_((res) => { 
        Js.log(res##status);
        Node.Fs.writeFileAsUtf8Sync("results.json", res##data);
        true |> resolve
    })
);