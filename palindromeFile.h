#ifndef PALINDROME
#define PALINDROME

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// definition de la structure
typedef struct Palindrome{
	char car;
	struct Palindrome *next;
}Palindrome, *Pldrm;
//
typedef struct File{
	Palindrome* first;
	Palindrome* last;
}File;
// pointeur initialisé

// prototype
File new_queue();
bool is_empty_queue();
void push_queue(File* f,char c);
void pop_queue(File* f);
void print_queue(File* f);
void check_palindrome(char* expr);
void clear_queue(File* f);

#endif
