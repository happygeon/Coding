li = [input().split() for i in range(20)]

x = 20
sum = 0
ssum = 0
for i in range(20):
    tmp = 0
    if(li[i][2] == 'A+'):
        tmp = 4.5
    elif(li[i][2] == 'A0'):
        tmp = 4.0
    elif(li[i][2] == 'B+'):
        tmp = 3.5
    elif(li[i][2] == 'B0'):
        tmp = 3.0
    elif(li[i][2] == 'C+'):
        tmp = 2.5
    elif(li[i][2] == 'C0'):
        tmp = 2.0
    elif(li[i][2] == 'D+'):
        tmp = 1.5
    elif(li[i][2] == 'D0'):
        tmp = 1.0
    elif(li[i][2] == 'F'):
        tmp = 0.0
    elif(li[i][2] == 'P'):
        continue
    sum += float(li[i][1]) * tmp
    ssum += float(li[i][1])
print(sum / ssum)