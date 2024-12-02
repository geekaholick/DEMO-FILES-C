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

    list[0] = newStudent(123, "Patrick", 1.5);
    list[1] = newStudent(234, "Ean Jason", 2.5);
    list[2] = newStudent(213, "Cobar", 3.0);
    list[3] = newStudent(405, "Godwin", 1.2);
    list[4] = newStudent(502, "Pena", 1.1);

    displayStudent(list[2]);
    printf("\n");
    displayAllStudents(list+1, 4);

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