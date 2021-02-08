// eas5957_D4.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include <string >
#include <fstream>
using namespace std;

//definir nos variables struct 

struct uneMatrice
{
	string	nomVariable;
	short	N_Rangees;
	short	M_Colonnes;
	long	T[100];

};
struct instruction
{
	uneMatrice operande1;
	uneMatrice operande2;
	uneMatrice matriceDeTransfert;
	char operateur[4];
	char sentinelle_instruction;
};

// fonctions de controle et verifications


long verifier_existance_matrice(uneMatrice M, uneMatrice Tab[], long nb_matrices_dans_le_tableau)
{
	long  reponse = (-1), i;
	string nom = M.nomVariable;
	// rechercher le nom de la matrice
	for (i = 0; i < nb_matrices_dans_le_tableau; i++)
	{
		if (nom == Tab[i].nomVariable) { reponse = i; }// si oui , affecter a reponse la valeur de l'indice 
		//else { reponse = -1; }
	}
	return reponse;
}

long   verifier_dimensions_multiplication(uneMatrice A, uneMatrice B)
{
	long verification = 0;
	if (A.M_Colonnes != B.N_Rangees) { verification = 1; }
	long taille_du_resultat = A.N_Rangees * B.M_Colonnes;
	if (taille_du_resultat > 100) { verification = 2; }
	return verification;
}


bool verifier_dimensions_additionEtSoustraction(uneMatrice A, uneMatrice B)
{
	// comparer le nombre de rangees 
	if (A.N_Rangees != B.N_Rangees) { return false; }
	// comparer le nombre de colonnes 
	if (A.M_Colonnes != B.M_Colonnes) { return false; }
	return true;
}

bool estNombreEntierNonSigne(string jeton)
{
	/* On peut accepter qu'il y ait un + avant le premier chiffre.
	*/
	unsigned long K = 0; // Pour le cas où il n'y a pas de plus, on commence au 1e caractère.
	if (jeton[0] == '+')
		K = 1; // Il y a un signe + , ce qui est OK. On commence avec le 2e caractère.

	for (; K < jeton.length(); K++)
		if (!isdigit(jeton[K]))
			return false;
	return true;
}

bool estNombreEntierSigne(string jeton)
{
	/*Il y a 3 cas à vérifier :
		- présence d'un +
		- présence d'un -
		- absence de signe.
	*/
	unsigned long K = 0; // Pour le cas où il n'y a pas de signe. On commence avec le 1e caractère.
	if (jeton[0] == '+' || jeton[0] == '-')
		K = 1; // Il y a un signe, ce qui est OK. On commence avec le 2e caractère.
	for (; K < jeton.length(); K++)
		if (!isdigit(jeton[K]))
			return false;
	return true;
}

bool estUnMot(string jeton)
{
	// Le mot ne contient que des lettres ?
	for (unsigned long K = 0; K < jeton.length(); K++)
		if (!isalpha(jeton[K]))
			return false;
	return true;
}



// fonctions de lectures 

