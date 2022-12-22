#include <string.h>
#include <stdlib.h>
#include "Rent.h"

#include "Dragon.h"
#include "Warrior.h"

int MAX_RENTS = 5;

Rent* rents;
int qttRents = 0;
int currentCodeRent = 1;

int initRents(){
	
	int i;
	
	rents = (Rent *) malloc(MAX_RENTS * sizeof(Rent));
	
	if(rents == NULL){
		return 0;
	}
	
	for(i = 0; i < MAX_RENTS; i++){
		rents[i].codeRent = -1;
		strcpy(rents[i].rentStartDate, "");
		strcpy(rents[i].rentEndDate, "");
		rents[i].paid = 0;
	}
	
	return 1;
}

int enclosesRents(){
	
	free(rents);
	
	rents = NULL;
}

int saveRents(Rent r){
	
	int resultDecreaseStock = decreaseStock(r.codeDragon, r.codeWarrior, r.leasedUnits);
	
	
	if(rents != NULL){
		

		if(resultDecreaseStock == 1){
			
			if(qttRents == MAX_RENTS){
				MAX_RENTS++;
				Rent* newPointerRents = (Rent *) realloc(rents, MAX_RENTS * sizeof(Rent));
				
				if(newPointerRents == NULL){
					MAX_RENTS--;
					return 0;
				}
				
				else{
					rents = newPointerRents;
				}
				
			}
			
			
			
			r.codeRent = currentCodeRent++;

			
			rents[qttRents] = r;
			rents[qttRents].paid = 1;
			
			qttRents++;
			
			
			return 1; 
		}
		
		else if(resultDecreaseStock == 2){
			return 2;
		}
		
		else if(resultDecreaseStock == 3){
			return 3;
		}
		
		else{
			return 4;
		}
	}
	
	else{
		return 0;
	}
}

int existRent(int code){
	
	int i;
	
	for(i = 0; i < qttRents; i++){
		
		if(rents[i].codeRent == code){
			
			return 1;
		}
	}
	
	return 0;
}

int amendRent(Rent r, int code){
	
	int i;
	
	int dif;
	
	for(i = 0; i < qttRents; i++){
		
		if(rents[i].codeRent == code){
			
			r.codeWarrior = rents[i].codeWarrior;
			r.codeDragon = rents[i].codeDragon;
			
			dif = r.leasedUnits - rents[i].leasedUnits;
			
			decreaseStock(code, rents[i].codeWarrior, dif);
			
			rents[i] = r;
			rents[i].codeRent = code;
			
	
			
			return 1;
		}
	}
	
	return 0;
}

int quantityRents(){
	
	return qttRents;
}

Rent* getRentByIndex(int index){
	
	Rent* r;
	
	r = (Rent *) malloc(1 * sizeof(Rent));
	
	if(r == NULL){
		return NULL;
	}
	
	*r = rents[index];
	
	return r;
}

Rent* getRentByCode(int code){
	
	int i;
	
	Rent* r;
	
	r = (Rent *) malloc(1 * sizeof(Rent));
	
	if(r == NULL){
		return NULL;
	}
	
	for(i = 0; i < qttRents; i++){
		if(rents[i].codeRent == code){
			
			*r = rents[i];
			
			return r;
		}
	}
	
	return NULL;
}

int giveBackRentByCode(int code){
	
	int i;
	
	for(i = 0; i < qttRents; i++){
	
		
		if(rents[i].codeRent == code){
			if(increaseStock(rents[i].codeDragon, rents[i].leasedUnits) == 1){
			
				rents[i] = rents[qttRents - 1];
				rents[qttRents - 1].codeRent = -1;

				rents[qttRents -1].paid = 0;
				
				qttRents--;
				
				if(qttRents <= 0.4 * MAX_RENTS){
					MAX_RENTS--;
					Rent* newPointerRents = (Rent *) realloc(rents, MAX_RENTS * sizeof(Rent));
					
					if(newPointerRents == NULL){
						
						MAX_RENTS++;
						return 0;
					}
					
					else{
						rents = newPointerRents;
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


int searchCodeDragon(int codeDragon){
	
	int i;
	
	for(i = 0; i < qttRents; i++){
		
		if(rents[i].codeDragon == codeDragon){
			return 1;
		}
	}
	
	return 0;
}


int searchCodeWarrior(int codeWarrior){
	
	int i;
	
	for(i = 0; i < qttRents; i++){
		
		if(rents[i].codeWarrior == codeWarrior){
			return 1;
		}
	}
	
	return 0 ;
}




