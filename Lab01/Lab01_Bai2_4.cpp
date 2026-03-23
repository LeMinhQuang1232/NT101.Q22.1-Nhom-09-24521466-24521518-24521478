//#include <iostream>
//#include <vector>
//#include <string>
//#include <cctype>
//using namespace std;
//
//char matrix5x5[5][5];
//
//string prepareKey(string key) {
//    string result = "";
//    bool used[26] = {false};
//
//    for (char c : key) {
//        if (isalpha(c)) {
//            c = toupper(c);
//            if (c == 'J') c = 'I';
//            if (!used[c - 'A']) {
//                result += c;
//                used[c - 'A'] = true;
//            }
//        }
//    }
//
//    for (char c = 'A'; c <= 'Z'; c++) {
//        if (c == 'J') continue;
//        if (!used[c - 'A']) {
//            result += c;
//            used[c - 'A'] = true;
//        }
//    }
//
//    return result;
//}
//
//void createMatrix(string key) {
//    string full = prepareKey(key);
//    int k = 0;
//
//    for (int i = 0; i < 5; i++)
//        for (int j = 0; j < 5; j++)
//            matrix5x5[i][j] = full[k++];
//}
//
//void printMatrix() {
//    cout << "\nPlayfair Matrix:\n";
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 5; j++)
//            cout << matrix5x5[i][j] << " ";
//        cout << endl;
//    }
//}
//
//pair<int,int> findPosition(char c) {
//    if (c == 'J') c = 'I';
//
//    for (int i = 0; i < 5; i++)
//        for (int j = 0; j < 5; j++)
//            if (matrix5x5[i][j] == c)
//                return {i,j};
//
//    return {-1,-1};
//}
//
//string prepareText(string text) {
//    string clean = "";
//
//    for (char c : text) {
//        if (isalpha(c)) {
//            c = toupper(c);
//            if (c == 'J') c = 'I';
//            clean += c;
//        }
//    }
//
//    string result = "";
//    for (int i = 0; i < clean.length(); i++) {
//        char a = clean[i];
//        char b = (i + 1 < clean.length()) ? clean[i + 1] : 'X';
//
//        if (a == b) {
//            result += a;
//            result += 'X';
//        }
//        else {
//            result += a;
//            result += b;
//            i++;
//        }
//    }
//
//    if (result.length() % 2 != 0)
//        result += 'X';
//
//    return result;
//}
//
//string encrypt(string text) {
//    text = prepareText(text);
//    string cipher = "";
//
//    for (int i = 0; i < text.length(); i += 2) {
//        char a = text[i];
//        char b = text[i + 1];
//
//        auto p1 = findPosition(a);
//        auto p2 = findPosition(b);
//
//        int r1 = p1.first, c1 = p1.second;
//        int r2 = p2.first, c2 = p2.second;
//
//        if (r1 == r2) {
//            cipher += matrix5x5[r1][(c1 + 1) % 5];
//            cipher += matrix5x5[r2][(c2 + 1) % 5];
//        }
//        else if (c1 == c2) {
//            cipher += matrix5x5[(r1 + 1) % 5][c1];
//            cipher += matrix5x5[(r2 + 1) % 5][c2];
//        }
//        else {
//            cipher += matrix5x5[r1][c2];
//            cipher += matrix5x5[r2][c1];
//        }
//    }
//
//    return cipher;
//}
//
//string decrypt(string text) {
//    string plain = "";
//
//    for (int i = 0; i < text.length(); i += 2) {
//        char a = text[i];
//        char b = text[i + 1];
//
//        auto p1 = findPosition(a);
//        auto p2 = findPosition(b);
//
//        int r1 = p1.first, c1 = p1.second;
//        int r2 = p2.first, c2 = p2.second;
//
//        if (r1 == r2) {
//            plain += matrix5x5[r1][(c1 + 4) % 5];
//            plain += matrix5x5[r2][(c2 + 4) % 5];
//        }
//        else if (c1 == c2) {
//            plain += matrix5x5[(r1 + 4) % 5][c1];
//            plain += matrix5x5[(r2 + 4) % 5][c2];
//        }
//        else {
//            plain += matrix5x5[r1][c2];
//            plain += matrix5x5[r2][c1];
//        }
//    }
//
//    return plain;
//}
//
//int main() {
//    string key;
//    cout << "Enter key: ";
//    getline(cin, key);
//
//    createMatrix(key);
//    printMatrix();
//
//    int choice;
//    cout << "\n1. Encrypt\n2. Decrypt\nChoice: ";
//    cin >> choice;
//    cin.ignore();
//
//    string text;
//
//    if (choice == 1) {
//        cout << "Enter plaintext: ";
//        getline(cin, text);
//        cout << "Ciphertext: " << encrypt(text) << endl;
//    }
//    else {
//        cout << "Enter ciphertext: ";
//        getline(cin, text);
//        cout << "Plaintext: " << decrypt(text) << endl;
//    }
//
//    return 0;
//}
//












