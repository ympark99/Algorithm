import java.util.*;
import java.io.*;


public class Main
{
    static int N;
    static int[][] arr;
    static int[] dy = {-1, 1, 0, 0};
    static int[] dx = {0, 0, -1, 1};
    static int homeCnt = 0;

    static void dfs(int row, int col) {
        arr[row][col] = 0;
        homeCnt++;
        for(int i = 0; i < 4; i++) {
            int nrow = row + dy[i];
            int ncol = col + dx[i];

            if(nrow < 0 || nrow >= N || ncol < 0 || ncol >= N || arr[nrow][ncol] == 0)
                continue;
            dfs(nrow, ncol);
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        ArrayList<Integer> list = new ArrayList<>();
        N = Integer.parseInt(br.readLine());
        arr = new int[N][N];
        int ans = 0;

        for(int i = 0; i < N; i++) {
            String tmp = br.readLine();
            for(int j = 0; j < tmp.length(); j++) {
                arr[i][j] = tmp.charAt(j) - '0';
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(arr[i][j] == 1) {
                    ans++;
                    dfs(i, j);
                    list.add(homeCnt);
                    homeCnt = 0;
                }
            }
        }
        Collections.sort(list);
        System.out.println(ans);
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }
    }
}
