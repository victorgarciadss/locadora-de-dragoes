#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <locale.h>

#include "Warrior.h"
#include "Dragon.h"
#include "Element.h"
#include "Rent.h"




void listElements();

void showMainMenu(){
	printf("MENU: \n");
	printf("\n 0 - Sair");
	printf("\n 1 - Guerreiros");
	printf("\n 2 - Drag�es");
	printf("\n 3 - Elementos de Drag�es");
	printf("\n 4 - Loca��es");
	printf("\n Escolha uma op��o: ");
}

void showSubMenu(){
	printf("\n 0 - Sair");
	printf("\n 1 - Listar");
	printf("\n 2 - Cadastrar");
	printf("\n 3 - Alterar");
	printf("\n 4 - Pesquisar");
	printf("\n 5 - Excluir");
	
	printf("\n O que voce quer fazer? ");
	

}

void showSubMenuRent(){
	printf("\n 0 - Sair");
	printf("\n 1 - Listar Loca��es");
	printf("\n 2 - Locar Drag�o");
	printf("\n 3 - Alterar Loca��o");
	printf("\n 4 - Pesquisar");
	printf("\n 5 - Devolver Drag�o");
	
	printf("\n O que voce quer fazer? ");
	
	
}

// ----------- FUN��ES GUERREIRO --------------------

void listWarriors(){
	
	
	int i;
	
	Warrior* w;
	
	
	for(i = 0; i < quantityWarriors(); i++){
		
		w = getWarriorByIndex(i);
		
		if(w == NULL){
			printf("\nN�o foi poss�vel obter guerreiro! \n");
			
			return;
		}
		
		
		if (w->codeWarrior > 0){
			printf("\n%d - Nome: %s - T�tulo: %s - Reino: %s",
			w->codeWarrior,
			w->name,
			w->title,
			w->kingdom);
		}
		
		free(w);
			
	}
	
	
	
	if(quantityWarriors() == 0){
		printf("N�o h� guerreiros cadastrados!!");
	}
		
	
	printf("\n\n");
}

void registerWarriors(){
	
	Warrior w;

	printf("Digite o nome do guerreiro: ");
	fflush(stdin);
	scanf("%[^\n]s", w.name);
	
	printf("Digite o titulo do guerreiro: ");
	fflush(stdin);
	scanf("%[^\n]s", w.title);
	
	printf("Digite o reino do guerreiro: ");
	fflush(stdin);
	scanf("%[^\n]s", w.kingdom);
	
	int resultWarrior = saveWarriors(w);
	

	if (resultWarrior == 1){
		printf("\nGuerreiro cadastrado com sucesso!\n");
	}
	
	else{
		printf("\nFalha ao cadastrar guerreiro!\n");
	}
		
}

void updateWarrior(){
	
	listWarriors();
	
	Warrior w;
	
	int codeWarrior;
	
	if(quantityWarriors() == 0){
		return;
	}
	
	printf("Digite o c�digo do guerreiro a ser alterado: ");
	scanf("%d", &codeWarrior);
	
	
	if(existWarrior(codeWarrior) != 1){
		printf("\nN�o h� guerreiro com esse c�digo! \n");
		
	}
	
	else{
		printf("\nQual o novo nome do Guerreiro? ");
		fflush(stdin);
		scanf("%[^\n]s", w.name);
		
		printf("Qual o novo T�tulo do Guerreiro? ");
		fflush(stdin);
		scanf("%[^\n]s", w.title);
		
		printf("Qual o novo Reino do Guerreiro? ");
		fflush(stdin);
		scanf("%[^\n]s", w.kingdom);
		
		if(amendWarrior(w, codeWarrior) == 1){
			printf("\nGuerreiro alterado com sucesso! \n");
		}
		
		else{
			printf("\nFalha ao alterar Guerreiro! \n");
		}
	}
}

void searchWarrior(){
	
	Warrior* w;
	
	char warriorName[30];
	
	printf("\nDigite o nome do guerreiro desejado: ");
	fflush(stdin);
	scanf("%[^\n]s", warriorName);
	
	w = getWarriorByName(warriorName);
	
	if(w == NULL){
		printf("\nGuerreiro n�o encontrado!!");
	}
	
	else{
		printf("\nC�digo do guerreiro - %d", w->codeWarrior);
		printf("\nNome do Guerreiro: %s", w->name);
		printf("\nT�tulo do Guerreiro: %s", w->title);
		printf("\nReino do Guerreiro: %s", w->kingdom);
	}
	
	free(w);
	
	printf("\n");
}

