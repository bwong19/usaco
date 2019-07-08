/*                                                                                                                                                                                   
  ID: bwong43                                                                                                                                                                        
  LANG: Java                                                                                                                                                                         
  PROB: milk                                                                                                                                                                         
*/

import java.util.SortedMap;
import java.util.Scanner;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.File;

public class milk {
    
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("milk.in"));
        PrintWriter pw = new PrintWriter(new File("milk.out"));
	
        int amt = sc.nextInt();
        int farmers= sc.nextInt();
	
        SortedMap<Integer, Integer> prices = null;
	
        for (int i = 0; i < farmers; ++i) {
	    int price = sc.nextInt();
	    int units = sc.nextInt();
	    
	    prices.put(price, units);
        }
	
        System.out.println("hello");
    }

}
