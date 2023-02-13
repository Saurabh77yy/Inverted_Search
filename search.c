#include "inverted_search.h"

int search(Wlist **head,char *word) 
{
	int index = tolower(word[0]) % 'a' ;
  
        // other than alphabet
        if(!(index >= 0 && index <= 25))
		index = 26 ;

	// if head[index] is null
	if(head[index] == NULL)
		return FAILURE ;
	
	// traverse through the list
	Wlist *temp = head[index] ;
	while(temp)
	{
		if(!strcmp(temp->word,word))
		{
			green() ;
			printf("Word [%s] is found in the database and it is present in %d file(s)\n",word,temp->file_count) ;
			// traverse through file table
			Ltable *ptr = temp->Tlink ;
			while(ptr)
			{
				printf("In file %s %d time(s)\n",ptr->file_name,ptr->word_count) ;

				ptr = ptr->table_link ;
			}
			reset() ;

			return SUCCESS ;

		}

		temp = temp->link ;
	}

	// came out of the loop word not present in the database
	return FAILURE ;
}
