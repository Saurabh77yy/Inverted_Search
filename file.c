#include "inverted_search.h"

/*
--Description :
*/

void file_validation_n_file_list(Flist **head, char *argv[]) 
{
	// Declare the variables
	int i = 1 , empty ;

	// traverse through CL
	while(argv[i] != NULL)
	{
		empty = isFileEmpty(argv[i]) ;

		if(empty == FILE_NOT_AVAILABLE)
		{
			printf("File : %s is not available\n",argv[i]) ;
			printf("Hence we are not adding this file into file linked list\n") ;
			i++ ;
			continue ;
		}
		else if(empty == FILE_EMPTY)
		{
			printf("File : %s is not having any contents in it\n",argv[i]) ;
			printf("Hence we are not adding this file into file linked list\n") ;
			i++ ;
			continue ;
		}
		else
		{
			// if file valid then --> add this to the file linked list 
			int ret_val = to_create_list_of_files(f_head,argv[i]) ;

			if(ret_val == SUCCESS)
			{
				printf("SUCCESSFULL : Inserting the file name : %s into file linked list\n",argv[i]) ;
			}
			else if(ret_val == REPETATION)
			{
				printf("This file name : %s is repeated. Do not insert more than once\n",argv[i]) ;
			}	
			else
			{
				printf("FAILURE\n") ;
			}
		}
	}

}

int isFileEmpty(char *filename)
{
	// open the file in read mode
	FILE *fptr = fopen(filename,"r") ;

	// error
	if(fptr == NULL)
	{
		if(error == ENOENT)
		{
			return FILE_NOT_AVAILABLE ;
		}
	}

	// read the contents of file
	fseek(fptr,0,SEEK_END) ;
	if(ftell(fptr) == 0)
	{
		return FILE_EMPTY ;
	}

}

int to_create_list_of_files(Flist **f_head, char *name)
{
	// check whether filenames are duplicate ?
	/*

	   */
	// create the linked list

			// insert_at_last() 

}	/*  */ 
