#a, b is int
a, b = map(int, input().split())

#if a is even, +1
if(not(a & 1)): a+=1

def is_prime(n):
    """
    miller rabin primality test
    """
    prime_list = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
    if n in prime_list:
        return True
    if n == 9:
        return True
    
    d = n - 1
    s = 0
    while d % 2 == 0:
        d >>= 1
        s += 1
    
    is_prime = True
    for a in prime_list:
        if a >= n: break
        if (pow(a, d, n) == 1): continue
        tmp = d
        found = False
        for r in range(s):
            if pow(a, tmp, n) == n - 1:
                found = True
                break
            tmp <<= 1
        
        if not found:
            is_prime = False
            break
    
    return is_prime
        
    

for i in range(a, b+1, 2):
    if(is_prime(i)):
        print(i, end=' ')