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
    printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f\n", students[i].roll, students[i].name, students[i].marks);
    }
}

void searchStudent() {
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Student Found: %s, Marks: %.2f\n", students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student not found.\n");
}

void displayAverageAndTopper() {
    if (count == 0) {
        printf("No students available.\n");
        return;
    }
    float total = 0, highest = students[0].marks;
    int topperIndex = 0;
    for (int i = 0; i < count; i++) {
        total += students[i].marks;
        if (students[i].marks > highest) {
            highest = students[i].marks;
            topperIndex = i;
        }
    }
    printf("Average Marks: %.2f\n", total / count);
    printf("Topper: %s (Roll: %d) - %.2f Marks\n", students[topperIndex].name, students[topperIndex].roll, highest);
}

void saveToFile() {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Unable to open file!\n");
        return;
    }
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(students, sizeof(struct Student), count, fp);
    fclose(fp);
    printf("Data saved to file successfully.\n");
}

void loadFromFile() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("No saved file found.\n");
        return;
    }
    fread(&count, sizeof(int), 1, fp);
    fread(students, sizeof(struct Student), count, fp);
    fclose(fp);
    printf("Data loaded from file successfully.\n");
}

int main() {
    int choice;
    loadFromFile();  // Optional load at start

    do {
        printf("\n--- Student Record Management ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search by Roll Number\n");
        printf("4. Display Average and Topper\n");
        printf("5. Save to File (optional)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: displayAverageAndTopper(); break;
            case 5: saveToFile(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 6);

    return 0;
}
