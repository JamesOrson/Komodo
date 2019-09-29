#! /bin/bash
cd packages

# Set up spdlog
echo "Setting up spdlog..."
cd spdlog

mkdir -f build
cd build
cmake ..
make -j
make install
