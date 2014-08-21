import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);	
		int count[] = new int[3];
		final String VOWELS = "[aeiouy]+";
		
		while(true)
		{
			String[] tokens = input.nextLine().split("/");
			if (tokens[0].equals("e") && tokens[1].equals("o") && tokens[2].equals("i"))
				break;
					
			for(int i = 0; i < 3; ++i)
			{
				tokens[i] = tokens[i].replaceAll("[aeiouy]+", "a");
				count[i] = tokens[i].length() - tokens[i].replaceAll("a", "").length();
			}
			
			if (count[0] != 5)
				System.out.println(1);
			else if (count[1] != 7)
				System.out.println(2);
			else if (count[2] != 5)
				System.out.println(3);
			else
				System.out.println('Y');			
		}	
		input.close();
	}
}
