import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class wh8l7e_3_5 {

	public static void main(String[] args) {

		masol("innen.txt", "ide.txt");
		
	}
	
	public static void masol(String innen, String ide) {
		String sor;
		String[] k1 = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "0" };
		String[] k2 = { " egy ", " kettõ ", " három ", " négy ", " öt ", " hat ", " hét ", "nyolc ", "kilenc ",
				" nulla" };
				
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(ide));
			BufferedReader br = new BufferedReader(new FileReader(innen));
			while ((sor = br.readLine()) != null) {
				for (int i = 0; i < 10; i++) {
					sor = sor.replace(k1[i], k2[i]);
				}
				bw.write(sor);
				bw.newLine();
			}
			
			br.close();
			bw.close();
			System.out.println("Ok");
		} catch (Exception ee) {
			ee.printStackTrace();
		}
	}

}
