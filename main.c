#include "inverted_search.h"

/*
--Description :
*/

int main( int argc, char *argv[])
{
	system("clear") ;

	// validation CLA

	if(argc <= 1)
	{
		printf("Enter the valid number of arguments\n") ;
		printf("./Slist.exe f1.txt f2.txt\n") ;
		return 0 ;
	}

	// create the list of filenames 
	// declare the head pointer
	Flist *f_head = NULL ;

	// validation the files

	file_validation_n_file_list(&f_head,argv) ;

	if(f_head == NULL)
	{
		printf("No files are availabe in the file linked list\n") ;
		printf("Hence the process is terminated\n") ;
		return 1 ;
	}

	// promt the menu for user

	// create database function 



	
		







}

