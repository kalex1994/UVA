import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.util.Vector;

class Main
{
	public static void main(String[] args) throws IOException 
	{	
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			
		int N = Integer.parseInt(reader.readLine());
		while(N-- > 0)
		{
			StringTokenizer st = new StringTokenizer(reader.readLine());
			BigInteger a = new BigInteger( new StringBuffer(st.nextToken()).reverse().toString() );  
			BigInteger b = new BigInteger( new StringBuffer(st.nextToken()).reverse().toString() );
			System.out.println( new BigInteger(new StringBuffer( a.add(b).toString() ).reverse().toString()).toString() );
		}
		
		reader.close();
	}
}