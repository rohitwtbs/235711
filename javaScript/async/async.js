// an array of async functions and execute them in that order

async function resolveAfter2Seconds(str) {
    return new Promise(resolve => {
      setTimeout(() => {
        resolve('resolved' + str);
      }, 2000);
    });
  }
  
  async function asyncCall() {
    console.log('calling  asyncCall');
    const result = await resolveAfter2Seconds();
    console.log(result);
    // expected output: 'resolved'
  }

  async function asyncCall1() {
    console.log('calling  asyncCall1');
    const result = await resolveAfter2Seconds('calling  asyncCall1');
    console.log(result);
    // expected output: 'resolved'
  }

  async function asyncCall2() {
    console.log('calling asyncCall2');
    const result = await resolveAfter2Seconds('calling  asyncCall2');
    console.log(result);
    // expected output: 'resolved'
  }
  
  asyncCall().then(
      asyncCall1().then(
          asyncCall2().then(console.log('in the end nothing matters'))
      )
  )

  
  