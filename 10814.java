import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;

class Main
{
	public static void main(String[] args) throws IOException 
	{	
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

		int tests = Integer.parseInt(reader.readLine());
		while(tests-- > 0)
		{
			String tokens[] = reader.readLine().split(" ");
			BigInteger a = new BigInteger(tokens[0]);
			BigInteger b = new BigInteger(tokens[2]);
			BigInteger gcd = a.gcd(b);
			System.out.println(a.divide(gcd).toString() + " / " + b.divide(gcd).toString());	
		}
	}
}
