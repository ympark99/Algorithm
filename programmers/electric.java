import java.util.*;

class Solution {
    static int arr[][];
    // ArrayList<Integer>[] arr = new ArrayList[100];
    
    public int solution(int n, int[][] wires) {
        int answer = n;
        arr = new int[n+1][n+1];
        
        for(int i = 0; i < wires.length; i++){
            arr[wires[i][0]][wires[i][1]] = 1;
            arr[wires[i][1]][wires[i][0]] = 1;
        }
        
        for(int i = 0; i < wires.length; i++){
            arr[wires[i][0]][wires[i][1]] = 0;
            arr[wires[i][1]][wires[i][0]] = 0;       
            
            answer = Math.min(answer, bfs(n, wires[i][0]));
            
            arr[wires[i][0]][wires[i][1]] = 1;
            arr[wires[i][1]][wires[i][0]] = 1;
        }
        
        return answer;
    }
    
    public int bfs(int n, int start){
        int[] visit = new int[n+1];
        int cnt = 1;
        
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        
        while(!q.isEmpty()){
            int point = q.poll();
            visit[point] = 1;
            
            for(int i = 1; i <= n; i++){
                if(arr[point][i] == 1 && visit[i] == 0){
                    q.offer(i);
                    cnt++;
                }
            }
        }
        return (int)Math.abs(n-2 * cnt);
    }
}
