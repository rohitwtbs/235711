let arr = [];
let n= 0;
while(n<10){
    arr.push(n);
    n++;
}
printArray(arr.length);
function printArray(n){
    if(n>0){
        printArray(n-1);
        console.log(arr[n]);
    }
}