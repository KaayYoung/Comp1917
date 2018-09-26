#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Pkmn.h"

const char * const TYPES[] = {
   "Bug",
   "Dark",
   "Dragon",
   "Electric",
   "Fairy",
   "Fighting",
   "Fire",
   "Flying",
   "Ghost",
   "Grass",
   "Ground",
   "Ice",
   "Normal",
   "Poison",
   "Psychic",
   "Rock",
   "Steel",
   "Water"};

#define NOTFOUND 0
#define FOUND 1


struct _list {
   
   Pkmn head;
   Pkmn tail;
   Pkmn curr;
   int number;
};

struct _pkmn {
  
   Pkmn next; 
   Pkmn prev;
   int id;
   char *name;
   double height;
   double weight;
   int type1;
   int type2;
   int find;
   int evolution;
};

const char * getTypeString(int i) {
   return TYPES[i];
}

static void printPkmnZero(PkmnList list) {
   // Calculate the quotient of list->curr->id by 10, if quotient is equal 0, then  print double 0
   // if bigger than 0 and less than 10, then print one 0, if bigger then 9, no 0
   int quo = list->curr->id/10;
      if (quo == 0) {
          printf("00%d\n",list->curr->id);
      } else if (quo >= 1 && quo <= 9) {
          printf("0%d\n",list->curr->id);
      } else {
          printf("%d\n",list->curr->id);
      }   
}

Pkmn createPkmn(int id, char * name, double height, double weight, int type1, int type2) {
   
   Pkmn newPkmn = malloc(sizeof(struct _pkmn));
   assert(newPkmn != NULL);
   newPkmn->next = NULL;
   newPkmn->prev = NULL;
   newPkmn->id = id;
   newPkmn->name = name;
   newPkmn->height = height;
   newPkmn->weight = weight;
   newPkmn->type1 = type1;
   newPkmn->type2 = type2;
   newPkmn->find = NOTFOUND;
   newPkmn->evolution = 0;
   return newPkmn;
}

void printCurrentPkmn(PkmnList list) {
  
   if (list->head == NULL) {
      printf("No Pokemon in list.\n");
   } else {
      if (list->curr->find == FOUND) {
         printf("Id: ");
         printPkmnZero(list);
         printf("Name: %s\n",list->curr->name);
         printf("Height: %.2lfm\n",list->curr->height);
         printf("Weight: %.2lfkg\n",list->curr->weight);
         if (list->curr->type2 == -1) {
             printf("Type: %s\n",TYPES[list->curr->type1]);
         } else if (list->curr->type1 == -1) {
             printf("Type: %s\n",TYPES[list->curr->type2]);
         } else  {
             int ret = strcmp(TYPES[list->curr->type1],TYPES[list->curr->type2]);
             if (ret > 0) {
                 printf("Type: %s/%s\n",TYPES[list->curr->type2], TYPES[list->curr->type1]);
             } else if (ret < 0) {
                 printf("Type: %s/%s\n",TYPES[list->curr->type1], TYPES[list->curr->type2]);
             } else {
                 printf("Type: %s\n",TYPES[list->curr->type1]);
             }
         }
      } else if (list->curr->find == NOTFOUND) {
         printf("Id: ");
         printPkmnZero(list);
         int i = 0;
         printf("Name: ");
         while (i < strlen(list->curr->name)) {
            printf("*");
            i++;
         }
         printf("\n");
         printf("Height: --\n");
         printf("Weight: --\n");
         printf("Type: --\n");
      }
   }
}


PkmnList createPkmnList() {
 
   PkmnList list = malloc(sizeof(struct _list));
   assert(list != NULL);
   list->head = NULL;
   list->tail = NULL;
   list->curr = NULL;
   list->number = 0;
   
   return list;
}

void freePkmnList(PkmnList list) {
 
   Pkmn curr = list->head;
   Pkmn restOfList = NULL;
   while (curr != NULL) {
      restOfList = curr->next;
      free(curr);
      curr = restOfList;
   }
   free(list);
}

void addPkmnToList(PkmnList list, Pkmn pkmn) {
   
   if (list->head == NULL) {
      list->head = pkmn;
      list->curr = pkmn;
   } else {
      list->tail->next = pkmn;
      pkmn->prev = list->tail;
   }
   list->tail = pkmn;
   list->number = list->number + 1;
}

