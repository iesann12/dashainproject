#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Student struct
typedef struct {
    int roll;
    char name[100];
    float marks;
    char grade;
} Student;

// Function prototypes
char calculateGrade(float marks);
void addStudent(Student students[], int *count);
void displayStudents(Student students[], int count);
void searchStudent(Student students[], int count, int roll);
void updateStudent(Student students[], int count, int roll);
int isValidRoll(int roll);

// Assign grade based on marks
char calculateGrade(float marks) {
    if (marks >= 80) return 'A';
    else if (marks >= 65) return 'B';
    else if (marks >= 50) return 'C';
    else if (marks >= 35) return 'D';
    else return 'F';
}

// Add a student
void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. Limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[*count].roll);

    if (!isValidRoll(students[*count].roll)) {
        printf("Invalid roll number!\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Enter Marks: ");
    scanf("%f", &students[*count].marks);

    students[*count].grade = calculateGrade(students[*count].marks);
    (*count)++;

    printf("Student added successfully!\n");
}

// Display all students
void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("\nNo students to display!\n");
        return;
    }

    printf("\n%-10s %-20s %-10s %-10s\n", "Roll No", "Name", "Marks", "Grade");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f %-10c\n",
               students[i].roll,
               students[i].name,
               students[i].marks,
               students[i].grade);
    }
}

// Search student by roll
void searchStudent(Student students[], int count, int roll) {
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("\nStudent Found:\n");
            printf("Roll: %d\nName: %s\nMarks: %.2f\nGrade: %c\n",
                   students[i].roll, students[i].name,
                   students[i].marks, students[i].grade);
            return;
        }
    }
    printf("\nStudent with Roll %d not found!\n", roll);
}

// Update student by roll
void updateStudent(Student students[], int count, int roll) {
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("\nEnter New Name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);
            students[i].grade = calculateGrade(students[i].marks);
            printf("Student updated successfully!\n");
            return;
        }
    }
    printf("\nStudent with Roll %d not found!\n", roll);
}

// Simple roll validation
int isValidRoll(int roll) {
    return roll > 0;
}

// Main menu
int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice, roll;

    do {
        printf("\n===== Student Grade Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                printf("Enter Roll Number to search: ");
                scanf("%d", &roll);
                if (isValidRoll(roll))
                    searchStudent(students, count, roll);
                else
                    printf("nvalid roll number!\n");
                break;
            case 4:
                printf("Enter Roll Number to update: ");
                scanf("%d", &roll);
                if (isValidRoll(roll))
                    updateStudent(students, count, roll);
                else
                    printf("Invalid roll number!\n");
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
