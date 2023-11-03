import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine);
        HashMap<String, Integer> map = new HashMap<>();
        ArrayList<String> list = new Arraylist<>();
      
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        for(int i = 0; i < N; i++) {
          map.put(br.readLine(), 1);
        }

        for(int i = 0; i < M; i++) {
          String name = br.readLine();
          map.put(name, map.getOrDefault(name, 0) + 1);
          if(map.get(name) == 2) {
            list.add(name);
          }
        }

        for(int i = 0; i < list.size(); i++) {
          System.out.println(list.get(i));
        }
    }
}
