#include <iostream>
#include <iomanip>
#include <vector>

int F(int right, int subkey) {
    return (right ^ subkey) & 0x0F;
}

void feistel_round(int& L, int& R, int subkey) {
    int temp = R;
    R = L ^ F(R, subkey);
    L = temp;
}

void encrypt_and_print(int M, const std::vector<int>& subkeys) {
    int L = (M >> 4) & 0x0F;
    int R = M & 0x0F;

    std::cout << "M = 0x" << std::hex << std::uppercase << M << "\n";
    std::cout << "Round 0: L = 0x" << L << ", R = 0x" << R << "\n";

    for (size_t i = 0; i < subkeys.size(); ++i) {
        feistel_round(L, R, subkeys[i]);
        std::cout << "Round " << i + 1 << ": L = 0x" << L << ", R = 0x" << R << "\n";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> subkeys = { 0x1, 0x2, 0x3, 0x4 };

    int M1 = 0xAB;
    int M2 = 0xAC;

    encrypt_and_print(M1, subkeys);
    encrypt_and_print(M2, subkeys);

    return 0;
}