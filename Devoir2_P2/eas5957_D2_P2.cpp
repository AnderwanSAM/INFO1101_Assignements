// eas5957_D2_P2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
using namespace std; 
/*Programmez la recherche binaire et écrivez un pilote pour tester votre fonction.
L’entête de la fonction est comme suit :
long rechercheBinaire( long T[], long debut, long fin, long cible)
Dans le cas de recherches avec réussite, la fonction retournera la position où se trouve la cible dans l’intervalle donné du tableau.
Dans le cas de recherches avec échec, la fonction retournera -1.*/

long rechercheBinaire(long T[], long debut, long fin, long cible)
{
	long Indice = 0,milieu , a = debut;
	while (debut <= fin )
	{
		milieu = ((debut + fin) / 2);
		if (T[milieu] == cible) { return (milieu-a); }
		else if (cible < T[milieu]) { fin -=1; }
		else { debut += 1; }
	}
	return -1; 
}
/*Erreurs possibles 
-la boucle tourne 1 fois de plus 
-la boucle tourne 1 fois de moins 
-la cible est absente mais la fonction renvoie un indice different de -1 
-la cible est presente mais la fonction renvoie -1
*/
long rechercheBinaire1(long T[], long debut, long fin, long cible) // la boucle tourne 1 fois de moins 
{
	long Indice = 0, milieu, a = debut;
	while ((debut) < fin)
	{
		milieu = ((debut + fin) / 2);
		if (T[milieu] == cible) { return (milieu - a); }
		else if (cible < T[milieu]) { fin -= 1; }
		else { debut += 1; }
	}
	return -1;
}
long rechercheBinaire2(long T[], long debut, long fin, long cible) // la boucle tourne 1 fois de plus 
{
	long Indice = 0, milieu, a = debut;
	while ((debut) <= fin+1)  
	{
		milieu = ((debut + fin) / 2);
		if (T[milieu] == cible) { return (milieu - a); }
		else if (cible < T[milieu]) { fin -= 1; }
		else { debut += 1; }
	}
	return -1;
}
int main()
{
	//|||||||||||||||||||||||||||||||||||||||||||||||||||||||la cible est presente ||||||||||||||||||||||||||||||||||||||||
				 /// 0 1 2 3 4 5 6 7 8 9
	long Tab[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "                                       " << "Debut des tests" << "                                       " << endl << endl;
	cout << "                                       " << " Avec  La Cible presente  " << "                            " << endl << endl;

	long frontiereGauche = 0, frontiereDroite = 9, cible1 = 6, nb_Erreurs = 0;
	                 /// [0;9]         [1;8]      [2;7]     [3;6]   [4;5]            |||les intervalles |||
	long Reponse[5] = { 5        ,     4,        3,         2     ,  1 };
	for (long i = 0; frontiereGauche < frontiereDroite; frontiereDroite-- && frontiereGauche++)
	{
		if (rechercheBinaire(Tab, frontiereGauche, frontiereDroite, 6) != Reponse[i])
		{
			++nb_Erreurs;
			cout << endl << "Erreur detectee sur l 'intervalle : [ " << frontiereGauche << ";" << frontiereDroite << "] . Le resultat obtenu est :"
				<< rechercheBinaire(Tab, frontiereGauche, frontiereDroite, 6)
				<< "  Et le resultat attendu est  " << Reponse[i] << endl;
		}
		i += 1;
	}
	cout << endl << " fin du test 1 . " << nb_Erreurs << "  Erreurs detectees " << endl;
	if (nb_Erreurs != 0) { cout << "le test est positif " << endl; }
	else { cout << "le test est negatif " << endl; }

	//|||||||||||||||||||||la cible est absente |||||||||||||||||||||||||||||||||||||\\\
	
	cout << "                                       " << " Debut du second test : Avec la cible  absente  " << "                            " << endl << endl;
	long resultat = -1;
	frontiereGauche = 0;
	frontiereDroite = 9;
	for (frontiereGauche = 0; frontiereGauche < frontiereDroite; frontiereDroite-- && frontiereGauche++)
	{
		if (rechercheBinaire(Tab, frontiereGauche, frontiereDroite, 29) != resultat) //29 est absent du tableau 
		{

			cout << endl << "Erreur detectee sur l 'intervalle : [ " << frontiereGauche << ";" << frontiereDroite << "] . Le resultat obtenu est :"
				<< rechercheBinaire(Tab, frontiereGauche, frontiereDroite, 6)
				<< "  Et le resultat attendu est  " << resultat << endl;
			++nb_Erreurs;
		}
	}
	cout << endl << " fin du test 2 . " << nb_Erreurs << "  Erreurs detectees " << endl;
	if (nb_Erreurs != 0) { cout << "le test est positif " << endl; }
	else { cout << "le test est negatif " << endl; }

	// ||||||||||||||||||||||||||||||||| la boucle tourne le bon nombre de fois |||||||||||||||||||||||||||||||||||
	cout << "                                       " << " Debut du troisieme test : La Boucle tourne t elle correctement - A droite  " << "                            " << endl << endl;
	frontiereGauche = 0;
	frontiereDroite = 9;
	long cible3, erreurTest3=0;
	for(frontiereGauche = 0; frontiereGauche < frontiereDroite; frontiereDroite--)
	{
		cible3 = frontiereDroite + 1;
		if (rechercheBinaire(Tab, frontiereGauche, frontiereDroite, cible3) != frontiereDroite) 
		{
			++erreurTest3;
			cout << "probleme - Erreur de 1 trop tard sur l'intervalle : [ " << frontiereGauche << ";" << frontiereDroite << "] . Le resultat obtenu est :"
				<< rechercheBinaire(Tab, frontiereGauche, frontiereDroite, cible3)
				<< "  Et le resultat attendu est  " << frontiereDroite << endl;;
		}
	}
	cout << endl << " fin du test 3 . " << erreurTest3 << "  Erreurs detectees " << endl;
	if (erreurTest3 != 0) { cout << "le test est positif " << endl; }
	else { cout << "le test est negatif " << endl; }

	cout << "                                       " << " Debut du quatrieme test : La Boucle tourne t elle correctement - A gauche    " << "                            " << endl << endl;
	frontiereGauche = 0;
	frontiereDroite = 9;
	long cible4, erreurTest4=0;
	for (frontiereGauche = 0; frontiereGauche < frontiereDroite; frontiereGauche++)
	{
		cible4 = frontiereGauche + 1;
		if (rechercheBinaire(Tab, frontiereGauche, frontiereDroite, cible4) != 0)
		{
			++erreurTest4;
			cout << "probleme - Erreur de 1 trop tard sur l'intervalle : [ " << frontiereGauche << ";" << frontiereDroite << "] . Le resultat obtenu est :"
				<< rechercheBinaire(Tab, frontiereGauche, frontiereDroite, cible4)
				<< "  Et le resultat attendu est  " << 0 << endl;;
		}
	}
	cout << endl << " fin du test 4 . " << erreurTest4 << "  Erreurs detectees " << endl;
	if (erreurTest4 != 0) { cout << "le test est positif " << endl; }
	else { cout << "le test est negatif " << endl; }





}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
