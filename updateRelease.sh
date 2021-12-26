#!/bin/sh
echo "Removing old release download."
rm -vf MIA\ release.tar.gz
echo "...done!"
echo "Updating executable(s)."
rm -vf release/MIA*
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