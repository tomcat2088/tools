function vercompare
{
	usage="$0 v1 v2"
	if [[ $# -lt 2 ]]; then
		echo $usage
		exit
	fi
	result=$( echo "$1\n$2" | sort | head -n 1 )
	echo $result
}

function dnsclear
{
	systemVersion=$(sw_vers -productVersion)
	#Use the following Terminal command to reset the DNS cache in OS X v10.10.4 or later:
	if [[ $(vercompare 10.10.4 $systemVersion) = '10.10.4' ]]; then
		sudo killall -HUP mDNSResponder
		echo 'clear dns complete！'
	#Use the following Terminal command to reset the DNS cache in OS X v10.10 through v10.10.3:
	elif [[ $(vercompare 10.10.0 $systemVersion) = '10.10.0' ]]; then
		sudo discoveryutil mdnsflushcache
		echo 'clear dns complete！'
	elif [[ $(vercompare 10.9.5 $systemVersion) = $systemVersion ]]; then
		sudo killall -HUP mDNSResponder
		echo 'clear dns complete！'
	elif [[ $(vercompare 10.6.8 $systemVersion) = $systemVersion ]]; then
		sudo dscacheutil -flushcache
		echo 'clear dns complete！'
	fi
}

