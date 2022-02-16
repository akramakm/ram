#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct date{
    int jour;
    int mois;
    int annee;
}date;

typedef struct adresse{

    int num;
    char ville[20];
}adresse;

typedef struct etudiant{
    char nom[50];
    char prenom[50];
    int cne;
    adresse hbt;
    date naissance;
}etudiant;

void echange_Etd(int i, int j, etudiant * Letd);
//Fonction saisi qui prend comme arguments la taille de type Int et qui retourne un pointeur
// qui pointe sur le type d’étudiant. On utilise cette fonction pour la saisi des informations.
etudiant* saisi(int taille)
{
    etudiant *tab;
    tab = (etudiant*)malloc(taille * sizeof(etudiant));
    int i;
    for(i = 0;i < taille ; i++)
    {
        printf("veuiller saisir le nom du %d etudiant\n",i + 1 );
        scanf("%s",tab[i].nom);
        printf("veuiller saisir le prenom du %d etudiant\n",i + 1 );
        scanf("%s",tab[i].prenom);
        printf("veuiller saisir le cne du %d etudiant\n",i + 1 );
        scanf("%d",&tab[i].cne);
        printf("veuiller saisir le jour de naissance du %d etudiant\n",i + 1 );
        scanf("%d",&tab[i].naissance.jour);
        printf("veuiller saisir le mois de naissance du %d etudiant\n",i + 1 );
        scanf("%d",&tab[i].naissance.mois);
         printf("veuiller saisir l annee de naissance du %d etudiant\n",i + 1 );
        scanf("%d",&tab[i].naissance.annee);
        printf("veuiller saisir le num de la maison du %d etudiant\n",i + 1 );
        scanf("%d",&tab[i].hbt.num);
        printf("veuiller saisir l ville du %d etudiant\n",i + 1 );
        scanf("%s",tab[i].hbt.ville);
    }
    return tab;
}
// Une fonction Afficher qui prend comme argument un pointeur de type étudiant et la taille. Une fonction qui affiche les informations d’étudiant. 
void afficher(etudiant *LEtd , int taille)
{
    int v;
    for (v = 0 ; v < taille ;v++)
    {
        printf(" nom : %s \n prenom: %s \n cne : %d \n  date de naissance : %d\t/\t%d/\t%d \n  l adresse : \n\t num : %d \n \tville : %s\n ",LEtd[v].nom,LEtd[v].prenom,LEtd[v].cne,LEtd[v].naissance.jour,LEtd[v].naissance.mois,LEtd[v].naissance.annee,LEtd[v].hbt.num,LEtd[v].hbt.ville);
        
    }
}

