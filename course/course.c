/**
 * @file course.c
 * @author Zitong Gu (guz38@mcmaster.ca)
 * @brief 
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "course.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Enroll a student into a course.
 * 
 * @param course a specific course represented as a pointer
 * @param student a student type as a pointer
 * @return nothing
 */
void enroll_student(Course *course, Student *student)
{
  course->total_students++;
  if (course->total_students == 1) 
  {
    course->students = calloc(1, sizeof(Student)); // intializing student in this course
  }
  else 
  {
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); // change the size of the array of students in this course
  }
  course->students[course->total_students - 1] = *student; // assign the student's info to this course
}

/**
 * @brief Prints the information of the course including: 
 * - name
 * - course code
 * - total number of students
 * - a list of students
 * 
 * @param course a course type represented as a pointer
 * @return nothing
 */
void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  for (int i = 0; i < course->total_students; i++) 
    print_student(&course->students[i]);
}

/**
 * @brief Uses linear traversal to find the student with highest average of the course
 * 
 * @param course a Course type as a pointer
 * @return Student* a pointer to the top student of the course
 */
Student* top_student(Course* course)
{
  if (course->total_students == 0) return NULL; // case when no student in the course
 
  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];
 
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average) 
    {
      max_average = student_average;
      student = &course->students[i];
    }   
  } // find the top student by comapring average grades

  return student;
}

/**
 * @brief Gives a list of students who passed the course and calculates the number of students passed
 * 
 * @param course a Course type represented by a pointer
 * @param total_passing a pointer to the number of total students passed the course
 * @return Student* a pointer to an array of students who passed the course
 */
Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL; // initializes a pointer to an array of students who passed the course
  
  for (int i = 0; i < course->total_students; i++) 
    if (average(&course->students[i]) >= 50) count++; // calculates the number of students passed
  
  passing = calloc(count, sizeof(Student)); // allocates the memory needed as the number of students passed

  int j = 0;
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++; 
    }
  } // stores student passed to the dynamic array

  *total_passing = count; // records the number of stundents passed

  return passing;
}