Simulateur d'Emprunt Immobilier en C++
Description du projet

Ce projet est une application en C++ permettant de simuler un emprunt immobilier et de comparer plusieurs offres bancaires.

L'utilisateur peut :

Saisir le montant du capital emprunté.
Ajouter plusieurs banques (par exemple : BNP, LCL, Crédit Agricole).
Saisir plusieurs taux d'intérêt annuels.
Saisir plusieurs durées de remboursement (en années).
Calculer les mensualités correspondantes pour toutes les combinaisons de taux et de durées.
Générer des listes de résultats exploitables dans le programme.

L'objectif de ce projet est de manipuler les concepts fondamentaux du C++ :

Programmation orientée objet (classe Emprunt)
Utilisation de vector
Calculs mathématiques avec pow()
Structuration des données avec struct
Gestion des entrées utilisateur
Fonctionnement

Le programme utilise la formule standard de calcul des mensualités d'un prêt amortissable :

M = C × i × (1 + i)^n / ((1 + i)^n - 1)

Avec :

M : mensualité
C : capital emprunté
i : taux mensuel
n : nombre total de mensualités

Compilation
g++ -std=c++17 -o emprunt main.cpp

Exécution
Linux / macOS
./emprunt
Windows
emprunt.exe

Exemple d'utilisation
Capital : 200000
Nombre de banques : 2
Banque 1 : BNP
Banque 2 : LCL

Nombre de taux : 2
Taux 1 : 3.2
Taux 2 : 3.5

Nombre de durées : 2
Durée 1 : 20
Durée 2 : 25
Résultat du programme


[Insérer ici la sortie du programme]
Méthodes principales
saisieUtilisateur() : saisie du capital emprunté.
saisieBanque() : saisie des banques, des taux et des durées.
calculerMensualite() : calcule la mensualité.
genererListes() : retourne les listes contenant les données et les résultats.
Améliorations possibles
Associer un taux spécifique à chaque banque.
Trier les offres par mensualité croissante.
Déterminer automatiquement la meilleure offre.
Exporter les résultats au format CSV ou Excel.
Ajouter une interface graphique.
Technologies utilisées
C++17
Bibliothèque standard C++ (vector, string, cmath)
Auteur

Votre Nom

Licence

Projet réalisé dans un cadre pédagogique.
