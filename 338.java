import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

class Main {
	
	private static String createFilledString(char ch, int count)
	{
		return new String(new char[count]).replace('\0', ch);
	}
	
	private static String createPaddedString(int padding, String s)
	{
		return String.format("%" + padding + "s", s);
	}
	
	private static int getWidth(BigInteger a, BigInteger b)
	{
		int aWidth = a.toString().length();
		int bWidth = b.toString().length();
		int abWidth = a.multiply(b).toString().length();
		return Math.max(abWidth, Math.max(aWidth, bWidth));
	}
	
	private static List<BigInteger> getNumbersToBeAdded(BigInteger a, BigInteger b)
	{
		List<BigInteger> numbers = new ArrayList<BigInteger>();		
		BigInteger temp = new BigInteger(b.toString());
		while(!temp.equals(BigInteger.ZERO))
		{
			numbers.add(temp.mod(BigInteger.TEN).multiply(a));
			temp = temp.divide(BigInteger.TEN);
		}
		return numbers;
	}
	
	private static int countOfNonZeroElements(List<BigInteger> list)
	{
		int count = 0;
		for(BigInteger i : list)
			if (!i.equals(BigInteger.ZERO))
				++count;
		return count;
	}
	
	private static void printMultiplication(BigInteger a, BigInteger b, PrintWriter pw)
	{
		final int width = getWidth(a, b);
		
		pw.println(createPaddedString(width, a.toString()));
		pw.println(createPaddedString(width, b.toString()));
		pw.println(createPaddedString(width, createFilledString('-', Math.max(a.toString().length(), b.toString().length()))));
		
		List<BigInteger> numbers = getNumbersToBeAdded(a, b);
	
		if (countOfNonZeroElements(numbers) < 2)
			pw.println(createPaddedString(width, a.multiply(b).toString()));
		else
		{
			for(int i = 0, padding = width; i < numbers.size(); ++i, --padding)
				if (!numbers.get(i).equals(BigInteger.ZERO))
					pw.println(createPaddedString(padding, numbers.get(i).toString()));
			pw.println(createFilledString('-', width));
			pw.println(createPaddedString(width, a.multiply(b).toString()));
		}
	}
		
	public static void main(String[] args) throws IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		BigInteger a, b;
		String line;
		
		while((line = input.readLine()) != null)
		{
			String tokens[] = line.trim().split("\\s+");
			if (tokens.length == 1)
				break;
			
			a = new BigInteger(tokens[0]);
			b = new BigInteger(tokens[1]);
			
			printMultiplication(a, b, output);
			output.println();					
		}				
		input.close();
		output.close();
	}
}
