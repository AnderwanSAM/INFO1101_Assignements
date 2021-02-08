// eas5957_D3_P2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
using namespace std; 

/*Programmez le Tri à Bulles et écrivez un pilote pour tester votre fonction.

L’entête de la fonction est comme suit :

void triABulles(long T[], long debut, long fin)

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

long Bulles(long T[], long debut, long fin)
{
	bool echange = false;
	long stock; // une variable ''intermediaire'' pour stocker une des valeurs lors de l'echange 
	for (long k = debut + 1; k < fin + 1; k++)
	{
		if (T[k - 1] > T[k])
		{
			echange = true;
			stock = T[k - 1]; T[k - 1] = T[k]; T[k] = stock; return echange;
		}
	}
}
void triABulles(long T[], long debut, long fin)
{
	/*long k;
	k = fin;
	while (Bulles(T, debut, k)!=0) { k = k - 1; }*/
	
	long stock; // une variable ''intermediaire'' pour stocker une des valeurs lors de l'echange 
	for (long i = fin ;i>debut;i--) // pour balayer l'intervalles le (nombre d'elements-1) fois ---rendu a ce niveau , la premiere valeur est forcement la plus petite  
	{
		for (long k = debut + 1; k <= fin; k++) // balayage
		{
			if (T[k - 1] > T[k]) { stock = T[k - 1]; T[k - 1] = T[k]; T[k] = stock; }//
		}
	}
}

int main()
{

	cout << "********************************************************************************" << endl<<endl ;


	cout << "Debut des Tests" << endl<<endl;


	cout << "********************************************************************************" << endl<<endl;


	cout << "Test 1 : frontiere Gauche - Debut trop tot " << endl; // recherche d'erreur par un 

	//               0   1    2   3  4  5    6  7  8  9
	long Tab[10] = { 75, 10 , 9, 12, 58, 65, 2, 9, 5, 4 };
	// on fait expres de laisser la plus grande valeur en position 0 et on fait commencer la fonction a la position 1

	triABulles(Tab, 1, 9);

	// ensuite on fait evaluer le tableau de 0 a 9 ; si le tableau a ete mis en ordre , alors  la fonction a detecte la grande valeur (on  a un probleme ) 
	if (estEnOrdre(Tab, 0, 9) != 0) { cout << "Positif => erreur : le balayage debut trop tot par la gauche " << endl; }
	else { cout << "Negatif " << endl; }

	cout << endl;

	cout << "********************************************************************************" << endl<< endl;

	cout << "Test 2 : frontiere Gauche - le balayage Debute trop tard " << endl;// recherche d'erreur par un

	long Tab2[10] = { 7500, 10000, 9, 12, 58, 65, 2, 9, 5, 4 };
	// on fait laisse la plus grande valeur en position 1 et on fait commencer la fonction a cette position 

	triABulles(Tab2, 1, 9);

	// // ensuite on fait evaluer le tableau de 1 a 9 ; si le tableau n'a pas  ete mis en ordre , alors  la fonction n'a pas  detecte la grande valeur (on  a un probleme ) 
	if (estEnOrdre(Tab2, 1, 9) != 1) { cout << "Positif => erreur : trop tard par la gauche " << endl; }
	else { cout << "Negatif " << endl; }

	cout << endl;

	cout << "********************************************************************************" << endl<<endl;


	cout << "Test 3 : frontiere Droite - le balayage se termine trop tot  " << endl;


	long Tab3[10] = { 10,9,8,7,6,5,4,3,2,1 };  // on place une petite valeur en derniere position 

	triABulles(Tab3, 0, 9); // on applique la fonction sur tout l'intervalle


	// si la boucle tourne le bon nombre de fois , le 1 sera envoye en position 0 et l'evaluation sur tout l'intervalle renverra un tableau ordonné 
	if (estEnOrdre(Tab3, 0, 9) != 1) { cout << "Positif => erreur : trop tot par la droite " << endl; }
	else { cout << "Negatif " << endl; }

	cout << endl;

	cout << "********************************************************************************" << endl<< endl ;
	

	cout << "Test 4 : frontiere Droite - le balayage se termine trop tard  " << endl;

	long Tab4[10] = { 75, 1000, 9, 12, 58, 65, 2, 9, 5, 1 };   // on place une petite valeur en derniere position 
	
	triABulles(Tab4, 0, 8); // on applique la fonction sur 0 a 8
	
	// si la boucle tourne une fois de trop  , elle trouvera le 1 et le resultat  de estEnOrdre sera 1 
	// on fait evaluer tout l'intervalle 
	if (estEnOrdre(Tab4, 0, 9) != 0) { cout << "Positif => erreur : trop tard par la droite " << endl; }// vrai signifierai que ca a tourne plus d'une fois
	else { cout << "Negatif " << endl; }

	cout << endl;

	cout << "********************************************************************************" << endl;

	// l'objectif ici est de savoir si le balayage et les insertions se font correctement sur de petits intervalles et si le reste du tableau est laisse intact 
	cout << "Test 5 : Intervalles de petites tailles" << endl; 

	//                0     1   2  3   4   5   6  7  8   9
	long Tab5[10] = { 75, 1000, 9, 12, 65, 58, 95, 9, 5, 1 };

	cout << endl << " Taille 1" << endl;
	triABulles(Tab5, 1, 2); 
	if (estEnOrdre(Tab5, 1, 2) != 1) { cout << "Positif => probleme avec les intervalles de taille 1 " << endl; }
	else { cout << "Negatif " << endl; }
	if (estEnOrdre(Tab5, 0, 9) != 0) { cout << "Positif => probleme --- tout le tableau a ete reorganise !!!!! " << endl; }


	cout << endl << "Taille 2 " << endl;
	triABulles(Tab5, 4, 6);
	if (estEnOrdre(Tab5, 4, 6) != 1) { cout << "Positif => probleme avec les intervalles de taille 2 " << endl; }
	else { cout << "Negatif " << endl; }
	if (estEnOrdre(Tab5, 0, 9) != 0) { cout << "Positif => probleme --- tout le tableau a ete reorganise !!!!! " << endl; }

	cout << endl;

	cout << "********************************************************************************" << endl;

	cout << "test 6 : Intervalles de tailles  nulle " << endl;
	//l'objectif est de s'assurer du bon comportement de la fonction face a un intervalle vide 


	long Tab6[10] = { 75, 1000, 9, 12, 65, 58, 95, 9, 5, 1 };

	triABulles(Tab6, 9, 1); // fin>debut alors l'intervalle est vide 
	if (estEnOrdre(Tab6, 0, 9) != 0) { cout << "Positif => probleme avec les intervalles de taille nulle " << endl; }
	else { cout << "Negatif " << endl; }

	// ensuite on verifie que le tableau est resté intact 
	long Talt[10]= { 75, 1000, 9, 12, 65, 58, 95, 9, 5, 1 };
	
	for(long k =0 ; k < 10;k++)
		if (Talt[k]!=Tab6[k])
		{
			cout << "le tableau a ete modifié---on a un probleme " << endl; 
		}
	
	cout << endl;

	cout << "********************************************************************************" << endl;

	cout << "Fin des tests" << endl  << endl;

	cout << "********************************************************************************" << endl;
}



