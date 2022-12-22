#include <string.h>
#include <stdlib.h>
#include "Warrior.h"


#include "Rent.h"

int MAX_WARRIORS = 5;


Warrior* warriors;
int qttWarriors = 0;
int currentCodeWarrior = 1;

int initWarriors(){
	
	int i;
	
	warriors = (Warrior *) malloc(MAX_WARRIORS * sizeof(Warrior));
	
	if(warriors == NULL){
		return 0;
	}
	
	
	
	for(i = 0; i < MAX_WARRIORS; i++){
		
		warriors[i].codeWarrior = -1;
		strcpy(warriors[i].name, "");
		strcpy(warriors[i].title, "");
		strcpy(warriors[i].kingdom, "");
	}
	
	warriors[0].codeWarrior = currentCodeWarrior++;
	strcpy(warriors[0].name, "Joao");
	strcpy(warriors[0].title, "Arquiteto");
	strcpy(warriors[0].kingdom, "Asgard");
	qttWarriors++;
	
	return 1;
}

int enclosesWarriors(){
	
	free(warriors);
	
	warriors = NULL;
}

int saveWarriors(Warrior w){

	
	if (warriors != NULL){
		
		if(qttWarriors == MAX_WARRIORS){
			MAX_WARRIORS++;
			Warrior* newPointerWarriors = (Warrior *) realloc(warriors, MAX_WARRIORS * sizeof(Warrior));
			
			if(newPointerWarriors == NULL){
				
				MAX_WARRIORS--;
				return 0;
				
			}
			
			else{
				warriors = newPointerWarriors;
			}
			
		}
		

		w.codeWarrior = currentCodeWarrior++;
		warriors[qttWarriors] = w;
		qttWarriors++;
		

		return 1;
	}
		
	else{
		return 0;
	}
		
}

int existWarrior(int code){
	
	int i; 
	
	for(i = 0; i < qttWarriors; i++){
		
		if(warriors[i].codeWarrior == code){
			
			return 1;
		}
	}
	
	return 0;
}

int amendWarrior(Warrior w, int code){
	
	int i;
	
	for(i = 0; i < qttWarriors; i++){
		
		if(warriors[i].codeWarrior == code){
			warriors[i] = w;
			warriors[i].codeWarrior = code;
			
			return 1;
		}
	
		
	}
	
	return 0;
	
}

int quantityWarriors(){
	
	return qttWarriors;
}

Warrior* getWarriorByIndex(int index){
	
	Warrior* w;
	
	w = (Warrior *) malloc(1 * sizeof(Warrior));
	
	if(w == NULL){
		return NULL;
	}
	
	*w = warriors[index];
	
	return w;
}

Warrior* getWarriorByCode(int code){
	
	int i;
	
	Warrior* w;
	
	w = (Warrior*) malloc(1 * sizeof(Warrior));
	
	if(w == NULL){
		return NULL;
	}
	
	for(i = 0; i < qttWarriors; i++){
		
		if(warriors[i].codeWarrior == code){
			
			*w = warriors[i];
			
			return w;
		}
		
	}
	
	return NULL;
}


Warrior* getWarriorByName(char* name){
	
	int i;
	
	Warrior* w;
	
	w = (Warrior*) malloc(1 * sizeof(Warrior));
	
	if(w == NULL){
		return NULL;
	}
	
	for(i = 0; i < quantityWarriors(); i++){
		if(strcmp(warriors[i].name, name) == 0){
			
			*w = warriors[i];
			
			return w;
		}
	}
	
	return NULL;
}



int deleteWarriorByCode(int code){
	
	int i;
	
	int checkWarrior = searchCodeWarrior(code);
	
	for(i = 0; i < qttWarriors; i++){
		
		if (warriors[i].codeWarrior == code){
			
			if(checkWarrior == 0){
				warriors[i] = warriors[qttWarriors-1];
				warriors[qttWarriors - 1].codeWarrior = -1;
				qttWarriors--;
				
				if(qttWarriors <= 0.4 * MAX_WARRIORS){
					MAX_WARRIORS--;
					Warrior* newPointerWarriors = (Warrior *) realloc(warriors, MAX_WARRIORS * sizeof(Warrior));
					
					if(newPointerWarriors == NULL){
						MAX_WARRIORS++;
						return 0;
					}
				
					else{
						warriors = newPointerWarriors;
					}
						
				}
				
				
				return 1;
			}
			
			else{
				return 2;
			}
				
		}
		
		
	}
	
	return 0;
}



