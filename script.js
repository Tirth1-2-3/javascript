const user1 = "Alice";
const user2 = "Bob";


function greetUser(user){
    console.log("Hello, " + user + "!");
}

greetUser(user1);
greetUser(user2);

const greetUserArrow = (user) => {
    console.log(`Hello, ${user}! from Arrow Function`)
}

greetUserArrow(user1);
greetUserArrow(user2);


class Account {
    constructor(name, age) {
        this.name = name;
        this.age = age;
    }
}

const account1 = new Account("Charlie", 30);
const account2 = new Account("Kirk", 25);

console.log(account1);
console.log(account2);

const user = {
    name: "Lakshya",
    friendname: "Kunal",
    greet() {
        console.log(`Hello, ${this.name} and ${this.friendname}!`);
    }

}
user.greet();
