#include "inverted_search.h"

/*
	Name : Saurabh Yadav
	Date : Feb 12th, 2023

  --->> Description : Inverted_Search Project (DS)  

 */

int main( int argc, char *argv[])
{
	system("clear") ;

	// validation CLA

	if(argc <= 1)
	{
		red() ;
		printf("Enter the valid number of arguments\n") ;
		printf("./Slist.exe f1.txt f2.txt\n") ;
		reset() ;
		return 0 ;
	}

	// create the list of filenames 
	// declare the head pointer
	Flist *f_head = NULL ,*temp,*last;

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
	int choice ,ret,flag=1;
	while(ch == 'Y' || ch == 'y')
	{
		purple() ;
		printf("1. Create Database\n2. Display Database\n3. Update Database\n4. Search\n5. Save Database\nEnter you choice : ") ;
		reset() ;
		scanf("%d",&choice) ;

		switch(choice)
		{
			case 1:
				if(flag == 1)
				{
					create_database(f_head,head) ;
					green() ;
					printf("INFO : Database created successfully\n") ;
					flag = 0 ;
					reset() ;
				}
				else
				{
					green() ;
					printf("INFO : Database already updated !!\n") ; 
					reset() ;
				}
				break ;
			case 2:
				display_database(head) ;
				break ;				
			case 3:
				printf("Enter the file name : ") ;
				scanf("%s",str) ;
				argv[argc] = str ;
				argc++ ;
				argv[argc] = NULL ;
				last = f_head ;
				while(last->link) 
				{
					last = last->link ;
				}

				file_validation_n_file_list(&f_head,argv) ;
				
				if(last->link != NULL)
				{
					green() ;
					create_database(last->link,head) ;
					printf("INFO : %s file is updated successfully in the database.\n",str) ;
					reset() ;
				}
				else
				{
					red() ;
					printf("INFO : Given file already included in the database or file is empty.\n") ;
					reset() ;
				}

				break ;
			case 4:
				printf("Enter the word : ") ;
				scanf("%s",str) ; red() ;
				if( (ret = search(head,str)) == FAILURE ) 
				{
					red() ;
					printf("Word [%s] not found in the database\n",str) ;
					reset() ;
				}
				reset() ;
				break ;
			case 5:
				save_database(head) ;
				break ;
			
		}


		purple() ;
		printf("Do you want to continue --> If yes then press [Y/y] :\n") ;
		reset() ;
		scanf(" %c",&ch) ;
	}

}



/* function definition to add colors */

void red()
{
	printf("\033[1;31m") ;
}

void green()
{
	printf("\033[1;32m") ;
}

void reset() 
{
	printf("\033[0m") ;
}

void purple()
{
	printf("\033[0;35m") ;
}

