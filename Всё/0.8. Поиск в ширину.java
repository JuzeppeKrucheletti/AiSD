import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;


public class Main {

    public static void BFS(Integer M[][], Integer P[], Queue<Integer> Q, Integer start, Integer num){
        while (Q.isEmpty()==false){
            int n = M.length;
            int i = Q.poll();
            for(int j = 0; j < n; j++){
                if(M[i][j]==1 && P[j]!=-1){
                    Q.add(j);
                    P[j] = num;
                    num++;
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
        Queue<Integer> Q = new LinkedList<>();





        String strmass[];
        for(int i = 0; i < n; i++){
            str = br.readLine();
            strmass = str.split(" ");
            P[i] = -1;
           for(int j = 0; j < n; j++){
               M[i][j] = Integer.parseInt(strmass[j]);
           }
        }
        Integer num = 1, start = 0;
        for(int k = 0; k < n; k++){
            if(P[k]==-1){
                start = k;
                Q.add(k);
                P[k] = num;
                num++;
                while (Q.isEmpty()==false){
                    int i = Q.poll();
                    for(int j = 0; j < n; j++){
                        if(M[i][j]==1 && P[j]==-1){
                            Q.add(j);
                            P[j] = num;
                            num++;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            pw.print(P[i]+" ");
        }
        //bfs






        pw.close();
        br.close();


    }
}