#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pe05.h"


/*
	Complete the main function and meet the followin specifications of argc and argv.
	1. argc: If argc is not 4, you should return `EXIT_FAILURE` and print "Wrong arguments\n".
	2. argv[1]: name of the input file. i.e., database.txt
	3. argv[2]: should be either "-a", or "-n".
		When argv[2] is "-a", you should sort the database by age in ascending order and print the database and return `EXIT_SUCCESS`.
		When argv[2] is "-n", you should sort the database by name in descending order and print the dataabse and return `EXIT_SUCCESS`. 
		For example, Student "Allen" should come after "Bob".
	  	If argv[2] is neither "-a" nor "-s", you should print "Wrong arguments\n" and return `EXIT_FAILURE`.
	4. argv[3]: This is the output filename. You should write the output of database into this file.
	5. print "Write to db\n" if `WriteDatabase()` work. Otherwise, print "Fail to write to db\n"

*/ 

int main(int argc, char ** argv) {

  int wtest = 0;

  // Test for # arguments
  if (argc != 4) {
    fprintf(stderr, "Wrong arguments\n");
    return EXIT_FAILURE;
  }

  // create database of student info
  StudentDatabase *studb = Connect(argv[1]);


  // Sort by age if argv[2] is -a
  if (strcmp(argv[2], "-a") == 0) {
    SortDatabaseByAge(studb);
  }
  
  // Sort by name if argv[2] is -s
  if (strcmp(argv[2], "-n") == 0) {
    SortDatabaseByName(studb);
  }

  // test for correct input
  if (strcmp(argv[2], "-n") != 0) {
    if (strcmp(argv[2], "-a") !=0) {
      fprintf(stderr, "Wrong arguments\n");
      Close(studb);
      return EXIT_FAILURE;
    }
  }

  // Write output file, test for success
  wtest = WriteDatabase(argv[3], studb);
  if (wtest == 1) {
    fprintf(stderr, "Write to db\n");
  } else {
    fprintf(stderr, "Fail to write db\n");
  }
  

  Close(studb);
  studb = NULL;
	
  return EXIT_SUCCESS;
}

