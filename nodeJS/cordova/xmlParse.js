var fs = require('fs');
var et = require('elementtree');

var contents = fs.readFileSync('AndroidManifest.xml', 'utf-8');
if(contents) {
    //Windows is the BOM. Skip the Byte Order Mark.
    contents = contents.substring(contents.indexOf('<'));
}
var obj =  new et.ElementTree(et.XML(contents));
console.log(obj);