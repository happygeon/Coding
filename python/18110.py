import math

n = int(input())
arr = []
de = math.floor(n * 0.15+ 0.5)

if n == 0:
    print(0)
else:
    for i in range(n):
        arr.append(int(input()))

    arr.sort()

    sum = 0
    n = 0
    for i in range(de, len(arr) - de):
        sum += arr[i]
        n += 1
        
    print(math.floor(sum / n+ 0.5))