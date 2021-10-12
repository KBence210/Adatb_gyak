package fajlkezelés;
import java.io.*;
import java.util.Scanner;



public class KBFileOlvas {
	
	public static void main(String[] args) throws Exception
	  {
	    File adat = new File("Bence.txt");
	    try {
	    	Scanner bemenet = new Scanner(adat);
	    	int szam = bemenet.nextInt();
	    	System.out.println("Adatok száma = 2");
	    	System.out.println("0. adat = " + szam);
	    	int szam2 = bemenet.nextInt();
	    	System.out.println("1. adat = " + szam2);
	    	
	    	System.out.println("Összeg = " + (szam + szam2));
	    	
	    	
	    	
	    }catch(FileNotFoundException ex) {
	    	System.out.println("Hiba");
	    }
	    
	
	    	

	
	}

}