void lecteurDeMatrices(string nomDeFichier, uneMatrice A[], string journalErreurs, long &nb_matrices) // a envoyer dans le cpp final pour remplacer celle qui est
{
	// cette fonction lis "toutes" les matrices dans le fichier 
	// Elle ecris dans le journal d'erreurs si elle rencontre quelque chose de non conforme 

	//creation des variables ---indices--tableau intermediaire pour lire comme des string 
	string stock = "0";
	long N, indiceM, k = 0;
	//creer un conduit et ouvrir le fichier 
	ifstream lecture;
	lecture.open(nomDeFichier, ios::in);
	//lire le nombre de matrices 
	lecture >> N; nb_matrices = N;
	//utiliser une boucle pour lire le nombre de matrices
	for (long indiceM = 0; indiceM < N; indiceM++)
	{
		string marqueur; stock = "0"; k = 0;
		//lire la definition de la matrice

		// lire le nom 
		lecture >> A[indiceM].nomVariable;
		// verifier que c est une lettre 
		if (estUnMot(A[indiceM].nomVariable) != 1)
		{
			// ce n'est pas un mot 
			// informer le journal   d erreur 
			// continue 

			ofstream conduit;
			conduit.open(journalErreurs, ios::app);
			conduit << endl;
			conduit << " ==== >   probleme avec la  definion d une des  matrice " << A[indiceM].nomVariable << "  " << "n'est pas un nom valide  " << endl;
			conduit.close();
		}
		else
		{
			lecture >> A[indiceM].N_Rangees;

			if (A[indiceM].N_Rangees <= 0) // verifier que c est un chiffre  positif 
			{
				ofstream conduit;
				conduit.open(journalErreurs, ios::app);
				conduit << endl;
				conduit << " ==== >   probleme avec la definion de la matrice " << A[indiceM].nomVariable << "  " << "le nombre de rangees ne peut pas etre nul  " << endl;
				conduit.close();
				continue;
			}


			else
			{

				//lire 
				lecture >> A[indiceM].M_Colonnes;
				if (A[indiceM].M_Colonnes <= 0)
				{
					ofstream conduit;
					conduit.open(journalErreurs, ios::app);
					conduit << endl;
					conduit << " ==== >   probleme avec la definion de la matrice " << A[indiceM].nomVariable << "  " << "le nombre de colonnes ne peut pas etre nul " << endl;
					conduit.close();
					continue;
				}
				//continue;
				else
				{
					// verifier que c est un chiffre 
					while (stock != "FIN")
					{
						//lire comme un string
						lecture >> stock;
						if (stock != "FIN")
						{
							if (estNombreEntierSigne(stock) != 1)
							{
								ofstream conduit;
								conduit.open(journalErreurs, ios::app);
								conduit << endl;
								conduit << " ==== >   probleme avec la definion de la matrice " << A[indiceM].nomVariable << "  " << "les elements doivent etre des entiers " << endl;
								conduit.close();
								break;

							}
							else { A[indiceM].T[k] = stol(stock); k += 1; }
						}
					}
					long nb_elements = A[indiceM].M_Colonnes*A[indiceM].N_Rangees;
					/*for (k = 0; k < nb_elements; k++)
					{
						//lire un nombre
						lecture >> A[indiceM].T[k];
						//verifier que c est un nombre
					}
					lecture >> marqueur;*/
					// informer le journal d'erreur si on a lu trop ou pas assez d'elements 
					if ((k) != nb_elements)
					{
						ofstream conduit;
						conduit.open(journalErreurs, ios::app);
						conduit << endl;
						if ((k) > nb_elements) { conduit << endl << "trop d'elements ont ete lus dans la matrice " << A[indiceM].nomVariable << " il y a " << k << "elements au  lieu de " << nb_elements << endl; }
						else { conduit << endl << "Pas assez d'elements lus dans la matrice " << A[indiceM].nomVariable << " il y a " << k << "elements au  lieu de " << nb_elements << endl; }
						conduit.close();
					}
					//k = 0;
				}
			}
		}
		k = 0;
	}

	lecture.close();
}


void lire_instructions(string nomdefichier, instruction instruction[], string erreurs, long &nb_instructions)
{
	ifstream lire;
	lire.open(nomdefichier, ios::in);
	/* un struct a ete cree pour conserver les instructions et leur informations*/
	for (long i = 0; i < 100; i++)
	{
		//lire operande gauche ---> matrice de transfert 
		lire >> instruction[i].matriceDeTransfert.nomVariable;
		//lire operateur = 
		lire >> instruction[i].operateur[0];
		if (instruction[i].operateur[0] != '=')
		{
			ofstream informer;
			informer.open(erreurs, ios::app);
			informer << endl << "--> dans l'instruction " << i << "l'operateur '=' n'est pas a sa place " << "a la place il y a : " << instruction[i].operateur[0] << endl;
			informer.close();
			continue;

		}
		//lire operande droite 1 
		lire >> instruction[i].operande1.nomVariable;
		// verifier que cette matrice existe 
		// lire operateur {+,-,T}
		lire >> instruction[i].operateur[1];
		// if l'operateur n est pas T , lire operande droite suivante 2 
		if (instruction[i].operateur[1] == 'T')
		{
			lire >> instruction[i].sentinelle_instruction;
			if (instruction[i].sentinelle_instruction == '.') { nb_instructions = i + 1; break; }
			continue;
		}
		lire >> instruction[i].operande2.nomVariable;
		// verifier que cette matrice existe 
		lire >> instruction[i].sentinelle_instruction;
		if (instruction[i].sentinelle_instruction == '.') { nb_instructions = i + 1; break; }
		// lire sentinelle {;,.}
		// tant que la sentinelle est differente de .
		// continuer les instructions 
	}
	lire.close();
}

// fonctions d' ecriture

