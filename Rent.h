
typedef struct {
	int codeRent;
	char rentStartDate[20];
	char rentEndDate[20];
	int paid;
	int codeWarrior;
	int codeDragon;
	int leasedUnits;
} Rent;

int initRents();
int enclosesRents();
int saveRents(Rent r);
int existRent(int code);
int amendRent(Rent r, int code);
int quantityRents();
Rent* getRentByIndex(int index);
Rent* getRentByCode(int code);
int giveBackRentByCode(int code);
int searchCodeDragon(int codeDragon);
int searchCodeWarrior(int codeWarrior);
