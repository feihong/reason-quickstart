/**
 * https://www.eventbrite.com/developer/v3/endpoints/events/
 * 
 */

type venue = {
  id: string,
  name: string,
  address: string,
}

type event = {
  id: string,
  name: string,
  description: string,
  url: string,
  start: string,
  venue: option(venue),
}

type pagination = {
  page_count: int,
}

type resultPage = {
  pagination: pagination,
  events: array(event),
}

module Decode = {
  let pagination = json => Json.Decode.{
    page_count: json |> field("page_count", int)
  };

  let event = json => Json.Decode.{
      id: json |> field("id", string),
      name: json |> at(["name", "text"], string),
      description: json |> at(["description", "text"], string),
      url: json |> field("url", string),
      start: json |> at(["start", "local"], string),
      venue: None,
    };
  
  let page = json => Json.Decode.{
    pagination: json |> field("pagination", pagination),
    events: json |> field("events", array(event)),
  };
}

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
  ());

Js.Promise.(
  Axios.getc("https://www.eventbriteapi.com/v3/events/search", cfg)
  |> then_(res => { 
      Js.log(res##status);
      let text = Helpers.prettyStringify(res##data);
      Node.Fs.writeFileAsUtf8Sync("results.json", text);
      res##data
      |> Decode.page
      |> (pg => pg.events)
      |> Array.iter(evt => {
        Js.log(evt.name);
      });
      resolve(ignore)
  })
  |> catch(_err => {
    Js.log("Unexpected error occurred");
    resolve(ignore)
  })
);