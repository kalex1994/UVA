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
		
		BigInteger fibo[] = new BigInteger[81];
		fibo[1] = BigInteger.ONE;
		fibo[2] = BigInteger.valueOf(2);
		for(int i = 3; i <= 80; ++i)
			fibo[i] = fibo[i - 2].add(fibo[i - 1]);
		
		int n;
		while( (n = Integer.parseInt(reader.readLine())) != 0 )
			System.out.println(fibo[n].toString());
			
		reader.close();
	}
}
