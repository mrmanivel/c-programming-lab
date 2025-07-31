// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

// Define a structure for student details
struct student {
    int rollno;
    char name[30]; // Increased size for longer names
    int marks;
};

int main() {
    int count;

    // Input the number of students
    printf("\n===== Student Marks Entry =====\n");
    printf("Enter number of students: ");
    scanf("%d", &count);

    struct student s[count];

    // Input details for each student
    for (int i = 0; i < count; i++) {
        printf("\n--- Enter details for Student %d ---\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &s[i].rollno);
        printf("Enter Name: ");
        scanf("%s", s[i].name);
        printf("Enter Marks: ");
        scanf("%d", &s[i].marks);
    }

    // Display all students' data
    printf("\n===== All Students Data =====\n");
    for (int i = 0; i < count; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll Number : %d\n", s[i].rollno);
        printf("Name        : %s\n", s[i].name);
        printf("Marks       : %d\n", s[i].marks);
    }

    // Find the topper
    int topper = 0;
    for (int i = 1; i < count; i++) {
        if (s[i].marks > s[topper].marks) {
            topper = i;
        }
    }

    // Display topper details
    printf("\n===== Topper Details =====\n");
    printf("Roll Number : %d\n", s[topper].rollno);
    printf("Name        : %s\n", s[topper].name);
    printf("Marks       : %d\n", s[topper].marks);

    return 0;
}
