#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Objet{
	char nomObjet[100];
	int prix;
	char caracteristique[100];
};
typedef struct Objet objet;

objet epee = {"Epee de feu", 5, "Une epee flamboyante"};
objet bouclier = {"Bouclier des Abysses",5, "Un bouclier rapporte des enfers"};
objet potion = {"Potion des horreurs",5, "Un poison si puissant qu'il ferait hurler satan"};
objet lance = {"Lance du tonnerre",5, "Deferle un puissant orage sur vos ennemis"};
objet armure = {"Armure en fer",5, "Une armure pas farouche"};
objet peluche = {"Peluche",2, "Elle vous regarde dormir la nuit"};


struct Lieux{
	char description[1000];
	int gainargent;
	int gainvie;
	char acces[1000];
};
typedef struct Lieux lieux;

lieux chapitre1 = {"\nL'entree de la tour. Une grosse porte en bois qui garde une demeure de pierre.", 50, 20, "Vous pouvez entrer [5] ou bien faire le tour [4] ou aller au magasin [6]"};
lieux chapitre2 = {"\nL'arriere de la tour. Un endroit qui aurait pu servir de beau jardin, mais qui a ete laisse a l'abandon. Parmis les plantes, vous percevez une petit porte en fer qui peux vous permettre d'entrer dans la tour.",40, 20, "vous pouvez retourner à la porte principale [3] ou bien entrer [5]"};
lieux chapitre3 = {"\nLe hall d'entree de la tour. Malgre les meubles en bon etat, l'accumulation de poussiere donne l'impression que le lieu est abandonne.",0, 0, "Vous pouvez sortir par la porte principale [3] et par la porte arriere [4]"};
lieux chapitre4 = {"\nUn magasin cache dans les feuillages." ,16, 10, "Vous pouvez vous rendre à la tour en [3]"};


	// Choix du joueur

	int choix ;
	int choix2 ;
	int choix3 ;
	int choixCombat;
	int itemachat ;
	int deplacement = 1;

	//Monstre

	int viemonstre = 100;
	int attmonstre = 20;
	int simonstreattaque ;
	int simonstredéfend ;
	int argentmonstre ;
	int xpmonstre ;
	int battle = 0;


	// Taux d'apparition des monstres. A chaque choix, le taux d'apparition augmente de 1, et quand il arrive à 5, le joueur est attaqué avant que ce soit remis à 0

	int apparition = 0;


	//info joueur

  char prenom[100];
	int vie = 100;
	int xp = 0;
	int argentJoueur = 10;
	int defense = 0;
	int attaque = 0;

	//Achats Magasins

	int epee1 = 0;
	int bouclier1 = 0;
	int potion1 = 0;
	int lance1 = 0;
	int armure1 = 0;
	int peluche1 = 0;

//Combat

	//Attaque / def du monstre

int attaquedumonstre(int battle){
	simonstreattaque = rand() % 2;

	if (simonstreattaque == 1){
		printf("\nLe monstre attaque !");
		printf("\nVous perdez %d",attmonstre);
		vie = vie - attmonstre;
		simonstreattaque = 3;
	}else if (simonstreattaque == 2){
		printf("\nLe monstre attaque mais il rate !");
		simonstreattaque = 3;
	}

}

	//VS le monstre with menu
