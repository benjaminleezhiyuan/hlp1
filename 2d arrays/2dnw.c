#include <stdio.h>
#include <stdlib.h>

int **read_grades(char const *file_name, int *student_count, int *quiz_count);
void print_grades(int **grades, int student_count, int quiz_count);
double *quiz_avg_grades(int **grades, int student_count, int quiz_count);
double *student_avg_grades(int **grades, int student_count, int quiz_count);
void free_grades(int **grades,int student_count);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: grades.exe grades-text-file\n");
        return 0;
    }

    int student_count, quiz_count;
    int **grades = read_grades(argv[1], &student_count, &quiz_count);
    print_grades(grades, student_count, quiz_count);

    double *quiz_avg = quiz_avg_grades(grades, student_count, quiz_count);
    if (quiz_avg)
    {
        for (int i = 0; i < quiz_count; i++)
        {
            fprintf(stdout, "Average grade for Quiz %d: %.2f\n", i, quiz_avg[i]);
        }
    }
    free(quiz_avg);

    double *student_avg = student_avg_grades(grades, student_count, quiz_count);
    if (student_avg)
    {
        for (int i = 0; i < student_count; i++)
        {
            fprintf(stdout, "Average quiz grade for Student ID %d: %.2f\n", i, student_avg[i]);
        }
    }
    free(student_avg);

    free_grades(grades,student_count);
}

void free_grades(int **grades,int student_count)
{
    for(int i=student_count-1;i>=0;i--)
    {
        free(*(grades+i));
    }
    free(grades);
}

int **read_grades(char const *file_name, int *student_count, int *quiz_count)
{
    FILE *ifs = fopen(file_name, "r");
    if (!ifs)
    {
        return NULL;
    }

    fscanf(ifs, "%d %d", student_count, quiz_count);

    int **grades = (int **)malloc(sizeof(int *) * *student_count);
    if (!grades)
    {
        return NULL;
    }

    for (int i = 0; i < *student_count; i++)
    {
        grades[i] = (int *)malloc(sizeof(int) * *quiz_count);

        if (!*(grades + i))
        {
            return NULL;
        }
        for (int j = 0; j < *quiz_count; j++)
        {
            fscanf(ifs, "%d", &grades[i][j]);
        }
    }
    fclose(ifs);
    return grades;
}

void print_grades(int **grades, int student_count, int quiz_count)
{
    if (!grades)
    {
        return;
    }
    for (int i = 0; i < student_count; i++)
    {
        fprintf(stdout, "Quiz grades for Student ID %d: ", i);
        for (int j = 0; j < quiz_count; j++)
        {
            fprintf(stdout, "%d%s", grades[i][j], (j == quiz_count - 1 ? "\n" : " "));
        }
    }
}

double *quiz_avg_grades(int **grades, int student_count, int quiz_count)
{
    if (!grades)
    {
        return NULL;
    }
    double *quiz_avg = (double *)malloc(sizeof(double) * quiz_count);
    if (!quiz_avg)
    {
        return NULL;
    }

    for (int i = 0; i < quiz_count; i++)
    {
        double average = 0;
        for (int j = 0; j < student_count; j++)
        {
            average += grades[j][i];
        }
        quiz_avg[i] = average / (double)student_count;
    }
    return quiz_avg;
}

double *student_avg_grades(int **grades, int student_count, int quiz_count)
{
    if (!grades)
    {
        return NULL;
    }
    double *student_avg = (double *)malloc(sizeof(double) * student_count);
    if (!student_avg)
    {
        return NULL;
    }

    for (int i = 0; i < student_count; i++)
    {
        double average = 0;
        for (int j = 0; j < quiz_count; j++)
        {
            average += grades[i][j];
        }
        student_avg[i] = average / (double)quiz_count;
    }
    return student_avg;
}
