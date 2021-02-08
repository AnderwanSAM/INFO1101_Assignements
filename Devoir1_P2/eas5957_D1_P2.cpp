// eas5957_D1_P2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
using namespace std; 
int main()
{
	// Declaration des variables
	short D;
	float Mp, Ti, Interet , an;
	
	// Recueil des donnees 
    cout << "Bonjour . Veuillez entrez le montant << principal >> investit :"; 
	cin >> Mp;
	cout << endl <<" A quel taux d interet evolue t il ? :";
	cin >> Ti;
	cout << endl << " Sur quelle duree voulez vous avoir le bilan du rendement de votre Certificat a intert Garanti ? :";
	cin >> D;
	Interet = Mp * Ti / 100;
	cout << endl << "Annee" << "      " << "Interet recu" << "      " << "Valeur actuelle du certificat" << endl;
	an = 1;
	Mp = Interet + Mp;
	for (int i = 1; i <= D; i++) {
	cout << an; cout << "           " << Interet << "        " << Mp << endl;
	Mp = Mp + Interet; 
	Interet = Mp * Ti / 100;
	Mp = Mp + Interet;
	an = an + 1; }
	cout << endl;
	cout << " essai ";

}