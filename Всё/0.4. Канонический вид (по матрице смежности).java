import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
        int n = 0;

        String str = br.readLine();
        n = Integer.parseInt(str);
        int M[][] = new int [n][n];

        int P[] = new int [n];

        String strmass[];
        for(int i = 0; i < n; i++){
            str = br.readLine();
            strmass = str.split(" ");
            P[i] = 0;
           for(int j = 0; j < n; j++){
               M[i][j] = Integer.parseInt(strmass[j]);
           }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ; j++){
                if(M[i][j]==1){
                    P[j] = i+1;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            pw.print(P[i]+" ");
        }



        pw.close();
        br.close();


    }
}