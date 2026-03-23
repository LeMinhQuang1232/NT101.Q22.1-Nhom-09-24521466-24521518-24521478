
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

string cleanText(string ciphertext)
{
    string rs = "";
    for (char c : ciphertext)
    {
        if (isalpha(c))
        {
            rs += toupper(c); 
        }
    }

    return rs;
}
void findDivisors(int n, map<int, int>& counts)
{
    for (int i = 2; i <= 20; i++)
    {
        if (n % i == 0)
        {
            counts[i]++;
        }
    }
}
int kasiskiExamination(string text) {

    map<string, vector<int>> posMap;
    map<int, int> divisorCounts;
    for (int i = 0;i <= (int)text.length() - 3;i++) {

        string sub = text.substr(i, 3);

        posMap[sub].push_back(i);
    }

    for (auto const& [seq, positions] : posMap) {

        if (positions.size() > 1) {

            for (int i = 1;i < positions.size();i++) {

                int distance = positions[i] - positions[i - 1];

                findDivisors(distance, divisorCounts);
            }
        }
    }

    int bestLen = 1;
    int maxCount = 0;

    for (auto const& [len, count] : divisorCounts) {

        if (count > maxCount) {
            maxCount = count;
            bestLen = len;
        }
    }

    return bestLen;
}

double IC(string text)
{
    if (text.length() <= 1) return 0;

    vector<int> freq(26, 0);

    for (char c : text)
        freq[c - 'A']++;

    double sum = 0;
    double N = text.length();

    for (int f : freq)
        sum += f * (f - 1);

    return sum / (N * (N - 1));
}
int estimateKeyLengthIC(string text, int maxLen = 20)
{
    int bestLen = 1;
    double bestDiff = 100;

    for (int keyLen = 1; keyLen <= maxLen; keyLen++) {

        double avgIC = 0;

        for (int i = 0;i < keyLen;i++) {

            string group = "";

            for (int j = i;j < (int)text.length();j += keyLen)
                group += text[j];

            avgIC += IC(group);
        }

        avgIC /= keyLen;

        double diff = abs(avgIC - 0.0667);

        if (diff < bestDiff) {
            bestDiff = diff;
            bestLen = keyLen;
        }
    }

    return bestLen;

}
char findKeyChar(string group)
{
    int bestShift = 0;
    double bestScore = 1e9;

    double englishFreq[26] =
    {
        8.167,1.492,2.782,4.253,12.702,2.228,
        2.015,6.094,6.966,0.153,0.772,4.025,
        2.406,6.749,7.507,1.929,0.095,5.987,
        6.327,9.056,2.758,0.978,2.360,0.150,
        1.974,0.074
    };

    for (int shift = 0; shift < 26; shift++)
    {
        vector<int> freq(26, 0);

        for (char c : group)
        {
            int p = (c - 'A' - shift + 26) % 26;
            freq[p]++;
        }

        double chi = 0;
        int N = group.length();

        for (int i = 0;i < 26;i++)
        {
            double expected = englishFreq[i] * N / 100.0;
            chi += pow(freq[i] - expected, 2) / expected;
        }

        if (chi < bestScore)
        {
            bestScore = chi;
            bestShift = shift;
        }
    }

    return 'A' + bestShift;
}
string findKey(string text, int keyLen) {

    string key = "";

    for (int i = 0;i < keyLen;i++) {

        string group = "";

        for (int j = i;j < (int)text.length();j += keyLen)
            group += text[j];

        key += findKeyChar(group);
    }

    return key;
}
string decrypt(string cipher, string key) {

    string plain = "";

    for (int i = 0;i < (int)cipher.length();i++) {

        int shift = key[i % key.length()] - 'A';

        plain += (char)((cipher[i] - 'A' - shift + 26) % 26 + 'A');
    }

    return plain;
}

int main()
{
    string ciphertext;
    cout << "Nhap ciphertext:";
    getline(cin, ciphertext);
    ciphertext = cleanText(ciphertext);
    if (ciphertext.length() < 10)
    {
        cout << "Ma qua ngan! Khong the phan tich\n";
        return 0;
    }
    cout << "KET QUA PHAN TICH\n";
    int lenKasiski = kasiskiExamination(ciphertext);
    int lenIC = estimateKeyLengthIC(ciphertext);
    cout << "Do dai khoa theo Kasiski: " << lenKasiski << endl;
    cout << "Do dai khoa theo IC: " << lenIC << endl;
    int keyLen;
    cout << "Chon do dai khoa de thu: ";
    cin >> keyLen;

    string key = findKey(ciphertext, keyLen);

    cout << "Key du doan: " << key << endl;

    cout << "Plaintext: " << decrypt(ciphertext, key) << endl;

    return 0;
}