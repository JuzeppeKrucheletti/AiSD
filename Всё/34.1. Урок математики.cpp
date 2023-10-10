#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include<stdio.h>
#pragma
using namespace std;

//ifstream fin;
//ofstream fout;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //fin.open("input.txt");
    int n;
    //fin >> n;
    scanf("%d", &n);
    map<long, int> M;
    for (int i = 0; i < n * n; i++) {
        long a;
        //fin >> a;
        scanf("%d", &a);
        M[a] += 1;
    }
    //fout.open("output.txt");
    long* F = new long[n];

    int value = (*M.begin()).first;
    F[0] = value/2;
    //fout << F[0];
    printf("%d", F[0]);
    printf("%s", "\n");
    if ((*M.begin()).second == 1) M.erase(value);
    else M[value]--;

    for (int i = 1; i < n; i++) {
     
        F[i] = (*M.begin()).first - F[0];
        printf("%d", F[i]);
        printf("%s", "\n");
        value = M[F[i] * 2];
        if (value == 1) M.erase(F[i] * 2);
        else {
            M[F[i] * 2]--;
        }
        for (int j = i; j > 0; j--) {
            long key = F[i] + F[j - 1];
            value = M[key];
            if (value <= 2) M.erase(key);
            else {
                M[key] -= 2;
            }
        }
    }

 
    
   
    /*for (int i = 0; i < n; i++) {
        fout << F[i] << endl;
    }*/
    
    
    
    
    

    /*
   import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.TreeMap;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
        int n;
        String str = br.readLine();
        n = Integer.parseInt(str);
        TreeMap<Long, Integer> M = new TreeMap<>();
        str = br.readLine();
        String strmass[] = str.split(" ");

        Long a;
        for(int i = 0; i < n*n; i++){

            a = Long.parseLong(strmass[i]);
            //System.out.println(a);
            Integer k = M.get(a);
            if(k==null) {
                M.put(a,1);
            }
            else {
                k++;
                M.replace(a,k);
            }
        }
        Long F[] = new Long[n];
        F[0] = M.firstKey()/2;
        Integer val = M.get(M.firstKey());
        if(val == 1) M.remove(M.firstKey());
        else {
            val--;
            M.replace(M.firstKey(),val);
        }
        for(int i = 1; i < n; i++){
            F[i] = M.firstKey() - F[0];
            Integer value = M.get(F[i]*2);
            if(value == 1) M.remove(F[i]*2);
            else {
                value--;
                M.replace(F[i]*2,value);
            }
            for(int j = i; j >0; j--){
                Long key = F[i]+F[j-1];
                value = M.get(key);
                if(value <= 2) M.remove(key);
                else {
                    value-=2;
                    M.replace(key,value);
                }
            }

        }

        //Arrays.sort(F);
        for(int i = 0; i < n; i++){
           pw.print(F[i]);
            pw.print("\n");
        }




        pw.close();
        br.close();


    }
}
    
    */

    
    
    //fin.close();
    //fout.close();

    return 0;
}