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
		printf("1. Create Database\n2. Display Database\n3. Update Database\n4. Search\n5. Save Database\nEnter you choice : ") ;
		scanf("%d",&choice) ;

		switch(choice)
		{
			case 1:
				if(flag == 1)
				{
					create_database(f_head,head) ;
					printf("INFO : Database created successfully\n") ;
					flag = 0 ;
				}
				else
				{
					printf("INFO : Database already updated !!\n") ; 
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
					// printf("%s\n",temp->file_name) ;
					last = last->link ;
				}

				file_validation_n_file_list(&f_head,argv) ;
				
				/*temp = f_head ;
				while(temp->link) 
				{
					// printf("%s\n",temp->file_name) ;
					temp = temp->link ;
				}*/

				if(last->link != NULL)
				{
					create_database(last->link,head) ;
					printf("INFO : %s file is updated successfully in the database.\n",str) ;
				}
				else
				{
					printf("INFO : Given file already included in the database or file is empty.\n") ;
				}

				break ;
			case 4:
				printf("Enter the word : ") ;
				scanf("%s",str) ;
				if( (ret = search(head,str)) == FAILURE ) 
				{
					printf("Word [%s] not found in the database\n",str) ;
				}
				break ;
			case 5:
				save_database(head) ;
				break ;
			
		}



		printf("Do you want to continue ??\nIf yes then press [Y/y] :\n") ;
		scanf(" %c",&ch) ;
	}

}

