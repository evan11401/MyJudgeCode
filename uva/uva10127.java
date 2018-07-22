import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class uva10127{
    public static void main(String [] args){
        Scanner in = new Scanner(System.in);
        String N;
        while(in.hasNext()){
            N=in.next();
            BigInteger n1 = new BigInteger(N);
            BigInteger ones = new BigInteger("1");
            BigInteger ten = new BigInteger("10");
            BigInteger one = new BigInteger("1");
            int onenum=1;
            boolean f=true;
            while(f){
                if(ones.mod(n1)==BigInteger.ZERO){
                    f=false;
                    System.out.println(onenum);
                }else{
                    ones = ones.multiply(ten);
                    ones = ones.add(one);
                    onenum++;
                }
            }
            
        }
        in.close();
    }
}