void deleteWarrior(){
	
	listWarriors();
	
	if(quantityWarriors() == 0){
		return;
	}
	
	int codeWarrior;
	
	printf("Digite o c�digo do guerreiro a ser apagado: ");
	scanf("%d", &codeWarrior);
	
	int resultDeleteWarrior = deleteWarriorByCode(codeWarrior);
	
	if (resultDeleteWarrior == 1){
		printf("\nGuerreiro apagado com sucesso!\n");
	}
	else if(resultDeleteWarrior == 2){
		printf("\nN�o � possivel excluir o Guerreiro, ele est� locando um drag�o! \n");
	}
		
	else{
		printf("\nFalha ao apagar o guerreiro!\n");
	}
		
}

// ------------ FUN��ES DRAG�ES ------------

void listDragons(){
	
	
	int i;
	
	Dragon* d;
	Element* e;
	
	for(i = 0; i < quantityDragons(); i++){
		
		d = getDragonByIndex(i);
		
		if(d == NULL){
			printf("\nN�o foi poss�vel obter drag�o! \n");
			
			return;
		}
	
		if(d->codeDragon > 0){
			printf("\n%d - Nome do Drag�o: %s - Idade: %d anos", d->codeDragon, d->name, d->age);
			printf("\nValor di�rio: R$ %.2f - Unidades em estoque: %d", d->dailyValue, d->stockUnits);
			
			e = getElementByCode(d->codeElement);
			
			printf("\nElemento do Drag�o: %s  \n", e->elementName);
		}
		
		free(d);
		free(e);
	}
	
	
	
	if(quantityDragons() == 0){
		printf("\nN�o h� drag�es cadastrados!");
	}
	
	printf("\n");
}

void registerDragons(){
	
	Dragon d;
	
	printf("\nDigite o Nome do Drag�o: ");
	fflush(stdin);
	scanf("%[^\n]s", d.name);
	
	printf("Digite a idade do Drag�o: ");
	fflush(stdin);
	scanf("%d", &d.age);
	
	printf("Qual � o valor di�rio em Reais do Drag�o? ");
	fflush(stdin);
	scanf("%f", &d.dailyValue);
	
	printf("Quantas unidades h� em estoque? ");
	fflush(stdin);
	scanf("%d", &d.stockUnits);
	
	listElements();
	
	printf("\nQual o c�digo do elemento do drag�o? ");
	fflush(stdin);
	scanf("%d", &d.codeElement);
	
	
	if(saveDragons(d) == 1){
		printf("\nDrag�o cadastrado com sucesso! \n");
	}
	
	else{
		printf("\nFalha ao cadastrar Drag�o! \n");
	}
	
	
}


void updateDragon(){
	
	listDragons();
	
	Dragon d;
	
	int codeDragon;
	
	if(quantityDragons() == 0){
		return;
	}
	
	printf("\nDigite o c�digo do Drag�o a ser alterado: ");
	scanf("%d", &codeDragon);
	
	if(existDragon(codeDragon) != 1){
		printf("\nN�o h� drag�o com esse c�digo! \n");
	}
	
	else{
		printf("\nDigite o novo Nome do Drag�o: ");
		fflush(stdin);
		scanf("%[^\n]s", d.name);
		
		printf("Digite a nova idade do Drag�o: ");
		fflush(stdin);
		scanf("%d", &d.age);
		
		printf("Qual � o novo valor di�rio em Reais do Drag�o? ");
		fflush(stdin);
		scanf("%f", &d.dailyValue);
		
		printf("Quantas unidades h� em estoque? ");
		fflush(stdin);
		scanf("%d", &d.stockUnits);
		
		listElements();
		
		printf("\nQual o novo c�digo do elemento do drag�o? ");
		fflush(stdin);
		scanf("%d", &d.codeElement);
		
		if(amendDragon(d, codeDragon) == 1){
			printf("\nDrag�o alterado com sucesso! \n");
		}
	}
	
	
	
}

void searchDragon(){
	
	Dragon* d;
	Element* e;
	
	char dragonName[30];
	
	printf("\nDigite o nome do Drag�o desejado: ");
	fflush(stdin);
	scanf("%[^\n]s", dragonName);
	
	d = getDragonByName(dragonName);
	
	if(d == NULL){
		printf("\nDrag�o n�o encontrado!");
	}
	
	else{
		printf("\nC�digo do Drag�o: %d", d->codeDragon);
		printf("\nNome do Drag�o: %s", d->name);
		printf("\nIdade do Drag�o: %d anos", d->age);
		printf("\nValor di�rio: R$ %.2f", d->dailyValue);
		printf("\nUnidades em estoque: %d", d->stockUnits);
		
		e = getElementByCode(d->codeElement);
		
		printf("\nElemento do Drag�o: %s", e->elementName);
		
		free(d);
		free(e);
	
	}
	
	printf("\n");
}

