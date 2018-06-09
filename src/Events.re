
let getAccessToken = () =>
    Node.Fs.readFileAsUtf8Sync("secrets.json")
    |> Json.parseOrRaise
    |> Json.Decode.(field("eventbrite_access_token", string))


getAccessToken()
|> Js.log
