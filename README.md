# Feihong's Reason Quickstart

# Prerequisites

    brew install entr
    yarn global add bs-platform

# Create project

    bsb -init hello-reason -theme basic-reason

# Commands

Build + Watch

    yarn start

Build

    yarn build

Run

    node src/Hello.bs.js

Run tests

    yarn test

# Notes

Find libraries using [Redex, the Reason Package Index](https://redex.github.io/).

Never use `"bsc-flags": ["-bs-g"]` (debug mode printing) in production.

## Documentation

- [OCaml standard library](https://reasonml.github.io/api/index)
- [Belt](https://bucklescript.github.io/bucklescript/api/index.html)
- [BuckleScript docs](https://bucklescript.github.io/en/)
- [ReasonML docs](https://reasonml.github.io/)
- [BuckleScript User Manual](https://bucklescript.github.io/bucklescript/Manual.html)
