// eas5957_D3_P3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
using namespace std; 

/*Programmez le Tri par Insertion et écrivez un pilote pour tester votre fonction.

L’entête de la fonction est comme suit :

void triParInsertion(long T[], long debut, long fin)

La fonction va trier en ordre croissant le contenu de l’intervalle donné du tableau.*/



bool estEnOrdre(long T[], long debut, long fin)

{

	// Démonstration d'un truc de programmation.

	// Ceci est sécuritaire car debut et fin sont passés par valeur (et non pas par référence).

	for (; debut < fin; debut++)

		if (T[debut] > T[debut + 1]) // Une paire contiguë de données est en désordre ?

			return false; // Si c'est le cas, l'intervalle n'est pas en ordre.

	return true; // Si on a complété le balayage sans problème, c'est que l'intervalle est en ordre.

}
void inserer(long T[], long debut, long fin)
{
	long k, stock;


	k = fin;
	while (debut < k && T[k - 1]>T[k])
	{
		stock = T[k]; T[k] = T[k - 1]; T[k - 1] = stock;
		k = k - 1;
	}
}
void triParInsertion(long T[], long debut, long fin)
{
	for (long k = debut + 1; k < fin + 1; k++) { inserer(T, debut, k); }
}

int main()
{
   
	cout << "********************************************************************************" << endl<<endl;

	cout << "                           Debut des Tests                                      " << endl<< endl;

	cout << "********************************************************************************" << endl<<endl;


	cout << "Test 1 : frontiere Gauche - Debut trop tot " << endl; // l'objectif ici est de savoir si le balayage et les insertions se font le bon nombre de fois - recherche d erreur par un 


	//               0   1    2   3  4  5    6  7  8  9
	long Tab[10] = { 75, 10 , 9, 12, 58, 65, 2, 9, 5, 4 };
	// on fait expres de laisser la plus grande valeur en position 0

	triParInsertion(Tab, 1, 9); 
	// et de faire commencer le travail de la fonction a partir de la position 1

	// si la fonction commence trop tot , elle trouvera la grande valeur et le tableau sera organise 
	if (estEnOrdre(Tab, 0, 9) != 0) { cout << "Positif => erreur : le balayage debut trop tot par la gauche " << endl; }
	else { cout << "Negatif " << endl; }

	cout << endl;

	cout << "********************************************************************************" << endl<< endl ;

	cout << "Test 2 : frontiere Gauche - le balayage Debute trop tard " << endl;
	//l'objectif ici est de savoir si le balayage et les insertions se font le bon nombre de fois - recherche d erreur par un 
	
	long Tab2[10]={ 7500, 10000, 9, 12, 58, 65, 2, 9, 5, 4 };
	// la plus grande valeur est sciamment en position debut 

	triParInsertion(Tab2, 1, 9);

	// si la fonction commence son balayage trop tard , elle ne verra pas la grande valeur 
	if (estEnOrdre(Tab2, 1, 9) != 1) { cout << "Positif => erreur : trop tard par la gauche " << endl; }
	else { cout << "Negatif " << endl; }

	
	cout << endl << "********************************************************************************" <<endl<< endl;

	cout << "Test 3 : frontiere Droite - le balayage se termine trop tot  " << endl;
	// l'objectif ici est de savoir si le balayage et les insertions se font le bon nombre de fois - recherche d erreur par un 

	long Tab3[10] = { 75, 1000, 9, 12, 58, 65, 2, 9, 5, 1};
	//une petite valeur (1) est place en derniere position 

	triParInsertion(Tab3, 0, 9); // on applique la fonction a tout l'intervalle

	//si le balayage se termine trop tot, la fonction ne trouvera pas le 1 et on aura alors un probleme 
	if (estEnOrdre(Tab3, 0, 9) != 1) { cout << "Positif => erreur : trop tot par la droite " << endl; }
	else { cout << "Negatif " << endl; }

	cout << endl <<  "********************************************************************************" << endl<< endl ;

	cout << "Test 4 : frontiere Droite - le balayage se termine trop tard  " << endl; 
	// l'objectif ici est de savoir si le balayage et les insertions se font le bon nombre de fois - recherche d erreur par un 
	
	long Tab4[10] = { 75, 1000, 9, 12, 58, 65, 2, 9, 5, 1 };
	//une petite valeur (1) est place en derniere position 

	triParInsertion(Tab4, 0, 8);
	// on demande a la fonction de s'arreter avant la position ou se trouve le (1)

	// si le tableau est mis  en ordre, alors le balayage se termine trop tard 
	if (estEnOrdre(Tab4, 0, 9) != 0) { cout << "Positif => erreur : trop tard par la droite " << endl; }// vrai signifierai que ca a tourne plus d'une fois
	else { cout << "Negatif " << endl; }

	cout <<endl << "********************************************************************************" <<endl << endl;

	cout << "Test 5 : Intervalles de petites tailles" << endl; 
	// l'objectif ici est de savoir si le balayage et les insertions se font correctement sur de petits intervalles et si le reste du tableau est laisse intact 

	//                0     1   2  3   4   5   6  7  8   9
	long Tab5[10] = { 75, 1000, 9, 12, 65, 58, 95, 9, 5, 1 };

	cout << endl << " Taille 1" << endl;
	triParInsertion(Tab5, 1, 2);
	if (estEnOrdre(Tab5, 1,2) != 1) { cout << "Positif => probleme avec les intervalles de taille 1 " << endl; }
	else { cout << "Negatif " << endl; }
	if (estEnOrdre(Tab5, 0, 9) != 0) { cout << "Positif => probleme --- tout le tableau a ete reorganise !!!!! " << endl; }

	cout << endl << "Taille 2 " << endl;
	triParInsertion(Tab5, 4, 6);
	if (estEnOrdre(Tab5, 4, 6) != 1) { cout << "Positif => probleme avec les intervalles de taille 2 " << endl; }
	else { cout << "Negatif " << endl; }
	if (estEnOrdre(Tab5, 0, 9) != 0) { cout << "Positif => probleme --- tout le tableau a ete reorganise !!!!! " << endl; }

	cout <<endl <<  "********************************************************************************" << endl  <<endl;

	cout << "test 6 : Intervalles de tailles  nulle " << endl;
	// l'objectif est de verifier que la fonction se comporte comme attendu face a un intervalle vide en ne touchant pas au tableau 

	long Tab6[10] = { 75, 1000, 9, 12, 65, 58, 95, 9, 5, 1 };
	triParInsertion(Tab6, 9, 1);

	if(estEnOrdre(Tab6,0,9) != 0) { cout << "Positif => probleme avec les intervalles de taille nulle " << endl; }
	else { cout << "Negatif " << endl; }
	
	long Talt [10] = { 75, 1000, 9, 12, 65, 58, 95, 9, 5, 1 };
	for (long k = 0; k < 10; k++) { if (Talt[k] != Tab6[k]) { cout << "le tableau a ete modifie " << endl; break; } }

	cout << "********************************************************************************" << endl << endl;

	cout << "                           Fin des Tests                                      " << endl << endl;

	cout << "********************************************************************************" << endl << endl;

}




