#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string normalize(string text)
{
    string result="";

    for(char c : text)
    {
        if(isalpha(c))
            result += toupper(c);
    }

    return result;
}

string generateKey(string text, string key)
{
    key = normalize(key);

    string newKey="";
    int j=0;

    for(int i=0;i<text.length();i++)
    {
        newKey += key[j];
        j = (j+1) % key.length();
    }

    return newKey;
}

string encrypt(string text, string key)
{
    string cipher="";

    for(int i=0;i<text.length();i++)
    {
        int p = text[i]-'A';
        int k = key[i]-'A';

        char c = (p + k) % 26 + 'A';

        cipher += c;
    }

    return cipher;
}

string decrypt(string cipher, string key)
{
    string plain="";

    for(int i=0;i<cipher.length();i++)
    {
        int c = cipher[i]-'A';
        int k = key[i]-'A';

        char p = (c - k + 26) % 26 + 'A';

        plain += p;
    }

    return plain;
}

int main()
{
    string key,text;

    cout<<"Enter key: ";
    getline(cin,key);

    cout<<"1. Encrypt\n2. Decrypt\nChoice: ";
    int choice;
    cin>>choice;
    cin.ignore();

    if(choice==1)
    {
        cout<<"Enter plaintext: ";
        getline(cin,text);

        text = normalize(text);

        string newKey = generateKey(text,key);

        string cipher = encrypt(text,newKey);

        cout<<"\nGenerated key: "<<newKey<<endl;
        cout<<"Ciphertext: "<<cipher<<endl;
    }
    else
    {
        cout<<"Enter ciphertext: ";
        getline(cin,text);

        text = normalize(text);

        string newKey = generateKey(text,key);

        string plain = decrypt(text,newKey);

        cout<<"\nGenerated key: "<<newKey<<endl;
        cout<<"Plaintext: "<<plain<<endl;
    }

    return 0;
}
