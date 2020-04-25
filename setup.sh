#! /bin/bash
cd packages

# Set up spdlog
echo "Setting up spdlog..."
cd spdlog

echo "    Making build directory"
mkdir -p build
echo "    Moving to build directory"
cd build
echo "    Running cmake"
cmake ..
echo "    Running make"
make -j
echo "    Running make install"
echo ""
make install

# Reset directory
cd ../..

# Set up SFML
echo "Setting up SFML..."
cd SFML

echo "    Making build directory"
mkdir -p build
echo "    Moving to build directory"
cd build
echo "    Running cmake"
cmake ..
echo "    Running make"
make -j
echo "    Running make install"
echo ""
make install

echo "Setup done..."