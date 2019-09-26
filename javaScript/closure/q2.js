// how closures work
// https://stackoverflow.com/questions/111102/how-do-javascript-closures-work?rq=1



const prizes = ['A Unicorn!', 'A Hug!', 'Fresh Laundry!'];
for (var btnNum = 0; btnNum < prizes.length; btnNum++) {

  // For each of our buttons, when the user clicks it...
  console.log("executed");
   () => {

    // Tell her what she's won!
    console.log(prizes);
    console.log(btnNum);
  };
}