#include <stdio.h>
#include <stdlib.h>

int scanValue(char values[],char optionvalues[],char optionvalues1[]);
int chooseDice(char values[],char optionvalues[]);
int sumOfPoints(char optionvalues[]);
void consecutive(char optionvalues[]);
void chooseReturn(char optionvalues[],char optionvalues1[],char optionvalues2[], int returnoption,char change1[],char rerollchoose1[]);
void  chooseThree(int returnoption,char optionvalues[]);
int checkChange(char change[], char optionvalues1[]);
void changeValue(char rerollchoose1[],char optionvalues1[],char change1[]);


int main(int argc, char *argv[]){
    
     char values[300];
     char optionvalues[20];
     char optionvalues1[20];
     char optionvalues2[20];
     char change1[10];
     char rerollchoose1[20];
     values[199] = '\0';
     int returnVal = 0;
     returnVal = scanValue(values,optionvalues,optionvalues1);
     if (returnVal == 1) {
         int returnoption = 0;
         returnoption = chooseDice(values,optionvalues);
         chooseReturn(optionvalues,optionvalues1,optionvalues2,returnoption,rerollchoose1,change1);
     }
     return EXIT_SUCCESS;
}

int scanValue(char values[],char optionvalues[],char optionvalues1[]) {
   
    
     printf("Please enter dice values:\n");
     printf(">");
     
     fgets(values,200,stdin);
     int t = 0;
     int i = 0;
     while (values[i] != '\0') {
                if(values[i] >= '1' && values[i] <= '6') {
                    optionvalues[t] = values[i];
                t++;
          }
          i++;
     }
     optionvalues[t]='\0';
     char temp = 0;
     i = 0;
     int j = 0;
     while (i < 5) {
           j = i;
        while (j < 4) {
            if (optionvalues[i] > optionvalues[j+1]) {
                   temp = optionvalues[i];
                   optionvalues[i] = optionvalues[j+1];
                   optionvalues[j+1] = temp;
            }
            j++;
        }
        i++;
     }
     i = 0;
     int counter = 0;
     while (values[i] != '\0') {
         if (values[i] >= '0' && values[i] <= '9') {
             counter++;
         }
          i++;
     }
     i = 0;
 
     int count1 = 0;
     int count2 = 0;
     int count3 = 0;
     int returnVal = 0;
     while (values[i] != '\0') {
          if (values[i] >= '1' && values[i] <= '6') {
             returnVal = 1;
          }   if ((values[i] < '0' || values[i] > '9') && (values[i] != ' ' && values[i] != '\n')) {
              count1++;
          }   if (values[i] == '0' || (values[i] >= '7' && values[i] <='9')) {
              count2++;
          }   if ((values[i] > '0' && values[i] < '9') && (values[i+1] > '0' && values[i+1] < '9')) {
              count3++;
          }  
          i++;
     }
     
     if ((count1 != 0 || count2 != 0 )|| (count3 != 0 || counter != 5)) {
         returnVal = 0;
     }
     if (returnVal == 1 && counter == 5) {
         printf("Your dice values are:");
         i = 0;
         t = 0;
         returnVal = 1;
         while(t < 5){
             if(values[i] >= '1' && values[i] <= '6') {
                    optionvalues1[t] = values[i];
                         printf(" %c", optionvalues1[t]);
                   t++;
                }
              i++;
         }
         optionvalues1[t] = 0;
         printf("\n");
     } else if (count1 > 0 || count3 != 0) {
         printf("Incorrect Input Format.");
     } else if(count2 != 0 && count1 == 0) {
         printf("Value Out of Range.");
     } else if ((counter != 5 && count2 == 0) && (count3 == 0 && count1 == 0)) {
         printf("Incorrect Number of Values.");
     }
    
     printf("\n");
     return returnVal;
}


