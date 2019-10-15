/*
on decoupe la chaine obtenue et on les enfile dans une tableau de pointeur 
*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

#define TAILLELECTURE 200
#define TAILLETABLEAU 30

int main() {

  char commande[TAILLELECTURE];// tableau contenant la chaine lue au clavier
  char *arguments[TAILLETABLEAU]; //tableau contenant les arguments découpés
  char *s; //caractere retourne par par la decoupage

char test[]={'\n','&'};

  int etatfils, i, pid;
  printf(">");
//on lit  200 caractere dans le flux stdin correpondant aux données rentrées au clavier
 while (fgets(commande, TAILLELECTURE, stdin) != NULL) 
 {
    if ((pid = fork()) != 0) { // Père
      for (i = 0; commande[i] !=test[0] && commande[i] !=test[1]; i++);
      if (commande[i] != test[1]){
        wait( & etatfils);
        printf("Code de retour = %d\n", WEXITSTATUS(etatfils));
      } else printf("[%d]\n", pid);
      printf(">");
    } else { // Fils
      for (i = 0; commande[i] != test[0] && commande[i] != test[1]; i++);
      printf("ehhhhhhhhhhhh %d\n",i);
      commande[i] = '\0';
      
      for(i=0;s=strtok(commande," ");i++)
      {

      }
      execlp(commande,commande, NULL);
      perror("Erreur a l’execl");
      exit(1);
    }
  } // while
}
/*

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define NB_ARGUMENTS 16
int main(int argc, char **argv){
char *argv_exec[NB_ARGUMENTS]; int indice;
if (argc < 2) {printf("Usage : programme commande liste_arguments\n"); exit(1);}
for (indice = 0; indice < argc; indice++) argv_exec[indice] = argv[indice + 1];
argv_exec[indice]=NULL;
execvp(argv_exec[0],argv_exec);
perror(argv_exec[0]);
exit(2);
return 0;
}
*/
