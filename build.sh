#!/bin/bash

usage()
{
  echo "build: build.sh [options...]"
  echo "  This build script will automate the build and install of MIA."
  echo ""
  echo "  Options:"
  echo "    -h    Display this help message."
  echo "    -i    Installs the executables to the program directory (/usr/bin/)"
}

while getopts "hi" opt; do
  case $opt in
    h) usage
      ;;
    i) install_binaries=1
      echo "Install binaries: True"
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

if (( install_binaries ))
then
  echo "Installing files."
  sudo mkdir -vp /etc/MIA/resources/InputFiles
  sudo cp -v bin/resources/*.MIA /etc/MIA/resources/
  sudo cp -v bin/resources/InputFiles/* /etc/MIA/resources/InputFiles/
  sudo cp -v bin/terminal/MIATerminal /usr/bin/
  echo "Finished installing files."
fi