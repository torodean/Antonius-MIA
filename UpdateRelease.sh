#!/bin/sh
echo "Removing old release download."
rm -vf MIA\ Release.tar.gz
echo "...done!"
echo "Updating executable."
rm -vf Release/MIA.exe
cp bin/MIA.exe Release/MIA.exe
echo "...done!"
echo "Updating manual."
rm -vf Release/MIAManual.pdf
cp Documentation/MIAManual.pdf Release/MIAManual.pdf
echo "...done!"
echo "Updating dependencies."
rm -vrf Release/Resources
cp -vr bin/Resources Release/Resources
echo "...done!"
echo "Creating compressed release file."
tar czvf MIA\ Release.tar.gz Release
echo "done..."