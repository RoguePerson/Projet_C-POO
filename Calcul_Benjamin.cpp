#include <iostream>
#include <cmath>

int main() {
    double pret;
    double tauxAnnuel, tauxMensuel;
    int dureeMois;
    double mensualite;

    std::cout << "Pret demander : ";
    std::cin >> pret;

    std::cout << "Taux d'interet annuel (%): ";
    std::cin >> tauxAnnuel;

    std::cout << "Duree du pret (en mois) : ";
    std::cin >> dureeMois;

    // Calcul du taux mensuel
    tauxMensuel = (tauxAnnuel / 100.0) / 12.0;

    // Formule de mensualité
    mensualite = pret * (tauxMensuel / (1 - std::pow(1 + tauxMensuel, -dureeMois)));

    std::cout << "\n--- RESULTATS ---\n";
    std::cout << "Capital emprunte : " << pret << " euros\n";
    std::cout << "Remboursement par mois : " << mensualite << " euros\n";

    return 0;
}
