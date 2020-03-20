class Person {
    constructor(data) {
        this.age = data.age;
        this.name = data.name;
        this.occupation = data.occupation;
    }

    logDetails() {
        console.log(this.age,this.name,this.occupation);

    }
    increaseAge(incrementParam) {
        this.age = this.age + incrementParam;
        this.logDetails();
    }

}

class Male extends Person{
    constructor(data) {
        super(data);
        this.isMale = true;
        Object.freeze(this);
    }

    logDetails() {
        console.log(this.age,this.name,this.occupation,this.isMale);

    }
}
let data = {};
data.age = 21;
data.name = 'rohit kumar';
data.occupation = 'swoftware developer';
let rohit = new Male(data);
console.log(rohit);
console.log(rohit.logDetails());
// console.log(rohit.increaseAge(2));
console.log(rohit.isMale = false);
console.log(rohit.logDetails()); 
// how to use a parent class method with the same name?
// what if a class is without constructore? 
// then i think we would not need super in the parent class
