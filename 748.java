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
		
		while( (line = reader.readLine()) != null)
		{
			StringTokenizer st = new StringTokenizer(line);
			BigDecimal R = new BigDecimal(st.nextToken());
			int n = Integer.parseInt(st.nextToken());
			
			String ans = R.pow(n).toPlainString();
			int end = ans.length();
			while(ans.charAt(end - 1) == '0')
				--end;
			
			if (ans.charAt(0) == '0')
				System.out.println(ans.substring(1, end));
			else
				System.out.println(ans.substring(0, end));
		}
		
		reader.close();
	}
}
