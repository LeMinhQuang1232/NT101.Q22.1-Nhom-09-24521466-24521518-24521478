from Crypto.Cipher import DES
def bytes_to_bin_string(data):
    bin_str = bin(int.from_bytes(data, 'big'))[2:]
    return bin_str.zfill(64)

def calculate_hamming_distance(bin1, bin2):
    return sum(b1 != b2 for b1, b2 in zip(bin1, bin2))

def evaluate_avalanche(student_id):
    key_bytes = student_id.ljust(8, '0').encode('utf-8')[:8]
    
    cipher = DES.new(key_bytes, DES.MODE_ECB)
    
    pt1 = b"STAYHOME"
    pt2 = b"STAYHOMA"
    
    ct1 = cipher.encrypt(pt1)
    ct2 = cipher.encrypt(pt2)
    
    bin1 = bytes_to_bin_string(ct1)
    bin2 = bytes_to_bin_string(ct2)
    
    distance = calculate_hamming_distance(bin1, bin2)
    percentage = (distance / 64) * 100
    
    
    
    
    
    print(f"MSSV (Key)      : {student_id} (Dạng bytes: {key_bytes})")
    print(f"    Bản mã 1 (bin)  : {bin1}")
    print(f"    Bản mã 2 (bin)  : {bin2}")
    print(f"    Hamming Distance: {distance} bits")
    print(f"    Tỷ lệ thay đổi  : {percentage:.2f}%\n")
if __name__ == "__main__":
    danh_sach_mssv = ["24521518", "24521466", "24521478"]
    for mssv in danh_sach_mssv:
        evaluate_avalanche(mssv)