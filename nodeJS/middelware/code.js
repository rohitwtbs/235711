var Middleware = require('./mw.js');  // <- you create this file;

var middleware = new Middleware();

middleware.use(function(next) {
  var self = this;
//   console.log('hook1 use');
  setTimeout(function() {
    // console.log('self.hook1 = true');
    self.hook1 = true;
    next();
  }, 10);
});

middleware.use(function(next) {
  var self = this;
//   console.log('hook 2 use');
  setTimeout(function() {
    // console.log('self.hook1 = true');
    self.hook2 = true;
    next();
  }, 10);
});

var start = new Date();
middleware.go(function() {
  console.log(this.hook1); // true
  console.log(this.hook2); // true
  console.log(new Date() - start); // around 20
});