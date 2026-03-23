#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;

string normalizeText(const string& text) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            result += toupper(c);
        }
    }
    return result;
}

map<string, double> loadQuadgrams(const string& filename) {
    map<string, double> quadgrams;
    ifstream file(filename);
    string ngram;
    long long count;
    long long totalCount = 0;

    quadgrams["TION"] = -2.5; quadgrams["NTHE"] = -2.7;
    quadgrams["THER"] = -2.8; quadgrams["THAT"] = -2.9;
    return quadgrams;
}


double calculateFitness(const string& text, const map<string, double>& quadgrams) {
    double score = 0.0;
    double floorScore = -10.0; 

    for (size_t i = 0; i < text.length() - 3; i++) {
        string quad = text.substr(i, 4);
        if (quadgrams.count(quad)) {
            score += quadgrams.at(quad);
        }
        else {
            score += floorScore;
        }
    }
    return score;
}

string decrypt(const string& text, const string& key) {
    string result = "";
    for (char c : text) {
        result += key[c - 'A'];
    }
    return result;
}

pair<string, string> hillClimbing(const string& ciphertext, const map<string, double>& quadgrams) {
    string parentKey = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    random_device rd;
    mt19937 g(rd());
    shuffle(parentKey.begin(), parentKey.end(), g);

    string parentText = decrypt(ciphertext, parentKey);
    double parentScore = calculateFitness(parentText, quadgrams);

    int maxIterations = 1000;
    int noImprovementCount = 0;

    while (noImprovementCount < maxIterations) {
        string childKey = parentKey;
        
        int a = g() % 26;
        int b = g() % 26;
        swap(childKey[a], childKey[b]);

        string childText = decrypt(ciphertext, childKey);
        double childScore = calculateFitness(childText, quadgrams);

       
        if (childScore > parentScore) {
            parentKey = childKey;
            parentScore = childScore;
            noImprovementCount = 0; 
        }
        else {
            noImprovementCount++;
        }
    }
    return { parentKey, parentText };
}

int main() {
    string ciphertext = "GHVHLIIBKZGGVISVIRVSUIRGGVMYBYIRGRSHLFGHZIQPIZUORMT..."; 
    ciphertext = normalizeText(ciphertext);

    map<string, double> quadgrams = loadQuadgrams("english_quadgrams.txt");

    int restarts = 10; 
    double bestOverallScore = -1e9;
    string bestOverallKey = "";
    string bestOverallText = "";

    cout << "Dang chay thuat toan Hill-Climbing voi " << restarts << " lan khoi dong lai..." << endl;

    for (int i = 0; i < restarts; i++) {
        pair<string, string> result = hillClimbing(ciphertext, quadgrams);
        double score = calculateFitness(result.second, quadgrams);

        cout << "[Lan " << i + 1 << "] Diem: " << score << " | Khoa: " << result.first << endl;

        if (score > bestOverallScore) {
            bestOverallScore = score;
            bestOverallKey = result.first;
            bestOverallText = result.second;
        }
    }
    cout << "Khoa tim duoc: " << bestOverallKey << endl;
    cout << "Diem Fitness : " << bestOverallScore << endl;
    cout << "Ban ro (Plaintext):\n" << bestOverallText << endl;

    return 0;
}