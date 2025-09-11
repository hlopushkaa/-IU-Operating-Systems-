#!/bin/bash 

mkdir -p ~/week01/root 

date 
sleep 3

touch ~/week01/root/root.txt
ls -ltr / > ~/week01/root/root.txt

date
sleep 3

mkdir -p ~/week01/home 

date
sleep 3

touch ~/week01/home/home.txt
ls -ltr ~/ > ~/week01/home/home.txt

cat ~/week01/home/home.txt
cat ~/week01/root/root.txt

ls ~/week01/home
ls ~/week01/root


