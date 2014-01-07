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
		
		int tests = Integer.parseInt(reader.readLine());
		while(tests-- > 0)
		{
			int N = Integer.parseInt(reader.readLine());
			BigInteger P = new BigInteger(reader.readLine());
			System.out.println(P.mod(BigInteger.valueOf(N)));
		}
		
		
		reader.close();
	}
}