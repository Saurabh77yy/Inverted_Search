#include "inverted_search.h"


void display_database(Wlist *head[])
{

	if(head[0] == NULL)
	{
		red() ;
		printf("Create your database first to use display option.\n") ; reset() ;
	}
	else
	{
		 green() ;
		printf("[index]\t    <word>\t<file_count>\t<file>\t\n") ; reset() ;
	}

	int i ;
	
	for(i=0 ; i<27 ; i++)
	{
		if(head[i] != NULL)
		{
			purple() ;
			printf(" [%2d]\t",i) ;
			reset() ;
			// traverse through the word node
			Wlist *temp = head[i] ;
			int var = 1 ;
			
			while(temp)
			{
				if(var == 1)
				{
					printf("%10s\t%2d file(s): file: ",temp->word,temp->file_count) ;
					var = 0 ;
				}
				else
					printf("\n\t%10s\t%2d file(s): file: ",temp->word,temp->file_count) ;

				
				// traverse through the files
				Ltable *ptr = temp->Tlink ;
				while(ptr)
				{
					printf("%s: %2d time(s)",ptr->file_name,ptr->word_count) ;

					ptr = ptr->table_link ;
				}

				temp = temp->link ;
			}
			printf("\n") ;
		}

	}
}

