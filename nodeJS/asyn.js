let fs = require('fs');

fs.readFile('check.txt','utf8',(err,data)=> {
    if (err) {
        console.log(err);
    }
    console.log(data);
});

console.log('why this happens');
for( let i=0;i<5;i++){
   // console.log(i);
    setTimeout(() => {
        console.log(i);
    }, 100);
}