#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

char matrix5x5[5][5];

string prepareKey(string key) {
    string result = "";
    bool used[26] = {false};

    for (char c : key) {
        if (isalpha(c)) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            if (!used[c - 'A']) {
                result += c;
                used[c - 'A'] = true;
            }
        }
    }

    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue;
        if (!used[c - 'A']) {
            result += c;
            used[c - 'A'] = true;
        }
    }

    return result;
}

void createMatrix(string key) {
    string full = prepareKey(key);
    int k = 0;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matrix5x5[i][j] = full[k++];
}

void printMatrix() {
    cout << "\nPlayfair Matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << matrix5x5[i][j] << " ";
        cout << endl;
    }
}

pair<int,int> findPosition(char c) {
    if (c == 'J') c = 'I';

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix5x5[i][j] == c)
                return {i,j};

    return {-1,-1};
}

string prepareText(string text) {
    string clean = "";

    for (char c : text) {
        if (isalpha(c)) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            clean += c;
        }
    }

    string result = "";
    for (int i = 0; i < clean.length(); i++) {
        char a = clean[i];
        char b = (i + 1 < clean.length()) ? clean[i + 1] : 'X';

        if (a == b) {
            result += a;
            result += 'X';
        }
        else {
            result += a;
            result += b;
            i++;
        }
    }

    if (result.length() % 2 != 0)
        result += 'X';

    return result;
}

string encrypt(string text) {
    text = prepareText(text);
    string cipher = "";

    for (int i = 0; i < text.length(); i += 2) {
        char a = text[i];
        char b = text[i + 1];

        auto p1 = findPosition(a);
        auto p2 = findPosition(b);

        int r1 = p1.first, c1 = p1.second;
        int r2 = p2.first, c2 = p2.second;

        if (r1 == r2) {
            cipher += matrix5x5[r1][(c1 + 1) % 5];
            cipher += matrix5x5[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2) {
            cipher += matrix5x5[(r1 + 1) % 5][c1];
            cipher += matrix5x5[(r2 + 1) % 5][c2];
        }
        else {
            cipher += matrix5x5[r1][c2];
            cipher += matrix5x5[r2][c1];
        }
    }

    return cipher;
}

string decrypt(string text) {
    string plain = "";

    for (int i = 0; i < text.length(); i += 2) {
        char a = text[i];
        char b = text[i + 1];

        auto p1 = findPosition(a);
        auto p2 = findPosition(b);

        int r1 = p1.first, c1 = p1.second;
        int r2 = p2.first, c2 = p2.second;

        if (r1 == r2) {
            plain += matrix5x5[r1][(c1 + 4) % 5];
            plain += matrix5x5[r2][(c2 + 4) % 5];
        }
        else if (c1 == c2) {
            plain += matrix5x5[(r1 + 4) % 5][c1];
            plain += matrix5x5[(r2 + 4) % 5][c2];
        }
        else {
            plain += matrix5x5[r1][c2];
            plain += matrix5x5[r2][c1];
        }
    }

    return plain;
}

string removeX(string text) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        if (i > 0 && i < text.length() - 1) {
            if (text[i] == 'X' && text[i - 1] == text[i + 1])
                continue;
        }
        result += text[i];
    }

    if (!result.empty() && result.back() == 'X')
        result.pop_back();

    return result;
}

int main() {
    string key;
    cout << "Enter key: ";
    getline(cin, key);

    createMatrix(key);
    printMatrix();

    int choice;
    cout << "\n1. Encrypt\n2. Decrypt\nChoice: ";
    cin >> choice;
    cin.ignore();

    string text;

    if (choice == 1) {
        cout << "Enter plaintext: ";
        getline(cin, text);
        cout << "Ciphertext: " << encrypt(text) << endl;
    }
    else {
        cout << "Enter ciphertext: ";
        getline(cin, text);

        string plain = decrypt(text);
        plain = removeX(plain);

        cout << "Plaintext: " << plain << endl;
    }

    return 0;
}
