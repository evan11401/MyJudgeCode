import java.util.*;
import java.io.*;
import java.math.BigInteger;
class uva10176{
    public static void main(String[] s){
        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
            boolean f=true;
            String input="" ;
            while(f){
                String str = in.next();
                
                for(int i=0;i<str.length();i++){
                    if(str.charAt(i)=='#'){
                        f=false;
                        break;
                    }
                    input+=str.charAt(i);
                }
            }   
            BigInteger exp = new BigInteger("1"); 
            BigInteger two = new BigInteger("2"); 
            BigInteger ans = BigInteger.ZERO;
            for(int i=input.length()-1;i>=0;i--){
                String a = String.valueOf(input.charAt(i));
                ans = ans.add(new BigInteger(a).multiply(exp));
                exp=exp.multiply(two);
            }
            //System.out.println(ans);
            System.out.println((ans.mod(new BigInteger("131071"))==BigInteger.ZERO?"YES":"NO"));
        }
        in.close();
    }
}