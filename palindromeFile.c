#include "palindromeFile.h"
File new_queue(){
	File f;
	f.first = NULL;
	f.last = NULL;
	return f;
}
bool is_empty_queue(File f){
	if (f.first == NULL && f.last == NULL){
		return true;
	}
	return false;
}
void push_queue(File* f,char c){
	Palindrome *file; 
	file = malloc(sizeof(*file));
	
	if(file == NULL){
		fprintf(stderr,"ERREUR : Problème d'allocation dynamique\n");
		exit(EXIT_FAILURE);
	}
	
	file->car = c;
	file->next = NULL;
	
	if (is_empty_queue(*f)){
	 	f->first = file;
	 	f->last = file;
	}
	else{
		f->last->next = file;
		f->last = file;
	}
}
void pop_queue(File* f){
	if(is_empty_queue(*f)){
		//printf("Rien à enlever, File vide\n");
		return;
	}
	if(f->first == f->last){
		Palindrome * file = f->first;
		*f = new_queue();
		free(file);
		return;
	}
	Palindrome * file = malloc(sizeof(*file));
	file = f->first;
	f->first = f->first->next;
	file->next = NULL;
	free(file);
}
void print_queue(File* f){
	if (is_empty_queue(*f)){
		//printf("Rien à afficher, File vide\n");
		return;
	}
	Palindrome * file = f->first;
	while(file != NULL){
		printf("[%c]\t", file->car);
		file = file->next;
	}
	printf("\n");
}
void check_palindrome(char expr[]){
	File f;
	f = new_queue();
	for(int i=0; i <= strlen(expr)-1; i++){
		push_queue(&f,expr[i]);
	}
	for (int i=strlen(expr)-1; i >=0 ; i--){
		if (expr[i] == f.first->car){
			pop_queue(&f);
		}
		else{
			break;
		}
	}
	if(is_empty_queue(f)){
		printf("%s est un palindrome\n",expr);
	}
	else{
		printf("%s n'est pas un palindrome\n",expr);
	}
	clear_queue(&f);
}
void clear_queue(File* f){
	if(is_empty_queue(*f)){
		//printf("Rien à vider, File vide.\n");
		return;
	}
	while(!is_empty_queue(*f)){
		pop_queue(f);
	}
}
