var inputObj = {
    'name': 'jane',
    'last_name': 'doe',
    'profession': 'engineer',
    'characteristics': {
            'intelligent': true,
            'punctual': false,
            'experience': {
                    '2012': 'college passout',
                    '2014': 'mba passout',
                    '2016': 'employed'
            }
    }
};
flatObj = {};
Object.assign(
    flatObj, 
    ...function _flatten(o) { 
      return [].concat(...Object.keys(o)
        .map(k => 
          typeof o[k] === 'object' ?
            _flatten(o[k]) : 
            ({[k]: o[k]})
        )
      );
    }(inputObj)
  )

// console.log(flatObj);


function flatten(obj) {
    const flatObject = {};
    const path = []; // current path

    function dig(obj) {
        if (obj !== Object(obj))
            /*is primitive, end of path*/
            return flatObject[path.join('.')] = obj; /*<- value*/ 

        //no? so this is an object with keys. go deeper on each key down
        for (let key in obj) {
            path.push(key);
            dig(obj[key]);
            path.pop();
        }
    }

    dig(obj);
    return flatObject;
}

console.log(flatten(inputObj));





/*
Write an implementation of a function called `flatten` that flattens a nested object. The method takes an object and returns a new flattened object.

Base structure:

function flatten(obj) {
 // should return a new flattened object.
}

For example:
For the given input object,
var inputObj = {
        'name': 'jane',
        'last_name': 'doe',
        'profession': 'engineer',
        'characteristics': {
                'intelligent': true,
                'punctual': false,
                'experience': {
                        '2012': 'college passout',
                        '2014': 'mba passout',
                        '2016': 'employed'
                }
        }
};

flatten(inputObj);

Output: 
{
        'name': 'jane',
        'last_name': 'doe',
        'profession': 'engineer',
        'characteristics.intelligent': true,
        'characteristics.punctual': false,
        'characteristics.experience.2012': 'college passout',
        'characteristics.experience.2014': 'mba passout',
        'characteristics.experience.2016': 'employed'
}

Note: The method should NOT modify the original object. It should return a new object.
Your Solution

*/