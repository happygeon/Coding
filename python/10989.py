n = int(input())

#make 0 array size 10001
arr = [0] * 10001

for i in range(n):
    arr[int(input())] += 1

for i in range(1, 10001):
    for j in range(arr[i]):
        print(i)