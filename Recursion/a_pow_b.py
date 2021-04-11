def a_pow_b(a,b):
    if b==0:
        return 1
    return a_pow_b(a,b-1) * a

print(a_pow_b(2,2))