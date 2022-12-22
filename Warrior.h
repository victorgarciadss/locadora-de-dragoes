
typedef struct {
	int codeWarrior;
	char name[30];
	char title[30];
	char kingdom[30];
} Warrior;


int initWarriors();
int enclosesWarriors();  // na entrega final, vai ser util
int saveWarriors(Warrior w);
int existWarrior(int code);
int amendWarrior(Warrior w, int code);
int quantityWarriors();
Warrior* getWarriorByIndex(int index);
Warrior* getWarriorByCode(int code);
Warrior* getWarriorByName(char* name);
int deleteWarriorByCode(int code);


