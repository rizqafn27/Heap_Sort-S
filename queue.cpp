#include "queue.h"
#include "boolean.h"

void EnQueue(LinkAddress *p,infotype value){
	LinkAddress PNew;
	Create_Node(&PNew);
	Isi_Node(&PNew,value);
	Ins_Akhir (p,PNew);	
}

void DeQueue(LinkAddress *p,infotype *X){
	Del_Awal(p,X);
}
