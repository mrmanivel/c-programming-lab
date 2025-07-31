#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student students[MAX_STUDENTS];
int count = 0;

void addStudent() {
    if (count >= MAX_STUDENTS) {
        printf("Student limit reached!\n");
        return;
    }
    printf("Enter name: ");
    scanf(" %[^\n]", students[count].name);
    printf("Enter roll number: ");
    scanf("%d", &students[count].roll);
    printf("Enter marks: ");
    scanf("%f", &students[count].marks);
    count++;
    printf("Student added successfully.\n");
}

void displayStudents() {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\n%-10s %-20s %-10s\n", "Roll No"…
