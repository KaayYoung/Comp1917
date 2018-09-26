#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pkmn.h"

void printMenu();

int main(int argc, char * argv[]) {
   
   int id;
   char name[50][50];
   double height;
   double weight;
   int type1;
   int type2;
   int i = 0;

   PkmnList list = createPkmnList();
   char tempName[50];
   printMenu();
   char selection;
   scanf(" %c", &selection);
   while(selection != 'q') {
      if(selection == 'a') {
        
         printf("Id: ");
         scanf("%d",&id);
         printf("Name: ");
         scanf("%s",tempName);
         strcpy(name[i],tempName);
         printf("Height: ");
         scanf("%lf",&height);
         printf("Weight: ");
         scanf("%lf",&weight);
         printf("Type: ");
         scanf("%d",&type1);
         printf("Type: ");
         scanf("%d",&type2);
         Pkmn pkmn = createPkmn(id,name[i],height,weight,type1,type2);   
         i++;
         addPkmnToList(list,pkmn);       
      } else if (selection == 'p') {
         printPkmnList(list);
      } else if (selection == 'd') {
         printCurrentPkmn(list);
      } else if (selection == '>') {
         nextPkmn(list);
      } else if (selection == '<') {
         prevPkmn(list);
      } else if (selection == 'j') {
         int id;
         printf("Id: ");
         scanf("%d",&id);
         jumpToPkmn(list,id);
      } else if (selection == 'r') {
         removePkmn(list);
      } else if (selection == 'f') {
         int seed;
         int factor;
         int numberOfNewPkmn;
         printf("Seed: ");
         scanf("%d",&seed);
         printf("Factor: ");
         scanf("%d",&factor);
         printf("Number to find: ");
         scanf("%d",&numberOfNewPkmn);
         findPkmn(seed,factor,numberOfNewPkmn,list);
      } else if (selection == 'c') {
         int totalnumber = totalFound(list);
         if (totalnumber == 0 || totalnumber == 1) {
             printf("%d Pokemon has been found\n",totalnumber);
         } else {
             printf("%d Pokemons have been found\n",totalnumber);
         }
      } else if (selection == 'e') {
         int pkmnId;
         int evolutionId;
         printf("Id of original Pokemon: ");
         scanf("%d", &pkmnId);
         printf("Id of evolution: ");
         scanf("%d", &evolutionId);
         addEvolution(list,pkmnId,evolutionId);
      } else if (selection == 's') {
         showEvolutions(list);
      } else if (selection == 'q') {
         return 0;
      } /*else if (selection == 't') {
         int type;
         printf("Type: ");
         scanf("%d",&type);
         PkmnList typelist = getPkmnOfType(list,type); 
         printPkmnList(typelist);
      } else if (selection == 'g') {
         PkmnList foundlist = getFoundPkmn(list);
         printPkmnList(foundlist);
      } else if (selection == 'n') {
         char text[50];
         printf("Text: ");
         scanf("%s",text);
         PkmnList namelist = searchByName(list,text);
         printPkmnList(namelist);
      } */
      printMenu();
      scanf(" %c", &selection);
   }

   freePkmnList(list);

   return EXIT_SUCCESS;
}

void printMenu() {

   printf("a - Add a Pokemon to the list\n");
   printf("p - Print list\n");
   printf("d - Display details of the current Pokemon\n");
   printf("> - Move to the next Pokemon\n");
   printf("< - Move to the previous Pokemon\n");
   printf("j - Jump to a specific Pokemon\n");
   printf("r - Remove the current Pokemon\n");
   printf("f - Find Pokemon\n");
   printf("c - Count the number of Pokemon which have been found\n");
   printf("e - Add an evolution to a Pokemon\n");
   printf("s - Show the evolutions of the current Pokemon\n");
   //printf("t - Find all the Pokemon which has the type\n");
   //printf("g - Get all the found Pokemon\n");
   //printf("n - Get all the Pokemon whose name includes the input text\n");
   printf("q - Quit\n");
}
