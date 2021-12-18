#!/bin/bash

usage()
{
  echo "build: build.sh [options...]"
  echo "  This build script will automate the build and install of MIA."
  echo ""
  echo "  Options:"
  echo "    -h    Display this help message."
}

while getopts "h" opt; do
  case $opt in
    h) usage
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      exit 1
      ;;
    :)
      echo "Option -$OPTARG requires an argument." >&2
      exit 1
      ;;
  esac
done

echo "...Beginning MIA Build!"

mkdir -p build
cmake -G "Unix Makefiles" -Bbuild/
cd build
make -j16

echo "...MIA Build done!"