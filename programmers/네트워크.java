import java.util.*;

class Solution {
    
    public void dfs(int idx, int[][] computers, boolean visited[], int n){
        visited[idx] = true;        
        for(int i = 0; i < n; i++){
            if(computers[idx][i] == 1 && !visited[i]){
                dfs(i, computers, visited, n);
            }
        }
    }
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        boolean visited[] = new boolean[n];
        
        for(int i = 0; i < n; i++){
            if(!visited[i]) {
                answer++;
                dfs(i, computers, visited, n);
            }
        }
            
        return answer;
    }
}
