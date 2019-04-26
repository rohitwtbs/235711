#!/usr/bin/swift
import Foundation

class Factorial {
    
    var num: Int
    init(of num: Int) {
        self.num = num
        print(factorial(of:num))
    }
    func factorial(of num: Int) -> Int {
    if num == 1 {
        return 1
    } else {
        return num * factorial(of:num - 1)
    }
}
}


let startTime = CFAbsoluteTimeGetCurrent()
let result = Factorial(of:5)
let resultMirror = Mirror(reflecting: result)
for (name, value) in resultMirror.children {
    guard let name = name else { continue }
    print("\(name): \(type(of: value)) = '\(value)'")
}
let timeElapsed = CFAbsoluteTimeGetCurrent() - startTime
print(timeElapsed*1000)