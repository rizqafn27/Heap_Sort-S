#include "Binary_Tree.h"
#include "queue.h"
#include "stack.h"

TreeAddress CreateNode(Infotype Data){
	TreeAddress Node;
	Node = (TreeAddress) malloc(sizeof(TreeNode));
	Node->Left = Node->Right = NULL;
	Node->Info = Data;
	Node->Disable = false;
	return Node;
}

int searching(LinkAddress angka)
{
	int value;
	printf("Masukkan nilai yang ingin di cari: ");
	scanf("%d", &value);
	int i=1;
	while (!isEmpty(angka))
	{
		if(angka->info->Info == value)
		{
			return i;
		}
		angka = angka->next;
		i++;
	}
	
}

void CreateTree(TreeAddress *Root){
	*Root = NULL;
}

TreeAddress Insert_Level_Order(TreeAddress Root, Infotype Data)
{
	
	if(Root != NULL){
	
	    LinkAddress Queue=NULL;
	    TreeAddress NodeCurrent;
	    NodeCurrent = Root;
	    EnQueue(&Queue,NodeCurrent);
	    
	    while (Queue != NULL) {
	    	
	    	DeQueue(&Queue,&NodeCurrent);
	    	
	        if (NodeCurrent->Left  == NULL) {
	            NodeCurrent->Left = CreateNode(Data);
	            Queue = DeleteAllLinkedList(Queue);
	            break;
	        } 
 			else EnQueue(&Queue,NodeCurrent->Left);
	 
	        if (NodeCurrent->Right == NULL) {
	            NodeCurrent->Right = CreateNode(Data);
	            Queue = DeleteAllLinkedList(Queue);
	            break;
	        } 
			else EnQueue(&Queue,NodeCurrent->Right);
	    }
	}
	else Root = CreateNode(Data);
	
	return Root;
}

void InOrder(TreeAddress Node){
    if (Node != NULL){
        InOrder(Node->Left);
        printf("%d ", Node->Info);
        InOrder(Node->Right);
    }
}
void LevelOrder(TreeAddress Node){
	LinkAddress Queue=NULL;
	TreeAddress NodeCurrent;
	
	EnQueue(&Queue, Node);
	
	while(Queue != NULL){
		DeQueue(&Queue, &NodeCurrent);
		printf("%d ", NodeCurrent->Info);
		
		if(NodeCurrent->Left != NULL){
			EnQueue(&Queue, NodeCurrent->Left);
		}
		
		if(NodeCurrent->Right != NULL){
			EnQueue(&Queue, NodeCurrent->Right);
		}
	}
	printf("\n");
}

void PreOrder(TreeAddress Node){
    if (Node != NULL){
    	printf("%d ", Node->Info);
        PreOrder(Node->Left);
        PreOrder(Node->Right);
    }
}

void PostOrder(TreeAddress Node){
    if (Node != NULL){
        PostOrder(Node->Left);
        PostOrder(Node->Right);
        printf("%d ", Node->Info);
    }
}

int Depth(TreeAddress Node) {
	if (Node==NULL) return 0;
	else{
		
		int LeftDepth = Depth(Node->Left);
		int RightDepth = Depth(Node->Right);
	
		if (LeftDepth > RightDepth) return(LeftDepth+1);
		else return(RightDepth+1);
	}
}

int Height(TreeAddress Node){
	return (Depth(Node) - 1);
}
//
//void DeleteNode(TreeAddress *Root,TreeAddress NodeDeleted){
//	
//	//Save Information Node Delete
//	TreeAddress TempParent 		= NodeDeleted->Parent;
//	TreeAddress TempBrother 	= NodeDeleted->Brother;
//	TreeAddress TempFirstSon 	= NodeDeleted->FirstSon;
//	Infotype TempInfo		= NodeDeleted->Info;
//	
//	if(NodeDeleted != (*Root)){
//		
//		//Check If This Node Is FirstSon / Not
//		if(TempParent->FirstSon == NodeDeleted){
//			//If FirstSon But Have Brother
//			//Move The FirstSon To Brother
//			if(!IsEmpty(TempBrother)){
//				TempParent->FirstSon = TempBrother;
//				if(!IsEmpty(NodeDeleted->FirstSon)) {
//					SubTreeDelete(NodeDeleted->FirstSon);	
//				}
//				NodeDeleted->Parent = NodeDeleted->FirstSon = NodeDeleted->Brother = NULL;
//				free(NodeDeleted);
//			}
//			//If FirstSon But NotHave Brother
//			else {
//				TempParent->FirstSon = NULL;
//				if(!IsEmpty(NodeDeleted->FirstSon)) {
//					SubTreeDelete(NodeDeleted->FirstSon);	
//				}
//				NodeDeleted->Parent = NodeDeleted->FirstSon = NodeDeleted->Brother = NULL;
//				free(NodeDeleted);
//			}
//		}
//		else {
//			
//			TreeAddress Before;
//			//Try To Search Position Before Node
//			Before = TempParent->FirstSon;
//			while(Before->Brother != NodeDeleted){
//				Before = Before->Brother;
//			}
//			//If Not FirstSon (Brother) And Have Other Brother
//			if(!IsEmpty(TempBrother)) {
//				Before->Brother = TempBrother;
//				if(!IsEmpty(NodeDeleted->FirstSon)) {
//					SubTreeDelete(NodeDeleted->FirstSon);	
//				}
//				NodeDeleted->Parent = NodeDeleted->FirstSon = NodeDeleted->Brother = NULL;
//				free(NodeDeleted);
//			}
//			
//			//If Not FirstSon (Brother) And Not Have Other Brother
//			else {
//				Before->Brother = NULL;
//				if(!IsEmpty(NodeDeleted->FirstSon)) {
//					SubTreeDelete(NodeDeleted->FirstSon);	
//				}
//				NodeDeleted->Parent = NodeDeleted->FirstSon  = NodeDeleted->Brother = NULL;
//				free(NodeDeleted);	
//			}
//		}	
//	}
//	else SubTreeDelete(NodeDeleted);
//	
//}

