#include <stdio.h>
#include <stdlab.h>
#include <conio.h>
#include <string.h>
#define password 70;

/******************infos d un adherent***********************************/
 struct adherent{
	int num_adh;
	char* nom_adh;
	char* prenom_adh;
	char* email_adh;
	char* adress_adh;
	int nbre_emprunts_adh;
}ad,adh;
/******************infos relatifs a l'autuer***********************************/
struct auteur {
	char* nom_aut;
	char* prenom_aut;
};
/******************infos sur les livres***********************************/
 struct livre{
	int num_liv;
	char* titre_liv;
	char* categ_liv;
	int emprunteur_liv;
	auteur *aut;
}lv,lvr;
/**********************************LES FICHIERS DE STOCKAGE D'INFOS****************************************************/
FILE *f_adh,*f_liv;
/*********************************PROTOTYPE DE TOUTES LES FONCTIONS UTILISABLES***************************************/
void menu_principal(void);
void GESTION_ADHERENT(void);
void GESTION_LIVRES(void);
void GESTION_EMPRUNTS(void);
void QUITTEER(void);
void ajout_adh(void);
void supprimer_adh(void);
void modifier_adh(void);
void recherche_adh(void);
void ajout_lvr(void);
void supprimer_lvr(void);
void modifier_lvr(void);
void ordonner_lvr(void);
void recherche_lvr(void);
int exist_liv(int num)
int exist_adh(int num)
void print_adh(struct adherent)
void print_liv(struct livre)
/*********************************MENU****************************************************/
int main(void)//main a rendre au dernier place;
{
    clrscr();
    gotoxy(35,12);printf("Bienvenu dans la librairie");
    gotoxy(35,13);printf("cliquez sur n'importe quelle touche pour continuer");
    getch();
    menu_principal();
    return 0;
}
void menu_principal(void){
    int choix;
    do
    {
        clrscr();
        gotoxy(35,1);printf("MENU PRINCPAL ");
        gotoxy(36,2)printf("1 : Gestion des adherents ");
        gotoxy(36,3)printf("2 : Gestion des livres ");
        gotoxy(36,4)printf("3 : gestion des emprunts ");
        gotoxy(36,5)printf("4:QUITTER");
		gotoxy(36,6)printf("priere d'entrer votre choix:");
        scanf("%d",&choix);
        switch(choix)
        {
            case 1: GESTION_ADHERENT();
                    break;
            case 2: GESTION_LIVRES();
                    break;
            case 3: GESTION_EMPRUNTS();
                    break;
			case 4:	QUITTER();
                    break;			
            default: printf("le choix doit etre de 1 a 4");
                    getch();
       
    }while(1);
	getch();
	return;
}
void GESTION_ADHERENT(void){
	   

        do{
	    gotoxy(35,1);printf("bonjour dans la zone GESTION DES ADHERENT");
        gotoxy(36,2)printf("1 : ajouter ");
        gotoxy(36,3)printf("2 :modifier ");
        gotoxy(36,4)printf("3 : supprimer ");
        gotoxy(36,5)printf("4: recherche adherent");
	    gotoxy(36,6)printf("priere d'entrer votre choix:");
        gotoxy(66,6);scanf("%d",&choix);
        switch(choix)
        {
            case 1: ajout_adh();
                    break;
            case 2: modifier_adh();
                    break;
            case 3: supprimer_adh();
                    break;
            case 4: recherche_adh();
                    break;
			case 5: QUITTER();
                    break;		
			default: printf("le choix doit etre 1,2 ou 3 ");
                    getch();
       
    }while(1);
	getch();
    return;
		}
		
void ajout_adh(void){
	char c;
	clrscr();
	do{
	f_adh=fopen("adherent.txt","w");
	gotoxy(35,1);printf("veillez remplir ce formulaire");
	gotoxy(10,2);printf("numero :");
	gotoxy(10,3);printf("nom :");
	gotoxy(10,4);printf("prenom :");
	gotoxy(10,5);printf("adresse mail :");
	gotoxy(10,6);printf("adresse personelle :");
	gotoxy(10,7);printf("livres emprunté :");
	gotoxy(19,2);scanf("%d",&adh.num_adh);
	gotoxy(16,3);scanf("%s",&adh.nom_adh);
	gotoxy(19,4);scanf("%s",&adh.prenom_adh);
	gotoxy(25,5);scanf("%s",&adh.email_adh);
	gotoxy(31,6);scanf("%s",&adh.adress_adh);
	gotoxy(28,7);scanf("%d",&adh.nbre_emprunts_adh);
	fwrite(&adh,sizeof(struct adherent),1,f_adh);
	clrscr();
	gotoxy(35,10);printf("voulez vous ajouter un autre adherent (o/n) :");
	gotoxy(82,10);scanf("%c",&c);
	
	}while(c=='o' || c== 'O');
	fclose(f_adh);
	return;
}
int exist_adh(int num)
{
    FILE *a;
    int i=0;
    a=fopen("adherent.txt","r");
    while(!feof(a))
    {
        if(fread(&ad,sizeof(struct adherent),1,a)==1)
            if(ad.num_adh==num)
        {
            i=1;
            break;
        }
    }
    fclose(a);
    return i;
}
void modifier_adh(void){
	ETQ:
	clrscr();
	char C;
	int id;
	do{
	printf("donner le numero de l'adherent que vous souhaitez modifier: ");
	gotoxy(61,1);scanf("%d",&id);
	f_adh=fopen("adherent.txt","r");
	FILE *ftmp;
	ftmp=fopen("temporiaire.txt","w");
	if(exist_adh(id)==1){
	while(!feof(f_adh)){
	   fread(&ad,sizeof(adherent),1,f_adh);
	    if(ad.num_adh==id){
            gotoxy(35,1);printf("veillez entrer les modifications  ");
	        gotoxy(10,3);printf("nom :");
	        gotoxy(10,4);printf("prenom :");
	        gotoxy(10,5);printf("adresse mail :");
	        gotoxy(10,6);printf("adresse personelle :");
	        gotoxy(10,7);printf("nombre livres empruntés :");
	        gotoxy(16,3);scanf("%s",&ad.nom_adh);
	        gotoxy(19,4);scanf("%s",&ad.prenom_adh);
	        gotoxy(25,5);scanf("%s",&ad.email_adh);
	        gotoxy(31,6);scanf("%s",&ad.adress_adh);
	        gotoxy(28,7);scanf("%d",&ad.nbre_emprunts_adh);
	        };
			break;
	}
	
     while(!feof(ftmp)){
		 fread(&adh,sizeof(adherent),1,f_adh);
		 if(adh.num_adh!=id)  fwrite(&adh,sizeof(struct adherent),1,ftmp);
			 }
	fclose(f_adh);
	remove("adherent.txt");
	fwrite(&ad,sizeof(struct adherent),1,ftmp);
	fclose(ftmp);
	rename("temporaire.txt","adherent.txt");
	clrscr();
	textcolor(2);cprintf("modifications enregistrés. taper pour continuer");
	getch();
	
	gotoxy(35,10);printf("voulez-vous modifier un autre adherent? (o/n)");
	gotoxy(80,10);scanf("%c",&C);
	}while(C=='o'|| C=='O');
	}
	 else{
		int x;
		printf("\nce numero n'est pas enregistré");
        printf("\n taper :\n  1:revenir au menu\n  2:essayer un autre numero");
		scanf("%d",&x);
		switch(x){
			case 1:return;
			       break;
			case 2: goto ETQ;
			        break;
			 default: printf("choisir 1 ou 2");		
			        break;
		        }
		
	getch();
	return;
}
void supprimer_adh(void){
     ETQ1: 
	 clrscr();
	 int id;
	 gotoxy(35,10);printf("donner le numero de l'adherent que vous souhaitez supprimer: ");
	 gotoxy(62,10);scanf("%d",&id);
	 if(exist_adh==1){
	 f_adh=fopen("adherent.txt","r");
	 FILE *ftmp;
	 ftmp=fopen("temporaire.txt","w");
	 while(!feof(f_adh)){
	    fread(&ad,sizeof(adherent),1,f_adh);
	   if !(ad.num_adh==id){
	   fwrite(&ad,sizeof(adherent),1,ftmp);
	   };
	fclose(ftmp);
    remove("adherent.txt");
    rename("temporaire.txt","adherent.txt");		
}
    else{
		int x;
		printf("\nce numero n'est pas enregistré");
        printf("\n taper :\n  1:revenir au menu\n  2:essayer un autre numero");
		scanf("%d",&x);
		switch(x){
			case 1:return;
			       break;
			case 2: goto ETQ1;
			        break;
			 default: printf("choisir 1 ou 2");		
			        break;
		        }
	getch();		
	return;
	}	
void print_adh(struct adherent a){ // fonction pour faciliter l'affichage
	  printf("numero : %d\nprenom: %s\nadresse mail: %s\nadresse personelle: %s\n",a.num_adh,a.prenom_adh,a.email_adh,a.adress_adh);
}		
void recherche_adh(void){
         ETIQUETTE:
		 clrscr();
		 char* nom;
		 int compteur=0;//si il y aurai plusieurs adherents de meme nom
		 printf("veillez entrer le nom de l'adherent que vous recherchez : ");
		 scanf("%s",&nom);
		 f_adh=fopen("adherent.txt","r");
		 FILE* f_tpm;
		 f_tpm=fopen("temporaire.txt","w");
		 while(!feof(f_adh)){
			 fread(&ad,sizeof(adherent),1,f_adh);
			 if(ad.nom_adh == nom){
				fwrite(&ad,sizeof(adherent),1,f_tmp);//penser a changer sizeof(adherent) c est pas nettt!!!!!!!!!!!!
				compteur++;
				 }	 
		 }
         fclose(f_adh);
		 rewind(f_tmp);
		 fclose(f_tmp);
		 f_tmp=fopen("temporaire","r");
		 clrscr();
		 while(!feof(f_tmp)){
			 printf("\nIl y a %d adherents avec ce nom\n",compteur);
			 fread(&ad,sizeof(adherent),1,f_tmp);
			 print_adh(ad);
		 }
		 fclose(f_tmp);
		 remove("temporaire,txt");
		 if(compteur==0){
			       printf("ce nom ne figure pas dans les adherents priere de taper autre nom");
				   getch();
		           goto ETIQUETTE;
		                }
		 
		 getch();
		 return;
}
/****************************************************************************************



                    GESTION LIVRES



*********************************************************************************/
void GESTION_LIVRES(void){
	   

        do{
	    gotoxy(35,1);printf("bonjour dans la zone GESTION DES LIVRES");
        gotoxy(36,2)printf("1 : ajouter ");
        gotoxy(36,3)printf("2 :modifier ");
        gotoxy(36,4)printf("3 : supprimer ");
        gotoxy(36,5)printf("4: ordonner les livres par categories");
	    gotoxy(36,6)printf("5: recherche d'un livre par categorie et titre");
        gotoxy(36,7)printf("6: QUITTER");
		gotoxy(36,8)printf("priere d'entrer votre choix:");
        gotoxy(66,8);scanf("%d",&choix);
        switch(choix)
        {
            case 1: ajout_lvr();
                    break;
            case 2: modifier_lvr();
                    break;
            case 3: supprimer_lvr();
                    break;
            case 4: ordonner_lvr();
                    break;
			case 5: recherche_lvr();
                    break;		
			case 6: QUITTER();
			        break;
			default: printf("le choix doit etre 1,2 ou 3 ");
                    getch();
       
    }while(1);
	getch();
    return;
		}
void ajout_lvr(void){
	char c;
	clrscr();
	do{
	f_liv=fopen("livre.txt","w");
	gotoxy(35,1);printf("veillez remplir ce formulaire");
	gotoxy(10,2);printf("numero du livre :");
	gotoxy(10,3);printf("titre :");
	gotoxy(10,4);printf("categorie :");
	gotoxy(10,5);printf("prenom d'auteur :");
	gotoxy(10,6);printf("nom d'auteur :");
	gotoxy(10,7);printf("numero d'emprunteur du livre :");
	gotoxy(28,2);scanf("%d",&lvr.num_liv);
	gotoxy(18,3);scanf("%s",&lvr.titre.liv);
	gotoxy(22,4);scanf("%s",&lvr.categ_liv);
	gotoxy(28,5);scanf("%s",&lvr.(aut->prenom_aut));//PAS SUUUUUUUUUUUR
	gotoxy(25,6);scanf("%s",&lvr.(aut->nom_aut));//PAS SUUUUUUUUUR
	gotoxy(41,7);scanf("%d",&lvr.emprunteur_liv);
	fwrite(&lvr,sizeof(struct livre),1,f_liv);
	clrscr();
	gotoxy(35,10);printf("voulez vous ajouter un autre livre (o/n) :");
	gotoxy(80,10);scanf("%c",&c);
	
	}while(c=='o' || c== 'O');
	fclose(f_liv);
	return;
}
int exist_liv(int num)
{
    FILE *a;
    int i=0;
    a=fopen("livre.txt","r");
    while(!feof(a))
    {
        if(fread(&lv,sizeof(struct livre),1,a)==1)
            if(lv.num_liv==num)
        {
            i=1;
            break;
        }
    }
    fclose(a);
    return i;
}
void modifier_lvr(void){
	ETQ:
	clrscr();
	char C;
	int id;
	do{
	printf("donner le numero du livre que vous souhaitez modifier: ");
	gotoxy(56,1);scanf("%d",&id);
	f_liv=fopen("livre.txt","w");
	if(exist_liv(id)==1){
	while(!feof(f_liv)){
	   fread(&lv,sizeof(struct livre),1,f_liv);
	    if(lv.num_liv==id){
            gotoxy(35,1);printf("veillez entrer les modifications");
	        gotoxy(10,2);printf("titre :");
	        gotoxy(10,3);printf("categorie :");
	        gotoxy(10,4);printf("prenom d'auteur :");
	        gotoxy(10,5);printf("nom d'auteur :");
	        gotoxy(10,6);printf("numero d'emprunteur du livre :");
	        gotoxy(18,2);scanf("%s",&lv.titre.liv);
	        gotoxy(22,3);scanf("%s",&lv.categ_liv);
	        gotoxy(28,4);scanf("%s",&lv.(aut->prenom_aut));//PAS SUUUUUUUUUUUR
	        gotoxy(25,5);scanf("%s",&lv.(aut->nom_aut));//PAS SUUUUUUUUUR
	        gotoxy(41,6);scanf("%d",&lv.emprunteur_liv);
	        };
			break;
	}
	fclose(f_liv);
	f_liv=fopen("livre.txt","w");
	fwrite(&lv,sizeof(struct livre),1,f_liv);
	fclose(f_liv);
	clrscr();
	textcolor(2);cprintf("modifications enregistrés. taper pour continuer");
	getch();
	
	gotoxy(35,10);printf("voulez-vous modifier un autre livre? (o/n)");
	gotoxy(77,10);scanf("%c",&C);
	}while(C=='o'|| C=='O');
	}
	 else{
		int x;
		printf("\nce numero n'est pas enregistré");
        printf("\n taper :\n  1:revenir au menu\n  2:essayer un autre numero");
		scanf("%d",&x);
		switch(x){
			case 1:return;
			       break;
			case 2: goto ETQ;
			        break;
			 default: printf("choisir 1 ou 2");		
			        break;
		        }
		
	getch();
	return;
}
void supprimer_lvr(void){
     ETQ1: 
	 clrscr();
	 int id;
	 gotoxy(35,10);printf("donner le numero du livre que vous souhaitez supprimer: ");
	 gotoxy(57,10);scanf("%d",&id);
	 if(exist_liv(id)==1){
	 f_liv=fopen("livre.txt","r");
	 FILE *ftmp;
	 ftmp=fopen("temporaire.txt","w");
	 while(!feof(f_liv)){
	    fread(&lv,sizeof(struct livre),1,f_liv);
	   if !(lv.num_liv==id){
	   fwrite(&lv,sizeof(struct livre),1,ftmp);
	   };
	fclose(ftmp);
    remove("adherent.txt");
    rename("temporaire.txt","adherent.txt");		
}
    else{
		int x;
		printf("\nce numero n'est pas enregistré");
        printf("\n taper :\n  1:revenir au menu\n  2:essayer un autre numero");
		scanf("%d",&x);
		switch(x){
			case 1:return;
			       break;
			case 2: goto ETQ1;
			        break;
			 default: printf("choisir 1 ou 2");		
			        break;
		        }
	getch();		
	return;
}

























void emprunt(void){
        clrscr();
		int id,i=1,j=0;
		printf("veillez entrer votre id : ");
		scanf("%d",&id);
		clrscr();
		//verification que le nbr emprunte ne depasse pas 3
		fopen(f_adh,rb);
		while(!feof){
			fread(&ad,sizeof(ad),1,f_adh);//ad pour le stockage adh pour le passage au fichier
			if(ad.num_adh == id){
				if (ad.nbre_emprunts_adh>=3){
					textcolor(4);cprintf("vous devez rendre un livre pour pouvoir en prendre un autre");
					cprintf("\n vous serez redirigé vers le menu ");
					ADHERENT();
					i=0;
				}
			}
		}
		fclose(f_adh);
		printf("");
}	
		
void QUITTER(void)
{
    clrscr();
    printf("\n\n\t\t voulez-vous vraiment quitter ?(O/N) : ");
    char ch;
    scanf(" %c",&ch);
    if(ch=='o'||ch=='O')
        exit(1);
    return;
}
	
	
	
	
	
	
	
	
	
	
	return 0;
	
}