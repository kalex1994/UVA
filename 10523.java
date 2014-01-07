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
			
		while((line = reader.readLine()) != null)
		{
			String t[] = line.split(" ");
			int n = Integer.parseInt(t[0]);
			BigInteger a = new BigInteger(t[1]);
			
			BigInteger sum = BigInteger.ZERO;
			for(int i = 1; i <= n; ++i)
				sum = sum.add(BigInteger.valueOf(i).multiply(a.pow(i)));
			System.out.println(sum.toString());
		}
			
		reader.close();
	}
}
