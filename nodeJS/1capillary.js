
function solve(N, arr){
    //Write your code here
    //To print use  console.log();
    for(let i=0;i<arr.length;i++){
        arr[i].push(i);
    }
    let eliminateArray=[...arr];
    while (eliminateArray.length > 1){
        buffer = [...eliminateArray];
        for(let i=0;i<buffer.length-1;i++){
            value = compareTWO(buffer[i],buffer[i+1]);
            if(value === 1) {
                // console.log()
                if(eliminateArray.indexOf(buffer[i+1])>=0){
                    eliminateArray.splice(eliminateArray.indexOf(buffer[i+1]),1);
                }
                
            } else {
                if(eliminateArray.indexOf(buffer[i])>=0){
                eliminateArray.splice(eliminateArray.indexOf(buffer[i]),1);
                }
            }
        }
    }
  

  
    console.log(eliminateArray[0][5]+1)
}

function compareTWO(arr1, arr2){
    let count1 = 0;
    let count2 = 0;
    for(i=0 ;i < 5;i++){
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


arr=[];
arr.push(a);
arr.push(b);
arr.push(c);
arr.push(d);

solve(4,arr);