// eas5957_D2_P1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
using namespace std;


/*Programmez la recherche séquentielle et écrivez un pilote pour tester votre fonction.

L’entête de la fonction est comme suit :

long rechercheSequentielle( long T[], long debut, long fin, long cible)

Dans le cas de recherches avec réussite, la fonction retournera la position où
se trouve la cible dans l’intervalle donné du tableau. Dans le cas de recherches avec échec, la fonction retournera -1 */


/*
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||la fonction||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| 
     
	  possibilites :
-cas 1 : la cible est presente une seule fois 
-cas 2 : la cible est presente plus d une fois 
-cas 3 : la cible n est pas presente 
      
	  etapes  : 
*balayer le tableau a l aide d une boucle for 
* si la valeur dans la case du tableau correspond a la cible , retourner  la valeur de l indice 
*si on atteint la frontiere droite , la boucle s arretera et retournera -1

|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| programme pilote|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||                         
Erreurs possibles du programme 
-la boucle commence trop tot a gauche 
-la boucle commence trop tard a gauche
-la boucle s'arrete trop top a droite
-la  boucle s'arrete trop tard a droite 
-la fonction retourne -1 alors que la cible est presente 
-la fonction retourne un indice different de -1 alors que la cible n est pas presente 
*/

//fonction ok 
long rechercheSequentielle(long T[],long debut ,long fin, long cible )
{
	
	long a = 0;
	for (long i = debut; i <=fin; i++) 
	{
		if (T[i] == cible) { a = ( i - debut) ; return a; }
	}
	return -1;
}
      
// ||||||||||||||||||||||||||||| fonctions avec erreurs volontaires --- testons notre programme pilote 
/*
//erreur - trop tot - a gauche 
long rechercheSequentielleErreur1(long T[], long debut, long fin, long cible)
{
long a = 0;
	for (long i = debut-1; i <=fin; i++)
	{
		if (T[i] == cible) { a = i - debut; return a; }
	}
	return -1;
}

// erreur- trop tard -  a gauche 
long rechercheSequentielleErreur2(long T[], long debut, long fin, long cible)
{
long a = 0;
	for (long i = debut+1; i <= fin+1 ; i++)
	{
		if (T[i] == cible) { a = i - debut; return a; }
	}
	return -1;
}

// erreur trop tot - a droite 
long rechercheSequentielleErreur3(long T[], long debut, long fin, long cible)
{
long a = 0;
	for (long i = debut; i <fin; i++)
	{
		if (T[i] == cible) { a = i - debut; return a; }
	}
	return -1;
}
 // erreur trop tard - a droite
long rechercheSequentielleErreur4(long T[], long debut, long fin, long cible)
{
long a = 0;
	for (long i = debut; i <= fin+1; i++)
	{
		if (T[i] == cible) { a = i - debut; return a; }
	}
	return -1;
}

// erreur - retour de -1 malgre la presence de la cible 
long rechercheSequentielleErreur5(long T[], long debut, long fin, long cible)
{
long a = 0;
	for (long i = debut; i <= fin; i++)
	{
		if (T[i] == cible) { return -1 ; }
	}
	return -1;
}
 
// erreur - retour d un indice alors que la cible est absente
long rechercheSequentielleErreur6(long T[], long debut, long fin, long cible)
{
long a = 0;
	for (long i = debut; i <= fin; i++)
	{
		if (T[i] == cible) { a = i - debut; return a; }
	}
	return a ;
}

// erreur - retour d une seule position pour une cible presente plus d une fois  
long rechercheSequentielleErreur7(long T[], long debut, long fin, long cible)
{
long a = 0;
	for (long i = debut; i <= fin; i++)
	{
		if (T[i] == cible) { a = i - debut; return a; }
	}
	return -1;
}

*/

