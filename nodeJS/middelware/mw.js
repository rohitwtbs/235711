var Middleware = function() {};

Middleware.prototype.use = function(fn) {
  var self = this;

  this.go = (function(stack) {
    return function(next) {
        // console.log('eval 1')
      stack.call(self, function() {
        // console.log('eval 2');
        fn.call(self, next.bind(self));
      });
    }.bind(this);
  })(this.go);
};

Middleware.prototype.go = function(next) {
  next();
};

module.exports = Middleware;