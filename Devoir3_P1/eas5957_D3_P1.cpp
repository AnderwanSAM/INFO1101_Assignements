// eas5957_D3_P1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
using namespace std;

/* Erreurs potentielles
-la fonction retourne des valeurs desordonnees
-des valeurs du tableau sont absentes (au cas ou la fonction recupere d'autres valeurs de la memoire )
-le balayage se termine trop tot
-le balayage se termine trop tard
-le balayage commence trop tot
-le balayage s'arrete trop tot
-la fonction modifie le tableau pour un intervalle vide
-la fonction n est pas adapte pour les intervalles de petite tailles
*/
void echange(long a, long b) { long c; c = a; a = b; b = c; }
long presence(long T[], long debut, long fin, long cible) // fonction pour le test 
{ 
	/*l'objectif de cette fonction est de verifier que le tableau 
	contient les memes elements 
	avant et apres le passage de la fonction triParSelection*/

	for (long K = debut; K <= fin; K++)
		if (T[K] == cible)
			return 1;
	return -1;
}

bool estEnOrdre(long T[], long debut, long fin) // fonction pour le test 
{

	// Démonstration d'un truc de programmation.

	// Ceci est sécuritaire car debut et fin sont passés par valeur (et non pas par référence).

	for (; debut < fin; debut++)

		if (T[debut] > T[debut + 1]) // Une paire contiguë de données est en désordre ?

			return false; // Si c'est le cas, l'intervalle n'est pas en ordre.

	return true; // Si on a complété le balayage sans problème, c'est que l'intervalle est en ordre.

}

long rechercheIndiceDuMaximum(long T[], long debut, long fin)
{
	if (debut > fin) return -1; // Cas de l'intervalle vide. C'est le seul cas où on ne peut trouver un maximum.
	long indiceMax = (debut + fin) / 2; // Pas la meilleure idée car elle utilise deux opérations arithmétiques mais elle permet de créer des cas pour le balayage commençant trop tard.
	for (long K = debut; K <= fin; K++)
	{
		if (T[K] > T[indiceMax])
			indiceMax = K;
	}
	return indiceMax;
}

void triParSelection(long T[], long debut, long fin)
{
	long position,a;
	for(long k=fin;k>=debut+1;k--)
	{
		position = rechercheIndiceDuMaximum(T, debut, k);
		a= T[k]; 
		T[k] = T[position];
		T[position] = a;

	}
}



int main()
{

	cout << "********************************************************************************" << endl;
	cout << "Debut des Tests" << endl;
    cout << "********************************************************************************" << endl;

	// on fait expres de laisser la plus grande valeur en position 0 et de commencer en position 1 --- si le tableau est mis en ordre , cela veut dire que la fonction a trouve la valeur et que par consequent son balayage commence trop tot 
	cout << "Test 1 : frontiere Gauche - Debut trop tot " << endl;
	//               0   1    2   3  4  5    6  7  8  9
	long Tab[10] = { 75, 10 , 9, 12, 58, 65, 2, 9, 5, 4 };	
	triParSelection(Tab, 1, 9);
	if (estEnOrdre(Tab, 0, 9) != 0) { cout << "Positif => erreur : le balayage debut trop tot par la gauche " << endl; }
	else { cout << "Negatif " << endl; }


	cout << "********************************************************************************" << endl;

	// on fait expres de laisser la plus grande valeur en position 1 --- si le tableau n'est pas  mis en ordre , cela veut dire que la fonction n'a pas trouvé la valeur et que par consequent son balayage commence trop tard  
	cout << "Test 2 : frontiere Gauche - le balayage Debute trop tard " << endl;
	long Tab2[10] = { 7500, 10000, 9, 12, 58, 65, 2, 9, 5, 4 };
	triParSelection(Tab2, 1, 8);
	if (estEnOrdre(Tab2, 1, 8) != 1) { cout << "Positif => erreur : trop tard par la gauche " << endl; }
	else { cout << "Negatif " << endl; }

	cout << "********************************************************************************" << endl;

	cout << "Test 3 : frontiere Droite - le balayage se termine trop tot  " << endl;
	long Tab3[10] = {5,1,2,58,17,7,14,20,12,25}; // si le balayage se termine trop tot , le 1 (position 1 de l'intervalle ) et le 5(position 0 de l'intervalle ) ne seront pas echangés 
	triParSelection(Tab3, 0, 9); 
	if (estEnOrdre(Tab3, 0, 9) != 1) { cout << "Positif => erreur : trop tot par la droite " << endl; }
	else { cout << "Negatif " << endl; }

	cout << "********************************************************************************" << endl;

	cout << "Test 4 : frontiere Droite - le balayage se termine trop tard  " << endl;
	long Tab4[10] = { 5,1,2,58,17,7,14,20,12,25 }; // si le balayage se termine trop tard  , le 1 (position 1 de l'intervalle ) et le 5(position 0 de l'intervalle )  seront  echangés 
	triParSelection(Tab4, 0, 8);
	if (estEnOrdre(Tab4, 0, 9) != 0) { cout << "Positif => erreur : trop tard par la droite " << endl; }// vrai signifierai que ca a tourne plus d'une fois
	else { cout << "Negatif " << endl; }

	cout << "********************************************************************************" << endl;
	cout << "********************************************************************************" << endl;

	cout << "Test 5 : Intervalles de petites tailles" << endl; // l'objectif ici est de savoir si le balayage et les insertions se font correctement sur de petits intervalles et si le reste du tableau est laisse intact 
	//                0     1   2  3   4   5   6  7  8   9
	long Tab5[10] = { 75, 1000, 9, 12, 65, 58, 95, 9, 5, 1 };
	cout << endl << " Taille 1" << endl;
	triParSelection(Tab5, 1, 2);
	if (estEnOrdre(Tab5, 1, 2) != 1) { cout << "Positif => probleme avec les intervalles de taille 1 " << endl; }
	else { cout << "Negatif " << endl; }
	if (estEnOrdre(Tab5, 0, 9) != 0) { cout << "Positif => probleme --- tout le tableau a ete reorganise !!!!! " << endl; }
	cout << endl << "Taille 2 " << endl;
	triParSelection(Tab5, 4, 6);
	if (estEnOrdre(Tab5, 4, 6) != 1) { cout << "Positif => probleme avec les intervalles de taille 2 " << endl; }
	else { cout << "Negatif " << endl; }
	if (estEnOrdre(Tab5, 0, 9) != 0) { cout << "Positif => probleme --- tout le tableau a ete reorganise !!!!! " << endl; }

	cout << "********************************************************************************" << endl;

	cout << "test 6 : Intervalles de tailles  nulle " << endl;
	// l'objectif est de s'assurer que face a un intervalle vide , la fonction ne touche pas aux element du tableau 
	long Tab6[10] = { 75, 1000, 9, 12, 65, 58, 95, 9, 5, 1 };
	triParSelection(Tab6, 9, 1);
	long Talt[10]= { 75, 1000, 9, 12, 65, 58, 95, 9, 5, 1 };
	bool ok=true;
	for (long i = 0; i < 9; i++) { if ((Talt[i] - Tab6[i]) != 0) { ok = false; break; } }
	if (ok  != 1) { cout << "Positif => probleme avec les intervalles de taille nulle " << endl; }
	else { cout << "Negatif " << endl; }
	for (long k = 0; k < 10; k++) { if (presence(Tab6, 0, 9, Tab6[k]) != 1) { cout << "probleme ====> le tableau a ete modifie "; } }
}

