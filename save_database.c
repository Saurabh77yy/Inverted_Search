#include "inverted_search.h"

void save_database(Wlist *head[])
{
	data_t f_name[20] ;
	printf("Enter file name : ") ;
	scanf("%s",f_name) ;

	FILE *fptr = fopen(f_name,"w") ;

	if(fptr)
	{
		int i ;
		for(i=0 ; i<27 ; i++)
		{
			if(head[i] != NULL)
			{
				fprintf(fptr,"#[%d];\n",i) ;
			
				// traverse through the word node
				Wlist *temp = head[i] ;
				int var = 1 ;
			
				while(temp)
				{
					if(var == 1)
					{
						fprintf(fptr,"[%s]\t%d file(s): file:",temp->word,temp->file_count) ;
						var = 0 ;
					}
					else
						fprintf(fptr,"\n[%s]\t%d file(s): file:",temp->word,temp->file_count) ;

				
					// traverse through the files
					Ltable *ptr = temp->Tlink ;
					while(ptr)
					{
						fprintf(fptr," %s : %d time(s)",ptr->file_name,ptr->word_count) ;

						ptr = ptr->table_link ;
					}

					temp = temp->link ;
				}
				fprintf(fptr,"#\n\n") ;
			}

		}

		printf("INFO : Backup file created successfully.\n") ;
	}
	else
	{
		printf("Backup file couldn't be created.\n") ;
	}
		
	fclose(fptr);
}
