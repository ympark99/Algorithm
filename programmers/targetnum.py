ans = 0

def dfs(numbers, target, sums, cnt):
    if cnt == len(numbers):
        if sums == target:
            global ans
            ans += 1
        return
    dfs(numbers, target, sums + numbers[cnt], cnt+1);
    dfs(numbers, target, sums - numbers[cnt], cnt+1);
    return

def solution(numbers, target):
    global ans
    dfs(numbers, target, 0, 0)
    return ans
