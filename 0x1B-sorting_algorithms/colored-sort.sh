#!/usr/bin/env bash

if ! (( $# ))
then
    if [[ -t 0 ]]
    then
        printf 1>&2 'usage: %s executable [arguments ...]\n' "${0##*/}"
        exit 2
    fi
elif [[ $1 != - ]]
then
    if ! [[ -e $1 ]]
    then
        printf 1>&2 '%s: %s: No such file or directory\n' "${0##*/}" "$1"
        exit 1
    fi
    if ! [[ -f $1 ]]
    then
        printf 1>&2 '%s: %s: Not a regular file\n' "${0##*/}" "$1"
        exit 1
    fi
    if ! [[ -r $1 && -x $1 ]]
    then
        printf 1>&2 '%s: %s: Permission denied\n' "${0##*/}" "$1"
        exit 1
    fi
    if [[ $1 != ?(.?(.))/* ]]
    then
        exec 0< <("./$@")
    else
        exec 0< <("$@")
    fi
fi
unset colors escapes numbers reset
while IFS=$', \t' read -ra numbers
do
    read -t 0.03 -u "${fd}" &
    if [[ ${numbers[@]} == +(?(-)[[:digit:]]*([[:blank:]])) ]]
    then
        for i in "${!numbers[@]}"
        do
            printf -v 'numbers[i]' '%02d' "${numbers[i]}"
            numbers[i]="${escapes[${colors[${numbers[i]}]=$((i))} % 14 + 1]=$(
            tput setaf "$((colors[numbers[i]] % 14 + 1))"
            )}${numbers[i]}${reset=$(tput sgr0)},"
        done
        numbers[-1]="${numbers[-1]%,}"
    fi
    echo "${numbers[@]}"
    wait "$!"
done {fd}<> <(:)
exit 0
