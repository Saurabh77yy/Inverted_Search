#include "inverted_search.h"

/*
--Description : insert_at_last() function definition
*/


extern char *fname ;

int insert_at_last(Wlist **head, data_t *data)
{
	// create a word node
	Wlist *new = malloc(sizeof(Wlist)) ;

	if(new == NULL)
		return FAILURE ;

	// update the values
	new->file_count = 1 ;
	strcpy(new->word,data) ;
	new->Tlink = NULL ;
	new->link = NULL ;

	// call the function to update the table link
	update_link_table(&new) ;

	// check whether word is empty or not
	if(*head == NULL)
	{
		*head = new ;
		return SUCCESS ;
	}

	// traverse through the list
	Wlist *temp = *head ;
	while(temp->link != NULL)
	{
		temp = temp->link ;
	}
	temp->link = new ;
	return SUCCESS ;

}


int update_link_table(Wlist **head)
{
	// create node
	Ltable *new = malloc(sizeof(Ltable)) ;

	if(new == NULL)
		return FAILURE ;

	new->word_count = 1 ;
	new->table_link = NULL ;
	strcpy(new->file_name,fname) ;
	(*head)->Tlink = new ;

	return SUCCESS ;
}


