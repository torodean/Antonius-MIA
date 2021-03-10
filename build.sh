#!/bin/bash

usage()
{
  echo "build: build.sh [options...]"
  echo "  This build script will automate the build and install of MIA."
  echo ""
  echo "  Options:"
  echo "    -h    Display this help message."
  echo "    -v    Enable verbose mode."
  echo "    -r    Builds a release version."
}


while getopts "hvr" opt; do
  case $opt in
    h) usage
      ;;
    v) verbose_mode=1
      echo "VerboseMode: True"
      ;;
    r) build_release=1
      echo "Release build: True"
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

cmake -G "Unix Makefiles"
make -j16

echo "...MIA Build done!"