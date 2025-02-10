a = int(input())
arr = []
for i in range(a):
    tmp = int(input())
    if(tmp == 0):
        arr.pop()
    else:
        arr.append(tmp)
print(sum(arr))