int chooseDice(char values[],char optionvalues[]) {
    char getoption1[20];
    char getoption[100];
    int returnoption = 0;
    int counter = 0;
    int i = 0;
    int t = 0;
    printf("Please choose:\n 1 -> Reroll some dice\n 2 -> Reroll all dice\n 3 -> Keep dice\n> ");
    fgets(getoption,100,stdin);
    while (getoption[i] != '\n'){
       if (getoption[i] != ' ') {
            getoption1[t] = getoption[i];
            t++;
        }
        i++;
    }
    getoption1[t] = 0;

    printf("\n");
    if ((getoption1[0] != '1' && getoption1[0] != '2') && (getoption1[0] != '3')) {
            printf("Invalid Choice");
        } else if (getoption1[0] == '1') {
           returnoption = 5;
        } else if (getoption1[0] == '2') {
            returnoption = 6;
        } else if (getoption1[0] == '3') {
            printf("Your score options are:\n");
            int i = 0;
            int counter1[10] = {0};
            while (optionvalues[i] != '\0') {
               if (optionvalues[i] == optionvalues[i+1]) {
                  counter++;
                  counter1[i]++;
               } 
                   i++;
            }
      
            if (counter == 2 && ((counter1[0] == 1 && counter1[1] == 1) || (counter1[1] == 1 && counter1[2] == 1) || (counter1[2] == 1 && counter1[3] == 1))) {
                 returnoption = 1;
            } else if((counter == 3) && ((optionvalues[0] != optionvalues[1]) || (optionvalues[3] != optionvalues[4]))) {
                 returnoption = 2;
            } else if ((counter == 3) && (((optionvalues[0] == optionvalues[1])
              && (optionvalues[1] != optionvalues[2])) || ((optionvalues[2] != optionvalues[3]) && (optionvalues[3] == optionvalues[4])))) {
                  returnoption = 3;
            } else if(counter == 4){
                  returnoption = 4;
            } else {
                  returnoption = 0;
            }
              chooseThree(returnoption,optionvalues);
    }
    return returnoption;
}

int sumOfPoints(char optionvalues[]) {
     int i = 0;
     char sum = 0;
     while (i < 5) {
         sum = sum + optionvalues[i] - 48 ;
         i++;
     }
     
     return sum;
}

void consecutive(char optionvalues[]) { 
    int counter = 0;
    char counter1[10] = {0};
    int i = 0;
    int sum = 0;
    int chooseoption = 0;
    sum = sumOfPoints(optionvalues);
    while (optionvalues[i] != '\0') {
         if (optionvalues[i+1] - optionvalues[i] == 1) {
                counter++;
                counter1[i]++;
         }
          i++;
    }

    if (counter == 3 && ((counter1[0] == 1 && counter1[3] != 1) || (counter1[0] != 1 && counter1[3] == 1))) {
          printf(" 1 -> Small Straight (30 points)\n 2 -> Chance (%d points)\n> ", sum);
          scanf("%d", &chooseoption);
          if (chooseoption == 1) {
                    printf("\nYour score is: 30 points");
                } else if(chooseoption == 2) {
                    printf("\nYour score is: %d points", sum);
                } else {
                    printf("\nInvalid Choice\n");
                }
          } else if (counter == 4) {
                printf(" 1 -> Small Straight (30 points)\n 2 -> Straight (40 points)\n 3 -> Chance (%d points)\n> ", sum);
                scanf("%d", &chooseoption);
                if (chooseoption == 1) {
                    printf("\nYour score is: 30 points");
                } else if (chooseoption == 2) {
                    printf("\nYour score is: 40 points");
                } else if (chooseoption == 3) {
                    printf("\nYour score is %d points", sum);
                } else {
                    printf("\nInvalid Choice\n");
                }
         }  else {
                printf(" 1 -> Chance (%d points)\n> ", sum);
                scanf("%d", &chooseoption);
                if (chooseoption == 1) {
                    printf("\nYour score is %d points", sum);
                } else {
                    printf("\nInvalid Choice\n");
                }
   } 
}

