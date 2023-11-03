import java.util.*;
import java.io.*;


public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        StringBuilder sb = new StringBuilder();
        ArrayList<Character> opers = new ArrayList<>();
        ArrayList<Integer> nums = new ArrayList<>();

        for(int i = 0; i < str.length(); i++) {
            if(str.charAt(i) == '-' || str.charAt(i) == '+') {
                opers.add(str.charAt(i));
                if(sb.length() != 0) {
                    nums.add(Integer.parseInt(sb.toString()));
                    sb.setLength(0);
                }
            }
            else sb.append(str.charAt(i));
        }
        nums.add(Integer.parseInt(sb.toString()));
        sb.setLength(0);

        int res = nums.get(0);
        int idx = 0;
        while(idx < opers.size()) {
            char oper = opers.get(idx);
            if(oper == '+') {
                res += nums.get(idx+1);
                idx++;
            }
            else if(oper == '-') {
                int tmp = nums.get(idx+1);
                idx++;
                while(idx < opers.size() && opers.get(idx) == '+') {
                    tmp += nums.get(idx+1);
                    idx++;
                }
                res -= tmp;
            }
        }
        System.out.println(res);
    }
}
