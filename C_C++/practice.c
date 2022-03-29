#include <stdio.h>
#include <string.h>

struct Student 
{
    char name[20];      // 이름
    int student_number; // 학번
    char gender[20];       // 성별
};

int main()
{
    struct Student *student;

    scanf("%s, %d, %s", student->name, &student->student_number, student->gender);
    printf("%s, %d, %s", student[0].name, student[0].student_number, student[0].gender);
}