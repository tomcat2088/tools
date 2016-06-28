if [[ $$ < 1 ]]; then
	echo "Usage: $0 mfile"
	exit
fi
SDK_PATH=/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator9.3.sdk
clang -x objective-c -isysroot $SDK_PATH -rewrite-objc -fobjc-arc -fblocks -mmacosx-version-min=10.11.4  -fobjc-runtime=macosx-10.11.4 -O0 $1