void deleteDragon(){
	
	
	listDragons();
	
	if(quantityDragons() == 0){
		return;
	}
	
	int codeDragon;
	
	printf("\nDigite o c�digo do drag�o a ser apagado: ");
	scanf("%d", &codeDragon);
	
	int resultDeleteDragon = deleteDragonByCode(codeDragon);
	
	if(resultDeleteDragon == 1){
		printf("\nDrag�o apagado com sucesso! \n");
	}
	
	else if(resultDeleteDragon == 2){
		printf("\nN�o � poss�vel excluir, drag�o est� locado!! \n");
	}
	
	else{
		printf("\nFalha ao apagar Drag�o! \n");
	}
	
	
}


// ----------- FUN��ES ELEMENTOS -------------


void listElements(){
	
	int i;
	
	Element* e;
	
	for(i = 0; i < quantityElements(); i++){
		
		e = getElementByIndex(i);
		
		if(e == NULL){
			printf("\nN�o foi possivel obter elemento! \n");
			
			return;
		}
		
		if(e->codeElement > 0){
			printf("\n%d - Nome do Elemento: %s - Vulnerabilidade: %s",
			
			e->codeElement,
			e->elementName,
			e->vulnerability);
		}
		
		free(e);
	}
	
	
	
	if(quantityElements() == 0){
		printf("\nN�o h� elementos cadastrados!");
	}
	
	printf("\n");
	
}

void registerElements(){
	
	Element e;
	
	printf("\nDigite o nome do Elemento: ");
	fflush(stdin);
	scanf("%[^\n]s", e.elementName);
	
	printf("Qual a vulnerabilidade desse elemento? ");
	fflush(stdin);
	scanf("%[^\n]s", e.vulnerability);
	
	if(saveElements(e) == 1){
		printf("\nElemento cadastrado com sucesso! \n");
	}
	
	else{
		printf("\nFalha ao cadastrar Elemento! \n");
	}
}

int updateElement(){
	
	listElements();
	
	Element e;
	
	int codeElement;
	
	if(quantityElements() == 0){
		return;
	}
	
	printf("\nDigite o c�digo do Elemento a ser alterado: ");
	scanf("%d", &codeElement);
	
	if(existElement(codeElement) != 1){
		printf("\nN�o h� Elemento com esse c�digo! \n");
	}
	
	else{
		printf("\nDigite o novo nome do Elemento: ");
		fflush(stdin);
		scanf("%[^\n]s", e.elementName);
		
		printf("Qual a nova vulnerabilidade do elemento? ");
		fflush(stdin);
		scanf("%[^\n]s", e.vulnerability);
		
		if(amendElement(e, codeElement) == 1){
			printf("\nElemento alterado com sucesso! \n");
		}
	}
}

void searchElements(){
	
	Element* e;
	
	char elementName[30];
	
	printf("\nDigite o nome do elemento desejado: ");
	fflush(stdin);
	scanf("%[^\n]s", elementName);
	
	e = getElementByName(elementName);
	
	if(e == NULL){
		printf("\nElemento n�o encontrado!!");
	}
	
	else{
		printf("\n%d - Nome do Elemento: %s", e->codeElement, e->elementName);
		printf("\nVulnerabilidade: %s", e->vulnerability);
		
		free(e);
	}
	
	
	
	printf("\n");
}

void deleteElement(){
	
	listElements();
	
	if(quantityElements() == 0){
		return;
	}
	
	int codeElement;
	
	printf("\nDigite o c�digo do elemento a ser apagado: ");
	fflush(stdin);
	scanf("%d", &codeElement);
	
	int resultDeleteElement = deleteElementByCode(codeElement);
	
	if(resultDeleteElement == 1){
		printf("\nElemento apagado com sucesso! \n");
	}
	
	else if(resultDeleteElement == 2){
		printf("\nFalha ao excluir, tem drag�o cadastrado com esse elemento! \n");
	}
	
	else{
		printf("\nFalha ao apagar Elemento! \n");
	}
}

// ----------- FUN��ES LOCA��ES ---------------

