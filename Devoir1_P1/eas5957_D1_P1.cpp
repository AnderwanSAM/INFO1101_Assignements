// eas5957_D1_P1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include "pch.h"
#include <iostream>
using namespace std;


// Notre Analyse (approche) du probleme se trouve apres la fonction main 

// Informations sur les caracteres graphiques a utiliser 
const char coin_sup_gauche = char(218);
const char coin_sup_droite = char(191);
const char coin_inf_gauche = char(192);
const char coin_inf_droite = char(217);
const char vertical = char(179);
const char horizontal = char(196);
const char espace = char(32);


//affichage du PLUS
void coinSupGauche() { cout << char(218); }//affichage du coin superieur gauche 
void carHorizontal(short &a) {
	for (short i = 1; i <= (a-2); i++) {
		cout << char(196); }
}//affichage du caractere horizontal 
void coinSupDroit() { cout << char(191); }// affichage coin superieur droit 
void carVerticale() { cout << char(179); } // caractere vertical 
void laisserEspace() { cout << char(32); } // espace


void ecrireLigneHorizontaleSup(short &b, short &n) { //nombre de ligne ou 'espace' a laisser avant 

	for (short z = 1; z <= n; z++) { cout << endl; };
	for (short z = 1; z <= n+1+b ; z++) { laisserEspace(); }
	; coinSupGauche(); carHorizontal(b); coinSupDroit(); }// ligne superieur du plus 
// cotes verticaux /// le d representera plutard la longueur du cote  // haut du plus 

void ecrireLigneVerticale( short &d,short &n) //du haut 
{ 


	for ( short f =1 ; f <= (d-2) ; f++) { //itteration
		for (short o = 1; o <= (d+n+1); o++) { laisserEspace(); }// laisser l espace avant le debut du plus
		carVerticale(); 
		for (short e = 1; e <= (d-2); e++) { laisserEspace(); }; // espace entre les lignes veticales du haut 
		carVerticale(); 
		cout << endl;
	}
}
//ignes horizontales milieux 
void ecrireLigneHorizontaleMilieux(short &f,short&n) 
{
	for (short z = 1; z <= n + 2; z++) { laisserEspace(); }
coinSupGauche(); 
carHorizontal(f); 
cout << coin_inf_droite;
for (short g = 1; g <= (f-2); g++)
{
	laisserEspace();
};
cout << coin_inf_gauche;
carHorizontal(f); 
coinSupDroit();
}

// lignes verticales milieu du plus 
void ligneVerticalesMilieu(short &h,short &n)//v = nombre de case ou lignes vides a laisser avant de commencer le plus a ce niveau 
{ 
	for (short k = 1; k <= (h-2); k++) 
	{ 
		for (short u = 1; u <= n+2 ; u++) { cout << espace; }
		carVerticale(); 
		for (short j = 1; j <= ((3 * h)-4); j++) { laisserEspace(); };
		carVerticale(); 
		cout << endl;
	} 
}

void ecrireLigneHorizontaleInf(short &l,short &n) {

	for (short z = 1; z <= n + 2; z++) { laisserEspace(); }
	cout << coin_inf_gauche ;
	carHorizontal(l);
	coinSupDroit();

	for (short m = 1; m <= ((l)-2); m++) {laisserEspace();}

	coinSupGauche();
	carHorizontal(l);
	cout << coin_inf_droite;

}

void ecrireLigneHorizontaleInfBas(short & e, short n) {
	for (short z = 1; z <= n + 1 + e; z++) { laisserEspace(); }
	cout << char(192); carHorizontal(e); cout << char(217);
}

int main()
{
	short c; short n1=1;
	cout << "Bonjour . Veuillez entrer la longueur d un cote du PLUS : "; cin >> c;

	//determination de n1
	if (c % 2 == 1) { n1 = (24 - (3 * c - 1) / 2); }
	else { n1 == 24 - (3 * c) / 2; }

		ecrireLigneHorizontaleSup(c,n1);
		cout << endl;
		ecrireLigneVerticale(c, n1);
		ecrireLigneHorizontaleMilieux(c,n1);
		cout << endl;
		ligneVerticalesMilieu(c, n1);
		ecrireLigneHorizontaleInf(c,n1);
		cout << endl;
		ecrireLigneVerticale(c, n1);
		ecrireLigneHorizontaleInfBas(c, n1);
	
		return 0;

	}
