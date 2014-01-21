import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;

class Main
{		
	public static void main(String[] args) throws IOException 
	{	
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));	
		String line;
		
		final int MAX_N = 1000;
		
		BigInteger factorial[] = new BigInteger[MAX_N + 5];
		factorial[0] = BigInteger.ONE;
		
		for(int i = 1; i <= MAX_N; ++i)
			factorial[i] = factorial[i - 1].multiply(BigInteger.valueOf(i));
		
		while( (line = reader.readLine()) != null )
		{
			System.out.printf("%s!\n", line);
			System.out.println(factorial[Integer.parseInt(line)]);
		}
							
		reader.close();
	}
}