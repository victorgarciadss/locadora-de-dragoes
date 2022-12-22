#include <string.h>
#include <stdlib.h>
#include "Dragon.h"

#include "Element.h"
#include "Rent.h"
#include "Warrior.h"

int MAX_DRAGONS = 5;

Dragon* dragons;
int qttDragons = 0;
int currentCodeDragon = 1;

int initDragons(){
	
	int i;
	
	dragons = (Dragon *) malloc(MAX_DRAGONS * sizeof(Dragon));
	
	if(dragons == NULL){
		return 0;
	}
	
	for(i = 0; i < MAX_DRAGONS; i++){
		
		dragons[i].codeDragon = -1;
		strcpy(dragons[i].name, "");
		dragons[i].age = -1;
		dragons[i].dailyValue = -1;
		dragons[i].stockUnits = -1;
		
	}
	
	dragons[0].codeDragon = currentCodeDragon++;
	strcpy(dragons[0].name, "Vafir");
	dragons[0].age = 300;
	dragons[0].dailyValue = 49.99;
	dragons[0].stockUnits = 100;
	dragons[0].codeElement = 1;
	
	qttDragons++;
	
	return 1;
	
}

int enclosesDragons(){
	
	free(dragons);
	
	dragons = NULL;
}

int saveDragons(Dragon d){
	
	int i;
	
	if(dragons != NULL){
		
		if(qttDragons == MAX_DRAGONS){
			MAX_DRAGONS++;
			Dragon* newPointerDragons = (Dragon *) realloc(dragons, MAX_DRAGONS * sizeof(Dragon));
			
			if(newPointerDragons == NULL){
				MAX_DRAGONS--;
				return 0;
			}
			
			else{
				dragons = newPointerDragons;
			}
		}
		
		
		
		d.codeDragon = currentCodeDragon++;

		dragons[qttDragons] = d;
		qttDragons++;
		
		
		
		return 1;
	}
	
	else{
		return 0;
	}
	
}

int existDragon(int code){
	
	int i;
	
	for(i = 0; i < qttDragons; i++){
		
		if(dragons[i].codeDragon == code){
			
			return 1;
		}
	}
	
	return 0;
}

int amendDragon(Dragon d, int code){
	
	int i;
	
	for(i = 0; i < qttDragons; i++){

		
		if(dragons[i].codeDragon == code){
			dragons[i] = d;
			dragons[i].codeDragon = code;
			
			return 1;
		}
	
		
	}
	
	return 0;
	
}

int quantityDragons(){
	
	return qttDragons;
}

Dragon* getDragonByIndex(int index){
	
	Dragon* d;
	
	d = (Dragon *) malloc(1 * sizeof(Dragon));
	
	if(d == NULL){
		return NULL;
	}
	
	*d = dragons[index];
	
	return d;
}

Dragon* getDragonByCode(int code){
	
	int i;
	
	Dragon* d;
	
	d = (Dragon *) malloc(1 * sizeof(Dragon));
	
	if(d == NULL){
		return NULL;
	}
	
	for(i = 0; i < qttDragons; i++){
		if(dragons[i].codeDragon == code){
			
			*d = dragons[i];
			
			return d;
		}
		
	}
	
	return NULL;
	
	
}

Dragon* getDragonByName(char* name){
	
	int i;
	
	Dragon* d;
	
	d = (Dragon *) malloc(1 * sizeof(Dragon));
	
	if(d == NULL){
		return NULL;
	}
	
	for(i = 0; i < qttDragons; i++){
		if(strcmp(dragons[i].name, name) == 0){
			
			*d = dragons[i];
			
			return d;
		}
	}
	
	return NULL;
}

int decreaseStock(int codeDragon, int codeWarrior, int qttUnits){
	
	int i;
	
	Warrior* w = getWarriorByCode(codeWarrior);
	
	if(w == NULL){
		return 0;
	}
	
	
	if(w->codeWarrior == codeWarrior){
	
		for(i = 0; i < qttDragons; i++){
			
			if(dragons[i].codeDragon == codeDragon){
			
				if(dragons[i].stockUnits > 0){
					dragons[i].stockUnits -= qttUnits;
					
					return 1;
				}
			
				else{
					return 2;
				}	
			}
		}
		
		return 3;
	
	}
	
	else{
		return 0;
	}
	
	
}

int increaseStock(int codeDragon, int qttUnits){
	
	int i;
		
		for(i = 0; i < qttDragons; i++){
		
			if(dragons[i].codeDragon == codeDragon){
				dragons[i].stockUnits += qttUnits;
				
				return 1;
			}
			
		
		}
		
		return 0;

	
}

int deleteDragonByCode(int code){
	
	int i;
	
	int checkDragon = searchCodeDragon(code);
	
	
	for(i = 0; i < qttDragons; i++){
		
		
		if(dragons[i].codeDragon == code){
			
			if(checkDragon == 0){
				
				dragons[i] = dragons[qttDragons-1];
				dragons[qttDragons - 1].codeDragon = -1;
				qttDragons--;
				
				if(qttDragons <= 0.4 * MAX_DRAGONS){
					MAX_DRAGONS--;
					Dragon* newPointerDragons = (Dragon *) realloc(dragons, MAX_DRAGONS * sizeof(Dragon));
					
					if(newPointerDragons == NULL){
						
						MAX_DRAGONS++;
						return 0;
						
					}
					
					else{
						dragons = newPointerDragons;
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


int searchDragonElement(int codeElement){
	
	int i;
	
	for(i = 0; i < qttDragons; i++){
		
		if(dragons[i].codeElement == codeElement){
			return 1;
		}
	}
	
	return 0;
}



