import java.io.*;
import java.util.*;
class Fact{
    int n;
    Fact(int num){
        this.n = num;
        System.out.println(Compute(n));
    }
    long Compute(int k){
        if(k>1)
        return k*Compute(k-1);
        else
        return 1;
    }
    public static void main(String args[]){
        long start = System.currentTimeMillis();
        System.out.println("start at:"+start);
        
        Fact f = new Fact(5);
        //Scanner s = new Scanner(System.in);
        //Fact f = new Fact(s.nextInt());
        long end = System.currentTimeMillis();
        System.out.println("end at:"+System.currentTimeMillis());
        System.out.println("total execution time:"+(end-start));
        
         
    }
}