import java.util.*;
import java.io.*;
import java.math.BigInteger;
class uva10220{
    public static void main(String [] args){
        Scanner in = new Scanner(System.in);
        BigInteger[] big =new BigInteger[1005];
        BigInteger a = new BigInteger("1");
        for(int i=1;i<=1000;i++){
            a=a.multiply(new BigInteger(Integer.toString(i)));
            big[i] = a;
        }
        while(in.hasNext()){
            int ans=0;
            int numi = in.nextInt();
            if(numi==0){
                System.out.println(0);
            }else{
                BigInteger num = big[numi];
                BigInteger zre = new BigInteger("0");
                BigInteger ten = new BigInteger("10");
                while(num.compareTo(zre)==1){
                    ans+=num.mod(ten).intValue();
                    num = num.divide(ten);
                }
                System.out.println(ans);
            }
        }
        in.close();
    }
}