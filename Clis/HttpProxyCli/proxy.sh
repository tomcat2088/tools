#!/bin/zsh
if [[ $1 -eq '-s' ]]; then
  networksetup -setwebproxystate 'Ethernet' off
else
  networksetup -setwebproxystate 'Ethernet' on
  networksetup -setwebproxy 'Ethernet' '127.0.0.1' 8080
fi
