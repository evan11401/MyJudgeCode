import java.util.*;
import java.io.*;
import java.math.BigInteger;
class uva495{
    public static void main(String[] a){
        Scanner in = new Scanner(System.in);
        BigInteger[] big = new BigInteger[5005];
        big[0] = new BigInteger("0");
        big[1] = new BigInteger("1");
        for(int i=2;i<=5000;i++){
            big[i] = big[i-1].add(big[i-2]);
        }
        while(in.hasNext()){
            int fin = in.nextInt();
            if(fin>0)
                System.out.println("The Fibonacci number for "+fin+" is "+big[fin]);
            else 
                System.out.println("The Fibonacci number for "+fin+" is 0");
        }
        
    }
}