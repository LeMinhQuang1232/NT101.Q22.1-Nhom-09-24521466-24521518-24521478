#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int modInverse(int a, int m) {
    a = a % m;
    if (a < 0) a += m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1; 
}

void getCofactor(const vector<vector<int>>& mat, vector<vector<int>>& temp, int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinantOfMatrix(const vector<vector<int>>& mat, int n) {
    if (n == 1) return mat[0][0];
    int D = 0;
    vector<vector<int>> temp(n, vector<int>(n));
    int sign = 1;
    for (int f = 0; f < n; f++) {
        getCofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f] * determinantOfMatrix(temp, n - 1);
        sign = -sign;
    }
    return D;
}

void adjoint(const vector<vector<int>>& mat, vector<vector<int>>& adj, int n) {
    if (n == 1) {
        adj[0][0] = 1;
        return;
    }
    int sign = 1;
    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            getCofactor(mat, temp, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign * determinantOfMatrix(temp, n - 1)); 
        }
    }
}

bool getInverseMatrix(const vector<vector<int>>& mat, vector<vector<int>>& inv, int n) {
    int det = determinantOfMatrix(mat, n);
    det = det % 26;
    if (det < 0) det += 26;

    int invDet = modInverse(det, 26);
    if (invDet == -1) {
        cout << "Loi: Ma tran khoa khong kha nghich trong modulo 26. Khong the giai ma!" << endl;
        return false;
    }

    vector<vector<int>> adj(n, vector<int>(n));
    adjoint(mat, adj, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = adj[i][j] % 26;
            if (val < 0) val += 26;
            inv[i][j] = (val * invDet) % 26;
        }
    }
    return true;
}

void NhanVectorVoiMatran(string& result_text, const vector<int>& block, const vector<vector<int>>& Matrix, int n) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += block[j] * Matrix[i][j];
        }
        sum %= 26;
        if (sum == 0) sum = 26; 
        result_text += char(sum + 'A' - 1);
    }
}

int main() {
    int n;
    cout << "Nhap kich thuoc ma tran khoa n x n: ";
    if (!(cin >> n)) return 0;
    cout << "Nhap ma tran khoa (dang chu cai, giong nhu luc ma hoa):\n";
    vector<vector<int>> K(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            K[i][j] = toupper(c) - 'A' + 1;
        }
    }
    vector<vector<int>> K_Inverse(n, vector<int>(n));
    if (!getInverseMatrix(K, K_Inverse, n)) {
        return 1; 
    }

    string ciphertext;
    cout << "Nhap Ciphertext can giai ma: ";
    cin.ignore(1000, '\n');
    getline(cin, ciphertext);
    string clean_cipher = "";
    for (char c : ciphertext) {
        if (isalpha(c)) clean_cipher += toupper(c);
    }
    vector<int> c_nums(clean_cipher.size());
    for (int i = 0; i < clean_cipher.size(); i++) {
        c_nums[i] = clean_cipher[i] - 'A' + 1;
    }

    string plaintext = "";

    for (int i = 0; i < c_nums.size(); i += n) {
        vector<int> block;
        for (int j = 0; j < n; j++) {
            block.push_back(c_nums[i + j]);
        }
        NhanVectorVoiMatran(plaintext, block, K_Inverse, n);
    }

    cout << "Ciphertext ban dau : " << clean_cipher << endl;
    cout << "Plaintext (Giai ma): " << plaintext << endl;

    return 0;
}