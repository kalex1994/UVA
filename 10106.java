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
		
		while( (line = reader.readLine()) != null )
		{
			BigInteger b = new BigInteger(line);
			System.out.println(b.multiply(new BigInteger(reader.readLine())).toString());
		}
			
		reader.close();
	}
}