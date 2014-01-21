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
			
			if (tokens[0].equals("0") && tokens[1].equals("0")) 
				break;
			
			tokens[1] = tokens[1].replaceAll(tokens[0], "");
			
			if (tokens[1].length() == 0) 
				System.out.println("0");
			else 
				System.out.println(new BigInteger(tokens[1]).toString());
		}
			
		reader.close();
	}
}