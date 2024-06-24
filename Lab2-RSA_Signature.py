import math


def power(x, y, M):

    if (y == 0):
        return 1

    p = power(x, y // 2, M) % M
    p = (p * p) % M

    if (y % 2 == 0):
        return p
    else:
        return ((x * p) % M)


def modInverse(A, M):

    g = math.gcd(A, M)

    if (g != 1):
        print("Inverse doesn't exist")
    else:
        return power(A, M - 2, M)


p = 641452276181854641108656711212426007392032535624286593352297230739655033308758795291525780661276052003446415402951276859305010843331485955731317776341
q = 550260068503913816794775756748734957217525557101277352617939473192429642846467658900405045171852174534967724674742228789190327015236678532191013890529

n = p*q
phi = (p-1) * (q-1)

val = 53453452354235252354234234235234523456243563264
e = 542909292734240323571856928357

print("e : ", e)
d = modInverse(e, n)

print("d : ", d)
m = int(input("Enter a message : "))

s = pow(m, d, n)
print("S : ", s)

mm = pow(s, e, n)
print("Sign verification : ", mm)


if mm == m:
    print("Verified")
else:
    print("Not Verified")
