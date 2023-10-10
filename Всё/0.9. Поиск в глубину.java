import java.io.*;
import java.util.*;


public class Main {
    static int num = 1;

    public static void DFS(Integer M[][], Integer P[], boolean V[], Integer start){
        if(V[start]==false) {
            V[start] = true;
            P[start] = num;
            num++;
            for (int i = 0; i < M.length; i++) {
                if (M[start][i] == 1 && V[i] == false) {
                    DFS(M, P, V, i);
                }
            }

        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
        Integer n = 0;

        String str = br.readLine();
        n = Integer.parseInt(str);
        Integer M[][] = new Integer [n][n];
        Integer P[] = new Integer[n];
        boolean V[] = new boolean[n];
        Stack<Integer> S = new Stack<>();





        String strmass[];
        for(int i = 0; i < n; i++){
            str = br.readLine();
            strmass = str.split(" ");
            P[i] = -1;
            V[i] = false;
            for(int j = 0; j < n; j++){
                M[i][j] = Integer.parseInt(strmass[j]);
            }
        }
        Integer num = 1, start = 0;
        for(int k = 0; k < n; k++){

                start = k;
                Main.DFS(M,P,V,start);

        }
        for(int i = 0; i < n; i++){
            pw.print(P[i]+" ");
        }
        //bfs






        pw.close();
        br.close();


    }
}