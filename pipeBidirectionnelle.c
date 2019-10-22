#include<stdio.h>

#include<unistd.h>

#include<stdlib.h>

#include<fcntl.h>

#include<sys/wait.h>

#include<sys/stat.h>

#include<string.h>

#define TAILLE 100

int main() 
{
      
           
        int coderetour;
        pid_t pid;
        char messageP[TAILLE];
        //char messageF[TAILLE];
        char receptionP[TAILLE];
        //char receptionF[TAILLE];

        int peretofils[2];
        int filstopere[2];

        int sortieFIls = peretofils[0];
        int entreeFIls = filstopere[1];
        int sortiePere = peretofils[0];
        int entreePere = filstopere[1];


        if (pipe(peretofils) == -1) {
                perror("pipe ");
                exit(EXIT_FAILURE);
        }

        if (pipe(filstopere) == -1) {
                perror("pipe ");
                exit(EXIT_FAILURE);
        }
        

            
        
        

        pid=fork();

        if (pid == -1) {
                perror("fork ");
                exit(EXIT_FAILURE);
        }

        if (pid == 0) // FILS
        {
              
               printf("Saisie Fils\n");
                fgets(messageP, 50, stdin);
                
                messageP[50]='\0';
                

                if(write(entreeFIls, messageP,  TAILLE)==-1)
                {
                        perror("write ");
                        exit(0);
                }

                printf("lecture fils\n");
                int t = read(sortieFIls, receptionP, TAILLE);
                
                if (t == -1) {
                        perror("read ");
                        exit(0);
                }


        
                printf("je suis le fils, j'ai recu de mon pere : %s\n", receptionP);

               
                exit(0);
                

        }
      
        
        printf("lecture pere \n");
        int t = read(sortiePere, receptionP, 50);
        printf("je suis le pere, j'ai recu de mon fils: %s\n",receptionP);

        if (t == -1) {
                perror("read");
                exit(0);
        }



                 //Pere
        printf("Saisie pere \n");
        int octet = strlen(fgets(messageP, 100, stdin));

        messageP[octet - 1] = '\0'; // eliminer le retour chariot

        printf("je suis le pere, j'envoie un message à mon fils %s \n", messageP);
        

        //printf("FILS");

        int dhh = strlen(messageP);

        if (write(entreePere, messageP, dhh) == -1) {
                perror("xxxxxxx");
                exit(0);
        }


        wait(&coderetour); //le pere doit attendre le fils
        
        
        
        return 0;

}
