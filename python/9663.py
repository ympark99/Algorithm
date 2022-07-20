def possible(x) :
    for i in range(x) :
        if row[x] == row[i] or abs(row[x] - row[i]) == abs(x - i) :
            return False
    return True

def n_queen(x) : 
    global ans
    if x == N :
        ans += 1
        return
    else : 
        for i in range(N) : 
            row[x] = i
            if possible(x) : 
                n_queen(x + 1)

N = int(input())
ans = 0
row  = [0] * N
n_queen(0)
print(ans)
