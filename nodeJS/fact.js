function factorial(num){
    if (num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1)
    }
}
startTime = new Date().getMilliseconds();
console.log(factorial(5));
endTime = new Date().getMilliseconds();
console.log(endTime-startTime);