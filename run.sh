#!/bin/bash
set -e

BUILD_DIR="build"
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

cd "$BUILD_DIR"

cmake ..
ln -sf compile_commands.json ../compile_commands.json

make

export XKB_LOG_LEVEL=critical

./lingshui_window