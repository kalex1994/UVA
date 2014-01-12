import java.io.*;
import java.math.BigInteger;

class Main
{
	public static void main(String[] args) throws IOException 
	{	
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
		int tests = Integer.parseInt(reader.readLine());

		while(tests-- > 0)
		{
			reader.readLine();
			
			BigInteger y = new BigInteger(reader.readLine());	
			BigInteger guess = BigInteger.ONE, prevGuess = BigInteger.ONE;	
			
			//Newthons method
			while(true)
			{
				guess = guess.add(y.divide(guess)).shiftRight(1);
				if (guess.equals(prevGuess)) break;
				prevGuess = guess;
			}
		
			writer.write(guess.toString());
			if (tests > 0) writer.write("\n\n");
			else writer.write("\n");
		}
		
		reader.close();
		writer.close();
	}
}
