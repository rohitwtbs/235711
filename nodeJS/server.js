const express = require('express');
const app = express();
const port = 3019;
const obj= {
    name:'rohit',
    profession:'programmer'
}
let getCookie = function (req) {
    let result = {};
    req.header('cookie') &&
        req
        .header('cookie')
        .toString()
        .split(';')
        .forEach(function (x) {
            let arr = x.trim().split('=');
            if (arr[1]) {
                result[arr[0]] = arr[1];
            }
        });
    return result;
};
app.use(function (req, res, next) {
    res.setHeader(
        'Access-Control-Allow-Headers',
        'Content-Type, Content-Length, Authorization, Accept, X-Requested-With, X-Access-Token, X-Signature, X-XSRF-TOKEN'
    );
    res.setHeader('Access-Control-Allow-Methods', 'POST, GET, OPTIONS');
    res.setHeader('Access-Control-Expose-Headers', 'X-Access-Token, loginState');
    res.setHeader('Access-Control-Max-Age', '86400');
    if (req.headers.origin) {
        if (req.headers.origin.startsWith('http://localhost')) {
            res.setHeader('Access-Control-Allow-Origin', '*');
        }
    }
next();
    
});
app.get('/', (req, res) => res.send(obj));

app.get('/name',function sendName(req ,res){
    console.log('call came in name module');
    res.send('rohit');
});

app.listen(port, () => console.log(`Example app listening on port ${port}!`));