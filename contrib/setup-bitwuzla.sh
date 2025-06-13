#!/bin/bash
set -e

BITWUZLA_VERSION=f516ce42c79cd42aa7b51f52d1b262e1336a0642
DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd)"
DEPS="$(dirname "$DIR")/deps"

mkdir -p $DEPS

if [ ! -d "$DEPS/bitwuzla" ]; then
    cd $DEPS
    git clone https://github.com/bitwuzla/bitwuzla.git
    cd bitwuzla
    git checkout -f $BITWUZLA_VERSION
    ./configure.py --prefix $DEPS/install
    cd build
    meson compile
    meson install
else
    echo "$DEPS/bitwuzla already exists. If you want to rebuild, please remove it manually."
fi
