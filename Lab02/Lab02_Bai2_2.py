from Crypto.Cipher import AES
from Crypto.Util import Counter

key = b'1234567890123456'  
plaintext = b"UIT_LAB_UIT_LAB_UIT_LAB_UIT_LAB_" 
iv = b'0000000000000000'   

cipher_ecb = AES.new(key, AES.MODE_ECB)
ct_ecb = cipher_ecb.encrypt(plaintext)

cipher_cbc = AES.new(key, AES.MODE_CBC, iv=iv)
ct_cbc = cipher_cbc.encrypt(plaintext)

ctr = Counter.new(128)
cipher_ctr = AES.new(key, AES.MODE_CTR, counter=ctr)
ct_ctr = cipher_ctr.encrypt(plaintext)

def print_blocks(name, ciphertext):
    print(f"--- {name} ---")
    chunks = [ciphertext.hex()[i:i+32] for i in range(0, len(ciphertext.hex()), 32)]
    for idx, chunk in enumerate(chunks):
        print(f"Block {idx+1}: {chunk}")
    print()

print_blocks("AES-ECB", ct_ecb)
print_blocks("AES-CBC", ct_cbc)
print_blocks("AES-CTR", ct_ctr)