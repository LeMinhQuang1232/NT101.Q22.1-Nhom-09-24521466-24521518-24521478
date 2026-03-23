#include <iostream>
#include <string>
#include <vector>

using namespace std;

string decryptCaesar(string text, int key) {
    string result = "";
    key = key % 26;

    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isupper(c)) {
            result += char((c - 'A' - key + 26) % 26 + 'A');
        }
        else if (islower(c)) {
            result += char((c - 'a' - key + 26) % 26 + 'a');
        }
        else {
            result += c;
        }
    }
    return result;
}

bool isEnglishMeaningful(const string& text) {
    string lowerText = "";
    for (char c : text) {
        lowerText += tolower(c);
    }
    vector<string> commonWords = { " the ", " and ", " is ", " in ", " a ", " to " };
    int matchCount = 0;
    for (const string& word : commonWords) {
        if (lowerText.find(word) != string::npos) {
            matchCount++;
        }
    }

    return matchCount >= 2;
}

int main() {
    string ciphertext = "Max NBM bl t extwbgz bglmbmnmbhg ngwxk OGN-AVF, lixvbtebsbgz bg max ybxew hy bgyhkftmbhg mxvaghehzr. Xlmtueblaxw pbma t fbllbhg mh yhlmxk bgghotmbhg tgw xqvxeexgvx bg BM xwnvtmbhg tgw kxlxtkva, NBM hyyxkl t pbwx ktgzx hy ngwxkzktwntmx tgw ihlmzktwntmx ikhzktfl tbfxw tm ikhwnvbgz abzaer ldbeexw ikhyxllbhgtel. Max ngboxklbmr bl kxvhzgbzxw yhk bml vnmmbgz-xwzx kxlxtkva bg tkxtl ebdx vruxklxvnkbmr, tkmbybvbte bgmxeebzxgvx, tgw lhymptkx xgzbgxxkbgz. Pbma lmtmx-hy-max-tkm ytvbebmbxl tgw t lmkhgz xfiatlbl hg vheetuhktmbhg pbma bgwnlmkr, NBM xjnbil lmnwxgml pbma uhma maxhkxmbvte dghpexwzx tgw iktvmbvte ldbeel mh makbox bg max ktibwer xoheobgz mxva bgwnlmkr.";

    bool found = false;

    for (int k = 1; k <= 25; k++) {
        string decryptedText = decryptCaesar(ciphertext, k);

        if (isEnglishMeaningful(decryptedText)) {
            cout << "k = " << k << endl;
            cout << "plaintext: \n" << decryptedText << endl;
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "Khong the tim thay ban ro co nghia tieng Anh!" << endl;
    }

    return 0;
}