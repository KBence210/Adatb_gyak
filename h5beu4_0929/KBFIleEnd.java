package fajlkezelés;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;

public class KBFIleEnd {

	public static void main(String[] args) {
		
		filetoend();
		filetoupper("Bence.txt");
		filemasol("be.txt", "ki.txt");
		
	}
	
	public static void filetoend () {
		String sor;
		String[] szavak;
		int sorid = 0;
		
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = null;
			
			while (sorid >= 0) {
				sor = br.readLine();
				if (sorid == 0) {
					bw = new BufferedWriter(new FileWriter(sor));
				} else {
					bw.write(sor);
					bw.newLine();
				}
				sorid = sorid+1;
				szavak = sor.split(" ");
				for (String sz : szavak) {
					System.out.println(sz+";");
					if(sz.compareTo("end")==0) {
						br.close();
						sorid = -1;
					}
				}
			}
			
		}catch (Exception e) {
			e.printStackTrace();
		}

	}
	
	public static void filetoupper (String filenev) {
		
		String sor;
		String[] szavak;
		int sorid = 0;
		
		try {
			BufferedReader br = new BufferedReader(new FileReader(filenev));
			while ((sor = br.readLine()) != null) {
				System.out.println(sor.toUpperCase());
			}
			br.close();
			System.out.println("Ok");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	
	public static void filemasol (String filenevbe, String filenevki) {
		String sor;
		String[] szavak;
		String[] k1 = {"1","2","3","4","5","6","7","8","9","0"};
		String[] k2 = {"egy", "kettõ", "három", "négy", "öt" , "hat", "hét", "nyolc", "kilenc", "nulla"};
		int sorid = 0;
		
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(filenevki));
			BufferedReader br = new BufferedReader(new FileReader(filenevbe));
			while ((sor = br.readLine()) != null) {
				for (int i=0; i<10; i++) {
					sor = sor.replace(k1[i], k2[i]);
				}
				bw.write(sor);
				bw.newLine();
			}br.close();
			bw.close();
			
				System.out.println("ok");
				
				} catch (Exception e) {
				e.printStackTrace();
			}
		}
	

	

}
