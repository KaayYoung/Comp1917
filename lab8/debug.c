#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define MAX_COURSES 4
#define PS 50
#define CR 65
#define DN 75
#define HD 85
 
typedef struct _student {
    int zid;
    double wam;
} student;

 
double calcAvg(double *marks,int numCourses);
student * getData(int numStudents);
int getNumFails(student * students, int numStudents);
int getPrize(student * students, int numStudents);
 
int main (int argc, char * argv[]) {
    //get number of students
    int numStudents;
    int numFailes = 0;

    printf("How many students do you want to calculate marks for? ");
    scanf("%d", &numStudents);
    //get students

    student * students = getData(numStudents);
    //find out how many failed

    numFailes = getNumFails(students, numStudents);
  
    if (numFailes == 0) {
        printf("Yay everyone passed!\n");
    } else {
        printf("%d students failed :(\n", numFailes);

    }
    //get university prize winner

    int winner = getPrize(students, numStudents);
    printf("The winner is z%d\n", winner);
    free(students);

    return EXIT_SUCCESS;

}

 

student * getData(int numStudents) {

    //this function returns an array of students
    //with information entered by a user
    //malloc array

    student * students = malloc(sizeof(struct _student)*numStudents);

    assert(students != NULL);
    //enter each student's info
    int i = 0;

    while (i < numStudents) {

        //get zid

        printf("zID of student %d: ", i+1);
        scanf("%d", &students[i].zid);
        //get num courses

        int numCourses;
        printf("How many courses is student z%d taking? ", students[i].zid);
        scanf("%d", &numCourses);
        assert(numCourses < MAX_COURSES);

        double * marks = malloc(sizeof(double) * numCourses);
        assert(marks != NULL);

        //get course marks

        printf("Please enter the marks for each course on a new line:\n");
        int j = 0;
        while (j < numCourses) {
            scanf("%lf", &marks[j]);
            assert(marks[j] <= 100);
            j++;
        }
        //calculate wam
        students[i].wam = calcAvg(marks,numCourses);
        i++;
        free(marks); 
    }
     
    return students;
}

 

double calcAvg(double *marks, int numCourses) {

    //calculate the average of an array of doubles

    int i = 0;

    double total = 0;
    //get sum of all marks

    while (i < numCourses) {

        total += marks[i];
        i++;
    }
    //get average

    double avg = total / numCourses;
    return avg;

}

int getNumFails(student * students, int numStudents) {
    //calculate how many students failed
    int i=0;

    int count = 0;

    while (i < numStudents) {

        //if they haven't passed, increment counter

        if (students[i].wam < PS) {           
            count++;
        }
        i++;

    }
    return count;
}

int getPrize(student * students, int numStudents) {

    int i = 0;
    int max = -1;
    int winner;

    //find student with highest wam

    while (i < numStudents) {
        //if current student wam greater than max wam
        //current student is now highest wam
        if (students[i].wam > max) {
            max = students[i].wam;
            winner = students[i].zid;
        }
        i++;
    
    }
    
    return winner;
}
