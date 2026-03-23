# Lab 01: Mật mã học cổ điển (Classical Cryptography)

## 1. Mục tiêu
Lab 01 tập trung vào việc tìm hiểu và triển khai các thuật toán mật mã cổ điển phổ biến, bao gồm các phương pháp thay thế và hoán vị. Mục tiêu chính là nắm vững nguyên lý hoạt động, cách triển khai mã nguồn và phương pháp thám mã đối với các hệ mã này. 

Mục tiêu chính là nắm vững:
- **Nguyên lý hoạt động:** hiểu rõ cách thức hoạt động của các hệ mã hóa
- **Cách triển khai mã nguồn:** tự tay lập trình các thuật toán bằng ngôn ngữ C++
- **Phương pháp thám mã:** cách tìm lại nội dung gốc khi không có khóa hoặc sử dụng các kỹ thuật phân tích

## 2. Thông tin nhóm thực hiện
- **Nhóm:** 09 – NT101.Q22.1
- **Thành viên:**
  - **Lê Minh Sang (24521518):** thực hiện Câu 2.1, 2.2, 2.3
  - **Lê Minh Quang (24521466):** thực hiện Câu 2.4, 2.5
  - **Phạm Phú Quang (24521478):** thực hiện Câu 2.6, 2.7

## 3. Nội dung chính các bài tập

### Câu 2.1 & 2.2: Mật mã Caesar
- **Mô tả:** triển khai thuật toán Caesar để mã hóa/giải mã dựa trên khóa $k$
- **Thám mã:** giải mã tự động bằng cách kiểm tra các từ khóa phổ biến trong tiếng Anh
- **File mã nguồn:** `Lab01_Bai2_1.cpp`, `Lab01_Bai2_2.cpp`

### Câu 2.3: Thám mã Monoalphabetic (Hill-Climbing)
- **Mô tả:** sử dụng thuật toán tối ưu cục bộ (Hill-Climbing) kết hợp với bảng Quadgrams để giải mã các văn bản bị mã hóa thay thế đơn bảng
- **File mã nguồn:** `Lab01_Bai2_3.cpp`

### Câu 2.4: Mật mã Playfair
- **Mô tả:** sử dụng ma trận 5x5 để mã hóa các cặp ký tự và xử lý các quy tắc về hàng, cột và hình chữ nhật
- **File mã nguồn:** `Lab01_Bai2_4.cpp`

### Câu 2.5: Mật mã Vigenère
- **Mô tả:** hệ mã đa bảng sử dụng một từ khóa (keyword) lặp lại để thực hiện dịch chuyển các ký tự tương ứng
- **File mã nguồn:** `Lab01_Bai2_5.cpp`

### Câu 2.6: Thám mã Vigenère
- **Mô tả:** phương pháp phân tích khoảng cách giữa các cụm ký tự lặp lại để xác định độ dài khóa và thám mã
- **File mã nguồn:** `Lab01_Bai2_6.cpp`

### Câu 2.7: Mật mã Hill
- **Mô tả:** mã hóa và giải mã dựa trên ma trận khóa $n \times n$, yêu cầu kiến thức về định thức và ma trận nghịch đảo modulo 26
- **File mã nguồn:** `Lab01_Bai2_7_1.cpp`, `Lab01_Bai2_7_2.cpp`

## 4. Hướng dẫn chạy chương trình

### Yêu cầu: trình biên dịch: `g++` hoặc các IDE hỗ trợ C++ (VSCode, CodeBlock,...)

### Thực hiện:
1. **Biên dịch file:**
   ```bash
   g++ <tên_file>.cpp -o <tên_chương_trình>
2. **Chạy chương trình:**
   ```bash
   ./<tên_file>
3. **Tương tác:** nhập dữ liệu (plaintext/ciphertext và key) theo yêu cầu hiển thị trên màn hình
