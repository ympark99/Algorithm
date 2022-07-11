from collections import deque

t = int(input())

for i in range(t):
    p = input()
    n = int(input())
    arr = input()[1:-1].split(',')

    queue = deque(arr)
    isReverse = 0

    if n == 0:
        queue = []

    for j in p:
        if j == 'R':
            isReverse += 1
        elif j == 'D':
            if len(queue) == 0:
                print("error")
                break
            else:
                if isReverse % 2 == 0:
                    queue.popleft()
                else:
                    queue.pop()

    else:
        if isReverse % 2 == 0:
            print("[" + ",".join(queue) + "]")
        else:
            queue.reverse()
            print("[" + ",".join(queue) + "]")
