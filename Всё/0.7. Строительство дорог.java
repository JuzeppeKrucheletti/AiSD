import java.io.*;
import java.util.Arrays;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
        int n = 0, q = 0;

        String str = br.readLine();
        String strmass[] = str.split(" ");
        n = Integer.parseInt(strmass[0]);
        q = Integer.parseInt(strmass[1]);
        int F[] = new int[n+1];
        int size[] = new int[n + 1];

        for (int i = 1; i < n+1; i++) {
            F[i] = i;
            size[i] = 1;
        }
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
           
            
            while (b_root != F[b_root]) {
                b_root = F[b_root];
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

        }
        pw.close();
        br.close();



    }
}