#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30

static int x = 0;

struct address{
	char vname[MAX];
	char nname[MAX];
	long PLZ;
	char ort[MAX];
	int geburtsjahr;
}adressen[100];

void Eingabe(int nr, struct address neu[]){
	printf("Vorname      : ");
	fgets(neu[nr].vname, MAX, stdin);

	printf("Nachname     : ");
	fgets(neu[nr].nname, MAX, stdin);

	printf("Postleitzahl : ");
	do{
		scanf("%ld", &neu[nr].PLZ);
	}while(getchar() != '\n');

	printf("Ort          : ");
	fgets(neu[nr].ort, MAX, stdin);

	printf("Geburtsjahr  : "); 
	do{
		scanf("%ld", &neu[nr].geburtsjahr);
	}while(getchar() != '\n');
}

void Suche(struct address search[], char buchstabe, int nr){
	int i;

	for(i=0;i<=nr;i++){
		if(search[i].nname[0] == buchstabe){
			printf("\n\nGefunden unter Buchstabe :\"%c\"\n\n", buchstabe);
		       	printf("Vorname ..........:%s", search[i].vname);
			printf("Nachname..........:%s", search[i].nname);
			printf("Postleitzahl......:%ld\n", search[i].PLZ);
			printf("Ort...............:%s", search[i].ort);
			printf("Geburtsjahr.......:%d\n", search[i].geburtsjahr);
			printf("\n\tWeiter mit <ENTER>\n");
			getchar();	
		}
	}
}

struct address testing(int nr){

	
	struct address adresse0 = {
		.vname="Marcel",
		.nname="Lecram",
		.PLZ=81248,
		.ort="München",
		.geburtsjahr=1990
	};

	struct address adresse1 = {
		.vname="Lobna",
		.nname="Wagner",
		.PLZ=81248,
		.ort="München",
		.geburtsjahr=1988
	};

	if(nr == 0)
		return adresse0;
	else if(nr == 1)
		return adresse1;

}

void Ausgabe(struct address all[], int nr)
{
	int i;

	for(i=0;i<nr;i++){
		printf("Vorname..............%s", all[i].vname);
		printf("Nachname............:%s", all[i].nname);
		printf("Postleitzahl........:%ld\n", all[i].PLZ);
		printf("Ort.................:%s", all[i].ort);
		printf("Geburtsjahr.........:%ld\n", all[i].geburtsjahr);
		
		if((!(i%2))&& i!=0) {	
			printf("\n\tWeiter mit <ENTER>\n\n");
			getchar();
		}
	}
}

void Sort(struct address sort[], int nr)
{
	int i,j;
	struct address *temp;

	temp = malloc(sizeof(struct address*));

	if(NULL == temp){
		printf("Konnte keinen Speicher reservieren ...\n");
		return;
	}

	for(i=0;i<nr;i++){
		for(j=i+1;j<nr;j++){
			if(strcmp(sort[i].nname, sort[j].nname) > 0){
				*temp=sort[j];
				sort[j]=sort[i];
				sort[i]=*temp;
			}
		}
	}
	printf(".......Sortiert!!\n\n");
}


int main(void){
	int auswahl;
	char c; 
	
	do{
		printf("-1- Neue Adresse eingeben\n");
		printf("-2- Bestimmte Adresse ausgeben\n");
		printf("-3- Alle Adressen ausgeben\n");
		printf("-4- Adressen sortieren\n");
		printf("-5- Programm beenden\n");

		scanf("%d", &auswahl);

		getchar();

		switch(auswahl){
			case 1: Eingabe(x++, adressen);
				break;
			case 2: printf("Anfangsbuchstabe des Nachnamens :");
				scanf("%c", &c);
				Suche(adressen,c,x);
				break;
			case 3: Ausgabe(adressen,x);
				break;
			case 4: Sort(adressen,x);
				break;
			case 5: printf("Ende ....\n");
				break;
			default: printf("Falsche Eingabe\n");
		}
	}while(auswahl < 5);
		
	return EXIT_SUCCESS;
}
