#!/bin/zsh
if [[ $1 -eq '-s' ]]; then
  networksetup -setwebproxystate Wi-Fi off
else
  networksetup -setwebproxystate Wi-Fi on
  networksetup -setwebproxy Wi-Fi 127.0.0.1 9999 off
fi
