import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);	
		while(input.hasNextLine())
			System.out.println(input.nextLine().replaceAll("[A-C]", "2").replaceAll("[D-F]", "3").
					                            replaceAll("[G-I]", "4").replaceAll("[J-L]", "5").
					                            replaceAll("[M-O]", "6").replaceAll("[P-S]", "7").
					                            replaceAll("[T-V]", "8").replaceAll("[W-Z]", "9"));	
		input.close();
	}
}
