open Belt;

[@bs.send] external stringIncludes: (string, string) => bool = "includes";

let handleMessage = mesg =>
  if (mesg->String.lowercase->(stringIncludes("success"))) {
    Result.Ok(mesg);
  } else {
    Result.Error(mesg);
  };

"The launch was a total success!"->handleMessage->Js.log;

"The rocket crashed and burned!?!"->handleMessage->Js.log;

Result.Ok("monkey shine")->(Result.map(x => x->String.uppercase))
|> Js.log2("map on Ok:");

Result.Error("monkey shine")->(Result.map(x => x->String.uppercase))
|> Js.log2("map on Error:");
