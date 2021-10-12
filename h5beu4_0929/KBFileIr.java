package fajlkezelés;
import java.io.*;

public class KBFileIr {

	public static void main(String[] args) {
		File adat = new File("Bence.txt");
		try {
			PrintWriter kimenet = new PrintWriter(adat);
			System.out.println("Adatok száma = 3 \n10,\n20,\n30");
			kimenet.println("10");
			kimenet.println("20");
			kimenet.println("30");
			kimenet.close();
		}catch(FileNotFoundException ex) {
			System.out.println("Hiba");
		}
		
	}

}
