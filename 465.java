import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.util.Vector;

class Main
{
	public static void main(String[] args) throws IOException 
	{	
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		final BigInteger intMax = BigInteger.valueOf(Integer.MAX_VALUE);
		String line;
			
		while( (line = reader.readLine()) != null )
		{
			System.out.println(line);
			
			StringTokenizer st = new StringTokenizer(line);
			BigInteger a = new BigInteger(st.nextToken());
			String op = st.nextToken();
			BigInteger b = new BigInteger(st.nextToken());
			
			if (intMax.compareTo(a) < 0)
				System.out.println("first number too big");
			if (intMax.compareTo(b) < 0)
				System.out.println("second number too big");
			
			BigInteger res;
			if (op.equals("*")) 
				res = a.multiply(b);
			else 
				res = a.add(b);
			
			if (intMax.compareTo(res) < 0) 
				System.out.println("result too big");		
		}	
		reader.close();
	}
}