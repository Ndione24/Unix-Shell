#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include<signal.h>

#define TAILLELECTURE 200
#define TAILLETABLEAU 30

int main(){
    int coderetour;
    char commande[TAILLELECTURE];
    char *arguments[TAILLETABLEAU];
    char*s; // token of commande

    printf("ndioneShell>");

    while (1)
    {
        fgets(commande,199,stdin);
        //strrchr( char *s , int c)  The  strchr() function returns a pointer to the first occurrence of the
       //  character c in the string s.
        printf("%ld\n",strlen(commande));
         if(strrchr(commande,'&'))
         {
             //traitement de l'excution en background;
         }

        // printf("long %ld",strlen(commande));
        
          //elimination du retour chariot
        
        
       commande[strlen(commande)-1]='\0';
         //retourne le premier element de commande separé par un espace 
         s=strtok(commande," ");

        int i=0;
         while (s!=NULL )
         {
             /*arguments[i]=(char*)malloc(strlen(s));
             strcpy(arguments[i],s); */
             arguments[i]=s; 
             s=strtok(NULL," ");
             i++;
         }
         
         for (int j = 0; j < i; j++)
         {
            // printf("%s\t",arguments[j]);
         }
        
         
        //le dernier argument doit etre nul
        arguments[i]=NULL;
        if(i>0)//pour verifier qu'il ya au moins un argument passé
        {
            if(fork()==0){//Fils
            
                char*arg[]={"ls","-l",NULL};
                execvp(arguments[0],arguments);
                perror("execvp: ");
    
            }
            else //Pere
            {
                wait(&coderetour);
                printf("code de retour %d",WEXITSTATUS(coderetour));
                exit(0);
            }
        }



         

    }
    


    return 0;
}

