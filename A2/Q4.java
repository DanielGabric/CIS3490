import java.util.*;
import java.io.*;
public class Assignment2 {
    public static void main(String[] args) throws FileNotFoundException{
        double start = System.currentTimeMillis();
        int freq[]=new int[101];
        Scanner s = new Scanner(new File("test.txt"));
        int c = 0;
        int sum = 0;
        int N = s.nextInt();
        boolean isAfterN=false;
        while(s.hasNextInt())freq[s.nextInt()]++;
        N/=2;
        for(int i=1;i<=100;++i){
            if(!isAfterN){
                c+=freq[i];
                if(c>=N){
                    sum+=(c-N)*i;
                    isAfterN = true;
                    freq[i]-=c-N;
                }
                sum -= freq[i]*i;
            }else
                sum += freq[i]*i;
        }
        System.out.println("Max difference: "+sum);
        System.out.println("Freq15: "+freq[15]);
        System.out.println("Freq27: "+freq[27]);
        System.out.println("Freq54: "+freq[54]);
        System.out.println("Freq89: "+freq[89]);
        System.out.println("Time: "+(System.currentTimeMillis()-start)+" ms");
    }   
}

//OUTPUT:
//Max difference: 2451048
//Freq15: 1025
//Freq27: 1040
//Freq54: 1040
//Freq89: 1052
//Time: 247.0 ms
