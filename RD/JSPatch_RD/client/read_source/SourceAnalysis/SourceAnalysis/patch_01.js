require('NSString')

defineClass('AppDelegate', {
            bugFunc: function() {
            _OC_log("bug fixed in app delegate");
            },
            bugFuncWithArg:function()
            {
             _OC_log("bug with arg fixed in app delegate");
            }
            });

defineClass('BugCls',{
            bug : function(){
            _OC_log("bug fixed");
            },
            bug1 : function(msg){
            _OC_log("bug1 fixed => " + _OC_formatJSToOC(msg));
            },
            bug2_arg : function(msg,arg){
            _OC_log("bug2 fixed => " + _OC_formatJSToOC(msg) + " " + _OC_formatJSToOC(arg));
            },
            bug3 : function(msg){
            return {x:20, y:20, width:100, height:100};
            }
            },{
            
            clsBug : function(){
            _OC_log("cls bug fixed");
            }
            
            });