//void SubTreeDelete(TreeAddress Node){
//
//    if (IsEmpty(Node)) return; 
//    //Delete SubTree
//    SubTreeDelete(Node->FirstSon);
//    SubTreeDelete(Node->Brother);
// 
//    //Then Delete The Node
//    Node->Parent = NULL;
//    Node->FirstSon = NULL;
//    Node->Brother = NULL;
//    free(Node);
//}

//
//Infotype Min(TreeAddress Node){
//	bool Resmi;
//	TreeAddress Current = Node;
//	Resmi = true;
//	Infotype Min,TempMin;
//	Min=Current->Info;
//	
//	if(!IsEmpty(Current->FirstSon)){
//		do{
//			if(Current->FirstSon != NULL && Resmi){
//				Current = Current->FirstSon;
//				TempMin = Current->Info;
//				if(TempMin < Min) Min = TempMin;
//			}
//			else {
//				if(Current->Brother != NULL){
//					Current = Current->Brother;
//					TempMin = Current->Info;
//					if(TempMin < Min) Min = TempMin;
//					Resmi = true;
//				}
//				else {
//					Current = Current->Parent;
//					Resmi = false;
//				}
//			}
//		}while(Current != Node);
//	}
//		
//	return Min;
//	
//}
//
//Infotype Max(TreeAddress Node){
//	bool Resmi;
//	Resmi = true;
//	Infotype Max,TempMax;
//	TreeAddress Current = Node;
//	Max=Current->Info;
//	
//	if(!IsEmpty(Current->FirstSon)){
//			
//		do{
//			if(Current->FirstSon != NULL && Resmi){
//				Current = Current->FirstSon;
//				TempMax = Current->Info;
//				if(TempMax > Max) Max = TempMax;
//			}
//			else {
//				if(Current->Brother != NULL){
//					Current = Current->Brother;
//					TempMax = Current->Info;
//					if(TempMax > Max) Max = TempMax;
//					Resmi = true;
//				}
//				else {
//					Current = Current->Parent;
//					Resmi = false;
//				}
//			}
//		}while(Current != Node);
//	}
//	
//	return Max;
//}
//
//int Degree(TreeAddress Node){
//	TreeAddress Current = Node;
//	bool Resmi;
//	Resmi = true;
//	int _Degree=0;
//	if(!IsEmpty(Current->FirstSon)){
//		Current = Current->FirstSon;
//		_Degree++;
//		printf("%c ",Current->Info);
//		while(!IsEmpty(Current->Brother)){
//			Current=Current->Brother;
//			_Degree++;
//		}
//	}
//	
//	return _Degree;
//}
//
//void Leaf(TreeAddress Node){
//	
//	bool Resmi;
//	TreeAddress Current = Node;
//	int _Leaf=0;
//	Resmi = true;
//	printf("{ ");
//	
//	if(!IsEmpty(Current->FirstSon)){
//			
//		do{
//			if(!IsEmpty(Current->FirstSon) && Resmi){		
//				Current = Current->FirstSon;
//			}
//			else {
//				if(!IsEmpty(Current->Brother)){
//					if(IsEmpty(Current->FirstSon)){
//						printf("%c ",Current->Info);
//						_Leaf++;	
//					}
//					Current = Current->Brother;
//					Resmi = true;
//				}
//				else {
//					if(IsEmpty(Current->FirstSon)){
//						printf("%c ",Current->Info);
//						_Leaf++;	
//					}
//					Current = Current->Parent;
//					Resmi = false;
//				}
//			}
//		}while(Current != Node);
//	}
//	printf("} [%d]\n",_Leaf);	
//
//}
//
//int Size(TreeAddress Node){
//	
//	TreeAddress Current=Node;
//	bool Resmi;
//	Resmi = true;
//	int _Size=0;
//	_Size++;
//	if(!IsEmpty(Current->FirstSon)){
//		
//		do{
//			if(!IsEmpty(Current->FirstSon) && Resmi){		
//				Current = Current->FirstSon;
//				_Size++;
//			}
//			else {
//				if(!IsEmpty(Current->Brother)){
//					_Size++;
//					Current = Current->Brother;
//					Resmi = true;
//				}
//				else {
//					Current = Current->Parent;
//					Resmi = false;
//				}
//			}
//		}while(Current != Node);
//	}
//	
//	return _Size;
//}
//
//void Ancestor(TreeAddress Node){
//	int _Ancestor=0;
//	Node=Node->Parent;
//	printf("{ ");
//	if(!IsEmpty(Node)){
//		do {
//			_Ancestor++;
//			printf("%c ",Node->Info);
//			Node = Node->Parent;
//		}while(!IsEmpty(Node));	
//	}
//	printf("} [%d]\n",_Ancestor);
//	
//}
//
//void Descendant (TreeAddress Node){
//	TreeAddress Current=Node;
//	bool Resmi;
//	int _Descendant=0;
//	Current=Current->FirstSon;
//	printf("{ ");
//	if(!IsEmpty(Current)){
//		_Descendant++;
//		printf("%c ",Current->Info);
//		Resmi = true;
//		do{
//			if(!IsEmpty(Current->FirstSon) && Resmi){	
//				_Descendant++;	
//				Current = Current->FirstSon;
//				printf("%c ",Current->Info);
//			}
//			else {
//				if(!IsEmpty(Current->Brother)){
//					_Descendant++;
//					Current = Current->Brother;
//					printf("%c ",Current->Info);
//					Resmi = true;
//				}
//				else {
//					Current = Current->Parent;
//					Resmi = false;
//				}
//			}
//		}while(Current != Node);
//	}
//	printf("} [%d]\n",_Descendant);
//}
//
//Infotype GetRoot(TreeAddress Node){
//
//	if(!IsEmpty(Node->Parent)){
//		do{
//			Node = Node->Parent;
//		}while(!IsEmpty(Node->Parent));	
//	}
//	
//	return Node->Info;
//}
//
//Infotype GetParent(TreeAddress Node){
//	return Node->Parent->Info;
//}
//
//Infotype GetSon(TreeAddress Node){
//	return Node->FirstSon->Info;
//}
//
//Infotype GetBrother(TreeAddress Node){
//	return Node->Brother->Info;
//}
//
//void SubTree(TreeAddress Node){
//	TreeAddress Current;
//	TreeAddress Child;
//	bool Resmi;
//	Child=Node->FirstSon;
//	int NumberOfSubTree = 0;
//	while(!IsEmpty(Child)){
//		if(!IsEmpty(Child->FirstSon)){
//			NumberOfSubTree++;
//			Current = Child;
//			printf("{ ");
//			printf("%c ",Current->Info);
//			Resmi = true;
//			do{
//				if(!IsEmpty(Current->FirstSon) && Resmi){	
//					Current = Current->FirstSon;
//					printf("%c ",Current->Info);
//				}
//				else {
//					if(!IsEmpty(Current->Brother)){
//						Current = Current->Brother;
//						printf("%c ",Current->Info);
//						Resmi = true;
//					}
//					else {
//						Current = Current->Parent;
//						Resmi = false;
//					}
//				}
//			}while(Current != Child);
//			printf("}, ");
//		}
//		Child = Child->Brother;
//	}
//	printf("[%d]\n",NumberOfSubTree);
//}
//
//int MaxDegree(TreeAddress Node){
//	TreeAddress Current=Node;
//	int MaxDegree;
//	int TempMaxDegree;
//	bool Resmi;
//	Resmi = true;
//	TempMaxDegree = 0;
//	MaxDegree = 0;
//	if(!IsEmpty(Node->FirstSon)){
//			
//		do{
//			if(!IsEmpty(Current->FirstSon) && Resmi){		
//				Current = Current->FirstSon;
//				TempMaxDegree=1;
//			}
//			else {
//				if(!IsEmpty(Current->Brother)){
//					TempMaxDegree+=1;
//					Current = Current->Brother;
//					Resmi = true;
//				}
//				else {
//					if(TempMaxDegree>=MaxDegree) MaxDegree = TempMaxDegree;
//					Current = Current->Parent;
//					Resmi = false;
//				}
//			}
//		}while(Current != Node);
//	}
//	return MaxDegree;
//}
//
//address Search (address p, infotype nilai){
///* Mencari apakah ada elemen list dengan Info(P) = nilai */
///* Jika ada, mengirimkan address elemen tsb. */
///* Jika tidak ada, mengirimkan Nil */
///* Menggunakan variabel bertype boolean */
//    bool ketemu = false;
//    address x = NULL ;
//
//    while(!ketemu && !isEmpty(p)){
//        if((*p).info == nilai){
//            x = p;
//            ketemu=true;
//        }
//        p = (*p).next;
//    }
//    return x;
//}



