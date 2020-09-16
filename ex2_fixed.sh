# fix
lock=/home/atrei/week5/file.lock
while [ -f "$lock" ] # waiting for access to file
do
:
done # loop is finished when file is unlocked

touch "$lock" # lock file

x=$(tail -n 1 "/home/atrei/week5/file.txt")
echo $((x+1)) >> "/home/atrei/week5/file.txt" # execute shell script

rm "$lock" # unlock the file
