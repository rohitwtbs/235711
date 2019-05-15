#!/usr/bin/swift
let dummuy = "dsjsjdsdjd"
for ch in dummuy {
print (ch)
}

let greeting = "rohit"
print ("delimiter")
print (greeting[greeting.startIndex])
//print ( greeting[greeting.index(:after greeting.startIndex)])   seee the syntax mistake i did

print (greeting[greeting.index(after: greeting.startIndex)])

let index = greeting.index(greeting.startIndex, offsetBy:3)

greeting[index]

// inserting and removing

