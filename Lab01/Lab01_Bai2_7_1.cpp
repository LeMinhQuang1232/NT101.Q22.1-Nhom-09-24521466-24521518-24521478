#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

void NhanVectorVoiMatran(string& ciphertext, vector<int> tmp, vector<vector<int>> K, int n)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = 0; j < n; j++)
        {
            sum += tmp[j] * K[i][j];
        }
        sum %= 26;
        if (sum == 0) sum = 26;
        ciphertext += char(sum + 'A' - 1);
    }
}

int main()
{
    int n;
    cout << "Nhap kich thuoc ma tran khoa n x n: ";
    cin >> n;

    cout << "Nhap ma tran khoa:\n";
    vector<vector<int>> K(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            K[i][j] = toupper(c) - 'A' + 1;
        }
    }

    string plaintext;
    cout << "Nhap plaintext: ";
    cin.ignore();
    getline(cin, plaintext);
    string rs = "";
    for (char c : plaintext)
    {
        if (isalpha(c))
            rs += toupper(c);
    }
    while (rs.size() % n != 0)
        rs += 'Z';
    vector<int> p(rs.size());
    for (int i = 0; i < rs.size(); i++)
        p[i] = rs[i] - 'A' + 1;

    vector<int> tmp;
    string ciphertext = "";
    int dem = 0;
    for (int i = 0; i < p.size(); i++)
    {
        tmp.push_back(p[i]);
        dem++;

        if (dem == n)
        {
            NhanVectorVoiMatran(ciphertext, tmp, K, n);
            tmp.clear();
            dem = 0;
        }
    }

    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}