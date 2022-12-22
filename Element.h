
typedef struct {
	int codeElement;
	char elementName[30];
	char vulnerability[30];
} Element;

int initElements();
int enclosesElements();
int saveElements(Element e);
int existElement(int code);
int amendElement(Element e, int code);
int quantityElements();
Element* getElementByIndex(int index);
Element* getElementByCode(int code);
Element* getElementByName(char* name);
int deleteElementByCode(int code);
