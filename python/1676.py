n = int(input())

fact = 1
for i in range(1, n+1):
    fact *= i

cnt = 0
for i in range(len(str(fact))-1, -1, -1):
    if(str(fact)[i] == '0'):
        cnt += 1
    else:
        break
print(cnt)