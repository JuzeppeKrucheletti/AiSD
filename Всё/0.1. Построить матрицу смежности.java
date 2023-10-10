import java.io.*;
import java.util.Arrays;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
        int n = 0, m = 0;

        String str = br.readLine();
        String strmass[] = str.split(" ");
        n = Integer.parseInt(strmass[0]);
        m = Integer.parseInt(strmass[1]);
        int M[][] = new int[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                M[i][j] = 0;
            }
        }
        int a = 0, b = 0;
        for(int i = 0; i < m; i++){
            str = br.readLine();
            strmass = str.split(" ");
            a = Integer.parseInt(strmass[0]);
            b = Integer.parseInt(strmass[1]);
            M[a-1][b-1] = M[b-1][a-1] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                pw.print(M[i][j]);
                pw.print(" ");
            }
            pw.print("\n");
        }


        pw.close();
        br.close();


    }
}