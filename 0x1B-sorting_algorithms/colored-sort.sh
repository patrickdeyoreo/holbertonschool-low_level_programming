#!/usr/bin/env bash

if [[ $0 != "${BASH_SOURCE[0]}" ]]
then
  printf 1>&2 '%s: Do not source this file\n' "${BASH_SOURCE[0]##*/}"
  return 2
fi
if ! (( $# ))
then
  printf 1>&2 'usage: %s program [arguments ...]\n' "${0##*/}"
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

declare -A colors=( ) && while IFS=$', \t' read -ra numbers
do
  if [[ ${numbers[@]} != +([[:digit:]]?(,)*([[:blank:]])) ]]
  then
    echo "${numbers[@]}"
    continue
  fi
  for i in "${!numbers[@]}"
  do
    colors["${numbers[i]}"]="$((i))"
  done
  while
    for i in "${!numbers[@]}"
    do
      numbers[i]="$(
      tput setaf "$((colors[$((numbers[i]))] % 14 + 1))"
      )$(
      printf '%02d' "$((numbers[i]))"
      )$(
      tput sgr0
      )$(
      if (( i + 1 < ${#numbers[@]} ))
      then
        echo ','
      fi
      )"
    done
    echo "${numbers[@]}"
    IFS=$', \t\n' read -ra numbers
  do
    if [[ ${numbers[@]} != +([[:digit:]]?(,)*([[:blank:]])) ]]
    then
      echo "${numbers[@]}"
      continue 2
    fi
  done
done < <(unbuffer "$@")
