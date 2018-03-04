mkdir $1
mkdir Dir1 Dir2
touch Dir1/File1
touch Dir2/File2
mkdir Dir1/Dir3
mkdir Dir1/Dir3/Dir4
touch Dir1/Dir3/Dir4/File4 Dir1/Dir3/Dir4/File3
chmod 666 Dir1/Dir3/Dir4/File4
chmod 200 Dir1/Dir3/Dir4/File3
chmod 400 Dir1/File1
chmod 640 Dir2/File2
chmod 750 Dir1/Dir3/Dir4
chmod 000 Dir1/Dir3
chmod 770 Dir1
chmod 775 Dir2
