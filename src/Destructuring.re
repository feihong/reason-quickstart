open Belt;

let (a, b, c) = (1, "two", 34.56);
Js.log4("Tuple values:", a, b, c);

type location = {
  country: string,
  state: option(string),
}

type player = {
  name: string,
  powerLevel: float,
  classes: list(string),     /* class is a reserved keyword */
  location: location,
}

let player1 = {
  name: "BurgerLizard",
  powerLevel: 9000.126,
  classes: ["NecroPaladin", "NinjaBerserker"],
  location: {
    country: "tw",
    state: None,
  }
};

let {name, powerLevel, classes, location: {country, state}} = player1;

Printf.printf("name: %s, powerLevel: %0.2f, country: %s, state: %s\n", 
  name, powerLevel, country, 
  state |. Option.getWithDefault("N/A"));
Js.log2("Classes:", classes);
