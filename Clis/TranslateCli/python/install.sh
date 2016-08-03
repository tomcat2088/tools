if [[ -f '/usr/local/bin/trans' ]]; then
	echo 'already installed';
else
	sudo cp main.py /usr/local/bin/trans
	chmod a+x /usr/local/bin/trans
	echo 'Install complete!'
	trans "Hello"
fi
