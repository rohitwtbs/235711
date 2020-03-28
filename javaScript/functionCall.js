

function check(str) {
    add = 'str()';
    if(typeof(str()) === 'function'){
        add = add + '()';
        check(eval(add));
    }
    if(typeof(str())!== 'function')
    console.log(str());
    }
    
    var innerPeace = function() {
        return function() {
          return function() {
            return function() {
              return function() {
                return function() {
                  return function() {
                    return function() {
                      return function() {
                        return '42';
                      };
                    };
                  };
                };
              };
            };
          };
        };
      };

      var scalar = 'foo';
var fn = function() { return 'bar'; };
var fn2 = function() {
  return fn;
};
var fn3 = function() {
  return fn2;
};


      //check('innerPeace');
      check(innerPeace);
      check(fn3)