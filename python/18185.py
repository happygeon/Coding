n = int(input())
arr = list(map(int, input().split()))

sum = 0
for i in range(n):
    if(arr[i] == 0):
        continue
    if(i + 2 < n):
        tmp = min(arr[i], arr[i + 1], arr[i + 2])
        sum += (tmp * 7)
        arr[i] -= tmp
        arr[i + 1] -= tmp
        arr[i + 2] -= tmp
    
    if(i + 1 < n):
        tmp = min(arr[i], arr[i + 1])
        sum += (tmp * 5)
        arr[i] -= tmp
        arr[i + 1] -= tmp
    
    tmp = arr[i]
    sum += (tmp * 3)
    arr[i] -= tmp

print(sum)