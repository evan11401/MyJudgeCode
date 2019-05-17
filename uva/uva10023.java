import java.util.*;
import java.math.*;
public class uva10023{
    static BigInteger Sqrt(BigInteger x){
        BigInteger ret = null,y=x;
        BigInteger two = new BigInteger("2");
        do{
            ret = y;
            y = (ret.add(x.divide(ret))).divide(two);
        }while(ret.compareTo(y)>0);
        return ret;
    }
     public static void main(String []args){
        Scanner in = new Scanner(System.in);
        int N;
        BigInteger x,ans;
        N = in.nextInt();
        while(N>0){
            x = in.nextBigInteger();
            ans = Sqrt(x);
            System.out.println(ans);
            N--;
            if(N>0)System.out.println();
            
        }
     }
}