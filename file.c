#include "inverted_search.h"

/*
--Description :
*/

static int flag = 1 ;

void file_validation_n_file_list(Flist **f_head, char *argv[]) 
{
	// Declare the variables
	int i = 1 , empty ;

	// traverse through CL
	while(argv[i] != NULL)
	{
		empty = isFileEmpty(argv[i]) ;

		if(empty == FILE_NOT_AVAILABLE)
		{
			if(flag == 1)
			{
				printf("File : %s is not available\n",argv[i]) ;
				printf("Hence we are not adding this file into file linked list\n") ;
			}
			//i++ ;
			//continue ;
		}
		else if(empty == FILE_EMPTY)
		{
			if(flag == 1)
			{
				printf("File : %s is not having any contents in it\n",argv[i]) ;
				printf("Hence we are not adding this file into file linked list\n") ;
			}
			//i++ ;
			//continue ;
		}
		else
		{
			// if file valid then --> add this to the file linked list 
			int ret_val = to_create_list_of_files(f_head,argv[i]) ;
			
			if(ret_val == SUCCESS)
			{
				if(flag == 1)
					printf("SUCCESSFULL : Inserting the file name : %s into file linked list\n",argv[i]) ;
			}
			else if(ret_val == REPETATION)
			{
				if(flag == 1)
					printf("This file name : %s is repeated. Do not insert more than once\n",argv[i]) ;
			}	
			else
			{
				if(flag == 1)
					printf("FAILURE\n") ;
			}

			//i++ ;
		}
		i++ ;
	}

	flag = 0 ;

}

int isFileEmpty(char *filename)
{
	int error ;

	// open the file in read mode
	FILE *fptr = fopen(filename,"r") ;

	// error
	if(fptr == NULL)
	{
		/*if(error == ENOENT)
		{
			return FILE_NOT_AVAILABLE ;
		}*/
		
		return FILE_NOT_AVAILABLE ;
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
	// when f_head is null
	if(*f_head == NULL)
	{
		Flist *new = malloc(sizeof(Flist)) ;
		if(new == NULL)
			return FAILURE ;
		
		strcpy(new->file_name,name) ;
		new->link = NULL ;
		*f_head = new ;
		return SUCCESS ;
	}


	// check whether filenames are duplicate ?
	Flist *ptr = *f_head,*prev ;

	while(ptr != NULL)
	{
		prev = ptr ;
		if(!strcmp(ptr->file_name,name))
			return REPETATION ;
		ptr = ptr->link ;
	}

	// create the linked list --> ptr will be pointing the last node --> insert_at_last() 
	Flist *new = malloc(sizeof(Flist)) ;

	if(new == NULL)
	{
		return FAILURE ;
	}
	
	// give file name 
	strcpy(new->file_name, name) ;
	new->link = NULL ;
	prev->link = new ; 

	return SUCCESS ;
}	 
