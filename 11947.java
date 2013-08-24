import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;

public class Main
{    
    public static void main(String[] args)
    {		
	Scanner cin = new Scanner(System.in);
	int dataSets, day, month, year;	
	
	dataSets = cin.nextInt(); cin.nextLine();
	for(int d = 1; d <= dataSets; ++d)
	{
	    String line = cin.nextLine();
	        
	    month = Integer.parseInt(line.substring(0,2));
	    day = Integer.parseInt(line.substring(2,4));
	    year = Integer.parseInt(line.substring(4,8)); 
	    
	    GregorianCalendar gc = new GregorianCalendar(year, month - 1, day);
	    gc.add(Calendar.DATE, 280);
	    
	    System.out.printf("%d %02d/%02d/%04d %s\n", d, gc.get(Calendar.MONTH) + 1, gc.get(Calendar.DATE), gc.get(Calendar.YEAR), getZodiac(gc));	    
	}	
    } 
    
    private static String getZodiac(GregorianCalendar gc)
    {
	switch(gc.get(Calendar.MONTH))
	{
	case Calendar.JANUARY:
	    if (gc.get(Calendar.DATE) >= 21)
		return "aquarius";
	    else 
		return "capricorn";
	case Calendar.FEBRUARY:
	    if (gc.get(Calendar.DATE) >= 20)
		return "pisces";
	    else 
		return "aquarius";
	case Calendar.MARCH:
	    if (gc.get(Calendar.DATE) >= 21)
		return "aries";
	    else 
		return "pisces";
	case Calendar.APRIL:
	    if (gc.get(Calendar.DATE) >= 21)
		return "taurus";
	    else 
		return "aries";
	case Calendar.MAY:
	    if (gc.get(Calendar.DATE) >= 22)
		return "gemini";
	    else 
		return "taurus";
	case Calendar.JUNE:
	    if (gc.get(Calendar.DATE) >= 22)
		return "cancer";
	    else 
		return "gemini";
	case Calendar.JULY:
	    if (gc.get(Calendar.DATE) >= 23)
		return "leo";
	    else 
		return "cancer";
	case Calendar.AUGUST:
	    if (gc.get(Calendar.DATE) >= 22)
		return "virgo";
	    else 
		return "leo";
	case Calendar.SEPTEMBER:
	    if (gc.get(Calendar.DATE) >= 24)
		return "libra";
	    else 
		return "virgo";
	case Calendar.OCTOBER:
	    if (gc.get(Calendar.DATE) >= 24)
		return "scorpio";
	    else 
		return "libra";
	case Calendar.NOVEMBER:
	    if (gc.get(Calendar.DATE) >= 23)
		return "sagittarius";
	    else 
		return "scorpio";
	default:
	    if (gc.get(Calendar.DATE) >= 23)
		return "capricorn";
	    else 
		return "sagittarius";	    
	}	
    }
}