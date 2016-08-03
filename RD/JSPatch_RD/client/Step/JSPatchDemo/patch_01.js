require('NSString,JPHttp')
// demo.js
defineClass('AppDelegate', {
            // replace the -genView method
            bugFunc: function() {
            _OC_log("bug fixed app delegate");
            }
            });

defineClass('BugCls',{
            bug_msg2 : function(msg,msg2){
            _OC_log("bug fixed bug cls" + _OC_formatJSToOC(msg));
            }
            });