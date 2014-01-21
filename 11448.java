import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;

class Main
{		
	public static void main(String[] args) throws IOException 
	{	
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int tests = Integer.parseInt(reader.readLine());
		while(tests-- > 0)
		{
			String tokens[] = reader.readLine().split(" ");
			System.out.println(new BigInteger(tokens[0]).subtract(new BigInteger(tokens[1])).toString());
		}	
		reader.close();
	}
}










