a = int(input())

sum = 0
if(a % 3 == 0):
    sum += (a // 15) * 3
    sum += (a % 15) // 3

elif(a % 3 == 1):
    if(a < 10):
        sum = -1
    else:
        sum += 2
        a -= 10
        sum += (a // 15) * 3
        sum += (a % 15) // 3

elif(a % 3 == 2):
    if(a < 5):
        sum = -1
    else:
        sum += 1
        a -= 5
        sum += (a // 15) * 3
        sum += (a % 15) // 3 
        
print(sum)