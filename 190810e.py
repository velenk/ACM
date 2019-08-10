def gcd(a, b):
    while(b!=0):
        a = a+b
        b = a-b
        a = a-b
        b = b%a
    return a

n = int(input())
if (n==1):
    k = int(input())
    print(float(k))
else:

    a = [0 for i in range(5005)]
    p = [0 for i in range(5005)]
    a_str = input()
    a = a_str.split(' ')
    for i in range(n):
        a[i] = int(a[i])

    sum0 = 1
    for i in range(n):
        sum0 = sum0 // gcd(sum0, a[i]) * a[i]

    for i in range(n):
        p[i] = sum0 // a[i]

    sum1 = 0
    for i in range(n):
        p[i] = pow(p[i], 1/(n-1))
        sum1 += p[i]
    
    sum2 = 0
    for i in range(n):
        sum2 += a[i]
        p[i] = p[i] * (n-1) / sum1
        sum2 -= pow(p[i], n) * a[i]

    sum2 /= n
    print(sum2)
