import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

class Main 
{
	private static final int MAX_TEXT_LENGTH = 10005;
	private static final int MAX_PATTERN_LENGTH = 105;
	private static BigInteger dp[][] = new BigInteger[MAX_PATTERN_LENGTH][MAX_TEXT_LENGTH];
	
	public static void main(String[] args) throws IOException 
	{
		for(int i = 0; i < MAX_PATTERN_LENGTH; ++i)
			dp[i][0] = BigInteger.ZERO;
		for(int j = 0; j < MAX_TEXT_LENGTH; ++j)
			dp[0][j] = BigInteger.ONE;
			
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		int tests = Integer.parseInt(in.readLine());
		while(tests-- > 0)
		{
			String text = in.readLine();
			String pattern = in.readLine();
			
			for(int i = 1; i <= pattern.length(); ++i)
				for(int j = 1; j <= text.length(); ++j)
				{
					if (pattern.charAt(i - 1) == text.charAt(j - 1))
						dp[i][j] = dp[i - 1][j - 1].add(dp[i][j - 1]);
					else
						dp[i][j] = dp[i][j - 1];
				}
			System.out.println(dp[pattern.length()][text.length()]);
		}
		in.close();
	}
}