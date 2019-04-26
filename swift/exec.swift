   @objc(execute: command: action: pluginName:)
   func execute(command: CDVInvokedUrlCommand,pluginName: String, action: String,  args: Data) -> Void{
       var apiKey1: String = "dummy"
       var locationId1: Double = 7.6
       if "initialize" == action {

           let json = try? JSONSerialization.jsonObject(with:args)
           if let array = json as? [Any] {
               if let firstObject = array.first {
                   // access individual object in array
                   if let dictionary = firstObject as? [String: Any] {
                       if  let apiKey = dictionary["apiKey"] as? String {
                           apiKey1 = apiKey
                           print(apiKey1)
                       }
                       if  let locationId = dictionary["locationId"] as? Double {
                           locationId1 = locationId
                           print(locationId1)
                       }
                   }
               }


          initializeInfsoft(apiKey1, locationId1);
           //callbackContext.success();
           //return true;
       }
       }

       if "getLocation" == action {
           getCurrentLocation(command);
           //return true;
       }

       if "onReceiveLocationData" == action {
           onReceiveLocationData(command);
          // return true;
       }

       //return false;  // Returning false
   }