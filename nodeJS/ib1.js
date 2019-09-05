function name (A) {
    let vowel = {
        'a':1,
        'e':1,
        'i':1,
        'o':1,
        'u':1,
    };
    let indexArray=[];
    for(i=0;i<A.length;i++){
        if(vowel.hasOwnProperty(A[i].toLowerCase())  ){
            indexArray.push(i+1);
        }
    }
    for(key in indexArray) 
    {
        if(isPrime(indexArray[key]) === false) {
            return 'NO';
        }
    }
    return 'YES';
}

function isPrime(num) {
    if (num ==0 || num ==1) {
        return false;
    }
    for(i=2;i<Math.sqrt(num);i++) {
        if(num % 2 == 0)
        return false;
    }
    return true;
}

console.log(name('rohit'));