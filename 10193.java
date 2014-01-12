import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;

class Main
{
	public static void main(String[] args) throws IOException 
	{	
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

		int tests = Integer.parseInt(reader.readLine());
		for(int test = 1; test <= tests; ++test)
		{
			System.out.printf("Pair #%d: %s\n", test, new BigInteger(reader.readLine(), 2).gcd(new BigInteger(reader.readLine(), 2)).
					compareTo(BigInteger.ONE) > 0 ? "All you need is love!" : "Love is not all you need!");
		}
		
		reader.close();
	}
}
