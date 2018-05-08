/*
convertisseurEgyptien.h
-----

MANUEL D'UTILISATION

Rôle : convertie les nombres entre 1 et 9 999 999 en numération égyptienne. (le 0 n'éxiste pas)

Règle de compilation: 
Les commandes suivantes permettant d’effectuer la compilation de programmes 
en C: cc,gcc(avec message d'erreur).le programme gcc construit un fichier exécutable dont le nom est 
celui par défaut a.out.

Pour compiler le programme: "gcc convertisseurEgyptien.c" ou "gcc convertisseurEgyptien.c -o nomProgramme"
Pour l'executer: "./a.out" ou "./nomProgramme" 

L'utilisateur doit saisir un nombre entier, compris entre 1 et 9 999 999.


*/


int initialisation(int *decompose);
/*
Rôle: mesure la taille du nombre
indique ou commence le nombre afin d'eviter les espaces superflus au debut 
exemple 97865 retourne 5
utile dans la fonction affichage
*/

wchar_t *creationTabSigne();
/*
Rôle: Creation du tableau des signes en unicode
Declarer en wchar car char est trop petit pour le code correspondant
Declarer avec un pointeur pour pouvoir utiliser le taleau dans la fonction affichage
Le L permet de manipuler les charactères sur plusieurs octets nécessaire pour l'unicode
*/

int *decomposition(int nb);
/*
Rôle: decompose le nombre dans un tableau dynamique et alloue l'espace necessaire
exemple: 97865 
decompose[0]=0
decompose[1]=0
decompose[2]=9
decompose[3]=7
decompose[4]=8
decompose[5]=6
decompose[6]=5
*/

void affichage(int *decompose, wchar_t *signe, int init);
/* 
Rôle: imprime les signes horizontalement sur 3 lignes en fonction du tableau decompose[]

le premier for resoud le beug d'affichage quand un nb est composé de 0
exemple: 5002 retourne tab=0110
si tab==1, rien est imprimé

Ensuite

Cas 1:
si decompose[7-i]>3, on imprime 3 fois le signe
on soustrait 3 de sa valeur
on passe au signe suivant

Cas 2:
si decompose[7-i]<3 && decompose[7-i]>0, on imprime 1 ou 2 fois le signe
on rajoute 1 ou 2 espaces
on soustrait 1 ou 2 de sa valeur
on passe au signe suivant

Cas 3:
si decompose[7-i]==0, on imprime 3 espaces
on passe au signe suivant

if (tab[8 - i] != 1) ajoute un espace entre chaque bloc de signe pour une meilleur lisibilité

quand init est parcouru complètement, retour à la ligne
*/

/* MAIN
SET LOCALE: pour indiquer ou demander la localisation courante du programme
*/


