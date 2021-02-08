// eas5957_D2_P3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
using namespace std;
/*Question #3

Programmez la recherche de l’indice du maximum et écrivez un pilote pour tester votre fonction.

L’entête de la fonction est comme suit :

long rechercheIndiceDuMaximum( long T[], long debut, long fin)

La fonction retournera la position dans le tableau où se trouve la plus grande valeur dans l’intervalle donné du tableau.*/
/*Erreurs possibles : 
-la fonction ne recherche pas dans l integralite du tableau (la boucle s arrete/commence trop tot ou trop tard 
*/
long rechercheIndiceDuMaximum(long T[], long debut, long fin)
{
	long Indicemax = 0, max = 0;  // on initialise a 0 
	for (long i = debut ; i <= fin; i++ ) // balayage de l intervalle avec les froontieres comprises 
	{
		if (T[i] > max) { max = T[i]; Indicemax = (i - debut); } // la valeur dans 
		else { max = max; }
	}
	return Indicemax; 
}
int main()
{

	                                                                       //TESTS 
                
/*la position dans l intervalle est donnee en considerant le premier element a la position 0 */

// test debut trop tot ou trop tard  par la gauche 


	cout << "                                              " << "Recherche d'une erreur  par la gauche   " << "                                                  " << endl;

	              ///  0 1 2 3 4 5 6 7 8 9 10 11  12 13 14
	long Tab1[15] = { 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };
	long  frontiereGauche = 0,  frontiereDroite = 14, resultat, reponse,erreur=0;
	// creation d une boucle pour tester tous les intervalles 
	for (frontiereDroite = 14; frontiereDroite >  frontiereGauche ; frontiereDroite-- && frontiereGauche++)
	{   
		reponse = 0;// position de la plus grande valeur dans notre tableau aux valeurs decroissantes 
		resultat = rechercheIndiceDuMaximum(Tab1, frontiereGauche, frontiereDroite); 
			if (rechercheIndiceDuMaximum(Tab1, frontiereGauche, frontiereDroite)!= reponse ) 
			{
				++erreur;
				//  annonce de l erreur                     precision de l intervalle testé                        affichage du resultat obtenu               et du resultat attendu 
				cout << " Erreur sur l'intervalle : " << "[" << frontiereGauche << ";" << frontiereDroite << "]" << "  l'indice trouve est = " << resultat << "  le resultat attendu est = " << reponse << endl;
				// precision de l erreur 
				if (resultat > reponse) { cout << " Erreur de " << resultat - reponse << " trop tot  par la gauche  " << endl; }// erreur trop tard par la gauche 
				else { cout << " Erreur de " << reponse - resultat << " trop tard  par la gauche  " << endl; } // erreur trop tot par la gauche
			}
	}
	cout << endl << " Nombre d'erreurs detectees sur  cette partie du test : " << erreur << endl;

	cout << endl << endl;

	// test arret trop tot ou trop tard  par la droite 



	cout << "                                              " << "Recherche d'une erreur  par la droite  " << "                                                  " << endl;
	             ///  0 1 2 3 4 5 6 7 8 9 10 11  12 13 14
    long Tab2[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	long resultat2,nb_erreurs=0;
	frontiereGauche = 0;
	frontiereDroite = 14; 

	for (frontiereDroite = 14; frontiereDroite >  frontiereGauche ; frontiereDroite-- && frontiereGauche++) // creation d une boucle pour tester tous les intervalles 
	{
		long reponse2 = frontiereDroite-frontiereGauche;// reponse2 donne la derniere position de l intervalle en considerant qu il commence par l indice 0
		resultat2 = rechercheIndiceDuMaximum(Tab2, frontiereGauche, frontiereDroite);
		if (resultat2 != reponse2)
		{
			++nb_erreurs;
			//  annonce de l erreur                     precision de l intervalle testé                        affichage du resultat obtenu               et du resultat attendu 
			cout << " Erreur sur l'intervalle : " << "[" << frontiereGauche << ";" << frontiereDroite << "]" << "  l'indice trouve est = " << resultat2 << "  le resultat attendu est = " << reponse2 << endl;
			// precision de l erreur 
			if (resultat2 > reponse2) { cout << " Erreur de " << resultat2 - reponse2 << " trop tard  par la droite " << endl; }// erreur trop tard par la gauche 
			else { cout << " Erreur de " << reponse2 - resultat2 << " trop tot  par la droite " << endl; } // erreur trop tot par la gauche
		}
	}
	cout << endl << " Nombre d'erreurs detectees sur  cette partie du test : "<< nb_erreurs << endl;
	cout << endl << endl;
}

