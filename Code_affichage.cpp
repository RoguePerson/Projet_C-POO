#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

string repeat(char c, int n) {
    string result = "";
    for (int i = 0; i < n; i++) {
        result += c;
    }
    return result;
}

string centerText(string text, int width) {
    int length = text.size();

    if (length >= width) {
        return text;
    }

    int spacesTotal = width - length;
    int spacesLeft = spacesTotal / 2;
    int spacesRight = spacesTotal - spacesLeft;

    string result = "";

    for (int i = 0; i < spacesLeft; i++) {
        result += " ";
    }

    result += text;

    for (int i = 0; i < spacesRight; i++) {
        result += " ";
    }

    return result;
}

string cleanNumber(double value) {
    string s = to_string(value);

    while (s.size() > 0 && s.back() == '0') {
        s.pop_back();
    }

    if (s.size() > 0 && s.back() == '.') {
        s.pop_back();
    }

    return s;
}

int main() {

    vector<string> banques = {"Banque1", "Banque2"};
    vector<double> taux = {1.5, 2.0};
    vector<int> durees = {10, 15, 20};

    vector<vector<vector<double>>> resultats = {
        { {100, 120, 140}, {110, 130, 150} },
        { {200, 230, 260}, {210, 240, 270} }
    };

    int colWidth = 15;
    int nbBanques = banques.size();

    cout << " " << repeat('_', (nbBanques + 1) * (colWidth + 1)) << endl;

    cout << "|" << centerText("Banque", colWidth);

    for (int i = 0; i < nbBanques; i++) {
        cout << "|" << centerText(banques[i], colWidth);
    }
    cout << "|" << endl;

    cout << "|" << repeat('_', colWidth);
    for (int i = 0; i < nbBanques; i++) {
        cout << "|" << repeat('_', colWidth);
    }
    cout << "|" << endl;

    for (int t = 0; t < taux.size(); t++) {

        for (int d = 0; d < durees.size(); d++) {

            string texteTaux = "Taux " + to_string(t + 1);
            cout << "|" << centerText(texteTaux, colWidth);

            for (int b = 0; b < nbBanques; b++) {
                string tauxNettoye = cleanNumber(taux[t]);
                cout << "|" << centerText(tauxNettoye, colWidth);
            }
            cout << "|" << endl;

            cout << "|" << repeat('_', colWidth);
            for (int i = 0; i < nbBanques; i++) {
                cout << "|" << repeat('_', colWidth);
            }
            cout << "|" << endl;

            string texteDuree = "Duree " + to_string(d + 1);
            cout << "|" << centerText(texteDuree, colWidth);

            for (int b = 0; b < nbBanques; b++) {
                cout << "|" << centerText(to_string(durees[d]), colWidth);
            }
            cout << "|" << endl;

            cout << "|" << repeat('_', colWidth);
            for (int i = 0; i < nbBanques; i++) {
                cout << "|" << repeat('_', colWidth);
            }
            cout << "|" << endl;

            cout << "|" << centerText("Résultat", colWidth);

            for (int b = 0; b < nbBanques; b++) {
                string resNettoye = cleanNumber(resultats[t][b][d]);
                cout << "|" << centerText(resNettoye, colWidth);
            }
            cout << "|" << endl;

            cout << "|" << repeat('_', colWidth);
            for (int i = 0; i < nbBanques; i++) {
                cout << "|" << repeat('_', colWidth);
            }
            cout << "|" << endl;
        }
    }
    return 0;
}
