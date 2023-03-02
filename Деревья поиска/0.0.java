
import java.io.*;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws IOException {
        Set S = new HashSet();
        File f = new File("input.txt");
        BufferedReader br = new BufferedReader(new FileReader(f));
        File f1 = new File("output.txt");
        BufferedWriter bw = new BufferedWriter(new FileWriter(f1));
        while(br.ready()) {
            Long l = Long.parseLong(br.readLine());
            S.add(l);
        }
        Long summ = new Long(0);
        for(Object obj: S){
            summ+=(Long)obj;
        }
        bw.write(Long.toString(summ));
        bw.close();
        br.close();
    }
}
