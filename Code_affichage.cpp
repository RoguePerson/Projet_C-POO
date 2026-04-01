#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

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
    value = round(value * 100) / 100;
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
    vector<string> banques = {"BNP", "LCL"};
    vector<double> taux = {3, 4};
    vector<int> durees = {10, 15, 20};
    double montant = 10000;

    int colWidth = 15;
    int nbBanques = banques.size();

    string tableauFinal = "";

    tableauFinal += " " + repeat('_', (nbBanques + 1) * (colWidth + 1)) + "\n";

    tableauFinal += "|" + centerText("Banque", colWidth);

    for (int i = 0; i < nbBanques; i++) {
        tableauFinal += "|" + centerText(banques[i], colWidth);
    }
    tableauFinal += "|\n";

    tableauFinal += "|" + repeat('_', colWidth);
    for (int i = 0; i < nbBanques; i++) {
        tableauFinal += "|" + repeat('_', colWidth);
    }
    tableauFinal += "|\n";

    for (int t = 0; t < taux.size(); t++) {

        for (int d = 0; d < durees.size(); d++) {

            string texteTaux = "Taux " + to_string(t + 1);
            tableauFinal += "|" + centerText(texteTaux, colWidth);

            for (int b = 0; b < nbBanques; b++) {
                string tauxNettoye = cleanNumber(taux[t]);
                tableauFinal += "|" + centerText(tauxNettoye, colWidth);
            }
            tableauFinal += "|\n";

            tableauFinal += "|" + repeat('_', colWidth);
            for (int i = 0; i < nbBanques; i++) {
                tableauFinal += "|" + repeat('_', colWidth);
            }
            tableauFinal += "|\n";

            string texteDuree = "Duree " + to_string(d + 1);
            tableauFinal += "|" + centerText(texteDuree, colWidth);

            for (int b = 0; b < nbBanques; b++) {
                tableauFinal += "|" + centerText(to_string(durees[d]), colWidth);
            }
            tableauFinal += "|\n";

            tableauFinal += "|" + repeat('_', colWidth);
            for (int i = 0; i < nbBanques; i++) {
                tableauFinal += "|" + repeat('_', colWidth);
            }
            tableauFinal += "|\n";

            tableauFinal += "|" + centerText("Résultat", colWidth);

            for (int b = 0; b < nbBanques; b++) {

                double tauxPourcent = taux[t] / 100.0;
                double dureeAnnees = durees[d] / 12.0;

                double resultat = montant * (1 + tauxPourcent * dureeAnnees);

                string resNettoye = cleanNumber(resultat);
                tableauFinal += "|" + centerText(resNettoye, colWidth);
            }
            tableauFinal += "|\n";

            tableauFinal += "|" + repeat('_', colWidth);
            for (int i = 0; i < nbBanques; i++) {
                tableauFinal += "|" + repeat('_', colWidth);
            }
            tableauFinal += "|\n";
        }
    }
    cout << tableauFinal;
    return 0;
}
