import java.util.*;
import java.io.*;


public class Main
{
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        Integer arr[][] = new Integer[N][M];
        boolean check[][] = new boolean[N][M];

        for(int i = 0; i < N; i++) {
            String str = br.readLine();
            for(int j = 0; j < M; j++) {
                arr[i][j] = str.charAt(j) - '0';
                check[i][j] = false;
            }
        }

        ArrayDeque<Point> deque = new ArrayDeque<>();
        deque.addLast(new Point(0, 0, 1));
        check[0][0] = true;

        while(!deque.isEmpty()) {
            Point point = deque.pollFirst();
            int row = point.row;
            int col = point.col;
            int cnt = point.cnt;

            if(row == N-1 && col == M-1) {
                System.out.print(cnt);
                return;
            }

            for(int i = 0; i < 4; i++) {
                int nrow = row + dy[i];
                int ncol = col + dx[i];

                if(nrow < 0 || nrow >= N || ncol < 0 || ncol >= M || check[nrow][ncol])
                    continue;
                if(arr[nrow][ncol] == 0) continue;

                check[nrow][ncol] = true;
                deque.addLast(new Point(nrow, ncol, cnt + 1));
            }
        }
    }

    static class Point {
        int row;
        int col;
        int cnt;
        public Point(int row, int col, int cnt) {
            this.row = row;
            this.col = col;
            this.cnt = cnt;
        }
    }
}
