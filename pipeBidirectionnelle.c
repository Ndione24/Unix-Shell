

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
        char message[TAILLE];
        char reponse[TAILLE];

        int codederetour;
        int peretofils[2];
        int filstopere[2];

        if(pipe(peretofils)==-1)
        {
                perror("peretofils ");
                exit(EXIT_FAILURE);
        }

        if(pipe(filstopere)==-1)
        {
                perror("filstopere ");
                exit(EXIT_FAILURE);
        }

       int pid=fork();

        if(pid==0)
        {//Fils
               
                        
                
                
                printf("je suis le fils\n");
                if(read(peretofils[0],reponse,10)==-1)
                {
                        perror("read");
                }

                printf("j'ai recu %s\n",reponse);

                printf("j'envoie un message maintenant à mon pere\n");
                fgets(message,10,stdin);
                if(write(filstopere[1],message,10)==-1)
                {
                        perror("write fils ");
                }
                
        }
        else
        {
              
              
              
              printf("je suis le pere\n");
              //close(peretofils[0]); descriteur de lecture bloque pour le pere
              fgets(message,10,stdin);
              
              if(write(peretofils[1],message,10)==-1)
              {
                       perror("write");
              }
              
                
              if(read(filstopere[0],reponse,10)==-1)
              {
                      perror("read in father ");
                      
              }  

              printf("message de mon fils %s\n",reponse);

              wait(&codederetour);
              printf("mon fils s'est terminé avec le code %d\n",WEXITSTATUS(codederetour));
          
        }
        

        return 0;

}
