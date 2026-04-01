#include <iostream>
#include <cmath>
using namespace std;

// Définition de la classe
class Emprunt {
private:
    float capital;
    float tauxAnnuel;
    int nbAn;

    float tauxMensuel;
    int nbMois;
    float mensualite;

public:
    // Méthode pour saisir les données
    void saisirDonnees() {
        cout << "Montant du capital emprunte : ";
        cin >> capital;

        cout << "Nombre d'annees : ";
        cin >> nbAn;

        cout << "Taux annuel (exemple 5.5%) : ";
        cin >> tauxAnnuel;
    }

    // Méthode de calcul
    void calculerMensualite() {
        float calcul1, calcul2, calcul3;

        nbMois = nbAn * 12;
        tauxMensuel = (tauxAnnuel / 100) / 12;

        calcul1 = capital * tauxMensuel;
        calcul2 = pow(1 + tauxMensuel, nbMois);
        calcul3 = calcul2 - 1;

        mensualite = calcul1 * (calcul2 / calcul3);
    }

    // Méthode d'affichage
    void afficherResultat() {
        cout << "Mensualite : " << mensualite << endl;
    }
};

// Programme principal
int main() {
    Emprunt e;

    e.saisirDonnees();
    e.calculerMensualite();
    e.afficherResultat();

    return 0;
}
