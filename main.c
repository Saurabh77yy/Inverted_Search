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

	/* Declare array of pointers */
	Wlist *head[27] = {NULL}  ;

	
	// promt the menu for user

        char str[WORD_SIZE] ,ch = 'Y';	
	int choice ,ret;
	while(ch == 'Y')
	{
		printf("1. Create Database\n2. Display Database\n3. Update Database\n4. Search\n5. Save Database\nEnter you choice : ") ;
		scanf("%d",&choice) ;

		switch(choice)
		{
			case 1:
				create_database(f_head,head) ;
				printf("INFO : Database created successfully\n") ;
				break ;
			case 2:
				display_database(head) ;
				break ;				
			case 4:
				printf("Enter the word : ") ;
				scanf("%s",str) ;
				if( (ret = search(head,str)) == FAILURE ) 
				{
					printf("Word [%s] not found the database\n",str) ;
				}
				break ;
			case 5:
				save_database(head) ;
				break ;
			
		}



		printf("Do you want to continue ?? [Y/n] :\n") ;
		scanf(" %c",&ch) ;
	}

}

