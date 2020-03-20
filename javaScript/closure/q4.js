// tell the time difference
function m(time, defaultTime) 
{
 defaultTime = defaultTime.split(':');
 array = time.split(':');
 hour = parseInt(array[0]);
 minute = paerseInt(array[1]);
 seconds = parseInt( array[2]);
 defaultTime[0] = parseInt(defaultTime[0]);
 defaultTime[1] = parseInt(defaultTime[1]);
 defaultTime[2] = parseInt(defaultTime[2]);
 if (hour - defaultTime[0] < 1) {
     return hour - defaultTime[0] + ' hours ago';
 }
 else {
     if(minute - defaultTime[1]) {
         return minute - defaultTime[1] + 'minute ago';

     }
     else {
         if(seconds - defaultTime[2] < 1)
          {
              return 'now';
          }
          else return seconds -defaultTime[2] + 'seconds ago';
     }
 }


}