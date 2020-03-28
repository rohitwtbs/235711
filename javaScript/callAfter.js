var foo = function(arg1, arg2) {console.log(arg1, arg2)};

Function.prototype.callAfter = function(time, arg1, arg2) {
    console.log(this);
 console.log('bar');
 setTimeout(() => {
    this.call(arg1,arg2);
 },time)
 
};

foo.callAfter(500,'r1','r2')






























/*
Question 4
Write an implementation of a function `callAfter` that enables ANY function to be called after some specified duration. The output of the function should remain the same. The function should have following syntax:

Example 1: Let's say you have a function called `sum` like so:

function sum(a, b) {
 console.log('Sum is: ', a + b);
}

Now you should be able to execute: 
sum.callAfter(5000, 8, 9);

This should invoke the function `sum` after 5 seconds with parameters 8 and 9. 
Output: 'Sum is: 17'.

Example 2: For a function `difference` with the following implementation:

function difference(a, b) {
  console.log('Difference is: ', a-b);
}

You should be able to execute: 
difference.callAfter(4000, 8, 6);

This should invoke the function `difference` after 4 seconds with parameters 8 and 6. 
Output: 'Difference is: 2'.
Your Solution
*/