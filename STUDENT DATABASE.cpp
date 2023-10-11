#include <stdio.h>
#include <string.h>

struct student {
    char name[50];
    int roll;
    float marks;
} s[100];

int main() {
    int i, n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter name, roll number, and marks of student %d: ", i+1);
        scanf("%s %d %f", s[i].name, &s[i].roll, &s[i].marks);
    }

    printf("\nStudent Database:\n");
    printf("Name\tRoll Number\tMarks\n");
    for(i = 0; i < n; i++) {
        printf("%s\t%d\t\t%.2f\n", s[i].name, s[i].roll, s[i].marks);
    }
    return 0;
}

