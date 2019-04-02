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
let timeElapsed = CFAbsoluteTimeGetCurrent() - startTime
print(timeElapsed*1000)