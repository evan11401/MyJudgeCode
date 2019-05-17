import java.util.*;
import java.math.BigInteger;
public class uva10328{

    static public void main(String[] avg){
        Scanner in = new Scanner(System.in);
        BigInteger [][] dp = new BigInteger[110][110];
        for(int i=0;i<110;i++){
            dp[0][i] = new BigInteger("1");
        }
        BigInteger two = new BigInteger("2");
        BigInteger neone = new BigInteger("-1");
        dp[1][0] = new BigInteger("1");
        for(int i = 1; i <= 100; i ++)
            dp[1][i] = new BigInteger("2");
        for(int i=2;i<=100;i++){
            for(int j=0;j<=100;j++){
                dp[i][j] = dp[i-1][j].multiply(two);
                if(i==j+1)
                    dp[i][j] = dp[i][j].add(neone);
                else if(i>j+1)
                    dp[i][j] = dp[i][j].add(dp[i-j-2][j].negate());
            }
        }
        int c,n;
        while(in.hasNext()){
            c = in.nextInt();
            n = in.nextInt();
            System.out.println(dp[c][c].add(dp[c][n-1].negate()));
        }
    } 
}