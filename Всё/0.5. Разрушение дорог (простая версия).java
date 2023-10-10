import java.io.*;
import java.util.Arrays;
import java.util.Scanner;


public class Main {
    public  static int FindSet(int a, int F[]) {
   if (a == F[a]) return a;
   F[a] = FindSet(F[a], F);
    return F[a];
}

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
        int n = 0, m = 0, q = 0;

        String str = br.readLine();
        String strmass[] = str.split(" ");
        n = Integer.parseInt(strmass[0]);
        m = Integer.parseInt(strmass[1]);
        q = Integer.parseInt(strmass[2]);
        int F[] = new int[n + 1];
        int size[] = new int[n + 1];
        int roads[][] = new int[m][2];
        int zemletr[] = new int[q];
        int zemletr_sort[] = new int[q];
        for (int i = 1; i < n + 1; i++) {
            F[i] = i;
            size[i] = 1;
        }
        for (int i = 0; i < m; i++) {
            str = br.readLine();
            strmass = str.split(" ");
            int a = 0, b = 0;
            a = Integer.parseInt(strmass[0]);
            b = Integer.parseInt(strmass[1]);
            roads[i][0] = a;
            roads[i][1] = b;
        }
        for (int i = 0; i < q; i++) {
            str = br.readLine();

            zemletr[i] = Integer.parseInt(str);
            zemletr_sort[i] = Integer.parseInt(str);
        }
        Arrays.sort(zemletr_sort);
        int comp_sv = n;
        boolean res[] = new boolean[q];
        if (m != q) {
            int roads_after[] = new int[m - q];
            for (int i = 1, j = 0, k = 0; i < m + 1; i++) {
                if (zemletr_sort[j] != i) {
                    roads_after[k] = i;

                    k++;
                } else {
                    if(j<q-1) j++;
                }
            }


            for (int i = 0; i < m - q; i++) {
                int a = 0, b = 0;
                a = roads[roads_after[i] - 1][0];
                b = roads[roads_after[i] - 1][1];
                //System.out.println(a+" "+b);

                int a_root = Main.FindSet(a,F), b_root = Main.FindSet(b,F);

                if (a_root == b_root) {
                    // pw.print(comp_sv + "\n");
                } else {
                    //Union
                    if (size[a_root] < size[b_root]) {
                        int el = a_root;
                        a_root = b_root;
                        b_root = el;
                    }

                    F[b_root] = a_root;
                    size[a_root] += size[b_root];
                    comp_sv--;
                    //pw.print(comp_sv + "\n");
                }

            }
            //for(int i = 0; i < m-q; i++) System.out.println(roads_after[i]);
        }


        for (int i = q-1; i >=0; i--) {
            int a = 0, b = 0;
            a = roads[zemletr[i]-1][0];
            b = roads[zemletr[i]-1][1];
            //System.out.println(a + " " + b);

            int a_root = a, b_root = b;
            while (a_root != F[a_root]) {
                a_root = F[a_root];
            }
            while (true) {
                if (F[a] != a) {
                    int a1 = a;
                    a = F[a];
                    F[a1] = a_root;
                }
                else break;
            }
            while (b_root != F[b_root]) {
                b_root = F[b_root];
            }
            while (true) {
                if (F[b] != b) {
                    int b1 = b;
                    b = F[b];
                    F[b1] = b_root;
                }
                else break;
            }
            if (a_root == b_root) {
                //pw.print(comp_sv+"\n");
                if(comp_sv==1) res[i] = true;
                else res[i] = false;
            }
            else {
                //Union
                if (size[a_root] < size[b_root]){
                    int el = a_root;
                    a_root = b_root;
                    b_root = el;
                }

                F[b_root] = a_root;
                size[a_root] += size[b_root];
                if(comp_sv==1) if(comp_sv==1) res[i] = true;
                else res[i] = false;
                comp_sv--;
            }
        }

        for(int i = 0; i < q; i++){
            if(res[i]==true) pw.print(1);
            else pw.print(0);
        }
/*
        int comp_sv = n;
        for (int i = 0; i < q; i++) {
            int a = 0, b = 0;
            str = br.readLine();
            strmass = str.split(" ");
            a = Integer.parseInt(strmass[0]);
            b = Integer.parseInt(strmass[1]);

            int a_root = a, b_root = b;
            while (a_root != F[a_root]) {
                a_root = F[a_root];
            }
            while (true) {
                if (F[a] != a) {
                    int a1 = a;
                    a = F[a];
                    F[a1] = a_root;
                }
                else break;
            }
            while (b_root != F[b_root]) {
                b_root = F[b_root];
            }
            while (true) {
                if (F[b] != b) {
                    int b1 = b;
                    b = F[b];
                    F[b1] = b_root;
                }
                else break;
            }
            if (a_root == b_root) {
                pw.print(comp_sv+"\n");
            }
            else {
                //Union
                if (size[a_root] < size[b_root]){
                    int el = a_root;
                    a_root = b_root;
                    b_root = el;
                }

                F[b_root] = a_root;
                size[a_root] += size[b_root];
                comp_sv--;
                pw.print(comp_sv+"\n");
            }

        }*/
        pw.close();
        br.close();


    }
}