int combat(int apparition){
	if (apparition == 4)
	{
		printf("\n \nUN MONSTRE APPARAIT !\nUn combat s'engage !");

		while (viemonstre > 0, vie > 0){

		printf("\nQue faites-vous ?!");
		printf("\n[1] Attaquer \n[2] Défendre \n[3] Voir votre inventaire \n[4]Statistiques");
		scanf("\n%d", &choixCombat);



		switch (choixCombat){
					case 1:
						printf("\nVous attaquez !");
						printf("Le monstre perd %d HP",attaque);
						viemonstre = viemonstre - attaque;
						attaquedumonstre(battle);
						choixCombat= 0;
						break;

					case 2:
						printf("\nVous vous défendez ! \nLe monstre n'a pas pu attaquer.");
						choixCombat= 0;
						break;

					case 3:
					printf("\n=== Inventaire ===\n");
					printf("\nVous possédez \n %d %s \n", epee1, epee.nomObjet);
					printf("\n %d %s \n", bouclier1, bouclier.nomObjet);
			    printf("\n %d %s \n", potion1, potion.nomObjet);
			   	printf("\n %d %s \n", lance1, lance.nomObjet);
			   	printf("\n %d %s \n", armure1, armure.nomObjet);
			   	printf("\n %d %s \n", peluche1, peluche.nomObjet);
					break;

					case 4:

				 	printf("\n=== Vos statistiques ===\n");
				  printf("Experience = %d\n", xp);
				  printf("Points de vie = %d\n", vie);
				  printf("Argent = %d\n", argentJoueur);
				  printf("Defense = %d\n", defense);
				  printf("Attaque = %d\n", attaque);
				  break;

	}
}

if (vie <= 0){
	printf("vous etes mort \n");
	return 0;
}

	if (viemonstre <= 0){
		argentmonstre = rand() % 15;
		xpmonstre = rand() % 15;
		printf("\n Le monstre n'a plus de HP ! Vous remportez %d xp ainsi que %dpieces d'ors !\n",xpmonstre,argentmonstre);
		argentJoueur = argentJoueur + argentmonstre;
		xp = xp + xpmonstre;
}

	}
}

