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
			StringTokenizer st = new StringTokenizer(line);
			BigInteger a = new BigInteger(st.nextToken());
			String operator = st.nextToken();
			BigInteger b = new BigInteger(st.nextToken());
			
			if (operator.equals("/"))
				System.out.println(a.divide(b).toString());
			else
				System.out.println(a.mod(b).toString());
		}
		
		reader.close();
	}
}
