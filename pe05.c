#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pe05.h"

#ifndef TEST_CPRNAME
static int CompareByName(const void * s1, const void * s2) {

  // Convert voids to known types
  const Student** ptr1 = (const Student**) s1;
  const Student** ptr2 = (const Student**) s2;

  // Get value from address
  const Student *str1 = *ptr1;
  const Student *str2 = *ptr2;


  // Since names are strings (i.e. array of chars)
  // use strcmp instead of comparing directly
  return strcmp(str1 -> name, str2 -> name);
  
  
}
#endif

#ifndef TEST_NAME
void SortDatabaseByName(StudentDatabase * studb) {
	// use qsort to sort the database.

  // qsort(base, #elements, sizeof elem, compar)
  // test for success

  qsort(studb -> students, studb -> number, sizeof(Student*), CompareByName);

}
#endif

#ifndef TEST_CPRAGE
static int CompareByAge(const void * s1, const void * s2) {

  // convert void to known type
  const Student** ptr1 = (const Student**) s1;
  const Student** ptr2 = (const Student**) s2;

  // get value from address
  const Student * n1 = * ptr1;
  const Student * n2 = * ptr2;
  
  return (n1 -> age - n2 -> age);
 
}
#endif

#ifndef TEST_AGE
void SortDatabaseByAge(StudentDatabase * studb) {
	// use qsort to sort the database.

  qsort(studb -> students, studb -> number, sizeof(Student*), CompareByAge);
  
}
#endif

#ifndef TEST_WRITE
int WriteDatabase(char *filename, StudentDatabase * db) {
	// Write the info storing in db to filename

  int i;
  int printtest;
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    fprintf(stderr, "Fail to open a file\n");
    return 0;
  }

  for(i=0; i<db -> number; i++) {
    printtest = fprintf(fp, "ID:%d, Name:%s, Major:%s, Enrollment:%s, Year:%s, Age:%d\n", db -> students[i] -> id, db -> students[i] -> name, db -> students[i] -> major, db -> students[i] -> year, db -> students[i] -> enrollment, db -> students[i] -> age);

    if (printtest < 0) {
      return 0;
    }
  }


  fclose(fp);

  return 1;

}
#endif

