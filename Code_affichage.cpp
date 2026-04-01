#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Fonction utilitaire
string repeat(char c, int n) {
    return string(n, c);
}

int main() {
    // -----------------------------
    // EXEMPLES DE DONNÉES (à remplacer)
    // -----------------------------
    vector<string> banques = {"Banque1", "Banque2"};
    vector<double> taux = {1.5, 2.0};
    vector<int> durees = {10, 15, 20};

    // resultats[taux][banque][duree]
    vector<vector<vector<double>>> resultats = {
        { {100, 120, 140}, {110, 130, 150} },
        { {200, 230, 260}, {210, 240, 270} }
    };

    int colWidth = 15;
    int nbBanques = banques.size();

    // -----------------------------
    // LIGNE DU HAUT
    // -----------------------------
    cout << " " << repeat('_', (nbBanques + 1) * (colWidth + 1)) << "\n";

    // -----------------------------
    // LIGNE DES BANQUES
    // -----------------------------
    cout << "|" << setw(colWidth) << left << "Banque";
    for (auto &b : banques)
        cout << "|" << setw(colWidth) << left << b;
    cout << "|\n";

    cout << "|" << repeat('_', colWidth);
    for (int i = 0; i < nbBanques; i++)
        cout << "|" << repeat('_', colWidth);
    cout << "|\n";

    // -----------------------------
    // AFFICHAGE : Taux → Durée → Résultat
    // -----------------------------
    for (int t = 0; t < taux.size(); t++) {

        for (int d = 0; d < durees.size(); d++) {

            // Ligne du taux (répété pour chaque durée)
            cout << "|" << setw(colWidth) << left << ("Taux " + to_string(t+1));
            for (int b = 0; b < nbBanques; b++)
                cout << "|" << setw(colWidth) << left << taux[t];
            cout << "|\n";

            cout << "|" << repeat('_', colWidth);
            for (int i = 0; i < nbBanques; i++)
                cout << "|" << repeat('_', colWidth);
            cout << "|\n";

            // Ligne de la durée
            cout << "|" << setw(colWidth) << left << ("Duree " + to_string(d+1));
            for (int b = 0; b < nbBanques; b++)
                cout << "|" << setw(colWidth) << left << durees[d];
            cout << "|\n";

            cout << "|" << repeat('_', colWidth);
            for (int i = 0; i < nbBanques; i++)
                cout << "|" << repeat('_', colWidth);
            cout << "|\n";

            // Ligne du résultat (CORRECTION : ajout d'un espace)
            cout << "|" << setw(colWidth) << left << "Résultat";
            for (int b = 0; b < nbBanques; b++)
                cout << "|" << setw(colWidth) << left << resultats[t][b][d];
            cout << "|\n";

            cout << "|" << repeat('_', colWidth);
            for (int i = 0; i < nbBanques; i++)
                cout << "|" << repeat('_', colWidth);
            cout << "|\n";
        }
    }

    return 0;
}
