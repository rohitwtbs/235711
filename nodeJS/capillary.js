
function solve(N, arr){
    //Write your code here
    //To print use  console.log();
    let eliminateArray=[];
    for(let i=0;i<N;i++) {
        eliminateArray.push(i);
    }
    while (eliminateArray.length > 1){
        console.log(eliminateArray.length);
        let num = eliminateArray.length;
        let i=0;
        buffer = [...eliminateArray];
        console.log('num ' + num);
        while(num > eliminateArray.length -2 ) {
          
            value = compareTWO(arr[buffer[i]],arr[buffer[i+1]])
            if(value === 1) {
                eliminateArray.splice(eliminateArray.indexOf(buffer[i+1]),1)
            } else {
                eliminateArray.splice(eliminateArray.indexOf(buffer[i]),1)
            }
            i=i+1;
            num--;
        }
        
    }
  
    console.log(eliminateArray[0]+1);
}

function compareTWO(arr1, arr2){
    let count1 = 0;
    let count2 = 0;
    for(i=0 ;i <arr1.length;i++){
        if(arr1[i]>arr2[i]){
            count1 ++;
            
        }
        else {
            count2++;
        }
    }
    if (count1 > count2)
    return 1;
    else
    return 2;
    
}

a = [1,2,3,4,5]
b = [2 ,4, 5, 6, 7]
c= [1 ,2 ,3, 4, 5]
d= [1 ,4, 2 ,2 ,3]
e= [9,9,9,9,9]
f= [8,8,8,8,8]

arr=[];
arr.push(a);
arr.push(b);
arr.push(c);
arr.push(d);
arr.push(e);
arr.push(f);

solve(6,arr);