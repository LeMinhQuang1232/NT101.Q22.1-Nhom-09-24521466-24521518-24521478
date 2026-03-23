#include <iostream>
#include <string>

using namespace std;

string caesarCipher(string text, int key, bool isEncrypt) {
    string result = "";

    key = key % 26;
    if (key < 0) key += 26;

    if (!isEncrypt) {
        key = (26 - key) % 26;
    }

    for (int i = 0; i < text.length(); i++) {
        char c = text[i];

        if (isupper(c)) {
            result += char(int(c + key - 'A') % 26 + 'A');
        }
        else if (islower(c)) {
            result += char(int(c + key - 'a') % 26 + 'a');
        }
        else {
            result += c;
        }
    }

    return result;
}

int main() {
    int choice, key;
    string text;

    cout << "Chon thao tac:\n1. Ma hoa\n2. Giai ma\nLua chon cua ban: ";
    cin >> choice;

    cout << "Nhap khoa k (so nguyen): ";
    cin >> key;

    cin.ignore();
    cout << "Nhap chuoi van ban: ";
    getline(cin, text);

    bool isEncrypt = (choice == 1);
    string result = caesarCipher(text, key, isEncrypt);

    cout << "Ket qua: " << result << endl;

    return 0;
}