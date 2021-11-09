import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class NBFileIr {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc= new Scanner(System.in);    
		System.out.print("Adatok szama = ");  
		int adatok= sc.nextInt();
		
		try {
		      FileWriter kiír = new FileWriter("vezeteknev.txt");
		      int szamok[]= new int[adatok];
				for(int i=0; i<adatok; i++) {
			    	  System.out.print(i);
			    	  System.out.print(".adat = ");
			    	  szamok[i]=sc.nextInt();
			    	  kiír.write(szamok[i] + "\n" + "");
			      }
		      kiír.close();
		    }
		catch (IOException e) 
		{
		      System.out.println("Valami problema van");
		      e.printStackTrace();
		}
		sc.close();
		
		System.out.println("Adatok kiirasa: a vezeteknev.txt allomanyba");
		File file = new File("vezeteknev.txt");
		Scanner scanner = new Scanner(file);
		
		while(scanner.hasNextInt())
		{
			 System.out.println(scanner.nextInt());
		}
		scanner.close();
	}
}
