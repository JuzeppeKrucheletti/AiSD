import java.io.*;
import java.util.Arrays;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
        int n = 0;

        String str = br.readLine();
        n = Integer.parseInt(str);
        int P[] = new int[n];
        for(int i = 0; i < n; i++){
            P[i] = 0;
        }

        String strmass[];
        int a = 0, b = 0;
        for(int i = 0; i < n-1; i++){
            str = br.readLine();
            strmass = str.split(" ");
            a = Integer.parseInt(strmass[0]);
            b = Integer.parseInt(strmass[1]);
            P[b-1] = a;
        }
        for(int i = 0; i < n; i++){
            pw.print(P[i]);
            pw.print(" ");
        }


        pw.close();
        br.close();


    }
}