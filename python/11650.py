n = int(input())
arr = []
for i in range(n):
    #input two int as tuple
    arr.append(tuple(map(int, input().split())))

arr.sort()

for i in arr:
    print(i[0], i[1])