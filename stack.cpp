#include "stack.h"
#include "boolean.h"

void push(LinkAddress *p,infotype value){
	LinkAddress PNew;
	Create_Node(&PNew);
	Isi_Node(&PNew,value);
	Ins_Awal (p,PNew);	
}

void pop(LinkAddress *p,infotype *X){
	Del_Awal(p,X);
}
