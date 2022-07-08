import sys
input = sys.stdin.readline

str = list(input().rstrip())
boom = list(input().rstrip())

stack = []

for i in range(len(str)) : 
    stack.append(str[i])
    if len(stack) >= len(boom) and stack[-1] == boom[-1] :
        if stack[-len(boom):] == boom :
            for i in range(len(boom)):
                stack.pop()

if stack : print("".join(stack))
else : print("FRULA")
