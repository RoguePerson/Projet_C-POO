#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "tableau.h"

using namespace std;

struct Resultats {
    vector<string> banques;
    vector<float> taux;
    vector<int> durees;
    vector<float> mensualites;
};

class Emprunt {
private:
    float capital;

    vector<string> banques;
    vector<float> taux;
    vector<int> durees;

public:

    void saisieUtilisateur() {
        cout << "Capital : ";
        cin >> capital;
    }

    void saisieBanque() {
        int NbBanque, NbTaux, NbDuree;

        cout << "Nombre de banques : ";
        cin >> NbBanque;

        banques.resize(NbBanque);
        for (int i = 0; i < NbBanque; i++) {
            cout << "Banque " << i + 1 << " : ";
            cin >> banques[i];
        }

        cout << "Nombre de taux : ";
        cin >> NbTaux;

        taux.resize(NbTaux);
        for (int i = 0; i < NbTaux; i++) {
            cout << "Taux " << i + 1 << " : ";
            cin >> taux[i];
        }

        cout << "Nombre de durees : ";
        cin >> NbDuree;

        durees.resize(NbDuree);
        for (int i = 0; i < NbDuree; i++) {
            cout << "Duree " << i + 1 << " : ";
            cin >> durees[i];
        }
    }

    float calculerMensualite(float tauxAnnuel, int duree) {
        int nbMois = duree * 12;
        float tauxMensuel = (tauxAnnuel / 100) / 12;

        return capital * tauxMensuel * pow(1 + tauxMensuel, nbMois)
               / (pow(1 + tauxMensuel, nbMois) - 1);
    }

    Resultats genererListes() {
        Resultats res;

        res.banques = banques;
        res.taux = taux;
        res.durees = durees;

        for (int i = 0; i < taux.size(); i++) {
            for (int j = 0; j < durees.size(); j++) {
                float m = calculerMensualite(taux[i], durees[j]);
                res.mensualites.push_back(m);
            }
        }

        return res;
    }
};

int main() {
    Emprunt e;

    e.saisieUtilisateur();
    e.saisieBanque();

    Resultats r = e.genererListes();

    string tableau = genererTableau(r.banques, r.taux, r.durees, r.mensualites);

    cout << tableau;

    return 0;
}
