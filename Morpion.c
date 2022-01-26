#include <stdio.h>
#include "main.h"
#include "action.h"

void initialisation(int morpion[3][3]){
  int i=0;
  int j=0;
  for (i=0; i<3; i++){ // 
    for (j=0; j<3; j++){
	morpion[i][j]=VIDE;
    }
  }
}

  // afficher grille

void affichage(int morpion[3][3]){
  int i;
  int j=0;
  for (i=0; i<3; i++){ // Tableau de 3 par 3 
    printf("\n%d | ", i+1); // Affiche la ligne
    for (j=0; j<3; j++){
      switch(morpion[i][j]){
	
      case VIDE:
	printf("  | ");
	break;
      case CROIX:
	printf("X | ");
	break;
      case ROND:
	printf("O | ");
	break;
      }
    }
  }
  printf("\n    ");
  for(j=0; j<3; j++){ // Affiche colonnes
    printf("%d   ",j+1); 
  }
  printf("\n\n"); // Retour fin d'affichage
}

int main(){
  int morpion[3][3];
  int joueurActuel = ROND;
  int finDuJeu = 0;
  printf("\n**************************\n* On va faire un morpion *\n**************************\n");
  
  initialisation(morpion);
  while (finDuJeu == 0){
    affichage(morpion);
    tour(joueurActuel, morpion);
    if (joueurActuel == ROND) joueurActuel = CROIX;
    else if(joueurActuel == CROIX) joueurActuel = ROND;

    finDuJeu = finPartie(morpion); // On regarde si le jeu est terminé
  }

  printf("\n ** Coup gagnant ** \n");
  affichage(morpion);

  switch(finDuJeu){ // Affichage du vainqueur 
    
  case 1: 
    printf("La team RONDS gagnent !\n");
    break;
 
  case 2:
    printf("La team CROIX gagnent !\n");
    break;
   
  case 3:
    printf("Le morpion est plein: Egalité ! !\n");
    break;
  }
 
  printf("\n \n *** FIN DE LA PARTIE, COMMENCER EN UNE AUTRE ***\n \n");
  return 0;
}