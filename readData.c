#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int studID;
    char studName[20];
    float gwa;
} Student;

Student newStudent(int studID, char *studName, float gwa);
void displayStudent(Student s);
void displayAllStudents(Student studs[], int n);

int main() {
    Student list[5];
    Student stud;
    int count = 0;

    FILE *fp;

    fp = fopen("mydata.dat", "rb");

    if(fp != NULL) {
        while(fread(&stud, sizeof(Student), 1, fp) != 0) {
            displayStudent(stud);
            list[count++] = stud;
        }

        fclose(fp);
    }

    displayAllStudents(list, count);

    return 0;
}

Student newStudent(int studID, char *studName, float gwa) {
    Student s;

    s.studID = studID;
    strcpy(s.studName, studName);
    s.gwa = gwa;

    return s;
}

void displayStudent(Student s) {
    printf("ID: %d\n", s.studID);
    printf("Name: %s\n", s.studName);
    printf("GWA: %.2f\n", s.gwa);
}

void displayAllStudents(Student studs[], int n) {
    printf("\n%-5s | %-15s | %s\n", "ID", "NAME", "GWA");
    for(int i = 0; i < n; ++i) {
       printf("%-5d | %-15s | %.2f\n", studs[i].studID, studs[i].studName, studs[i].gwa); 
    }
}