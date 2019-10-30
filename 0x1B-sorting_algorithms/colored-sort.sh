#!/usr/bin/env bash

if ! (( $# ))
then
    printf 1>&2 'usage: %s executable [arguments ...]\n' "${0##*/}"
    exit 2
fi
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
    set -- "./$1" "${@:2}"
fi

colors=( )
while IFS=$', \t' read -ra numbers
do
    if [[ ${numbers[@]} == +(?(-)[[:digit:]]*([[:blank:]])) ]]
    then
        for i in "${!numbers[@]}"
        do
            : "${colors[${numbers[i]}]=${i}}"
            numbers[i]="$(
            tput setaf "$((colors[${numbers[i]}] % 14 + 1))"
            printf '%02d' "${numbers[i]}"
            tput sgr0
            if (( i + 1 < ${#numbers[@]} ))
            then
                echo ','
            fi
            )"
        done
    fi
    echo "${numbers[@]}"
    read -t 0.001 -u "${pause}"
done 0< <("$@") {pause}<> <(:)

exit 0
