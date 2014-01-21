import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;

class Main
{		
	public static void main(String[] args) throws IOException 
	{	
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));	
		String line;
		
		while( (line = reader.readLine()) != null )
		{
			BigInteger n = new BigInteger(line);
			if (n.equals(BigInteger.ZERO))
				System.out.println("Not an Automorphic number.");
			else if ( n.multiply(n).toString().endsWith(line))
				System.out.printf("Automorphic number of %d-digit.\n", line.length());
			else 
				System.out.println("Not an Automorphic number.");
		}		
		
		reader.close();
	}
}










