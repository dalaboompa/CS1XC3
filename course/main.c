/**
 * @mainpage Course function and Student function demonstration
 * 
 * The course fucntion demonstration shows how multiple functions in the course library work, including:
 * - enrolling a student
 * - printing course information
 * - finding the top student of a course
 * - finding the students who passed a course
 * 
 * The student function demonstration shows how multiple functions inthe course library work, including:
 * - adding a grade to a student
 * - finding the average of a student
 * - printing student's information
 * - generating a random student with grades
 * 
 * @file main.c
 * @author Zitong Gu (guz38@mcmaster.ca)
 * @brief Runs demonstration code for course and student library methods
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

/**
 * @brief crates a course and performs a series of tests including: \n 
 * 
 * - the course library methods:
 *    | enrolling students
 *    | printing the course information
 *    | finding the top student
 *    | finding the students passed this course and calculating the number of students passed \n 
 * 
 * - the student library methods:
 *    | generating random students
 *    | printing the inforamtion of the top student and students who passed the course
 * 
 */
int main()
{
  srand((unsigned) time(NULL)); // randomizes the seeds for generating random students

  // creates a course dynamically
  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  // enrolls some random students in the course
  for (int i = 0; i < 20; i++) 
    enroll_student(MATH101, generate_random_student(8));
  
  print_course(MATH101);

  // prints the inforamtio of the top student
  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  // prints all students who passed the course with their inforamtion
  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);
  
  return 0;
}