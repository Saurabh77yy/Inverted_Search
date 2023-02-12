#include "inverted_search.h"


void display_database(Wlist *head[])
{
	int i ;
	for(i=0 ; i<27 ; i++)
	{
		if(head[i] != NULL)
		{
			printf("[%d]\t",i) ;
			
			// traverse through the word node
			Wlist *temp = head[i] ;
			int var = 1 ;
			
			while(temp)
			{
				if(var == 1)
				{
					printf("[%s]\t%d file(s): file:",temp->word,temp->file_count) ;
					var = 0 ;
				}
				else
					printf("\n\t[%s]\t%d file(s): file:",temp->word,temp->file_count) ;

				
				// traverse through the files
				Ltable *ptr = temp->Tlink ;
				while(ptr)
				{
					printf(" %s : %d time(s)",ptr->file_name,ptr->word_count) ;

					ptr = ptr->table_link ;
				}

				temp = temp->link ;
			}
			printf("\n") ;
		}

	}
}

