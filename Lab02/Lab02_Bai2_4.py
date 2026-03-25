from Crypto.Cipher import AES
import os

def flip_bit(data, byte_index):
    list_data = list(data)
    list_data[byte_index] = list_data[byte_index] ^ 0x01 
    return bytes(list_data)

def run_experiment(mode_name, mode_type):
    print(f"\n--- Che do: {mode_name} ---")
    plaintext = b"A" * 1008 
    key = b'1234567890123456'
    iv = b'0' * 16 
    
    if mode_name == "ECB":
        cipher_enc = AES.new(key, mode_type)
    else:
        cipher_enc = AES.new(key, mode_type, iv=iv)
    ciphertext = cipher_enc.encrypt(plaintext)
    corrupted_ct = flip_bit(ciphertext, 25)
    
    if mode_name == "ECB":
        cipher_dec = AES.new(key, mode_type)
    else:
        cipher_dec = AES.new(key, mode_type, iv=iv)
    decrypted = cipher_dec.decrypt(corrupted_ct)
    
    block_size = 16
    for i in range(0, 80, block_size): 
        original_block = plaintext[i:i+block_size]
        decrypted_block = decrypted[i:i+block_size]
        
        if original_block == decrypted_block:
            status = "OK"
        else:
            diff_count = sum(1 for a, b in zip(original_block, decrypted_block) if a != b)
            status = f"BI HONG ({diff_count}/{block_size} bytes sai)"
            
        print(f"Khoi {i//block_size + 1} (bytes {i:2}-{i+15:2}): {status}")

run_experiment("ECB", AES.MODE_ECB)
run_experiment("CBC", AES.MODE_CBC)
run_experiment("CFB", AES.MODE_CFB)
run_experiment("OFB", AES.MODE_OFB)