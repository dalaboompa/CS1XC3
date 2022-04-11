/**
 * @file course.h
 * @author Zitong Gu (guz38@mcmaster.ca)
 * @brief Course library for managing courses, including Course type definition and course functions.
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "student.h"
#include <stdbool.h>

/**
 * @brief Course type that stores a course with name, code, students enrolled and number of students.
 * 
 */
typedef struct _course 
{
  char name[100]; /**< Course name */
  char code[10]; /**< Code of this course */
  Student *students; /**< Students enrolled in this course */
  int total_students; /**< Total number of students */
} Course;

void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course* course);
Student *passing(Course* course, int *total_passing);


