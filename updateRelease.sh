#!/bin/sh

usage()
{
  echo "updateRelease: updateRelease.sh [options...]"
  echo "  This will update release files and executables based on a build."
  echo ""
  echo "  Options:"
  echo "    -W    Specify Windows."
  echo "    -L    Specify Linux."
}

while getopts "hWL" opt; do
  case $opt in
    h) usage
      ;;
    W) usingWindows=1
      ;;    
    L) usingLinux=1
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



echo "Removing old release download."
rm -vf MIA\ release.tar.gz
echo "...done!"
echo "Updating executable(s)."
if [[ $usingWindows ]]; then
  # Don't remove the built Linux executables.
  rm -vf release/MIA*.exe
elif [[ $usingLinux ]]; then
  # Don't remove the built Windows executables.
  rm -vf release/MIA
  rm -vf release/MIATerminal
else
  rm -vf release/MIA*
fi
rm -vf release/MIAManual.pdf
cp -uv build/bin/MIA.exe release/MIA.exe
cp -uv build/bin/MIA release/MIA
cp -uv build/bin/terminal/MIATerminal.exe release/MIATerminal.exe
cp -uv build/bin/terminal/MIATerminal release/MIATerminal
echo "...done!"
echo "Updating manual."
rm -vf release/MIAManual.pdf
cp documentation/MIAManual.pdf release/MIAManual.pdf
echo "...done!"
echo "Updating dependencies."
rm -vrf release/resources
cp -vr bin/resources release/resources
cp -vr dlls/* release/
echo "...done!"
echo "Creating compressed release file."
tar -czvf MIA-release.tar.gz release/
echo "...done!"