def gcd(aa, bb):
    while(bb):
        aa = aa + bb
        bb = aa - bb
        aa = aa - bb
        bb = bb % aa
    return aa
def lcm(aaa, bbb):
    return aaa // gcd(aaa, bbb) * bbb
x = 0
y = 0
a = [0 for i in range(150)]
b = [0 for i in range(150)]

def exgcd(al, bl):
    global x
    global y
    if(bl == 0):
        x = 1
        y = 0
        return al
    r = exgcd(bl, al%bl)
    temp = y
    y = x - (al//bl) * y
    x = temp
#     print(x)
    return r

def excrt(n):
    global x
    M = a[1]
    res = b[1] % a[1]
    for i in range(2, n+1):
        d = exgcd(M, a[i])
        t = x
        c = b[i] - (res % a[i]) + a[i]
#         print(x)
        c = c % a[i]
#         print("t: ", t)
        if(c % d):
            return -1
        
        t = (t * (c // d)) % a[i]
        res += (t * M)
        M = lcm(M, a[i])
        res = (res % M + M) % M
#         print("M: ", M)
#         print("res: ", res)
#         print("t: ", t)
    return (res % M + M) % M
    
nm_str = input()
nm_str = nm_str.split(' ')
n = int(nm_str[0])
m = int(nm_str[1])
for i in range(1, n+1):
    ab_str = input()
    ab_str = ab_str.split(' ')
    a[i] = int(ab_str[0])
    b[i] = int(ab_str[1])
ans = excrt(n)
if(ans == -1):
    print("he was definitely lying")
elif(ans > m):
    print("he was probably lying")
else:
    print(ans)
