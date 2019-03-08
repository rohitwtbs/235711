import java.util.Scanner;
import java.lang.*;

/**
 * relax
 */
public class relax {

    public static void main(String[] args) {
        int number = 6;
        boolean flag= false;
        for(int i=2;i<Math.sqrt(number);i++){
            if(number%i == 0){
                flag= true;
                break;
            }
        }
        if(flag)
        System.out.println("not prime");
        else
        System.out.println("is prime");
        relax now = new relax();
        now.student("rohit");
    }

    public void student(String name) {
        System.out.println(name);
    }
}