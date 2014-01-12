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
			BigDecimal sum = BigDecimal.ZERO, x;
			
			do
			{
				x = new BigDecimal(reader.readLine());
				sum = sum.add(x);
			}while(!x.equals(BigDecimal.ZERO));
			
			StringBuilder s = new StringBuilder(sum.toPlainString());
			int pos = s.length() - 1;
			while(s.charAt(pos) == '0')
			{
				s.deleteCharAt(pos);
				--pos;
			}
			if (s.charAt(pos) == '.')
				s.deleteCharAt(pos);
						
			System.out.println(s.toString());
		}
	}
}