let getAccessToken = () =>
    Node.Fs.readFileAsUtf8Sync("secrets.json")
    |> Json.parseOrRaise
    |> Json.Decode.(field("eventbrite_access_token", string));


/* getAccessToken()
|> Js.log; */

let _ = 
    Js.Promise.(
        Axios.get("http://ipecho.net/plain")
        |> then_((res) => 
            Js.log(res##data) |> resolve
        )
    );