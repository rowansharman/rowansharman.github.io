#!/bin/bash
echo "Serving site to LAN"
myip=$(ifconfig wifi0 | grep "inet " | awk '{print $2}')
port=":4000"
echo "Access from other devices on LAN at:"
echo "http://${myip}:4000"
jekyll serve

#run dos2unix on file if modified in Windows to avoid whitespace issues..
