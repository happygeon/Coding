n = int(input())
arr = []
for i in range(n):
    #input : "int str"
    a, b = input().split()
    arr.append((int(a), b))
#sort by first element
arr.sort(key = lambda x : x[0])
for i in arr:
    print(i[0], i[1])