int menu(void)
{
	int choice;
	do {
		printf("\n\n\n\n__Choisissez une operation\n\n");
		printf("   1 -> Afficher la liste des etdudiants?\n");
		printf("   2 -> Trier la liste des etdudiants?\n");
		printf("   3 -> Afficher un etudiant dont vous connaissez le CNE?\n");
		printf("   4 -> Afficher un etudiant dont vous connaissez le nom?\n");
		printf("   5 -> Supprimer un etudiant par CNE?\n");
			printf("   6 -> methode dechotomie\n");
		printf("   0 -> Quitter l'application?\n");
		printf("\n\n___Votre choix ===>>>>> ");
		scanf("%d",&choice);
		
		if (choice < 0 || choice > 7) {
			printf ("\nsaisie invalide\n");
		}
	}while(choice< 0 || choice >7);
	return choice;
}
//Une fonction Affiche par CNE qui recherche (séquentielle) et affiche les informations d'un étudiant par son CNE. 
void AfficheParCNE(etudiant *LEtd, int cne, int taille)
{
    for(int v=0;v < taille;v++)
    {
        if(cne == LEtd[v].cne)
        {
            printf(" nom : %s \n prenom: %s \n cne : %d \n  date de naissance : %d\t/\t%d/\t%d \n  l adresse : \n\t num : %d \n \tville : %s\n ",LEtd[v].nom,LEtd[v].prenom,LEtd[v].cne,LEtd[v].naissance.jour,LEtd[v].naissance.mois,LEtd[v].naissance.annee,LEtd[v].hbt.num,LEtd[v].hbt.ville);
        }
    }
}
etudiant * ChercherDich(etudiant *Letd, int taille) {
    char aChercher[21] ;
    int  mini, maxi, milieu, trouve ;
    int  compare, longueur ;

    printf("\n\n>>>>>>>     RECHERCHE DICHOTOMIQUE     <<<<<<<<<\n");

    printf("\n\n>>>>>>>     Entrez le nom de l'etudiant recherche  >>\t");
    fflush(stdin);
    gets(aChercher); /* get string = lire une cha�ne */

    longueur = strlen(aChercher) ;

    mini = 0           ;
    maxi = taille - 1 ;
    trouve = 0 ; /* on ne trouve pas encore */
    while (!trouve && mini <= maxi) {
        milieu = (mini + maxi) / 2 ;
        compare = strncmp(aChercher, Letd[milieu].nom, longueur);
        if ( compare < 0 )
            maxi = milieu - 1 ;
        else  if (compare > 0)
            mini = milieu + 1 ;
        else trouve = 1 ;
    }
    if (!trouve)
    {
        printf("Desole, on ne trouve pas %s\n", aChercher);
    }

    else 
    {
        return (Letd+milieu);
    }
}
//Une fonction Affiche par Nom qui recherche (séquentielle) et affiche les informations d'un étudiant par son nom. 
void afficheParNom(etudiant *LEtd, char * nm, int taille)
{
    for(int v=0;v < taille;v++)
    {
        if(strcmp(nm,LEtd[v].nom) == 0)
        {
            printf(" nom : %s \n prenom: %s \n cne : %d \n  date de naissance : %d\t/\t%d/\t%d \n  l adresse : \n\t num : %d \n \tville : %s\n ",LEtd[v].nom,LEtd[v].prenom,LEtd[v].cne,LEtd[v].naissance.jour,LEtd[v].naissance.mois,LEtd[v].naissance.annee,LEtd[v].hbt.num,LEtd[v].hbt.ville);
        }
    }
}
// Une fonction Echange qui prend en argument un pointeur de type étudiant (*Letd) et deux entiers i et j. Une fonction qui 
//permet d’échanger deux étudiants d’indices i et j.
void echange_Etd(int i, int j, etudiant * Letd)
{
    etudiant tmp;

    tmp =  *(Letd+i);
    *(Letd+i) = *(Letd+j);
    *(Letd+j) = tmp;
}

//Une fonction de suppression qui supprime la première occurrence d'un étudiant selon son CNE. 
//Cette fonction affiche le tableau après la suppression de l'étudiant.
void SupprimerEtdParCNE(etudiant *LEtd, int cne, int *taille){
    int  i=0,j;
    
    while(LEtd[i].cne != cne && i < *taille)
        i++;
    for(j=i; j<*taille-1; j++)
    {
        LEtd[j]=LEtd[j+1];
    }
    (*taille)--;                  
}
//Une fonction de Tri par sélection qui prend comme arguments un pointeur de type étudiant et la taille de type Int.
// Cette fonction permet de trier par sélection du tableau des étudiants 
void tri_par_nom(etudiant *l,int taille)
{
    int i;
    int j;
    for(i=0;i<taille-1;i++)
    {
        for(j=i+1;j<taille;j++)
        {
            if (strcmp(l[j].nom,l[i].nom) < 0){
              echange_Etd(i,j,l);
            }
        }
    }
}

int main()
{
    int nbEtd, choix, cne;
	char nomCherche[20], c;
	printf("\n-Entrez la taille de la liste des etdudiants : \t" ) ;
	scanf( "%d" , &nbEtd) ;
	etudiant *ListeEtd;
	ListeEtd = saisi(nbEtd);
	do{
		choix=menu();
		switch(choix) {
			//case 1 :saisie(nbEtd); break;

			case 1 :afficher(ListeEtd, nbEtd); 
			break;

			case 2 :tri_par_nom(ListeEtd, nbEtd);afficher(ListeEtd, nbEtd); 
			break;

			case 3 : printf("ENTRER LE CNE  ?\t");
				scanf("%d",&cne);
				AfficheParCNE(ListeEtd,cne, nbEtd);
			break;

			case  4: printf("donnez le nom de l etudiant ?\t");
				scanf("%s",nomCherche);
				afficheParNom(ListeEtd, nomCherche, nbEtd);
		    break;
			case 5 : printf("donnez le cne?\t");
				scanf("%d",&cne);
				SupprimerEtdParCNE(ListeEtd,cne, &nbEtd);
			break;
		}
	}while(choix!=0);
	free(ListeEtd);
	ListeEtd=0;
            return 0;
}