int main(){

	//Debut du jeu

    printf("Heros, veuillez designer votre nom.\n ");
    scanf("%s", prenom);
    printf("\nBienvenue %s, et merci de nous venir en aide ! \nIl y a peu, une fille du village a disparu. Nous soupconnons le sorcier de la tour voisine d'etre a l'origine de son enlevement.\n", prenom);

	while (vie > 0){

	printf("\nPouvez-vous aller la sauver ? \n [1] Oui \n [2] Non");
	scanf("\n%d", &choix2);

	while (choix2 == 2){

	printf("\nStp \n[1] Oui \n[2] Non");
	scanf("\n%d", &choix2);

	}

	if (choix2 == 1){
	printf("\nMerci %s \n", prenom);
    printf("\nVous avez %d/HP ! \n", vie);

	printf("\nVous gagnez la tour du sorcier. Il y a une entree principale, dotee d'une lourde porte en bois massif. Mais peut-etre y a-t-il une autre entree a l'arriere? \n");
    printf("\nQue desirez vous faire ? \n[3] Entree principale \n[4] Faire le tour pour trouver une autre entree \n[6] Allez au magasin ?");
    scanf("\n%d", &choix2);

	// Se deplacer d'un lieu à un autre

	while (deplacement == 1){

		switch (choix2){
					case 3:
						apparition = apparition + 1;
						combat(apparition);
						printf(" %s \n %s\n ", chapitre1.description);
						printf("\nVous pouvez \n[1] Fouiller l'endroit \n[2] partir");
						scanf ("\n%d",&choix3);

							switch (choix3){
								case 1:

								printf("\nVous trouvez %d\n", chapitre1.gainargent);
								argentJoueur = argentJoueur + chapitre1.gainargent;
								chapitre1.gainargent = 0;

								case 2 :
								printf("%s", chapitre1.acces);
								scanf("\n%d", &choix2);
								break;
							}
						break;

					case 4:
						apparition = apparition + 1;
						combat(apparition);
						printf(" %s \n %s \n", chapitre2.description);
						printf("\nVous pouvez \n[1]Fouiller l'endroit \n[2] partir");
						scanf ("\n%d",&choix3);

							switch (choix3){
								case 1:

								printf("\nVous trouvez %d\n", chapitre2.gainargent);
								argentJoueur = argentJoueur + chapitre2.gainargent;
								chapitre2.gainargent = 0;

								case 2 :
								printf("%s", chapitre2.acces);
								scanf("\n%d", &choix2);
								break;
							}
						break;

					case 5:
						apparition = apparition + 1;
						combat(apparition);
						printf(" %s \n %s \n", chapitre3.description);
						printf("\nVous pouvez \n[1]Fouiller l'endroit \n[2] partir");
						scanf ("\n%d",&choix3);

							switch (choix3){
								case 1:

								printf("\nVous trouvez %d\n", chapitre3.gainargent);
								argentJoueur = argentJoueur + chapitre3.gainargent;
								chapitre3.gainargent = 0;

								case 2 :
								printf("%s", chapitre3.acces);
								scanf("\n%d", &choix2);
								break;
							}
						break;

					case 6:
						apparition = apparition + 1;
						combat(apparition);
						printf(" %s \n %s ", chapitre4.description);
						printf("\nVendeur : Salut %s, que veux-tu aujourd'hui ?", prenom);

  // Magasin

  while (argentJoueur > 0){
    printf("\nVeux-tu m'acheter quelque chose ? \n[1] oui \n[2] non \n[3] Voir votre inventaire \n[4] Voir vos statistiques");
    scanf("\n%d", &choix);

    if (choix == 1){
    	printf("\nQue veux-tu acheter %s ?\n", prenom);
    	printf(" [1] %s | %d | %s \n", epee.nomObjet, epee.prix, epee.caracteristique);
    	printf(" [2] %s | %d | %s \n", bouclier.nomObjet, bouclier.prix, bouclier.caracteristique);
    	printf(" [3] %s | %d | %s \n", potion.nomObjet, potion.prix, potion.caracteristique);
    	printf(" [4] %s | %d | %s \n", lance.nomObjet, lance.prix, lance.caracteristique);
    	printf(" [5] %s | %d | %s \n", armure.nomObjet, armure.prix, armure.caracteristique);
    	printf(" [6] %s | %d | %s \n", peluche.nomObjet, peluche.prix, peluche.caracteristique);
    	scanf("%d", &itemachat);

		  switch (itemachat){
				case 1:
					printf("\nOkay Niquel Vla l'epee \n");
					argentJoueur = argentJoueur - epee.prix;
					epee1 = epee1 + 1;
					attaque = attaque + 10;
					printf("Il te reste %d\n", argentJoueur);
				break;

				case 2:
					printf("\nOkay Perfect Vla le bouclier \n");
					argentJoueur = argentJoueur - bouclier.prix;
					bouclier1 = bouclier1 + 1;
					defense = defense + 10;
					printf("Zyva il te reste %d\n", argentJoueur );
				break;

				case 3:
					printf("\n... Eu... ok, voilà la potion \n");
					argentJoueur = argentJoueur - potion.prix;
					potion1 = potion1 + 1;
					printf("Zyva il te reste %d\n", argentJoueur );
				break;

				case 4:
					printf("\nOkay zyva la Lance \n");
					argentJoueur = argentJoueur - lance.prix;
					lance1 = lance1 + 1;
					attaque = attaque + 10;
					printf("Zyva il te reste %d\n", argentJoueur );

				case 5:
					printf("\n'Kay vla l'armure, protège toi bien ptit chou \n");
					argentJoueur = argentJoueur - armure.prix;
					armure1 = armure1 + 1;
					defense = defense + 20;
					printf("Zyva il te reste %d\n", argentJoueur );
				break;

				case 6:
					printf("\nOH OUI PRENDS CETTE HORREUR ! ... hum, je veux dire... Un choix judicieux. \n");
					argentJoueur = argentJoueur - peluche.prix;
					peluche1 = peluche1 + 1;
					printf("Zyva il te reste %d\n", argentJoueur );
				break;
	    }
    }else if (choix == 2){
		  printf("%s", chapitre4.acces);
		  scanf("\n%d", &choix2);
		break;

	  }else if (choix == 3){

		printf("\n=== Inventaire ===\n");
		printf("\nVous possédez \n %d %s \n", epee1, epee.nomObjet);
		printf("\n %d %s \n", bouclier1, bouclier.nomObjet);
    	printf("\n %d %s \n", potion1, potion.nomObjet);
    	printf("\n %d %s \n", lance1, lance.nomObjet);
    	printf("\n %d %s \n", armure1, armure.nomObjet);
    	printf("\n %d %s \n", peluche1, peluche.nomObjet);
	  }else if (choix == 4){

		  printf("\n=== Vos statistiques ===\n");
		  printf("Experience = %d\n", xp);
		  printf("Points de vie = %d\n", vie);
		  printf("Argent = %d\n", argentJoueur);
		  printf("Defense = %d\n", defense);
		  printf("Attaque = %d\n", attaque);
	  }
	}
		}
	}


		if (argentJoueur <= 0){
		printf("T'as plus d'argent fdp \n *Vous etes jete dehors* \n");
	}
					}





    return 0;
}
}
