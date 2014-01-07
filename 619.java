import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.util.Vector;

class Main
{
	private static String encode(String word)
	{
		String s = new StringBuffer(word).reverse().toString();
		BigInteger value = BigInteger.ONE, power = BigInteger.ONE;
		
		for(int i = 0; i < s.length(); ++i)
		{
			int diff = (int)s.charAt(i) - (int)'a' + 1;
			value = value.add(power.multiply(BigInteger.valueOf(diff)));
			power = power.multiply(BigInteger.valueOf(26));
		}
		
		return value.subtract(BigInteger.ONE).toString();
	}
	
	static String insertCommas(String s)
	{
		StringBuffer sb = new StringBuffer(s);
		sb = sb.reverse();
		for(int i = 3; i < sb.length(); i += 4)
			sb.insert(i, ',');
		return sb.reverse().toString();
	}
	
	private static String decode(String value)
	{
		StringBuffer sb = new StringBuffer();
		BigInteger x = new BigInteger(value);
		
		do
		{
			sb.append((char)(x.mod(BigInteger.valueOf(26)).intValue() - 1 + (int)'a'));
			x = x.divide(BigInteger.valueOf(26));
		}while(!x.equals(BigInteger.ZERO));	
				
		return sb.reverse().toString();
	}
	
	public static void main(String[] args) throws IOException 
	{	
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String line;
		
		while( (line = reader.readLine()) != null && line.charAt(0) != '*' )
		{
			if (line.charAt(0) >= '0' && line.charAt(0) <= '9')
				System.out.printf("%-22s%s\n", decode(line), insertCommas(line));
			else
				System.out.printf("%-22s%s\n", line, insertCommas(encode(line)));
		}
		
		reader.close();
	}
}