require('NSString,JPHttp')
// demo.js
defineClass('XXXViewController', {
            // replace the -genView method
            viewDidLoad: function() {
                self.ORIGviewDidLoad();
                /**
                 [[RACObserve([EFSNFXGTradeManager sharedManager], status) distinctUntilChanged] subscribeNext:^(id x) {
                 @strongify(self);
                 EFSNFXGTradeSocketConnectionStatus status = [x integerValue];
                 switch (status) {
                 case EFSNFXGTradeSocketConnectionStatusSignTradeProtocol :{
                 [self backAction];
                 }
                 break;
                 default:
                 break;
                 }
                 }];
                 **/
            }
            });

defineClass('BugCls',{
            bug_msg2 : function(msg,msg2){
            _OC_log("bug fixed bug cls" + _OC_formatJSToOC(msg));
            }
            });