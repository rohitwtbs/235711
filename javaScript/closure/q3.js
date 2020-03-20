// function mul (x) {
//     return function (y) { // anonymous function 
//         console.log(x);
//         return function (z) { // anonymous function 
//             console.log(x,y);
//             return x * y * z; 
//         };
//     };
// }

console.log((mul(1)(2)(3)))
console.log((mul('1')('2')('3')))
console.log((mul('1')('2')('3r')))

function mul (x) {
    return function mul1 (y) { // anonymous function 
        console.log(x);
        return function  mul2 (z) { // anonymous function 
            console.log(x,y);
            return x * y * z; 
        };
    };
}

// it doesnot matter whether it is a anonymous function or not
// it will work