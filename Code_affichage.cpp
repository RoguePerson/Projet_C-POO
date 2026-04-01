#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ------------------------------------------------------------
// Répète un caractère n fois (pour dessiner les lignes)
// ------------------------------------------------------------
string repeat(char c, int n) {
    string result = "";
    for (int i = 0; i < n; i++) {
        result += c;
    }
    return result;
}

// ------------------------------------------------------------
// Centre un texte dans une largeur donnée
// ------------------------------------------------------------
string centerText(string text, int width) {
    int length = text.size();

    // Si le texte est plus long que la case, on le retourne tel quel
    if (length >= width) {
        return text;
    }

    int spacesTotal = width - length;
    int spacesLeft = spacesTotal / 2;
    int spacesRight = spacesTotal - spacesLeft;

    string result = "";

    // Ajouter les espaces à gauche
    for (int i = 0; i < spacesLeft; i++) {
        result += " ";
    }

    // Ajouter le texte
    result += text;

    // Ajouter les espaces à droite
    for (int i = 0; i < spacesRight; i++) {
        result += " ";
    }

    return result;
}

// ------------------------------------------------------------
// Nettoie un nombre : supprime les zéros inutiles
// ------------------------------------------------------------
string cleanNumber(double value) {
    string s = to_string(value);

    // Supprimer les zéros à la fin
    while (s.size() > 0 && s.back() == '0') {
        s.pop_back();
    }

    // Supprimer le point si plus rien après
    if (s.size() > 0 && s.back() == '.') {
        s.pop_back();
    }

    return s;
}

// ------------------------------------------------------------
// PROGRAMME PRINCIPAL
// ------------------------------------------------------------
int main() {

    // -----------------------------
    // EXEMPLES DE DONNÉES
    // -----------------------------
    vector<string> banques = {"Banque1", "Banque2"};
    vector<double> taux = {1.5, 2.0};
    vector<int> durees = {10, 15, 20};

    // resultats[taux][banque][duree]
    vector<vector<vector<double>>> resultats = {
        { {100, 120, 140}, {110, 130, 150} },
        { {200, 230, 260}, {210, 240, 270} }
    };

    int colWidth = 15;              // largeur d'une colonne
    int nbBanques = banques.size(); // nombre de banques

    // -----------------------------
    // LIGNE DU HAUT
    // -----------------------------
    cout << " " << repeat('_', (nbBanques + 1) * (colWidth + 1)) << endl;

    // -----------------------------
    // LIGNE DES BANQUES
    // -----------------------------
    cout << "|" << centerText("Banque", colWidth);

    for (int i = 0; i < nbBanques; i++) {
        cout << "|" << centerText(banques[i], colWidth);
    }
    cout << "|" << endl;

    // Ligne de séparation
    cout << "|" << repeat('_', colWidth);
    for (int i = 0; i < nbBanques; i++) {
        cout << "|" << repeat('_', colWidth);
    }
    cout << "|" << endl;

    // -----------------------------
    // AFFICHAGE DES BLOCS : Taux → Durée → Résultat
    // -----------------------------
    for (int t = 0; t < taux.size(); t++) {

        for (int d = 0; d < durees.size(); d++) {

            // -----------------------------
            // Ligne du taux
            // -----------------------------
            string texteTaux = "Taux " + to_string(t + 1);
            cout << "|" << centerText(texteTaux, colWidth);

            for (int b = 0; b < nbBanques; b++) {
                string tauxNettoye = cleanNumber(taux[t]);
                cout << "|" << centerText(tauxNettoye, colWidth);
            }
            cout << "|" << endl;

            // Ligne de séparation
            cout << "|" << repeat('_', colWidth);
            for (int i = 0; i < nbBanques; i++) {
                cout << "|" << repeat('_', colWidth);
            }
            cout << "|" << endl;

            // -----------------------------
            // Ligne de la durée
            // -----------------------------
            string texteDuree = "Duree " + to_string(d + 1);
            cout << "|" << centerText(texteDuree, colWidth);

            for (int b = 0; b < nbBanques; b++) {
                cout << "|" << centerText(to_string(durees[d]), colWidth);
            }
            cout << "|" << endl;

            // Ligne de séparation
            cout << "|" << repeat('_', colWidth);
            for (int i = 0; i < nbBanques; i++) {
                cout << "|" << repeat('_', colWidth);
            }
            cout << "|" << endl;

            // -----------------------------
            // Ligne du résultat
            // -----------------------------
            cout << "|" << centerText("Résultat", colWidth);

            for (int b = 0; b < nbBanques; b++) {
                string resNettoye = cleanNumber(resultats[t][b][d]);
                cout << "|" << centerText(resNettoye, colWidth);
            }
            cout << "|" << endl;

            // Ligne de séparation
            cout << "|" << repeat('_', colWidth);
            for (int i = 0; i < nbBanques; i++) {
                cout << "|" << repeat('_', colWidth);
            }
            cout << "|" << endl;
        }
    }

    return 0;
}
