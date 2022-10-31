import java.util.Arrays;

class Solution {
    int ans = -1;
    int arr[][];
    boolean check[];
    
    void dfs(int hp, int cnt){
        if(cnt > ans) ans = cnt;
        
        for(int i = 0; i < arr.length; i++){
            if(check[i] || arr[i][0] > hp) continue;
            check[i] = true;
            dfs(hp - arr[i][1], cnt+1);
            check[i] = false;
        }
    }
    
    public int solution(int k, int[][] dungeons) {
        arr = dungeons;
        check = new boolean[8+1];
        Arrays.fill(check, false);

        for(int i = 0; i < dungeons.length; i++){
            if(dungeons[i][0] > k) continue;
            check[i] = true;
            dfs(k - dungeons[i][1], 1);
            check[i] = false;
        }

        return ans;
    }
}