int main()
{

	                                                                 //TESTS 

	           //||||||||||||||||||||||||||||||||||||||||||||||||||Avec la cible presente|||||||||||||||||||||||||||||||||||||||||||| 
	/*la position dans l intervalle est donnee en considerant le premier element a la position 0 */

    // test debut trop tot ou trop tard  par la gauche 
	
	// 
	cout << "                                              " << "Recherche d'une erreur  par la gauche   " << "                                                  " << endl;
	             ///  0 1 2 3 4 5 6 7 8 9 10 11  12 13 14
	long Tab1[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	long  frontiereGauche=0, frontiereDroite=14,resultat,reponse,nb_Erreurs=0;
	long cible1;  
	// creation d une boucle pour tester tous les intervalles 
	for (frontiereDroite = 14; frontiereDroite >  frontiereGauche  ; frontiereDroite-- && frontiereGauche++) 
	{
		cible1 = frontiereGauche+1; // +1 parce que le compte commence par 0 dans notre tableau 
		reponse = 0;// (11 - frontiereGauche);// position du 12 dans l intervalle 
		resultat = rechercheSequentielle(Tab1, frontiereGauche, frontiereDroite, cible1);
		   if (rechercheSequentielle(Tab1, frontiereGauche, frontiereDroite, cible1) != reponse)
		   {
			   ++nb_Erreurs;
					//  annonce de l erreur                     precision de l intervalle testé                        affichage du resultat obtenu               et du resultat attendu 
					cout << " Erreur sur l'intervalle : " << "[" << frontiereGauche << ";" << frontiereDroite << "]" << "  l'indice trouve est = " << resultat << "  le resultat attendu est = " << reponse << endl;
					// precision de l erreur 
					if (resultat==(-1)) { cout << " Erreur -  trop tard  par la gauche  " << endl; }// erreur trop tard par la gauche 
					else { cout << " Erreur -  trop tot  par la gauche  " << endl; } // erreur trop tot par la gauche
			}					
	}
	if (nb_Erreurs == 0) { cout << endl << "Fin de ce test . le test est negatif ." << endl; }	else { cout << endl << "le test est positif ." << nb_Erreurs << "  ont ete detectees " << endl; }
	cout << endl << endl;
	                                                  // test arret trop tot ou trop tard  par la droite 
											


	cout << "                                              "<< "Recherche d'une erreur  par la droite  " << "                                                  " <<endl;
	                ///  0 1 2 3 4 5 6 7 8 9 10 11  12 13 14
	// long Tab1[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	long resultat2;
	frontiereGauche = 0;
	nb_Erreurs = 0; // reintialisation du nombre d erreurs 
	for (frontiereDroite = 14; frontiereDroite > frontiereGauche  ; frontiereDroite-- && frontiereGauche++) // creation d une boucle pour tester tous les intervalles presents dans notre tableau
	{
	
	 long cible2 = frontiereDroite+1;// on attribue a la cible la valeur de la frontiere droite ; si la fonction teste une valeur de plus ou de moins , elle retournera un indice different de 
	                              // la derniere position de l intervalle ; +1 parce que dans le tableau le decompte commence a  partir de 0
	 
	 long reponse2= frontiereDroite - frontiereGauche;// reponse2 donne la derniere position de l intervalle en considerant qu il commence par l indice 0
			resultat2 = rechercheSequentielle(Tab1, frontiereGauche, frontiereDroite, cible2);
			if (resultat2 != reponse2) 
			{
				++nb_Erreurs;
				//  annonce de l erreur                     precision de l intervalle testé                        affichage du resultat obtenu               et du resultat attendu 
				cout << " Erreur sur l'intervalle : " << "[" << frontiereGauche << ";" << frontiereDroite << "]" << "  l'indice trouve est = " << resultat2 << "  le resultat attendu est = " << reponse2 << endl;
				// precision de l erreur 
				if (resultat2 > reponse2) { cout << " Erreur de " << resultat2 - reponse2 << " trop tard  par la droite " << endl; }// erreur trop tard par la gauche 
				else { cout << " Erreur de " << reponse2 - resultat2 << " trop tot  par la droite " << endl; } // erreur trop tot par la gauche
			}
	}
	if (nb_Erreurs == 0) { cout << endl << "Fin de ce test . le test est negatif ." << endl; }
	else { cout << endl << "le test est positif ." << nb_Erreurs << "  ont ete detectees " << endl; }
	cout << endl << endl;

	                                                                                                                                                                                                                                                                       // test la valeur est presente plus d'une fois --- la fonction retourne t elle toutes les positions de la cible  ?
                              // ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||test avec une  valeur absente |||||||||||||||||||||||||||||||||||||||||

	cout << "                                              " << " Test suivant : Recherche d'une cible absente   " << "                                                  " << endl;
	long cible3 = 25; // la cible est absente
	long reponse3 = -1;// -1 correspond a la valeur que doit rendre la fonction puisque la cible est absente 
	long frontiereDroite1, frontiereGauche1 = 0;
	nb_Erreurs = 0;
	for (frontiereDroite1 = 14; frontiereDroite > frontiereGauche1 ; frontiereDroite1-- && frontiereGauche1++) // creation d une boucle pour tester tous les intervalles 
	{
		long resultat3 = rechercheSequentielle(Tab1, frontiereGauche1, frontiereDroite1, cible3);
		if (resultat3 != reponse3)
		{
			++nb_Erreurs;
			//  annonce de l erreur                     precision de l intervalle testé                        affichage du resultat obtenu               et du resultat attendu 
			cout << " Erreur sur l'intervalle : " << "[" << frontiereGauche << ";" << frontiereDroite << "]" << "  l'indice trouve est = " << resultat3<< "  le resultat attendu est = " << reponse3 << endl;
		}
	}
	if (nb_Erreurs == 0) { cout << endl << "Fin de ce test . le test est negatif ." << endl; }	else { cout << endl << "le test est positif ." << nb_Erreurs << "  ont ete detectees " << endl; }
	cout << endl << endl;


}


/*Plan 
-creer la bonne fonction 
-creer des fonctions avec des erreurs volontaires 
- series de test pour chacune des fonctions fautives  :
tests effectuees sur tous les modeles (on verifie que le programme pilote marche correctement et que les erreurs presentes dans chacune des fonctions sont trouvees)
-series de test sur la bonne fonction 

*/