void listRents(){
	
	int i;
	
	Rent* r;
	
	Warrior* w;
	Dragon* d;
	
	
	for(i = 0; i < quantityRents(); i++){
		
		r = getRentByIndex(i);
		
		w = getWarriorByCode(r->codeWarrior);
		d = getDragonByCode(r->codeDragon);
		
		if(r == NULL){
			printf("\nN�o foi possivel obter a loca��o! \n");
			return;
		}
		
		if(w == NULL){
			printf("\nN�o foi possivel obter guerreiro! \n");
			return;
		}
		
		if(d == NULL){
			printf("\nN�o foi possivel obter drag�o! \n");
			return;
		}
		
	
		if(r->codeRent > 0){
			printf("%d - Guerreiro: %s, locou o Drag�o: %s",
			r->codeRent,
			w->name,
			d->name);
			
			printf("\nQuantidade de Drag�es locados: %d", r->leasedUnits);
			printf("\nData de in�cio da Loca��o: %s", r->rentStartDate);
			printf("\nData de fim da Loca��o: %s \n\n", r->rentEndDate);
		}
		
		free(r);
		
		free(w);
		free(d);
	
	}
	
	
	
	if(quantityRents() == 0){
		printf("N�o h� loca��es realizadas!! \n");
	}
}

void registerRents(){
	
	Rent r;
	
	listWarriors();
	
	printf("\nDigite o c�digo do guerreiro que vai locar drag�o: ");
	fflush(stdin);
	scanf("%d", &r.codeWarrior);
	
	listDragons();
	
	printf("\nDigite o c�digo do drag�o a ser locado: ");
	fflush(stdin);
	scanf("%d", &r.codeDragon);
	
	printf("\nQuantas unidades voc� deseja locar? ");
	fflush(stdin);
	scanf("%d", &r.leasedUnits);
	
	printf("\nDigite a data de in�cio da loca��o: ");
	fflush(stdin);
	scanf("%[^\n]s", r.rentStartDate);
	
	printf("Digite a data de fim da loca��o: ");
	fflush(stdin);
	scanf("%[^\n]s", r.rentEndDate);
	
	int result = saveRents(r);
	
	if(result == 1){
		printf("\nLoca��o realizada com sucesso!! \n");
	}
	
	else if(result == 2){
		printf("\nFalha ao realizar loca��o!! Pouco estoque! \n");
	}
	
	else if(result == 3){
		printf("\nDrag�o n�o est� cadastrado!! \n");
	}
	
	else if(result == 4){
		printf("\nGuerreiro n�o est� cadastrado!! \n");
	}
	
	else{
		printf("\nFalha ao realizar Loca��o!! \n");
	}
	
}

int updateRent(){
	
	listRents();
	
	Rent r;
	
	int codeRent;
	
	if(quantityRents() == 0){
		return;
	}
	
	printf("\nDigite o c�digo da loca��o a ser alterada: ");
	scanf("%d", &codeRent);
	
	if(existRent(codeRent) != 1){
		printf("\nN�o h� loca��o com esse c�digo! \n");
	}
	
	else{
		printf("\nDigite a quantidade de unidades que voc� deseja locar? ");
		fflush(stdin);
		scanf("%d", &r.leasedUnits);
		
		printf("\nDigite a data de in�cio da loca��o: ");
		fflush(stdin);
		scanf("%[^\n]s", r.rentStartDate);
		
		printf("Digite a data de fim da loca��o: ");
		fflush(stdin);
		scanf("%[^\n]s", r.rentEndDate);
		
		printf("\nDigite se est� pago(1) ou n�o(0): ");
		fflush(stdin);
		scanf("%d", &r.paid);
		
		
		if(amendRent(r, codeRent) == 1){
			printf("\nLoca��o alterado com sucesso! \n");
		}
	}
}


void searchRents(){
	
	Rent* r;
	
	int codeRent;
	
	printf("\nDigite o c�digo da loca��o que voc� deseja pesquisar: ");
	fflush(stdin);
	scanf("%d", &codeRent);
	
	r = getRentByCode(codeRent);
	
	if(r == NULL){
		printf("\nC�digo n�o encontrado!");
	}
	
	else{
		printf("\nLoca��o de c�digo %d", r->codeRent);
		
		Warrior* w = getWarriorByCode(r->codeWarrior);
		Dragon* d = getDragonByCode(r->codeDragon);
		
		if(w == NULL){
			printf("\nN�o foi possivel obter guerreiro! \n");
			return;
		}
		
		if(d == NULL){
			printf("\nN�o foi possivel obter drag�o! \n");
			return;
		}
		
		printf("\nNome do Guerreiro: %s", w->name);
		printf("\nNome do Drag�o: %s", d->name);
		printf("\nData de in�cio: %s", r->rentStartDate);
		printf("\nData de fim: %s", r->rentEndDate);
		printf("\nQuantidade de unidades locadas: %d", r->leasedUnits);
		printf("\nPago: %d", r->paid);
		
		free(w);
		free(d);
	}
	
	free(r);
	
	printf("\n");
}