void chooseReturn(char optionvalues[],char optionvalues1[], char optionvalues2[],int returnoption,char change1[],char rerollchoose1[]) {

    int finalreturn = 0;
    char rerollchoose[200];
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;    
    if (returnoption == 5) {
         int i = 0;
         char change[20];
         int returnVal = 0;
         printf("Please enter dice to reroll (1 - 5):\n> ");
         int counter2 = 0;
         
         fgets(rerollchoose,99,stdin);
         printf("\n");
         int t = 0;
         while (rerollchoose[i] != '\0') {
                if (rerollchoose[i] >= '0' && rerollchoose[i] <= '9') {
                       rerollchoose1[t] = rerollchoose[i];
                          t++;
                          counter2++;
                   }
                     rerollchoose1[t] = 0;
                if ((rerollchoose[i] == '1' || rerollchoose[i] == '2') || (rerollchoose[i] == '3' || rerollchoose[i] == '4') || rerollchoose[i] == '5') {
                     returnVal = 1;
                 } 
                 if ((rerollchoose[i] < '0' || rerollchoose[i] > '9') && (rerollchoose[i] != ' ' && rerollchoose[i] != '\n')) {
                    count2++;
                 } 
                 if (rerollchoose[i] >= '6' && rerollchoose[i] <= '9') {
                     count3++;
                 } 
                 if ((rerollchoose[i] > '0' && rerollchoose[i] < '9') && (rerollchoose[i+1] > '0' && rerollchoose[i+1] < '9')) {
                     count4++;
                 }
                 i++;
        }     
        if ((count2 != 0 || count3 != 0) || count4 != 0) {
                 printf("Invalid Choice");
            }  
           
        if ((returnVal == 1 ) && (count3 == 0 && count4 == 0)) {
              if (counter2 == 1) {
                   printf("Please enter one dice value:\n> ");
                   fgets(change,199,stdin);
                   t = 0;
                   i = 0;
                   while (change[i] != '\0') {
                       if(change[i] <= '9' && change[i] >= '0'){
                           change1[i] = change[i];
                            t++;
                   } 
                           i++;
                   }
                     
                   finalreturn = checkChange(change,optionvalues1);
                   if (finalreturn == 1){
                      changeValue(rerollchoose1,optionvalues1,change1);
                   }
               } else if (count2 != 1) {
                     printf("Please enter %d values\n> ",counter2);
                     fgets(change,199,stdin);
                     t = 0;
                     i = 0;
                     while (change[i] != '\0') {
                         if(change[i] <= '6' && change[i] >= '1'){
                             change1[t] = change[i];
                              t++;
                         } 
                           i++;
                     }
                     change1[t] = 0;
                    finalreturn = checkChange(change,optionvalues1);
                     if(finalreturn == 1){
                         changeValue(rerollchoose1,optionvalues1,change1);
                     }
               }
         }
    } else if (returnoption == 6) {
           char optionvalu[5];
           char optionvalu1[5];
           int returnVa = 0;
           char vals[300]={0};
              vals[199] = '\0';
                setbuf(stdin,NULL);
           returnVa = scanValue(vals,optionvalu,optionvalu1);
                       
            if (returnVa == 1){
                    
                char optionvalu2[5];
                int returnopti = 0;
                char chan1[5];
                char rerollchoo1[20];
                  returnopti = chooseDice(vals,optionvalu);
                  chooseReturn(optionvalu,optionvalu1,optionvalu2,returnopti,rerollchoo1,chan1);
            }
     }
}

