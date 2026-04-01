#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <list>
#include <variant>
using namespace std;

    int NbBanque;
    int NbTaux;
    int NbDuree;

// Définition de la classe
class Emprunt {
private:
    float capital;
    float tauxAnnuel;
    int nbAn;
    string Nom;

    float tauxMensuel;
    int nbMois;
    float mensualite;

public:
    // Méthode pour saisir les données
    void saisirDonnees() {
        cout << "Nom de la banque : ";
        cin >> Nom;

        cout << "Montant du capital emprunte : ";
        cin >> capital;
        
        cout << "Nombre d'annees : ";
        cin >> nbAn;

        cout << "Taux annuel : ";
        cin >> tauxAnnuel;
    }

    // Méthode de calcul
    void calculerMensualite(float taux,float duree) {
        float calcul1, calcul2, calcul3;

        nbMois = duree * 12;
        tauxMensuel = (taux / 100) / 12;

        calcul1 = capital * tauxMensuel;
        calcul2 = pow(1 + tauxMensuel, nbMois);
        calcul3 = calcul2 - 1;

        mensualite = calcul1 * (calcul2 / calcul3);
    }

    // Méthode d'affichage
    void afficherResultat() {
        cout << "Mensualite : " << mensualite << endl;
    }
    // mettre en forme les valeurs
    void mettreEnForme(const vector<string>& TabBanque,const vector<float>& TabTaux,const vector<float>& TabDuree)
    {
        list<variant<float, string>> Tab;
        
        Tab.push_back(Nom);
         //Tab.push_back(TabBanque[i]);
        for (int i = 0; i < NbTaux; i++)
        {
        for (int j = 0; j < NbDuree; i++)
        {
            calculerMensualite(TabTaux[i],TabDuree[j]);
            Tab.push_back(TabDuree[j]);
            Tab.push_back(mensualite);
        }
        }
       
    }
    
    
    
};

// Programme principal
int main() {
    
    cout << "Rentrez le nombre de banques: ";
    cin >> NbBanque;
    
    vector<string> TabBanque(NbBanque);
    for (int i = 0; i < NbBanque; i++)
    {
        
        cout << "Rentrez le nom de la banque"<< i+1 << " : ";
        cin >> TabBanque[i];
    }
    
    cout << "Rentrez le nombre de taux: ";
    cin >> NbTaux;
    
    vector<float>TabTaux(NbTaux);
    for (int i = 0; i < NbTaux; i++)
    {
        
        cout << "Rentrez le Taux"<< i+1 << " : ";
        cin >> TabTaux[i];
    }
    
    cout << "Rentrez le nombre de banques: ";
    cin >> NbDuree;
    
    vector<float> TabDuree(NbDuree);
    for (int i = 0; i < NbDuree; i++)
    {
        
        cout << "Rentrez la duree"<< i+1 << " : ";
        cin >> TabDuree[i];
    }

    Emprunt e;

    e.saisirDonnees();

    e.afficherResultat();

    return 0;
}
