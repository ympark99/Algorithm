import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    static int N;
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 1; t <= T; t++){
            N = Integer.parseInt(in.readLine());
            dfs(1, "1");
            System.out.println();
        }
    }

    public static void dfs(int depth, String str){
        if(depth == N){
            String express = str.replaceAll(" ", "");
            if(cal(express))
                System.out.println(str);
            return;
        }

        dfs(depth+1, str + " " + Integer.toString(depth+1));
        dfs(depth+1, str + "+" + Integer.toString(depth+1));
        dfs(depth+1, str + "-" + Integer.toString(depth+1));
    }

    public static boolean cal(String str){
        StringTokenizer st = new StringTokenizer(str, "-|+", true);
        int sum = Integer.parseInt(st.nextToken());
        while (st.hasMoreTokens()){
            String s = st.nextToken();
            if(s.equals("+"))
                sum += Integer.parseInt(st.nextToken());
            else
                sum -= Integer.parseInt(st.nextToken());
        }

        if(sum == 0)
            return true;
        return false;
    }
}
