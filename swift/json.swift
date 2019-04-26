#!/usr/bin/swift
import Foundation
var myLocation = [String: Double]()
        myLocation["latitude"] = 1.6;
        myLocation["longitude"] = 1.6;
        myLocation["accuracyInMetres"] = 1.6;
        myLocation["level"] = 1.6;
        
        
print(type(of: myLocation))

    do {
                let jsonData =
                    try JSONSerialization.data(withJSONObject: myLocation, options: .prettyPrinted)
                    let nature = type(of: jsonData)
                    let json = try JSONSerialization.jsonObject(with:jsonData)

                    if let dictionary = json as? [String: Any] {
                       if  number = dictionary["latitude"] as? Double {
                        print(number)
                    }
                    }
                    
            } catch {
                print(error.localizedDescription)
            }
////print(jsonData)



