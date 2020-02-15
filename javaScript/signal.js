function solve(A,B,C,D) {
    result = [];
    let distance = {};
    i = 0;
    for(key in C){
        distance[i] = calcDistance(A,B,C[key],D[key]);
        i++;
    }
    let sorted = Object.entries(distance).sort((a,b)=> a[1]-b[1]);
    for(i=0;i<sorted.length;i++) { result.push(parseInt(sorted[i][0])+1);}

    console.log(result);

    return result;
    function calcDistance(a,b,x,y) {
        return Math.pow(Math.pow((x-a),2) + Math.pow((y-b),2),0.5);
    } 

}




solve(0,0,[1,2,3],[2,3,1]);