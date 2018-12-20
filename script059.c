/* txt2html_example.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* nchars = Anzahl der Zeichen */
/* tag    = Sonderzeichen in HTML */
/* ziel   = Datei, in die geschrieben wird */

struct special_char{
	char z;
	char utf8[100];
};

void sonderzeichen(int nchars, char *tag, FILE *ziel) {
   int i;
   char zeichen;

   for(i = 0; i < nchars; i++) {
      zeichen = tag[i];
      putc(zeichen, ziel);
   }
}

int main(int argc, char **argv) {

	
   FILE *q, *z;
   int zeichen;

   struct special_char map[100];
   map[0].z = '<';
   map[1].z = '>';
   map[2].z = '\"';
   map[3].z = '&';
   map[4].z = 'ä';
   map[5].z = 'Ä';
   map[6].z = 'ö';
   map[7].z = 'Ö';
   map[8].z = 'ü';
   map[9].z = 'Ü';
   map[10].z = 'ß';

   strcpy(map[0].utf8, "&lt;");
   strcpy(map[1].utf8, "&gt;");
   strcpy(map[2].utf8, "&quot;");
   strcpy(map[3].utf8, "&amp;");
   strcpy(map[4].utf8, "&auml;");
   strcpy(map[5].utf8, "&Auml;");
   strcpy(map[6].utf8, "&ouml;");
   strcpy(map[7].utf8, "&Ouml;");
   strcpy(map[8].utf8, "&uuml;");
   strcpy(map[9].utf8, "&Uuml;");
   strcpy(map[10].utf8, "&szlig;");

   if(argc < 3) {
      printf("Benutzung : %s quelle ziel\n", *argv);
      return EXIT_FAILURE;
   }

   q = fopen(argv[1], "r");
   z = fopen(argv[2], "w");
   if(q == NULL || z == NULL) {
      printf("Fehler bei Oeffnen einer Datei ...\n");
      return EXIT_FAILURE;
   }
   while((zeichen=getc(q)) != EOF) {
      if(zeichen==map[0].z)
         sonderzeichen(strlen(map[0].utf8),map[0].utf8, z);
      else if(zeichen==map[1].z)
         sonderzeichen(strlen(map[1].utf8),map[1].utf8, z);
      else if(zeichen==map[2].z)
         sonderzeichen(strlen(map[2].utf8),map[2].utf8,z);
      else if(zeichen==map[3].z)
         sonderzeichen(strlen(map[3].utf8),map[3].utf8,z);
      else if(zeichen==map[4].z)
         sonderzeichen(strlen(map[4].utf8),map[4].utf8,z);
      else if(zeichen==map[5].z)
         sonderzeichen(strlen(map[5].utf8),map[5].utf8,z);
      else if(zeichen==map[6].z)
         sonderzeichen(strlen(map[6].utf8) ,map[6].utf8,z);
      else if(zeichen==map[7].z)
         sonderzeichen(strlen(map[7].utf8) ,map[7].utf8,z);
      else if(zeichen==map[8].z)
         sonderzeichen(strlen(map[8].utf8) ,map[8].utf8,z);
      else if(zeichen==map[9].z)
         sonderzeichen(strlen(map[9].utf8) ,map[9].utf8,z);
      else if(zeichen==map[10].z)
         sonderzeichen(strlen(map[10].utf8) ,map[10].utf8,z);
      else
         putc(zeichen, z);
   }
   return EXIT_SUCCESS;
}
