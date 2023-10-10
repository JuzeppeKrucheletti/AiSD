import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;


public class Main {

    public static Integer max = 1;
    public static Integer rez = 0;
    public  static Queue<Integer[]> Q = new LinkedList<>();
    public static void Vomper_BFS(Integer[][] M, int n, int m) {
       // System.out.println(Q.size());
        Integer imass[] = new Integer[2];
        imass = Q.poll();
        if(imass[0]==-1){
            max++;
            Q.add(imass);

        }
        else {

            if (imass[0] < n - 1 )
                if( M[imass[0] + 1][imass[1]] > max) {
                    Integer imass1[] = new Integer[2];
                    imass1[0] = imass[0] + 1;
                    imass1[1] = imass[1];
                    Q.add(imass1);
                    M[imass1[0]][imass1[1]] = max;
                }
            if (imass[1] < m - 1)
                if( M[imass[0]][imass[1] + 1] > max) {
                    Integer imass1[] = new Integer[2];
                    imass1[0] = imass[0];
                    imass1[1] = imass[1] + 1;
                    Q.add(imass1);
                    M[imass1[0]][imass1[1]] = max;
                }
            if (imass[0] > 0)
                if( M[imass[0] - 1][imass[1]] > max) {
                    Integer imass1[] = new Integer[2];
                    imass1[0] = imass[0] - 1;
                    imass1[1] = imass[1];
                    Q.add(imass1);
                    M[imass1[0]][imass1[1]] = max;
                }
            if (imass[1] > 0)
                if( M[imass[0]][imass[1] - 1] > max) {
                    Integer imass1[] = new Integer[2];
                    imass1[0] = imass[0];
                    imass1[1] = imass[1] - 1;
                    Q.add(imass1);
                    M[imass1[0]][imass1[1]] = max;
                }
        }
    }

    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();


        BufferedReader br = new BufferedReader(new FileReader("vampires.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("vampires.out"));
        Integer n = 0, m = 0;

        String str = br.readLine();
        String strmass[];
        strmass = str.split(" ");
        n = Integer.parseInt(strmass[0]);
        m = Integer.parseInt(strmass[1]);
        Integer M[][] = new Integer [n][m];
        //Queue<Integer[]> Q = new LinkedList<>();

        //Integer P[] = new Integer[n];
        for(int i = 0; i < n; i++){
            str = br.readLine();

            for(int j = 0; j < m; j++){
                if(str.charAt(j)=='V'){
                    M[i][j] = -1;
                    Integer imass[] = new Integer[2];
                    imass[0] = i;
                    imass[1] = j;
                    Q.add(imass);
                }
                if(str.charAt(j)=='.')
                    M[i][j] = 1000000;
                if(str.charAt(j)=='#')
                    M[i][j] = -2;
            }
        }
        Integer imass[] = new Integer[2];
        imass[0] = -1;
        imass[1] = -1;

        Q.add(imass);


        while(Q.size()!=1) {
            Main.Vomper_BFS( M, n, m);
        }
       /*for(int i = 0; i < 2000; i++){
            pw.print("\n");
            for(int j = 0; j < 2000; j++){
                pw.print(".");
            }
        }*/


        pw.print(max-1);


        pw.close();
        br.close();


    }
}