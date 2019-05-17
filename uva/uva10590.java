import java.util.*;
import java.math.BigInteger;
public class uva10590{
    static public void main(String[] avg){
        Scanner in = new Scanner(System.in);
        BigInteger [] dp = new BigInteger[5001];
        BigInteger one = new BigInteger("1");
        BigInteger zero = new BigInteger("0");
        for(int i=0;i<5001;i++){
            dp[i]=zero;
        }
        dp[0]=one;
        for(int i=1;i<5001;i++){
            for(int j=i;j<5001;j++){
                dp[j] = dp[j].add(dp[j-i]);
            }
        }
        while(in.hasNext()){
            int input = in.nextInt();
            System.out.println(dp[input]);
        }
    }
}