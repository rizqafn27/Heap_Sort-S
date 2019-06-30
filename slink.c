#include "slink.h"
#include "boolean.h"
boolean isEmpty(LinkAddress p){
	if(p == Nil){
		return true;
	}
	else return false;
}

void Create_Node (LinkAddress *p){
	*p = (LinkAddress) malloc(sizeof(ElmtList));
	if(isEmpty(*p)) printf("Alokasi Gagal");	
}

void Isi_Node(LinkAddress *p,infotype nilai){
	if(!isEmpty(*p)){
		info(*p) = nilai;    
   		next(*p) = Nil;	
	}
	else printf("Isi Nilai Gagal");    
} 

LinkAddress GetNodeSequenceTo(LinkAddress Queue,int count){
	LinkAddress QueueTemp = Queue;
	while(count != 0){
		QueueTemp = QueueTemp->next;
		count--;
	}
	return QueueTemp;	
}

void Tampil_List (LinkAddress p){
	printf("{ ");
   	while(!isEmpty(p)){
   	printf("%d ",p->info->Info);
	p = next(p);
   }
   printf("}\n");
}

void Ins_Awal (LinkAddress *p, LinkAddress PNew){
	if(isEmpty(*p)){
		next(PNew) = Nil;        
   		*p = PNew;
	}
	else {
			next(PNew) = Nil; 
		   	next(PNew) = *p;    
		   	*p = PNew;
	}	
}

void Ins_Akhir (LinkAddress *p, LinkAddress PNew){
	LinkAddress temp;
	if(isEmpty(*p)){
		next(PNew) = Nil;        
   		*p = PNew;
	}
	else {
		temp = *p;
		while(!isEmpty(next(temp))){
			temp=next(temp);
		}
		next(temp) = PNew;	
	}	
}

int NbElmt (LinkAddress p){
	if(p == Nil) return 0;
	return 1 + NbElmt(next(p));
	
}

LinkAddress Search (LinkAddress p, infotype nilai){
		if(isEmpty(p)){
			return 0;
		}
		else {
		LinkAddress temp;
		boolean found=false;
		temp = p;
		while(!isEmpty(p) && !found){
			if (info(temp) == nilai)found = true;
			else temp = next(temp);
		}
		return temp;
		}
}
	
void InsertAfter (LinkAddress *pBef, LinkAddress PNew){
	if(!isEmpty(*pBef)){
	next(PNew) = next(*pBef);
	next(*pBef) = PNew;
	}
}
	
void Del_Awal (LinkAddress * p, infotype * X){
		if(!isEmpty(*p)){
			LinkAddress temp;
			temp = *p;
			*p = next(temp);
			*X = info(temp);
			next(temp) = Nil;
			DeAlokasi(&temp);
			temp = NULL;	
		}
	}
	
void DeAlokasi (LinkAddress *p){
	if(isEmpty(*p)) free(*p);
	*p==NULL;
}

LinkAddress DeleteAllLinkedList(LinkAddress Node){
	infotype DeletedInfo;
	while(Node!=NULL){
		Del_Awal(&Node,&DeletedInfo);
	}	
}

void Del_Akhir (LinkAddress * p, infotype * X){
		LinkAddress temp;
		LinkAddress temp2;
		if(!isEmpty(*p)){
			temp = temp2 = *p;
			while(!isEmpty(next(temp))){
				temp2=temp;
				temp=next(temp);
			}
			if(*p == temp){
				Del_Awal(p,X);
			}
			else {
				next(temp2) = Nil;
				*X = info(temp);
				DeAlokasi(&temp); 	
			}	
		}
	}

//infotype Rerata (LinkAddress p){
//		if (!isEmpty(p)){
//			int Tot, Sum = 1, Avg;
//			Tot = info(p);
//			while(next(p)!=Nil){
//				p = next(p);
//				Tot = Tot + info(p);
//				Sum++;
//			}
//			Avg = Tot/Sum;
//			return Avg;	
//		}
//		else return 0;
//	}
	
	
LinkAddress BalikList (LinkAddress p)
	{
		if(!isEmpty(p)){
			LinkAddress current, prev, next1;	
			current = p;
			prev = Nil;
			while (current != Nil){
				next1 = next(current);
				next(current) = prev;
				prev = current;
				current = next1;
			}
			p = prev;
			return p;
		}
		else return 0;
	}
void Del_After(LinkAddress *pBef,infotype *X){
	if(!isEmpty(*pBef)){
		LinkAddress temp;
		temp = next(*pBef);
		next(*pBef) = Nil;
		next(*pBef) = next(temp);
		next(temp) = Nil;
		DeAlokasi(&temp);	
	}
	
}

//infotype Min (LinkAddress p)
//	{
//		if(!isEmpty(p)){
//			int min;
//			LinkAddress Q;
//			Q = p;
//			min = info(Q);
//			while(next(Q) != Nil){
//				Q = next(Q);
//				if(info(Q) < min){
//					min = info(Q);
//				}
//			}
//			return min;
//		}
//		else return 0;
//	}
