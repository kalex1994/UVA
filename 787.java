import java.io.*;
import java.util.StringTokenizer;
import java.math.BigInteger;

class Main {

	public static void main(String[] args) throws IOException 
	{	
		int[] numbers = new int[100];
		
		BigInteger[][] dp = new BigInteger[100][100];	
	
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter output = new BufferedWriter(new PrintWriter(System.out));
		
		String line;
		while( (line = input.readLine()) != null)
		{
			if (line.length() == 0) break;
			StringTokenizer st = new StringTokenizer(line);
			
			int size = 0;
			for(int i = 0; ; ++i, ++size)
			{
				String token = st.nextToken();
				if (token.equals("-999999")) break;
				numbers[i] = Integer.parseInt(token);
			}
			
			BigInteger maxProduct = BigInteger.valueOf(numbers[0]); 
			for(int i = 0; i < size; ++i)
				for(int j = i; j < size; ++j)
				{
					if (i == j) dp[i][j] = BigInteger.valueOf(numbers[i]);
					else dp[i][j] = dp[i][j - 1].multiply(BigInteger.valueOf(numbers[j]));
					
					if (dp[i][j].compareTo(maxProduct) > 0)
						maxProduct = dp[i][j];
				}
			
			output.write(maxProduct.toString() + '\n');							
		}	
		input.close();
		output.close();		
	}
}