void ecriture_Matrices_Resultats(string nomFichier, instruction &Instruction)
{
	// cette fonction ecrit les matrices dans les fichiers de sortie --- sauf dans le journal d erreur  
   //ouvrir le fichier
	ofstream ecrire;
	ecrire.open(nomFichier, ios::app);
	// ecrire 2 lignes vides
	ecrire << endl << endl;
	// ecrire l'instruction 
	ecrire << Instruction.matriceDeTransfert.nomVariable << " " << Instruction.operateur[0] << " " << Instruction.operande1.nomVariable << " " << Instruction.operateur[1];
	switch (Instruction.operateur[1])
	{
	case '+':
		ecrire << " " << Instruction.operande2.nomVariable << " " << Instruction.sentinelle_instruction << "  "; break;
	case '-':
		ecrire << " " << Instruction.operande2.nomVariable << " " << Instruction.sentinelle_instruction << "  "; break;
	case '*':
		ecrire << " " << Instruction.operande2.nomVariable << " " << Instruction.sentinelle_instruction << "  "; break;
	case 'T':
		ecrire << " " << Instruction.sentinelle_instruction << "  ";
	}
	// ecrire 1 ligne vide 
	ecrire << endl;
	// ecrire le nom de la matrice
	ecrire << Instruction.matriceDeTransfert.nomVariable << " ";
	// ecrire le nombre de rangees 
	Instruction.matriceDeTransfert.N_Rangees = 4;
	ecrire << Instruction.matriceDeTransfert.N_Rangees << " ";
	// ecrire le nombre de colonnes
	Instruction.matriceDeTransfert.M_Colonnes = 3;
	ecrire << Instruction.matriceDeTransfert.M_Colonnes << " ";
	// ecrire les element sous forme matricielle
	ecrire << endl;
	long a, indice = 0;
	for (long k = 0; k < Instruction.matriceDeTransfert.N_Rangees; k++)     //pour chaque rangee
	{
		for (a = 0; a < Instruction.matriceDeTransfert.M_Colonnes; a++)        // pour chaque colonne - etant donné qu'elles ne bougent pas 
		{
			ecrire << Instruction.matriceDeTransfert.T[indice] << " ";
			indice += 1;
		}
		ecrire << endl;
	}
	ecrire.close();
}

void ecrire_toutes_lesMatrices(uneMatrice A[], string nomFichier, long nb_matrices_total)
{
	//ouvrir le fichier
	ofstream ecrire;
	ecrire.open(nomFichier, ios::app);
	// laisser une ligne vide 
	ecrire << endl;
	// pour toutes les matrices 
	for (long i = 0; i < nb_matrices_total; i++)
	{
		// ecrire le nom de la matrice 
		ecrire << A[i].nomVariable;
		// ecrire le nombre de rangees 
		ecrire << " " << A[i].N_Rangees << " ";
		// ecrire le nombre de colonnes
		ecrire << A[i].M_Colonnes;
		// ecrire les elements de la matrice sous forme matricielle 
		ecrire << endl;
		long a, indice = 0;
		for (long k = 0; k < A[i].N_Rangees; k++)     //pour chaque rangee
		{
			for (a = 0; a < A[i].M_Colonnes; a++)        // pour chaque colonne - etant donné qu'elles ne bougent pas 
			{
				ecrire << A[i].T[indice] << " ";
				indice += 1;
			}
			ecrire << endl;
		}
		// ecrire FIN 
		ecrire << "FIN";
		// sauter une ligne 
		ecrire << endl;
	}
	ecrire.close();
}

// fonctions de calcul

long calculerPosition(long NombreDeColonnes, long numeroRangee, long numeroColonne)
{
	return  numeroRangee * NombreDeColonnes + numeroColonne;
}



