import random
import math

def is_prime(n, k=5):
    if n < 2:
        return False
    if n in (2, 3):
        return True
    if n % 2 == 0:
        return False
    d = n - 1
    s = 0
    while d % 2 == 0:
        d //= 2
        s += 1

    for _ in range(k):
        a = random.randrange(2, n - 1)
        x = pow(a, d, n)

        if x == 1 or x == n - 1:
            continue

        for _ in range(s - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False

    return True

def generate_prime(bits):
    while True:
        n = random.getrandbits(bits)
        n |= 1  
        n |= (1 << (bits - 1))  

        if is_prime(n):
            return n

def top_10_primes_below_mersenne():
    M10 = (1 << 89) - 1  
    result = []
    n = M10 - 2  
    while len(result) < 10:
        if is_prime(n):
            result.append(n)
        n -= 2 

    return result

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def mod_exp(a, x, p):
    return pow(a, x, p)  

if __name__ == "__main__":
    print("Tạo ra một số nguyên tố ngẫu nhiên có 8 bits, 16 bits, 64 bits")
    print("8-bit prime :", generate_prime(8))
    print("16-bit prime:", generate_prime(16))
    print("64-bit prime:", generate_prime(64))

    print("\nXác định 10 số nguyên tố lớn nhất nhỏ hơn số nguyên tố Mersenne thứ 10")
    primes = top_10_primes_below_mersenne()
    for p in primes:
        print(p)

    print("\nKiểm tra số nguyên có phải số nguyên tố hay không")
    try:
        n = int(input("Nhập n: "))
        print("Là số nguyên tố" if is_prime(n) else "Không phải số nguyên tố")
    except ValueError:
        print("Vui lòng nhập số nguyên tố hợp lệ")

    print("\nTìm ước chung lớn nhất giứa hai số nguyên")
    try:
        a = int(input("Nhập a: "))
        b = int(input("Nhập b: "))
        print("GCD =", gcd(a, b))
    except ValueError:
         print("Vui lòng nhập số nguyên hợp lệ.")

    print("\nTính lũy thừa theo modulo a^x % p")
    try:
        a = int(input("Nhập a: "))
        x = int(input("Nhập x: "))
        p = int(input("Nhập p: "))
        print("a^x mod p =", mod_exp(a, x, p))
    except ValueError:
         print("Vui lòng nhập số nguyên hợp lệ")