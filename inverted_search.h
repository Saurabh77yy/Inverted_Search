#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>

#define FAILURE -1 
#define SUCCESS  0
#define FNAME_SIZE 15 
#define WORD_SIZE 10 
#define FILE_EMPTY -2 
#define FILE_NOT_AVAILABLE -3
#define REPETATION -4 

/* structure for file list */
typedef char data_t ;
typedef struct file_node
{
	data_t file_name[FNAME_SIZE] ;
	struct file_node *link ;
}Flist;

/* structure for link table */
typedef struct linkTable_node
{
	int word_count ;
	data_t file_name[FNAME_SIZE] ;
	struct linkTable_node *table_link ;
}Ltable;

/* structure for word_node */ 
typedef struct word_node
{
	int file_count ;
	data_t word[WORD_SIZE] ;
	Ltable *Tlink;
	struct word_node *link ;
}Wlist;


/* file validation */
void file_validation_n_file_list(Flist **f_head, char *argv[]) ;

/* create database */
void create_database(Flist *f_head,Wlist *head[]) ;
int to_create_list_of_files(Flist **f_head, char *name) ;
Wlist* read_datafile(Flist *file, Wlist *head[], char *filename) ;
int insert_at_last(Wlist **head, data_t *data) ;
int update_link_table(Wlist **head) ;
int update_word_count(Wlist **head) ;
int isFileEmpty(char *filename) ;

int print_word_count(Wlist *head) ;

/* search database */
int search(Wlist **head,char *word) ;

/* display database */
void display_database(Wlist *head[]) ;

/* save database */
void save_database(Wlist *head[]) ;
void write_database(Wlist *head, FILE* databsefile);

/* update database */
void update_database(Wlist *head[], Flist **f_head, char *argv[]) ;

/* to add color */
void red() ;
void reset() ;
void green() ;
void purple() ;

#endif

