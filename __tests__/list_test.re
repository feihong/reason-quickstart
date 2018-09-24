open Belt;
open Jest;

describe("Belt.List", () => {
  open Expect;

  test("make", () =>
    List.make(4, 'A') |> expect |> toEqual(['A', 'A', 'A', 'A'])
  );

  test("makeBy", () =>
    List.makeBy(5, i => 2 * i) |> expect |> toEqual([0, 2, 4, 6, 8])
  );

  test("getAssoc", () =>
    [(1, "a"), (2, "b"), (3, "c")]->(List.getAssoc(2, (==)))
    |> expect
    |> toEqual(Some("b"))
  );

  test("zip", () =>
    List.zip([1, 2, 3], ['a', 'b', 'c', 'd'])
    |> expect
    |> toEqual([(1, 'a'), (2, 'b'), (3, 'c')])
  );

  test("zipBy", () =>
    List.zipBy([1, 2, 3, 4], ['a', 'b', 'c'], (x, y) => (x * 3, y))
    |> expect
    |> toEqual([(3, 'a'), (6, 'b'), (9, 'c')])
  );
});
