function vercompare
{
	$usage="$0 v1 v2"
	if [[ $# -lt 3 ]]; then
		echo $usage
		exit
	fi
	result=$(( "$1\n$2" | sort | head -n 1))

	[[ result = $1 ]]
}
function dnsclear
{
	systemVersion=$(sw_vers -productVersion)
	#Use the following Terminal command to reset the DNS cache in OS X v10.10.4 or later:
	sudo killall -HUP mDNSResponder
}

