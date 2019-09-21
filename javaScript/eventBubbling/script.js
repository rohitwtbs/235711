
var onLoadFunction = function() {

  /*****
  Using fromCapture=true uses event Capture phase to execute the
  event. fromCapture=false uses event Bubbling phase to execute the
  event.
  *****/
  var fromCapture = true;

  var p = document.querySelector('#parent');

  p.addEventListener('click', function(e) {
    console.log('parent clicked');
    console.log(e);
  }, fromCapture);

  var c = document.querySelector('#child');

  c.addEventListener('click', function() {
    console.log('clild clicked');
  }, fromCapture);

  var o = document.querySelector('#other');

  o.addEventListener('click', function() {
    console.log('other clicked');
  }, fromCapture);

  var m = document.querySelector('#middle');

  m.addEventListener('click', function() {
    console.log('middle clicked');
  }, fromCapture);

  var l = document.querySelector('#little');

  l.addEventListener('click', function() {
    console.log('little clicked');
  }, fromCapture);

  let divs = document.getElementsByClassName("image");
  divs[0].addEventListener("click", function() {
    console.log("Hello " + this + " (" + this.innerHTML + ") from event listener [0]");
    /* Here, "this" refers to 1st div */
});

divs[1].addEventListener("click", function() {
    console.log("Hello " + this + " (" + this.innerHTML + ") from event listener [1]");
    /* Here, "this" refers to 2nd div */
});

divs[2].addEventListener("click", function() {
    console.log("Hello " + this + " (" + this.innerHTML + ") from event listener [2]");
    /* Here, "this" refers to 3rd div */
});
Object.entries(divs).map(( object ) => {

  // Here, object = Array[index, object] (object is the
  // HTML element object). This means that the actual element
  // is stored in object[1], not object. Do whatever you need
  // with it here. In this case we attach a click event:
  
  object[1].addEventListener("click", function() {
  
  // Output innerHTML of the clicked element
  console.log("Hello " + this +
                  " (" + this.innerHTML + ") from map method...");
  });
});
}