void printPkmnList(PkmnList list) {
  
   Pkmn curr1 = list->head;
   if (curr1 == NULL) {
       printf("No pokemon in list.\n");
   } else {
       while (curr1 != NULL) {
          if (curr1 != NULL && curr1->find == FOUND) {
            if (curr1 == list->curr) {
               printf("--> ");
            } else {
               printf("    ");
            }
            int quo = curr1->id/10;
            if (quo == 0) {
               printf("#00%d: %s\n",curr1->id,curr1->name);
            } else if (quo >= 1 && quo <= 9) {
               printf("#0%d: %s\n",curr1->id,curr1->name);
            } else {
               printf("#%d: %s\n",curr1->id,curr1->name);
            } 
         } else {
            if (curr1 == list->curr) {
               printf("--> ");
            } else {
               printf("    ");
            }
            int quo = curr1->id/10;
            if (quo == 0) {
               printf("#00%d: ",curr1->id);
            } else if (quo >= 1 && quo <= 9) {
               printf("#0%d: ",curr1->id);
            } else {
               printf("#%d: ",curr1->id);
            }

            int i = 0;
            while (i < strlen(curr1->name)) {
                printf("*");
                i++;
            }
            printf("\n");
         }
         curr1 = curr1->next;
         
      }
   }
}

void nextPkmn(PkmnList list) {
   
   if (list->head != NULL) {
       if (list->curr != list->tail) {    
          list->curr = list->curr->next;
      }
   }
}

void prevPkmn(PkmnList list) {
  
   if (list->head != NULL) {
       if (list->curr != list->head) {
           list->curr = list->curr->prev;          
      }   
   }
}

void jumpToPkmn(PkmnList list, int id) {
 
   Pkmn curr1 = list->head;
   while (curr1 != NULL) {
        if (curr1->id == id) {
            list->curr = curr1;
        }
        curr1 = curr1->next;
   }
}

void removePkmn(PkmnList list) {
   
   if (list->number == 1) {
     free(list->head);
     list->head = NULL;
     list->curr = NULL;
     list->tail = NULL;
     list->number = 0;
   } else {
     Pkmn curr1 = list->curr;
        if (list->curr == list->head) {
            list->curr->prev = NULL;
            list->curr = list->curr->next;
            list->head = list->head->next;
            list->tail = list->curr;
        } else if (list->curr == list->tail) {
            curr1 = curr1->prev;
            list->curr = curr1;
            list->tail = curr1;
        } else {
          Pkmn pre = curr1->prev;
          pre->next = curr1->next;
          curr1->prev = pre;
          list->curr = curr1->next;
        }
     free(curr1);
     list->number = list->number - 1;
   } 
}

// Stage 3 Functions
void findPkmn(int seed, int factor, int numberOfNewPkmn, PkmnList list) {
  
   srandom(seed);
   int count = 0;
   if (list->head != NULL) {
      Pkmn cur = list->head;
      while (count < numberOfNewPkmn) {
         int num = rand() %factor;
         while (cur->id != num && cur->next != NULL) {
             cur = cur->next;
         }
         if (cur->id == num) {
            cur->find = FOUND;
            count++;
         }
         cur = list->head;
      } 
   }
}

int totalFound(PkmnList list) {
  
   Pkmn curr1 = list->head;
   int totalnumber = 0;
   while (curr1 != NULL) {
      if (curr1 -> find == FOUND) {
          totalnumber++;
      }
      curr1 = curr1->next;
   }
   return totalnumber;
}


// Stage 4 Functions
void addEvolution(PkmnList list, int pkmnId, int evolutionId) {
  
   Pkmn curr1 = list->head;
   while (curr1 != NULL) {
      if (curr1->id == pkmnId) {
         curr1->evolution = evolutionId;
      }
      curr1 = curr1->next;
   }
}

