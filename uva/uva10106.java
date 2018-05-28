import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class uva10106{
    public static void main(String [] args){
        Scanner in = new Scanner(System.in);
        String N,M;
        while(in.hasNext()){
            N=in.next();
            M=in.next();
            BigInteger n1 = new BigInteger(N);
            BigInteger n2 = new BigInteger(M);
            System.out.println(n1.multiply(n2));
            
        }
        in.close();
    }
}