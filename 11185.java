import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;

class Main
{
	public static void main(String[] args) throws IOException 
	{	
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

		while(true)
		{
			BigInteger n = new BigInteger(reader.readLine());
			if (n.compareTo(BigInteger.ZERO) < 0) break;
			System.out.println(n.toString(3));
		}
		
		reader.close();
	}
}
