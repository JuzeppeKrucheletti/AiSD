import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
        int n = 0, m = 0;

        String str = br.readLine();
        String strmass[]= str.split(" ");
        n = Integer.parseInt(strmass[0]);
        m = Integer.parseInt(strmass[1]);
        ArrayList<Integer> P[] = new ArrayList[n];
        for(int i = 0; i < n; i++){
            P[i] = new ArrayList<>();
            P[i].add(0);
        }


        int a = 0, b = 0;
        for(int i = 0; i < m; i++){
            str = br.readLine();
            strmass = str.split(" ");
            a = Integer.parseInt(strmass[0]);
            b = Integer.parseInt(strmass[1]);
            P[b-1].set(0, P[b-1].get(0)+1);
            P[b-1].add(a);
            P[a-1].set(0, P[a-1].get(0)+1);
            P[a-1].add(b);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < P[i].size(); j++){
                pw.print(P[i].get(j)+" ");
            }
            pw.print("\n");
        }


        pw.close();
        br.close();


    }
}