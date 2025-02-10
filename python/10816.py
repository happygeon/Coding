n = int(input())
tmp = list(map(int, input().split()))
m = int(input())
ttmp = list(map(int, input().split()))

arr = {}
for i in tmp:
    if i in arr:
        arr[i] += 1
    else:
        arr[i] = 1

for i in ttmp:
    if i in arr:
        print(arr[i], end=" ")
    else:
        print(0, end=" ")