void finishRent(){
	
	listRents();
	
	if(quantityRents() == 0){
		return;
	}
	
	int codeRent;
	
	printf("\nDigite o c�digo da loca��o que voc� deseja terminar: ");
	fflush(stdin);
	scanf("%d", &codeRent);
	
	int answerCode = giveBackRentByCode(codeRent);
	
	if(answerCode == 1){
		printf("\nDrag�o devolvido com sucesso!! \n");
	}
	
	else if(answerCode == 2){
		printf("\nDrag�o n�o est� locado!! \n");
	}
	
	else{
		printf("\nLoca��o n�o encontrada!! \n");
	}
	
}



int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	
	int answerWarriors = initWarriors();
	int answerDragons = initDragons();
	int answerElements = initElements();
	int answerRents = initRents();
	
	if(answerWarriors == 0  || answerDragons == 0 || answerElements == 0 || answerRents == 0){
		printf("\nErro ao locar mem�ria! \n");
		
		return;
	}
	
	
	
	int optionMenu;
	int optionSubMenu;
	
	do{
		
		showMainMenu();
		
		scanf("%d", &optionMenu);
		
		
		switch(optionMenu){
			
			case 1:
				
				do{
					showSubMenu();
					scanf("%d", &optionSubMenu);
					printf("\n");
					
					switch(optionSubMenu){
						
						case 1: 
							listWarriors();
						break;
						
						case 2:
							registerWarriors();
						break;
						
						case 3:
							updateWarrior();
						break;
						
						case 4:
							searchWarrior();
						break;
						
						case 5:
							deleteWarrior();
						break;
						
						default:
							if(optionSubMenu != 0){
								printf("Op��o Inv�lida!! \n");
							}
						break;
							
					}
					
				} while(optionSubMenu != 0); 
				
			break;
			
			case 2:
				
				do{
					showSubMenu();
					
					scanf("%d", &optionSubMenu);
					printf("\n");
					
					switch(optionSubMenu){
						
						case 1:
							listDragons();
						break;
						
						case 2:
							registerDragons();
						break;
						
						case 3:
							updateDragon();
						break;
						
						case 4:
							searchDragon();
						break;
						
						case 5:
							deleteDragon();
						break;
						
						default:
							if(optionSubMenu != 0){
								printf("\nOp��o inv�lida!! \n");
							}
						break;
					}
					
					
					
				} while(optionSubMenu != 0);
				
				
			break;
			
			case 3:
				
				do{
					
					showSubMenu();
					
					scanf("%d", &optionSubMenu);
					printf("\n");
					
					switch(optionSubMenu){
						
						case 1:
							listElements();
						break;
						
						case 2:
							registerElements();
						break;
						
						case 3:
							updateElement();
						break;
						
						case 4:
							searchElements();
						break;
						
						case 5:
							deleteElement();
						break;
						
						default:
							if(optionSubMenu != 0){
								printf("\nOp��o inv�lida!! \n");
							}
						break;
					}
					
				} while (optionSubMenu != 0);
				
			break;
			
			case 4:
				
				do{
					
					showSubMenuRent();
					
					scanf("%d", &optionSubMenu);
					printf("\n");
					
					switch(optionSubMenu){
						
						case 1:
							listRents();
						break;
						
						case 2:
							registerRents();
						break;
						
						case 3:
							updateRent();
						break;
						
						case 4:
							searchRents();
						break;
						
						case 5:
							finishRent();
						break;
						
						default:
							if(optionSubMenu != 0){
								printf("\nOp��o inv�lida!! \n");
							}
						break;
					}
					
				} while (optionSubMenu != 0);
				
			break;
			

			default:
				if(optionMenu != 0){
					printf("\nOp��o inv�lida!! \n\n");
				}
			
				else{
					enclosesWarriors();
					enclosesDragons();
					enclosesElements();
					enclosesRents();
				}
				
			break;
		}
		
		
	 } while(optionMenu != 0);
	 
	 
	 
	 
	return 0;
}
