import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.util.Vector;

class Main
{
	public static void main(String[] args) throws IOException 
	{	
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));	
		String line;
		
		final BigInteger TWO = BigInteger.valueOf(2);
		while((line = reader.readLine()) != null)
		{
			BigInteger n = new BigInteger(line);
			if (n.equals(BigInteger.ZERO)) System.out.println("1");
			else System.out.println(TWO.add(n.multiply(n.subtract(BigInteger.ONE))).toString());
		}
		
		reader.close();
	}
}
