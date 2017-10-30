#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
    
	char fileNmae[7];
	int i = 0;
	char line[10];
    int count = 0;
	while (i < 100) {
    sprintf(fileNmae,"area%d",i);
    FILE* fp = fopen(fileNmae,"r");
    
    	while (!feof(fp)) {
    		fgets(line,10,fp);
    		if (strstr(line,"truffle")) {    
                count++;
        	}
    	}
        if (count != 0) {
                printf("%s\n",fileNmae);
            }
        fclose(fp);
        i++;
        count = 0;
    }
    
	return EXIT_SUCCESS;
}