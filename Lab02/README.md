# Lab 02: Mật mã học hiện đại (Modern Cryptography)

## 1. Mục tiêu
Lab 02 tập trung vào việc tìm hiểu và thực hành các khái niệm trong mật mã học hiện đại, bao gồm hệ mật mã khóa đối xứng, các chế độ mã hóa khối và các cơ sở toán học cơ bản cho hệ mật mã khóa công khai

Mục tiêu chính là nắm vững:
- **Cấu trúc mạng mã hóa:** hiểu và triển khai nguyên lý mạng Feistel
- **Tiêu chuẩn mã hóa khối (AES & DES):** áp dụng các thư viện mật mã để mã hóa/giải mã, đồng thời phân tích sự khác biệt giữa các chế độ hoạt động (ECB, CBC, CTR)
- **Tính chất an toàn của hệ mã:** phân tích và đo lường Hiệu ứng tuyết lở (Avalanche Effect) và sự lan truyền lỗi (Error Propagation) trong mã hóa khối
- **Cơ sở toán học:** tự tay lập trình các thuật toán toán học làm nền tảng cho mật mã khóa công khai như kiểm tra số nguyên tố, tìm ước chung lớn nhất (GCD), và lũy thừa modulo

## 2. Thông tin nhóm thực hiện
- **Nhóm:** 09 – NT101.Q22.1
- **Thành viên:**
  - **Lê Minh Sang (24521518):** thực hiện Câu 1, Câu 3 (33.33%)
  - **Lê Minh Quang (24521466):** thực hiện Câu 2, Câu 4 (33.33%)
  - **Phạm Phú Quang (24521478):** thực hiện Câu 5, Câu 6 (33.33%)

## 3. Nội dung chính các bài tập

### Câu 1: Mạng Feistel 
- **Mô tả:** triển khai cấu trúc mạng Feistel cơ bản bằng ngôn ngữ C++ với hàm F đơn giản, chương trình thực hiện mã hóa một bản rõ qua nhiều vòng với các khóa con cho trước
- **File mã nguồn:** `Lab02_Bai2_1.cpp`

### Câu 2: Các chế độ hoạt động của khối 
- **Mô tả:** sử dụng thuật toán AES để mã hóa một thông điệp độ dài chuẩn, đánh giá và in ra sự khác biệt của các block bản mã khi sử dụng 3 chế độ hoạt động khác nhau: ECB, CBC, và CTR
- **File mã nguồn:** `Lab02_Bai2_2.py`

### Câu 3: Hiệu ứng tuyết lở 
- **Mô tả:** thử nghiệm tính chất khuếch tán của thuật toán DES bằng cách mã hóa 2 bản rõ chỉ khác biệt nhau 1 bit (STAYHOME và STAYHOMA) bằng khóa là MSSV sau đó tính toán khoảng cách Hamming
- **File mã nguồn:** `Lab02_Bai2_3.py`

### Câu 4: Sự lan truyền lỗi
- **Mô tả:** kiểm tra mức độ ảnh hưởng của lỗi khi truyền dữ liệu bằng cách lật 1 bit trên bản mã AES, giải mã và phân tích sự lan truyền lỗi theo từng chế độ
- **File mã nguồn:** `Lab02_Bai2_4.py`

### Câu 5 & 6: Cơ sở toán học cho Mật mã khóa công khai
- **Mô tả:** triển khai các thuật toán toán học mật mã bằng Python mà không dùng thư viện có sẵn (Kiểm tra tính nguyên tố Miller-Rabin, sinh số nguyên tố lớn, thuật toán Euclid tìm GCD, thuật toán bình phương và nhân)
- **File mã nguồn:** `Lab02_Bai2_6.py`

## 4. Hướng dẫn chạy chương trình

### Yêu cầu môi trường:
- Trình biên dịch **C++** (như `g++`) cho Câu 1
- Môi trường **Python 3.x** cho các câu còn lại
- Thư viện mật mã cho Python:
  ```bash
  pip install pycryptodome
### Thực hiện
1. Đối với file C++(Lab02_Bai2_1.cpp):
  ```bash
  g++ Lab02_Bai2_1.cpp -o lab2_1
  ./lab2_1
  ```
2. Đối với các file Python (Lab02_Bai2_2.py đến Lab02_Bai2_6.py):
  ```bash
  python Lab02_Bai2_2.py
  ```
  (Thay tên file tương ứng với bài tập muốn chạy)
