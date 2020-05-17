// giebn two binary numbers add them
// here i am taking equla digit number
// do padding or masking  to make them equal incase they are unequal

let num1 = '1111';
let num2 = '0011';
let finalNum = [];
let sum = 0;
let carryIn = 0;
let carryOut = 0;

num1 = num1.split('').reverse().map( x => parseInt(x));
num2 = num2.split('').reverse().map( x => parseInt(x));

for(index in num1) {
    sum = num1[index] ^ num2[index] ^ carryIn;
    carryOut = (num1[index] & num2[index]) | (carryIn & (num1[index] ^ num2[index]));
    carryIn = carryOut;
    finalNum.push(sum);
}

finalNum.push(carryOut);

console.log(finalNum.reverse().join(''));