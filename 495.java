import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;

class Main
{		
	public static void main(String[] args) throws IOException 
	{	
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));	
		String line;
		
		final int N = 5000;
		
		BigInteger fibonacci[] = new BigInteger[N + 1];
		fibonacci[0] = BigInteger.ZERO;
		fibonacci[1] = BigInteger.ONE;	
		
		for(int i = 2; i <= N; ++i)
			fibonacci[i] = fibonacci[i - 2].add(fibonacci[i - 1]);
		
		while((line = reader.readLine()) != null)
			System.out.printf("The Fibonacci number for %s is %s\n", line, fibonacci[Integer.parseInt(line)].toString());
		
		reader.close();
	}
}