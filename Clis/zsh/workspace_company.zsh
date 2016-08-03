SELF=$0
alias edaliaswc="subl $SELF"
alias dxm="cd /Users/ocean/Documents/Company/Projects/dxmobile/"
alias pfm="cd /Users/ocean/Documents/Codes/ForPractice/PlaneFightMaker/Classes"
alias epm="cd /Users/ocean/Documents/Company/Projects/epmyg"
alias apnt="cd /Users/ocean/Documents/Company/Projects/APN"

function tbwc
{
	if [ $1 ]; then
		subl "/Users/ocean/Documents/Company/Temp/$1"
	else
		cd "/Users/ocean/Documents/Company/Temp/"
	fi
}

function xcodecft
{
	if [[ $# = 2 ]]; then
		/Users/ocean/Documents/Company/Tools/xcode_template_creator.sh $1 $2
	elif [[ $# = 1 ]]; then
		/Users/ocean/Documents/Company/Tools/xcode_template_creator.sh $1
	fi
}

function edxcodecft
{
	subl '/Users/ocean/Documents/Company/Tools/xcode_template_creator.sh'
}