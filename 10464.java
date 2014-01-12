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
			StringBuilder sb = new StringBuilder(new BigDecimal(tokens[0]).add(new BigDecimal(tokens[1])).toPlainString());
			int pos = sb.length() - 1;
			
			while(sb.charAt(pos - 1) != '.' && sb.charAt(pos) == '0')
				--pos;
			sb.setLength(pos+1);
			
			System.out.println(sb.toString());
		}
		
		reader.close();
	}
}
