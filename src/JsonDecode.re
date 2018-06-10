/**
 * Note that this is the deprecated way to do things.
 */

let text = {|
{
    "name": "Wario",
    "job": "Villain",
    "powerLevel": 8999.99,
    "bio": "Evil version of Mario"
}    
|};

type person = {
    name: string,
    job: string,
    powerLevel: float,
    /* leave out the bio field */
}

let json: Js.Json.t = Json.parseOrRaise(text);
Js.log(json);

/* obj will be of type person */
let obj = Json.Decode.{
    name: field("name", string, json),
    job: field("job", string, json),
    powerLevel: field("powerLevel", Json.Decode.float, json)
};
Js.log(obj);
Js.log(obj.name);