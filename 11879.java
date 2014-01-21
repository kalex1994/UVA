import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;

class Main
{		
	public static void main(String[] args) throws IOException 
	{	
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));	
		String line;
		
		final BigInteger SEVENTEEN = BigInteger.valueOf(17);
		
		while( (line = reader.readLine()) != null && line.charAt(0) != '0' )
		{
			if ( new BigInteger(line).mod(SEVENTEEN).equals(BigInteger.ZERO)) System.out.println("1");
			else System.out.println("0");
		}
					
		reader.close();
	}
}










