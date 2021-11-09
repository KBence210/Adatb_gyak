import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class NBFileOlvas {

	public static void main(String[] args) throws FileNotFoundException {
		File file = new File("vezeteknev.txt");
		Scanner scanner = new Scanner(file);
		int i=0;
		
		while(scanner.hasNextInt())
		{
			 System.out.print(i);
			 System.out.print(".adat:");
			 System.out.println(scanner.nextInt());
		         i++;
		}
		
		System.out.print("Adatok szama:");
		System.out.println(i);
		
		File fájl = new File("vezeteknev.txt");
		Scanner scan = new Scanner(fájl);
		int osszeg=0;
		while(scan.hasNextInt())
		{
			osszeg += scan.nextInt();
		}
		
		System.out.print("Osszeg:");
		System.out.println(osszeg);
	}

}