void  chooseThree(int returnoption,char optionvalues[]) {
    int chooseoption = 0;
    int sum = 0;
    if (returnoption == 0) {
             consecutive(optionvalues);
    } else if (returnoption == 1) {
             sum = sumOfPoints(optionvalues);
             printf(" 1 -> Three of a Kind (%d points)\n 2 -> Chance (%d points)\n> ", sum, sum);
             scanf("%d", &chooseoption);
             if (chooseoption == 1) {
                 printf("\nYour score is: %d points",sum);
             } else if (chooseoption == 2) {
                 printf("\nYour score is: %d points", sum);
             } else {
                 printf("\nInvalid Choice");
             }
    } else if (returnoption == 2) {
             sum = sumOfPoints(optionvalues);
             printf(" 1 -> Three of a Kind (%d points)\n 2 -> Four of a Kind (%d points)\n 3 -> Chance (%d points)\n> ", sum, sum, sum);
             scanf("%d", &chooseoption);
               if (chooseoption == 1) {
                 printf("\nYour score is: %d points",sum);
             } else if (chooseoption == 2) {
                 printf("\nYour score is: %d points", sum);
             } else if (chooseoption == 3) {
                 printf("\nYour score is: %d points", sum);
             } else {
                 printf("\nInvalid Choice");
             }
    } else if (returnoption == 3) {
             sum = sumOfPoints(optionvalues);
             printf(" 1 -> Three of a Kind (%d points)\n 2 -> Full House (25 points)\n 3 -> Chance (%d points)\n> ", sum, sum);
             scanf("%d", &chooseoption);
                if (chooseoption == 1) {
                 printf("\nYour score is: %d points",sum);
             } else if (chooseoption == 2) {
                 printf("\nYour score is: 25 points");
             } else if (chooseoption == 3) {
                 printf("\nYour score is: %d points", sum);
             } else {
                 printf("\nInvalid Choice");
             }
    } else if (returnoption == 4) {
             sum = sumOfPoints(optionvalues);
             printf(" 1 -> Three of a Kind (%d points)\n 2 -> Four of a Kind (%d points)\n 3 -> Yahtzee (50 points)\n 4 -> Chance (%d points)\n>",sum, sum, sum);
             scanf("%d", &chooseoption);
                if (chooseoption == 1){
                 printf("\nYour score is: %d points",sum);
             } else if (chooseoption == 2) {
                 printf("\nYour score is: %d points", sum);
             } else if (chooseoption == 3) {
                 printf("\nYour score is: 50 points");
             } else if (chooseoption == 4) {
                 printf("\nYour score is: %d points", sum);
             } else {
                 printf("\nInvalid Choice");
             }
    }
}

int checkChange(char change[], char optionvalues1[]) {
    int i = 0;
    int counter = 0;
    int returnVal = 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int finalreturn = 0;
    while (change[i] != '\0') {
        if (change[i] >= '0' && change[i] <= '9') {
             counter++;
         }
         i++;
    }
     i = 0;
     
    while (change[i] != '\0') {
          if (change[i] >= '1' && change[i] <= '6') {
             returnVal = 1;
          } if ((change[i] < '0' || change[i] > '9') && (change[i] != ' ' && change[i] != '\n')) {
             count1++;
          } if (change[i] == '0' || (change[i] >= '7' && change[i] <='9')) {
             count2++;
          } if ((change[i] > '0' && change[i] < '9') && (change[i+1] > '0' && change[i+1] < '9')) {
              count3++;
          }
          i++;
     }
  
     if ((count1 != 0 || count2 != 0 )|| count3 != 0) {
         returnVal = 0;
     }
     if (returnVal == 1 && count3 == 0) {
         i = 0;
         finalreturn = 1;
      } else if(returnVal != 1){
      if (count1 > 0 || returnVal == 0) {
         printf("Incorrect Input Format.");
     } else if (returnVal == 0 && count1 == 0) {
         printf("Value Out of Range.");
     } else if ((counter != 5 && count2 == 0) && (count3 == 0)) {
         printf("Incorrect Number of Values.");
     }
     }
     
     return finalreturn;
}

void changeValue(char rerollchoose1[],char optionvalues1[],char change1[]) {
   
    int i = 0;
    int position[10]={0};
    while(rerollchoose1[i] != 0){
        position[i] = rerollchoose1[i]-48;
        i++;
    }
    i=0;
    while(position[i] != 0){
        optionvalues1[position[i]-1] = change1[i];
            i++;
    }
    i = 0;
    printf("Your dice values are:");
    while (i < 5){
         printf(" %c",optionvalues1[i]);
         i++;
    }

    printf("\n\n");
    
    int j = 0;
    int temp = 0;
    while (i < 5) {
           j = i;
        while (j < 4) {
            if (optionvalues1[i] > optionvalues1[j+1]) {
                   temp = optionvalues1[i];
                   optionvalues1[i] = optionvalues1[j+1];
                   optionvalues1[j+1] = temp;
            }
            j++;
        }
        i++;
     }
    char opti[5];
    char valuessome[300];
    char opti2[5];
    char cha1[5];
    char rerochse1[5];
     
    int some = chooseDice(valuessome,optionvalues1);
    chooseReturn(opti,optionvalues1,opti2,some,rerochse1,cha1);
     
}

