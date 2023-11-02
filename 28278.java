import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Deque<Integer> deque = new ArrayDeque<Integer>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st;

        while(N > 0) {
            st = new StringTokenizer(br.readLine());
            String command = st.nextToken();
            if(command.equals("1")) {
                deque.addLast(Integer.parseInt(st.nextToken()));
            }
            else if(command.equals("2")) {
                if(deque.isEmpty() == true)
                    sb.append(-1).append("\n");
                else sb.append(deque.pollLast()).append("\n");
            }
            else if(command.equals("3")) {
                sb.append(deque.size()).append("\n");
            }
            else if(command.equals("4")) {
                if(deque.isEmpty() == true) {
                    sb.append(1).append("\n");
                }
                else {
                    sb.append(0).append("\n");
                }
            }
            else if(command.equals("5")) {
                if (deque.isEmpty() == false) {
                    sb.append(deque.getLast()).append("\n");
                } else {sb.append(-1).append("\n");}
            }
            N--;
        }
        System.out.println(sb);
    }
}
