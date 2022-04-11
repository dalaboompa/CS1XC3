/**
 * @file student.h
 * @author Zitong Gu (guz38@mcmaster.ca)
 * @brief Student library for managing students, including Student definition and student functions.
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Student type stores a student with first name, last name, ID, grades and number of grades.
 * 
 */
typedef struct _student 
{ 
  char first_name[50]; /**< the student's first name */
  char last_name[50]; /**< the student's last name */
  char id[11]; /**< the student's ID */
  double *grades; /**< array of the student's grades */
  int num_grades; /**< the number of the student's grades */
} Student;

void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades); 
