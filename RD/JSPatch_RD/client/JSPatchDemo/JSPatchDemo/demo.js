// demo.js
require('UIView, UIColor, UILabel,Animal')
defineClass('AppDelegate', {
            // replace the -genView method
            genView: function() {
//            var view = self.ORIGgenView();
//            view.setBackgroundColor(UIColor.greenColor())
//            var label = UILabel.alloc().initWithFrame(view.frame());
//            label.setText("JSPatch");
//            label.setTextAlignment(1);
//            view.addSubview(label);
            _OC_log("hello");
            var echo = dog_say("cheese");
            _OC_log(echo);
            var dog = Animal.alloc().init();
            dog.freeze();
            }
});