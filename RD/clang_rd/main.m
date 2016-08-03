#import <Foundation/Foundation.h>

typedef int (^blk_t)(int);
blk_t func(int rate)
{
    return ^(int count){return rate * count;};
}

int main(int argc, char * argv[]) {
	__weak NSObject* obj = [NSObject new];
	[obj copy];
	return 0;
}