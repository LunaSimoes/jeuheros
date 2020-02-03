#include <stdio.h>
#include <string.h>

int main()
{
    char prenom[100];

    int choix ;
	int vie = 100;

    printf("Heros, veuillez designer votre nom. ");
    scanf("%s", prenom);
    printf("Bienvenue %s, et merci de nous venir en aide ! \nIl y a peu, une fille du village a disparu. Nous soupconnons le sorcier de la tour voisine d'etre a l'origine de son enlevement. \n", prenom);
	
	while (vie > 0){
	
	printf("Pouvez-vous aller la sauver ? \n [1] Oui  [2] Non");
	scanf("%d", &choix);
	
	if (choix == 2){
		
	printf("Stp \n");
	
	}
	
	if (choix == 1){
		printf("Merci %s", prenom);
    printf("Tu as %d points de vie\n", vie);

	printf("vous gagnez la tour du sorcier. Il y a une entree principale, dotee d'une lourde porte en bois massif. Mais peut-etre y a-t-il une autre entree a l'arriere? \n");
    printf("Que desirez vous faire ? \n [3] Entree principale \n [4] Faire le tour pour trouver une autre entree /n");
    scanf("%d", &choix);

    if (choix == 3){
    	printf("Vous decidez d'entree par la porte principale. \n.");
	}

	if (choix == 4){
		printf("Vous faites le tour pour gagner l'autre côté. \n");
	}

		}

		if (vie <= 0){
			printf("vous etes mort \n");
		}
					}





    return 0;
}