bool  additionnerMatrices(uneMatrice &Resultat, long &positionResultat, uneMatrice operande1, uneMatrice operande2, string fichier_d_erreurs, long &nb_matrices, uneMatrice tableaudeMatrice[])
{
	//cette fonction additionne des matrices
	//elle verifiera d'abord que les deux matrices a additionner existent
	if (verifier_existance_matrice(operande1, tableaudeMatrice, nb_matrices) == (-1))
	{
		//si non , informer le journal d'erreurs 
		ofstream conduit;
		conduit.open(fichier_d_erreurs, ios::app);
		conduit << " la matrice " << operande1.nomVariable << "   n'existe pas " << endl;
		conduit << " l'addition ne pourra pas etre faite  " << endl;
		conduit.close();
		return false;
	}
	else
	{
		if (verifier_existance_matrice(operande2, tableaudeMatrice, nb_matrices) == (-1))
		{
			//si non , informer le journal d'erreurs 
			ofstream conduit;
			conduit.open(fichier_d_erreurs, ios::app);
			conduit << " la matrice " << operande2.nomVariable << "   n'existe pas " << endl;
			conduit << " l'addition ne pourra pas etre faite  " << endl;
			conduit.close();
			return false;
		}
		else
		{

			// elle doit comparer les dimensions des matrices pour etre sur qu'elles sont correcte
			// si oui , on  continue 
			// sinon informer le journal d'erreur 
			bool verifie = verifier_dimensions_additionEtSoustraction(operande1, operande2);
			if (verifie != true)
			{
				ofstream conduit;
				conduit.open(fichier_d_erreurs, ios::app);
				conduit << " les  matrices " << operande2.nomVariable << " et " << operande1.nomVariable << "   n'ont pas les memes dimensions " << endl;
				conduit << " l'addition ne pourra pas etre faite  " << endl;
				conduit.close();
				return false;
			}
			else
			{
				// il n 'y a pas de probleme 
				// on fait l'addition 
				Resultat.M_Colonnes = operande1.M_Colonnes; Resultat.N_Rangees = operande2.N_Rangees;
				for (long i = 0; i < (operande1.M_Colonnes*operande1.N_Rangees); i++)
				{
					Resultat.T[i] = operande1.T[i] + operande2.T[i];
				}
				//on verifie si la matrice est dans le tableau 
				//si non on utilise la prochaine position libre 
				if ( verifier_existance_matrice(Resultat,tableaudeMatrice,nb_matrices) == (-1))
				{
					positionResultat = nb_matrices; // etant donne que le tableau commence en 0
					tableaudeMatrice[positionResultat] = Resultat; nb_matrices += 1;
				}				

				return true;



			}
		}


	}

}


bool  soustraireMatrices(uneMatrice &Resultat, long &positionResultat, uneMatrice operande1, uneMatrice operande2, string fichier_d_erreurs, long &nb_matrices, uneMatrice tableaudeMatrice[])
{
	//cette fonction additionne des matrices
	//elle verifiera d'abord que les deux matrices a additionner existent
	if (verifier_existance_matrice(operande1, tableaudeMatrice, nb_matrices) == (-1))
	{
		//si non , informer le journal d'erreurs 
		ofstream conduit;
		conduit.open(fichier_d_erreurs, ios::app);
		conduit << " la matrice " << operande1.nomVariable << "   n'existe pas " << endl;
		conduit << " l'addition ne pourra pas etre faite  " << endl;
		conduit.close();
		return false;
	}
	else
	{
		if (verifier_existance_matrice(operande2, tableaudeMatrice, nb_matrices) == (-1))
		{
			//si non , informer le journal d'erreurs 
			ofstream conduit;
			conduit.open(fichier_d_erreurs, ios::app);
			conduit << " la matrice " << operande2.nomVariable << "   n'existe pas " << endl;
			conduit << " l'addition ne pourra pas etre faite  " << endl;
			conduit.close();
			return false;
		}
		else
		{

			// elle doit comparer les dimensions des matrices pour etre sur qu'elles sont correcte
			// si oui , on  continue 
			// sinon informer le journal d'erreur 
			bool verifie = verifier_dimensions_additionEtSoustraction(operande1, operande2);
			if (verifie != true)
			{
				ofstream conduit;
				conduit.open(fichier_d_erreurs, ios::app);
				conduit << " les  matrices " << operande2.nomVariable << " et " << operande1.nomVariable << "   n'ont pas les memes dimensions " << endl;
				conduit << " l'addition ne pourra pas etre faite  " << endl;
				conduit.close();
				return false;
			}
			else
			{
				// il n 'y a pas de probleme 
				// on fait l'addition 
				Resultat.M_Colonnes = operande1.M_Colonnes; Resultat.N_Rangees = operande2.N_Rangees;
				for (long i = 0; i < (operande1.M_Colonnes*operande1.N_Rangees); i++)
				{
					Resultat.T[i] = operande1.T[i] - operande2.T[i];
				}
				//on verifie si la matrice est dans le tableau 
				//si non on utilise la prochaine position libre 
				if (verifier_existance_matrice(Resultat, tableaudeMatrice, nb_matrices) == (-1))
				{
					positionResultat = nb_matrices; // etant donne que le tableau commence en 0
					tableaudeMatrice[positionResultat] = Resultat; nb_matrices += 1;
				}

				return true;



			}
			/* on va faire  ca dans une autre fonction
			// si oui , on continue
			// elle vera si la matrice resultante existe
			if (verifier_existance_matrice(Resultat, tableaudeMatrice, nb_matrices) == (-1))
			{
				// sinon elle utilisera la prochaine position libre du tableau
				positionResultat = nb_matrices;
				tableaudeMatrice[positionResultat] = Resultat; nb_matrices += 1;

			}
			else
			{
				// si oui , elle recueillera les reponses
				positionResultat = verifier_existance_matrice(Resultat, tableaudeMatrice, nb_matrices);
				tableaudeMatrice[positionResultat]= Resultat;
			}
			*/
		}


	}

}


