#!/bin/bash

scriptLocation=$(readlink -f "$0")
rootDirectory=$(dirname "$scriptLocation")
echo "rootDirectory: $rootDirectory"
cd $rootDirectory || exit

usage()
{
  echo "build: build.sh [options...]"
  echo "  This build script will automate the build and install of MIA."
  echo ""
  echo "  Options:"
  echo "    -h    Display this help message."
  echo "    -I    Attempt to Install dependencies."
  echo "    -u    Update release files on successful build."
}

while getopts "hIu" opt; do
  case $opt in
    h) usage
      exit 1
      ;;
    I) installDependencies=1
      ;;
    u) updateReleaseFiles=1
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

# Place linux specific code here.
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
  if [[ $installDependencies ]]; then
    echo "...Installing dependencies"
    sudo apt-get update

    # Install the mysql packages.
    sudo apt-get install libmysqlcppconn-dev -y
  fi
elif [[ "$OSTYPE" == "darwin"* ]]; then
  echo "Installing dependencies not coded yet."
  # Mac OSX
elif [[ "$OSTYPE" == "cygwin" ]]; then
  echo "Installing dependencies for cygwin not coded yet."
  # POSIX compatibility layer and Linux environment emulation for Windows
elif [[ "$OSTYPE" == "msys" ]]; then
  echo "Installing dependencies for msys not coded yet."
  # Lightweight shell and GNU utilities compiled for Windows (part of MinGW)
elif [[ "$OSTYPE" == "win32" ]]; then
  echo "Installing dependencies for win32 not coded yet."
  # I'm not sure this can happen.
elif [[ "$OSTYPE" == "freebsd"* ]]; then
  echo "Installing dependencies for freebsd not coded yet."
  # ...
else
  echo "Undetected OS - install dependencies manually."
  # Unknown.
fi

echo "...Beginning MIA Build!"

mkdir -p "$rootDirectory"/build
cmake -G "Unix Makefiles" -B"$rootDirectory"/build
cd "$rootDirectory"/build || exit
make -j16 || exit

# Copy needed files for running MIA from build directory.
cp -ruv "$rootDirectory/bin/resources/"*".MIA" "$rootDirectory/build/bin/resources/"

if [[ $updateReleaseFiles ]]; then
  $rootDirectory/updateRelease.sh
fi
echo "...MIA Build done!"