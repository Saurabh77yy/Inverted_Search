#include "inverted_search.h"

/*
--Description :
*/

char *fname ;

void create_database(Flist *f_head,Wlist *head[])
{
	while(f_head)
	{
		read_datafile(f_head,head,f_head->file_name) ;
		f_head = f_head->link ;
	}

}


Wlist* read_datafile(Flist *file, Wlist *head[], char *filename)
{
	// open file in read mode
	fname = filename ;

	FILE *fptr = fopen(filename,"r") ;

	// declare an array to read
	char word[WORD_SIZE] ;
	while(fscanf(fptr,"%s",word) != EOF)
	{
		int flag = 1 ;
		/*printf("#----checking word %s------#\n",word) ;*/

		int index = tolower(word[0]) % 'a' ;

		// other than alphabet
		if(!(index >= 0 && index <= 25))
			index = 26 ;
		
		// check whether words are repeated or not
		if(head[index] != NULL)
		{
			Wlist *temp = head[index] ;
			
			// compare and check if repeated
			while(temp)
			{
				if(!(strcmp(temp->word,word))) 
				{
					update_word_count(&temp) ;
					flag = 0 ;
					break ;
				}
				
				temp = temp->link ; 	
			}
		}

		if(flag == 1)
		{
			// words are not repeated
			insert_at_last(&head[index],word) ;
		}
	}

}


int update_word_count(Wlist **head)
{
	// check whether filename are same or not
	Ltable *temp =  (*head)->Tlink,*prev ;
	
	while(temp)
	{
		prev = temp ;
		
		if(!strcmp(temp->file_name,fname))
		{
			temp->word_count++ ;
			return SUCCESS ;
		}

		temp = temp->table_link ;
	}

	// if file is not same then create table link --> increment file count  
	Ltable *new = malloc(sizeof(Ltable)) ;

	if(new == NULL)
	{
		return FAILURE ;
	}

	(*head)->file_count++ ;

	// update data
	strcpy(new->file_name,fname) ;
	new->word_count = 1 ;
	new->table_link = NULL ;

	// temp->table_link = new ;
	prev->table_link = new ;
	return SUCCESS ;

}
