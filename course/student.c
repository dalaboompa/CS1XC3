/**
 * @file student.c
 * @author Zitong Gu (guz38@mcmaster.ca)
 * @brief 
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/**
 * @brief Updates a grade to a student
 * 
 * @param student a Student type represeted by a pointer
 * @param grade grade represented by a double
 * @return nothing
 */
void add_grade(Student* student, double grade)
{
  student->num_grades++;
  if (student->num_grades == 1) student->grades = calloc(1, sizeof(double)); // case when no previous grade availiable of the student
  else 
  {
    student->grades = 
      realloc(student->grades, sizeof(double) * student->num_grades); // changes the size of the array for storing grades of the student
  }
  student->grades[student->num_grades - 1] = grade; // records the given grade to the array for storing grades
}

/**
 * @brief Calculates the average grade of a student
 * 
 * @param student a Student type represented by a pointer
 * @return double: the average grade of the student
 */
double average(Student* student)
{
  if (student->num_grades == 0) return 0;

  double total = 0;
  for (int i = 0; i < student->num_grades; i++) total += student->grades[i];
  return total / ((double) student->num_grades);
}

/**
 * @brief Prints a student's information including name, ID, grades, and average grade
 * 
 * @param student a Student type represented by a pointer
 * @return nothing
 */
void print_student(Student* student)
{
  printf("Name: %s %s\n", student->first_name, student->last_name);
  printf("ID: %s\n", student->id);
  printf("Grades: ");
  for (int i = 0; i < student->num_grades; i++) 
    printf("%.2f ", student->grades[i]); // print student's grades to 2 decimal places
  printf("\n");
  printf("Average: %.2f\n\n", average(student)); // print student's average to 2 decimal places
}

/**
 * @brief Generates a random student of a Student type
 * 
 * @param grades int: number of grades required to add
 * @return Student* a pointer to the random student generated
 */
Student* generate_random_student(int grades)
{
  char first_names[][24] = 
    {"Shahrzad", "Leonti", "Alexa", "Ricardo", "Clara", "Berinhard", "Denzel",
     "Ali", "Nora", "Malcolm", "Muhammad", "Madhu", "Jaiden", "Helena", "Diana",
     "Julie", "Omar", "Yousef",  "Amir", "Wang", "Li", "Zhang", "Fen", "Lin"};

  char last_names[][24] = 
   {"Chen", "Yang", "Zhao", "Huang", "Brown", "Black", "Smith", "Williams", 
    "Jones", "Miller", "Johnson", "Davis", "Abbas", "Ali", "Bakir", "Ismat", 
    "Khalid", "Wahed", "Taleb", "Hafeez", "Hadid", "Lopez", "Gonzalez", "Moore"};
 
  Student *new_student = calloc(1, sizeof(Student)); // allocates memory for the new student

  // copies the random first name and last name to the new student
  strcpy(new_student->first_name, first_names[rand() % 24]);
  strcpy(new_student->last_name, last_names[rand() % 24]);

  // generates and stores a random ID
  for (int i = 0; i < 10; i++) new_student->id[i] = (char) ((rand() % 10) + 48);
  new_student->id[10] = '\0';

  // generates and stores a random grade in a range from 25 to 100 to the student
  for (int i = 0; i < grades; i++) 
  {
    add_grade(new_student, (double) (25 + (rand() % 75))); 
  }

  return new_student;
}