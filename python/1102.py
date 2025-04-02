inf = 987654321
initial = [pow(2, i) for i in range(16)]

n = int(input())
n_bit = pow(2, n)

arr = []
for i in range(n):
    tmp = list(map(int, input().split()))
    arr.append(tmp)

st = input()
start = 0
for _ in range(len(st)):
    tmp = st[-1]
    st = st[:-1]

    if(tmp == 'N'):
        start *= 2
    else:
        start = start * 2 + 1

p = int(input())

dp = [-1 for _ in range(n_bit)]
dp[start] = 0

def check(n):
    cnt = 0
    while(n > 0):
        if(n % 2 == 1):
            cnt += 1
        n //= 2
    return cnt

if(start == 0):
    if(p == 0):
        print(0)
        exit(0)
    else:
        print(-1)
        exit(0)
if(check(start) >= p):
    mini = 0   


def dynamic(nn):
    if((dp[nn] != inf) and (dp[nn] != -1)):
        return
    if(nn == 0):
        dp[nn] = 0
        return
    mini = inf
    ii = -1
    for i in initial:
        ii += 1
        if((nn | i) == nn and (nn != i)):
            ##i번째를 켜는 경우 고려
            tmp = nn - i

            if(dp[tmp] == -1):
                dynamic(tmp)
            #print(dp[tmp])
            cost = dp[tmp]

            tmpmin = inf
            for j in range(n):
                if (tmp >> j) & 1:
                    tmpmin = min(tmpmin, arr[j][ii])
            #print(tmpmin, cost, n)

            mini = min(mini, cost + tmpmin)
    dp[nn] = mini
    return
                    



mini = inf
for i in range(n_bit):
    if(check(i) < p):
        continue
    dynamic(i)
    mini = min(mini, dp[i])



print(mini)
    
