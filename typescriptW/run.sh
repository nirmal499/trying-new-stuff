#!/usr/bin/bash
tsc $1.ts --lib es6,dom && node $1.js