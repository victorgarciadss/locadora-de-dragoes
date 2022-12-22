
typedef struct {
	int codeDragon;
	char name[30];
	int age;
	float dailyValue;
	int stockUnits;
	int codeElement;
} Dragon;

int initDragons();
int enclosesDragons();
int saveDragons(Dragon d);
int existDragon(int code);
int amendDragon(Dragon d, int code);
int quantityDragons();
Dragon* getDragonByIndex(int index);
Dragon* getDragonByCode(int code);
Dragon* getDragonByName(char* name);
int decreaseStock(int codeDragon, int codeWarrior, int qttUnits);
int increaseStock(int codeDragon, int qttUnits);
int deleteDragonByCode(int code);
int searchDragonElement(int codeElement);
