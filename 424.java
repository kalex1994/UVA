import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

class Main
{
	public static void main(String[] args) throws IOException 
	{	
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String line;
		
		BigInteger sum = BigInteger.ZERO;
		while( (line = reader.readLine())!=null )
		{
			BigInteger x = new BigInteger(line);
			sum = sum.add(x);
		}
		
		System.out.println(sum.toString());
	}
}