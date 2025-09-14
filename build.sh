#!/bin/bash
set -e
set +x

mkdir -p ./build > /dev/null
pushd ./build > /dev/null

c++ -o handmade ../src/handmade.cpp -Wall -g

for n in $@; do
  if [ "${n}" = '-x' ]; then
    ./handmade
  fi
done

popd > /dev/null
