#include <stdio.h>
#define NB_SYSTNUM 5

int main(void){
    int syst_num = 0;
    int type_traitement = 0;
    int type_traitement2 = 0;
    int type_traitement3 = 0;
    int nb_donne1 = 0;
    int nb_donne2 = 0;
    int car_actuel;
    char syst_nom[NB_SYSTNUM];
    char emplacement_fic;
    char *ligne_fic;
    FILE* f = NULL;

    // Initialisation du tableau
    syst_nom[0] = Grecque;
    syst_nom[1] = Egyptien;
    syst_nom[2] = Chinois;
    syst_nom[3] = Japonais;
    syst_nom[4] = Romain;

    printf("Bienvenue sur le programme de conversion du syst�me de num�ration indo-arabe � un autre.\n");
    printf("Dans quel syst�me souhaitez vous effectuer une conversion?\n");
    printf("Appuyez sur :\n");
    printf("0 - Grecque\n1 - Egyptien(Babylonien)\n2 - Chinois\n3 - Japonais\n4 - Romain\n");
    scanf("%d",&syst_num);
    system("clear");

    printf("Vous avez choisi '%s'. D�sirez-vous appliquer le programme � un fichier texte ou bien sur un seul chiffre en ligne de commande?\n",syst_nom[syst_num]);
    printf("0 - Appliquer � un fichier\n1 - Appliquer en ligne de commande\n");
    scanf("%d",&type_traitement);
    if((type_traitement != 1) && (type_traitement != 0)){
        printf("Vous avez donn� un nombre qui ne correspond � aucun type de traitement, veuillez r�essayer.\n");
        printf("0 - Appliquer � un fichier\n1 - Appliquer en ligne de commande\n");
        scanf("%d",&type_traitement);
        if((type_traitement != 1) && (type_traitement != 0)){
            printf("Erreur1 - Traitement inexistant\n");
            return 1;
        }
    }
    system("clear");

    if(type_traitement == 0){
        printf("Vous avez choisi d'appliquer le programme � un fichier texte, veuillez ecrire le chemin relatif de l'emplacement du fichier.\n");// Chemin relatif portable
        scanf("%s",&emplacement_fic);
        f = fopen(emplacement_fic,"r");
        if(f != NULL){
	    printf("En choisissant de traiter un fichier texte vous avez la possibilit� de traduire ou bien d'utiliser notre calculatrice int�gr�e(en respectant le formatage indiqu� dans le ReadMe).\n");
	    printf("Tapez :\n");
	    printf("0 - Traduction\n");
	    printf("1 - Calcul\n");
	    scanf("%d",&type_traitement2);
	    system("clear");
	    if((type_traitement2 != 0) && (type_traitement2 != 1)){
	        printf("Vous avez donn� un nombre qui ne correspond � aucun type de traitement, veuillez r�essayer.\n");
        	printf("0 - Traduction\n1 - Calcul\n");
        	scanf("%d",&type_traitement2);
        	if((type_traitement != 1) && (type_traitement != 0)){
                    printf("Erreur1 - Traitement inexistant");
                    return 1;
                }
	    }
	    else if(type_traitement==0){
	        do
                {
                    car_actuel = fgetc(f);
                    printf("%c", car_actuel);
                } while (car_actuel != EOF);
                fclose(f);
	    }
	    else{
		fscanf("%d %d",&nb_donne1,&nb_donne2);
		printf("Quelle op�ration souhaitez vous faire?\n");
		printf("Vous avez le choix entre :\n");
		printf("0 - Multiplication\n1 - Addition\n2 - Soustraction\n3 - Division\n");
		scanf("%d",&type_traitement3);
		switch(syst_num){
		    case 0 :
			if(type_traitement == 0) cv_grec(nb_donne1*nb_donne2) ;
			else if(type_traitement == 1) cv_grec(nb_donne1+nb_donne2) ;
			else if(type_traitement == 2) cv_grec(nb_donne1-nb_donne2) ;
			else if(type_traitement == 3) cv_grec(nb_donne1/nb_donne2) ;
			else{
				printf("Erreur1 - Traitement inexistant\n");
				return 1;
			}
		        break;
		    case 1 :
		        if(type_traitement == 0) cv_egypt(nb_donne1*nb_donne2) ;
			else if(type_traitement == 1) cv_egypt(nb_donne1+nb_donne2) ;
			else if(type_traitement == 2) cv_egypt(nb_donne1-nb_donne2) ;
			else if(type_traitement == 3) cv_egypt(nb_donne1/nb_donne2) ;
			else{
				printf("Erreur1 - Traitement inexistant\n");
				return 1;
			}
		        break;
		    case 2:
		        if(type_traitement == 0) cv_chin(nb_donne1*nb_donne2) ;
			else if(type_traitement == 1) cv_chin(nb_donne1+nb_donne2) ;
			else if(type_traitement == 2) cv_chin(nb_donne1-nb_donne2) ;
			else if(type_traitement == 3) cv_chin(nb_donne1/nb_donne2) ;
			else{
				printf("Erreur1 - Traitement inexistant\n");
				return 1;
			}
		        break;
		    case 3 :
		        if(type_traitement == 0) cv_jap(nb_donne1*nb_donne2) ;
			else if(type_traitement == 1) cv_jap(nb_donne1+nb_donne2) ;
			else if(type_traitement == 2) cv_jap(nb_donne1-nb_donne2) ;
			else if(type_traitement == 3) cv_jap(nb_donne1/nb_donne2) ;
			else{
				printf("Erreur1 - Traitement inexistant\n");
				return 1;
			}
		        break;
		    case 4 :
		        if(type_traitement == 0) cv_rom(nb_donne1*nb_donne2) ;
			else if(type_traitement == 1) cv_rom(nb_donne1+nb_donne2) ;
			else if(type_traitement == 2) cv_rom(nb_donne1-nb_donne2) ;
			else if(type_traitement == 3) cv_rom(nb_donne1/nb_donne2) ;
			else{
				printf("Erreur1 - Traitement inexistant\n");
				return 1;
			}
		        break;
		    default :
		        printf("Erreur2 - systeme de num inexistant\n");
		        return 2;
		}
	    }
        }
        else{
            printf("Erreur3 - Le fichier n'existe pas.\n");
            return 3;
        }
    }
    else{
        printf("Vous avez choisi d'appliquer le programme en ligne de commande, �crivez votre nombre :\n");
        scanf("%d",&nb_donne1);
        switch(syst_num){
            case 0 :
                cv_grec(nb_donne1);
                break;
            case 1 :
                cv_egypt(nb_donne1);
                break;
            case 2:
                cv_chin(nb_donne1);
                break;
            case 3 :
                cv_jap(nb_donne1);
                break;
            case 4 :
                cv_rom(nb_donne1);
                break;
            default :
                printf("Erreur2 - systeme de num inexistant\n");
                return 2;
        }
    }
    return 0;
}
