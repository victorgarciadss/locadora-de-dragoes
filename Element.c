#include <string.h>
#include <stdlib.h>
#include "Element.h"

#include "Dragon.h"

int MAX_ELEMENTS = 5;

Element* elements;
int qttElements = 0;
int currentCodeElement = 1;

int initElements(){
	
	int i;
	
	elements = (Element *) malloc(MAX_ELEMENTS * sizeof(Element));
	
	if(elements == NULL){
		return 0;
	}
	
	for(i = 0; i < MAX_ELEMENTS; i++){
		
		elements[i].codeElement = -1;
		strcpy(elements[i].elementName, "");
		strcpy(elements[i].vulnerability, "");
		
	}
	
	elements[0].codeElement = currentCodeElement++;
	strcpy(elements[0].elementName, "Agua");
	strcpy(elements[0].vulnerability, "Planta");
	
	elements[1].codeElement = currentCodeElement++;
	strcpy(elements[1].elementName, "Pedra");
	strcpy(elements[1].vulnerability, "Terra");
	
	qttElements+=2;
	
	return 1;
	
}

int enclosesElements(){
	
	free(elements);
	
	elements = NULL;
}

int saveElements(Element e){
	
	if(elements != NULL){
		
		if(qttElements == MAX_ELEMENTS){
			MAX_ELEMENTS++;
			Element* newPointerElements = (Element *) realloc(elements, MAX_ELEMENTS * sizeof(Element));
			
			if(newPointerElements == NULL){
				MAX_ELEMENTS--;
				return 0;
			}
			
			else{
				elements = newPointerElements;
			}
		}
		
		
		e.codeElement = currentCodeElement++;
		elements[qttElements] = e;
		qttElements++;
		
		return 1;
	}
	
	else{
		return 0;
	}
}

int existElement(int code){
	
	int i;
	
	for(i = 0; i < qttElements; i++){
		
		if(elements[i].codeElement == code){
			
			return 1;
		}
	}
	
	return 0;
}

int amendElement(Element e, int code){
	
	int i;
	
	for(i = 0; i < qttElements; i++){
		
		if(elements[i].codeElement == code){
			elements[i] = e;
			elements[i].codeElement = code;
			
			return 1;
		}
	}
	
	return 0;
}

int quantityElements(){
	
	return qttElements;
}

Element* getElementByIndex(int index){
	
	Element* e;
	
	e = (Element *) malloc(1 * sizeof(Element));
	
	if(e == NULL){
		return NULL;
	}
	
	*e = elements[index];
	
	return e;
}

Element* getElementByCode(int code){
	
	int i;
	
	Element* e;
	
	e = (Element *) malloc(1 * sizeof(Element));
	
	if(e ==  NULL){
		return NULL;
	}
	
	for(i = 0; i < qttElements; i++){
		if(elements[i].codeElement == code){
			
			*e = elements[i];
			
			return e;
		}
		
	}
	
	return NULL;
}

Element* getElementByName(char* name){
	
	int i;
	
	Element* e;
	
	e = (Element *) malloc(1 * sizeof(Element));
	
	if(e == NULL){
		return NULL;
	}
	
	for(i = 0; i < qttElements; i++){
		if(strcmp(elements[i].elementName, name) == 0){
			
			*e = elements[i];
			
			return e;
		}
	}
	
	return NULL;
}

int deleteElementByCode(int code){
	
	int i;
	
	int checkElement = searchDragonElement(code);
	
	for(i = 0; i < qttElements; i++){
		
		if(elements[i].codeElement == code){
			
			if(checkElement == 0){
				
				elements[i] = elements[qttElements-1];
				elements[qttElements - 1].codeElement = -1;
				qttElements--;
				
				if(qttElements <= 0.4 * MAX_ELEMENTS){
					MAX_ELEMENTS--;
					Element* newPointerElements = (Element *) realloc(elements, MAX_ELEMENTS * sizeof(Element));
					
					if(newPointerElements == NULL){
						
						MAX_ELEMENTS++;
						return 0;
						
					}
					
					else{
						elements = newPointerElements;
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
