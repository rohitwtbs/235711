import Foundation

let fullName : String = "First Last"
let fullNameArr : [String] = fullName.components(separatedBy: "la")

// And then to access the individual words:
print(fullNameArr.length)
var firstName : String = fullNameArr[0]
var lastName : String = fullNameArr[1]
print(firstName)
print(lastName)