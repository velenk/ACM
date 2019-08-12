def gcd(a0, b0):
    while(b0!=0):
        a0 = a0+b0
        b0 = a0-b0
        a0 = a0-b0
        b0 = b0%a0
    return a0


n = int(input())
n0 = n
if (n==1):
    k = int(input())
    print(float(k))
else:

    a = [0 for i in range(5050)]
    a_str = input()
    a = a_str.split(' ')
    for i in range(n):
        a[i] = int(a[i])

    a.sort(reverse=True)
    
    sum0 = 1000
        
    p = [0 for i in range(5050)]
    
    while(n>1):

        for i in range(n):
            p[i] = sum0 / a[i]

        sum1 = 0
        flag = 0
        for i in range(n):
            p[i] = pow(p[i], 1/(n0-1))
            sum1 += p[i]
            
        
        sum2 = 0
        for i in range(n):
            sum2 += a[i]
            p[i] = p[i] * (n-1) / sum1
            if (p[i] > 1):
                flag = 1
            sum2 -= pow(p[i], n0) * a[i]

        if (flag == 0):
            break
        for i in range(n-1, 0, -1):
            if (p[i] > 1):
                n -= 1
            else:
                break
    
    print('{0:.12f}'.format(sum2/n0))
