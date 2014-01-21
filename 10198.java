import java.io.*;
import java.math.BigInteger;

class Main
{		
	public static void main(String[] args) throws IOException 
	{	
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));	
		String line;
		
		final int MAX_N = 1000;
		
		BigInteger dp[] = new BigInteger[MAX_N + 5];
		dp[1] = BigInteger.valueOf(2);
		dp[2] = BigInteger.valueOf(5);
		dp[3] = BigInteger.valueOf(13);
		
		for(int i = 4; i <= MAX_N; ++i)
			dp[i] = dp[i - 1].shiftLeft(1).add(dp[i - 2].add(dp[i - 3]));
		
		while( (line = reader.readLine()) != null)
			System.out.println(dp[Integer.parseInt(line)].toString());
		
		reader.close();
	}
}










