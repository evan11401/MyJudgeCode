import java.util.*;
import java.io.*;
import java.math.BigInteger;
class uva10925{
    public static void main(String[] avgs){
        Scanner in = new Scanner(System.in);
        String m;
        int n,nn=1;
        while(in.hasNext()){
            n = in.nextInt();
            m = in.next();
            if(n==0&&m.equals("0"))break;
            BigInteger sum = new BigInteger("0");
            for(int i=0;i<n;i++){
                String input = in.next();
                sum = sum.add(new BigInteger(input)); 
            }
            System.out.println("Bill #"+nn+" costs "+sum+": each friend should pay "+sum.divide(new BigInteger(m))+"\n");
            nn++;
        }
    }
}