void showEvolutions(PkmnList list) {
  
   Pkmn curr2 = list->head;
   Pkmn curr3 = list->curr;
   int i = 0;
   int quo1 = list->curr->id/10;
   if (curr3->find == FOUND) {
      if (quo1 == 0) {
          printf("#00%d %s",list->curr->id,list->curr->name);
      } else if (quo1 >= 1 && quo1 <= 9) {
          printf("#0%d %s",list->curr->id,list->curr->name);
      } else {
          printf("#%d %s",list->curr->id,list->curr->name);
      }
   } else {
      if (quo1 == 0) {
          printf("#00%d ",list->curr->id);
      } else if (quo1 >= 1 && quo1 <= 9) {
          printf("#0%d ",list->curr->id);
      } else {
          printf("#%d ",list->curr->id);
      }
      while (i < strlen(list->curr->name)) {
          printf("*");
          i++;
      } 
   }
   if (list->curr->evolution != 0) {
      Pkmn curr1 = list->head;
       int quo2;
       // If there is no id which is equal evolution in the list,
       // then the check = 0, and exit the while loop
       int check = 1;
      while (curr3->evolution != 0 && check != 0) {
        check = 0;
         while (curr1 != NULL) {
            quo2 = curr1->id/10;
            if (curr1->id == curr3->evolution) {
               check++;
               printf(" --> ");
               curr2 = curr1;
               if (curr1->find == FOUND) {
                   if (quo2 == 0) {
                      printf("#00%d %s",curr1->id,curr1->name);
                   } else if (quo2 >= 1 && quo2 <= 9) {
                      printf("#0%d %s",curr1->id,curr1->name);
                   } else {
                      printf("#%d %s",curr1->id,curr1->name);
                   }
               } else {
                   if (quo2 == 0) {
                      printf("#00%d ",curr1->id);
                   } else if (quo2 >= 1 && quo2 <= 9) {
                      printf("#0%d ",curr1->id);
                   } else {
                      printf("#%d ",curr1->id);
                   }
                   i = 0;
                   while (i < strlen(curr1->name)) {
                      printf("*");
                      i++;
                   }
               }
            } 
            curr1 = curr1->next;
         }
         curr3 = curr2;
         curr1 = list->head;
      }
      if (curr2->evolution != 0) {
        if (check == 0) {
           printf(" --> ");
           int quo3 = curr2->evolution/10;
           if (quo3 == 0) {
                     printf("#00%d ?????",curr2->evolution);
           } else if (quo3 >= 1 && quo3 <= 9) {
                     printf("#0%d ?????",curr2->evolution);
           } else {
                     printf("#%d ?????",curr2->evolution);
           }
        }
      }
   } 
   printf("\n");
}


// Stage 5 Functions
PkmnList getPkmnOfType(PkmnList list, int type) {
   
   PkmnList typelist = createPkmnList();
   Pkmn curr1 = list->head;
   while (curr1 != NULL) {
      if (curr1->type1 == type || curr1->type2 == type) {
          Pkmn typePkmn = createPkmn(curr1->id,curr1->name,curr1->height,curr1->weight,curr1->type1,curr1->type2);
          typePkmn->find = curr1->find;
          typePkmn->evolution = curr1->evolution;
          addPkmnToList(typelist,typePkmn);
      } 
      curr1 = curr1->next;
   }
   return typelist;
}

PkmnList getFoundPkmn(PkmnList list) {
   
   PkmnList foundlist = createPkmnList();
   Pkmn curr1 = list->head;
   int i = 0;
   int findP[20];
   while (curr1 != NULL) {
      if (curr1->find == FOUND) {
          findP[i] = curr1->id; 
          i++;
      }
      curr1 = curr1->next;
   }
   int num = i;
   i = 0;
   int j = 0;
   int temp = 0;
   while (i < num) {
    j = i;
      while (j < num-1) {
         if (findP[i] > findP[j+1]) {
            temp = findP[i];
            findP[i] = findP[j+1];
            findP[j+1] = temp;
         }
         j++;
      }
      i++;
   }
   i = 0;
   while (i < num) {
    curr1 = list->head;
      while (curr1 != NULL) {
         if (curr1->id == findP[i]) {
             Pkmn foundPkmn = createPkmn(curr1->id,curr1->name,curr1->height,curr1->weight,curr1->type1,curr1->type2);
             foundPkmn->find = FOUND;
             foundPkmn->evolution = curr1->evolution; 
             addPkmnToList(foundlist,foundPkmn);
         }
         curr1 = curr1->next;
      }
      i++;
   }
   return foundlist;
}

PkmnList searchByName(PkmnList list, char text[]) {
   
   PkmnList namelist = createPkmnList();
   Pkmn curr1 = list->head;
   int i = 0;
   int j = 0;
   while (curr1 != NULL) {
        while (curr1->name[i] != text[0] && text[i] != '\0') {
          i++;
        }
        while (curr1->name[i] == text[j] && (curr1->name[i] != '\0' && text[j] != '\0')) {
          i++;
          j++;
        }
        if (text[j] == '\0') {
          Pkmn namePkmn = createPkmn(curr1->id,curr1->name,curr1->height,curr1->weight,curr1->type1,curr1->type2);
          namePkmn->find = curr1->find;
          namePkmn->evolution = curr1->evolution;
          addPkmnToList(namelist,namePkmn);
        }
      i = 0;
      j = 0;
      curr1 = curr1->next;
   }
   return namelist;
}
