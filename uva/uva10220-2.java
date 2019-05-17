import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class HelloWorld{

     public static void main(String []args){
       Scanner in = new Scanner(System.in);
        BigInteger[] ans = new BigInteger[1005];
        BigInteger a = new BigInteger("1");
        for(int i=1;i<=1000;i++){
            a=a.multiply(new BigInteger(Integer.toString(i)));
            ans[i] = a;
        }
        int input;
        while(in.hasNext()){
            input = in.nextInt();
            int sum = 0;
            BigInteger zre = new BigInteger("0");
            BigInteger ten = new BigInteger("10");
            if(input==0){
                System.out.println("0");
            }else{
                BigInteger num = ans[input];
                while(num.compareTo(zre)==1){
                    sum+=num.mod(ten).intValue();
                    num = num.divide(ten);
                }
                System.out.println(sum);
            }
        }
        in.close();
     }
}