bool transposerMatrice(uneMatrice a_transposer, uneMatrice &Resultat_Transpo, uneMatrice Tableau_des_matrices[], long &nb_matrices, string fichier_erreurs)
{
	// verifier l 'existance de la matrice 
	if (verifier_existance_matrice(a_transposer, Tableau_des_matrices, nb_matrices) == (-1))
	{
		ofstream informer;
		informer.open(fichier_erreurs, ios::app);
		informer << endl << "===> erreur transposition de matrice " << endl;
		informer << "la matrice a transposer n'existe pas : " << a_transposer.nomVariable << endl;
		informer.close();
		return false;
	}
	else
	{
		// transformation du tableau lineaire de la matrice en  tableau bi-dimensionnel 
		long Tableau_intermediaire[50][50];
		for (long colonne = 0; colonne < a_transposer.M_Colonnes; colonne++)
		{
			for (long rangee = 0; rangee < a_transposer.N_Rangees; rangee++)
			{
				Tableau_intermediaire[colonne][rangee] = a_transposer.T[calculerPosition(a_transposer.M_Colonnes, rangee, colonne)];
			}
		}
		long indice = 0;
		// retransformons ce tableau en  format lineaire en faisant une bonne transposition ! 
		for (long k = 0; k < a_transposer.M_Colonnes; k++)
		{
			for (long i = 0; i < a_transposer.N_Rangees; i++)
			{
				Resultat_Transpo.T[indice] = Tableau_intermediaire[k][i]; indice += 1;

			}
		}
		// faire le changement des informations sur le nombre de rangees et colonnes 
		Resultat_Transpo.M_Colonnes = a_transposer.N_Rangees;
		Resultat_Transpo.N_Rangees = a_transposer.M_Colonnes;

		long verification = verifier_existance_matrice(Resultat_Transpo, Tableau_des_matrices, nb_matrices);
		if (verification == (-1))
		{
			long position = nb_matrices;
			Tableau_des_matrices[position] = Resultat_Transpo; nb_matrices += 1;
		}
		return true;
	}
}



int main()
{
	uneMatrice Tableau_de_Matrices[52];


	
	long nb_matrices, position, nb_instructions;

	
	string  fichier_instructions,
		fichier_matrices,
		fichier_toutes_lesMatrices,
		Journal_d_erreurs,
		fichier_resultats_des_instructions;

	instruction tableau_Instructions[100];

	
	cout << "Dans quel fichier se trouvent les Matrices   ? : ";
	cin >> fichier_matrices;

	cout << "Dans quel fichier se trouvent les instructions  ? : ";
	cin >> fichier_instructions;

	cout << endl << "Dans quel fichier souhaitez vous mettre les resultats de vos  instructions ? : ";
	cin >> fichier_resultats_des_instructions;

	cout << endl << "Dans quel fichier devra se trouver le recapitulatif (matrices lues et crees ) ? : ";
	cin >> fichier_toutes_lesMatrices;

	cout << endl << "Quel fichier recevra les messages d'erreurs  ? : ";
	cin >> Journal_d_erreurs;

	lecteurDeMatrices(fichier_matrices, Tableau_de_Matrices, Journal_d_erreurs, nb_matrices);
	lire_instructions(fichier_instructions, tableau_Instructions, Journal_d_erreurs, nb_instructions);

	for (long i =0 ; i<nb_instructions;nb_instructions++)
	{
		switch (tableau_Instructions[i].operateur[1]) 
		{
		case '+' :
			additionnerMatrices(tableau_Instructions[i].matriceDeTransfert, position, tableau_Instructions[i].operande1, tableau_Instructions[i].operande2, Journal_d_erreurs, nb_matrices, Tableau_de_Matrices); break;
		case '-' :
			soustraireMatrices(tableau_Instructions[i].matriceDeTransfert, position, tableau_Instructions[i].operande1, tableau_Instructions[i].operande2, Journal_d_erreurs, nb_matrices, Tableau_de_Matrices); break;
		case 'T' : 
			transposerMatrice(tableau_Instructions[i].operande1, tableau_Instructions[i].matriceDeTransfert, Tableau_de_Matrices, nb_matrices, Journal_d_erreurs); break;

		}
	
	}
	
	for (long k = 0; k < nb_instructions; k++) 
	{
		ecriture_Matrices_Resultats(fichier_resultats_des_instructions, tableau_Instructions[k]);
	}

	ecrire_toutes_lesMatrices(Tableau_de_Matrices, fichier_toutes_lesMatrices, nb_matrices);
}


