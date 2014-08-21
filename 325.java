import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		
		final String REGEX = "[+-]?[0-9]+((\\.[0-9]+([eE][+-]?[0-9]*)?)|([eE][+-]?[0-9]*))";
		
		Scanner input = new Scanner(System.in);
		while(true)
		{
			String s = input.next();
			if (s.equals("*"))
				break;
			if (s.matches(REGEX))
				System.out.println(s + " is legal.");
			else
				System.out.println(s + " is illegal.");
		}			
		input.close();
	}
}
