import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;

class Main
{
	public static void main(String[] args) throws IOException 
	{	
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

		while(true)
		{
			String tokens[] = reader.readLine().split(" ");
			if (tokens[0].equals("0") && tokens[1].equals("0")) break;	
			BigInteger p = new BigInteger(tokens[0]);
			BigInteger a = new BigInteger(tokens[1]);		
			if (a.modPow(p, p).equals(a) && !p.isProbablePrime(10)) System.out.println("yes");
			else System.out.println("no");		
		}		
		
		reader.close();
	}
}










