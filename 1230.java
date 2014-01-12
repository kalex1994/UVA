import java.io.*;
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
			System.out.println(new BigInteger(tokens[0]).modPow(new BigInteger(tokens[1]), new BigInteger(tokens[2])));
		}
		
		reader.close();
	}
}
