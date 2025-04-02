import sys
sys.setrecursionlimit(10**7)

N = int(input())
W = int(input())
lis = [[0,0]]
dp = [[0 for i in range(W+10)] for j in range(W+10)]
log = [[0 for i in range(W+10)] for j in range(W+10)]
for i in range(W):
    lis.append(list(map(int, input().split())))

def get_dist(x1,y1,x2,y2):
    """get taxi distance"""
    return abs(x1-x2) + abs(y1-y2)

def dynamic(xidx, yidx):
    if dp[xidx][yidx] != 0:
        return dp[xidx][yidx]
    if xidx == W or yidx == W:
        return 0
    
    maxidx = max(xidx, yidx) + 1
    if xidx == 0:
        x = 1
        y = 1
    else:
        x = lis[xidx][0]
        y = lis[xidx][1]
    if yidx == 0:
        nx = N
        ny = N
    else:
        nx = lis[yidx][0]
        ny = lis[yidx][1]
    
    tx = lis[maxidx][0]
    ty = lis[maxidx][1]
    
    if(dynamic(maxidx, yidx) == 0):
        dp[maxidx][yidx] = dynamic(maxidx, yidx)
    if(dynamic(xidx, maxidx) == 0):
        dp[xidx][maxidx] = dynamic(xidx, maxidx)
    
    if(dp[maxidx][yidx] + get_dist(x,y,tx, ty) < dp[xidx][maxidx] + get_dist(nx,ny,tx, ty)):
        log[xidx][yidx] = 1
        dp[xidx][yidx] = dp[maxidx][yidx] + get_dist(x,y,tx, ty)
    else:
        log[xidx][yidx] = 2
        dp[xidx][yidx] = dp[xidx][maxidx] + get_dist(nx,ny,tx, ty)
        
    return dp[xidx][yidx]

def tracking(xidx, yidx):
    if xidx == W or yidx == W:
        return
    maxidx = max(xidx, yidx)
    if log[xidx][yidx] == 1:
        print(1)
        tracking(maxidx+1, yidx)
    else:
        print(2)
        tracking(xidx, maxidx+1)
    
min = dynamic(0,0)
print(min)
tracking(0,0)