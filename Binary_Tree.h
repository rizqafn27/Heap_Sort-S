#ifndef BINTREE
#define BINTREE
#define MAX_SIZE 15
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef int Infotype;
typedef struct TreeNode *TreeAddress;
typedef struct TreeNode {
	Infotype Info;
	bool Disable;
	TreeAddress Left;
	TreeAddress Right;
};
typedef struct Tree {
	TreeAddress Root;
};

/*--------- About Create / Delete A Node/Tree -----------*/
void CreateTree(TreeAddress *Root);
TreeAddress CreateNode(Infotype Data,int Indexs);
TreeAddress Insert_Level_Order(TreeAddress Root, Infotype Data);
//Belum
void DeleteNode(TreeAddress *Root,TreeAddress NodeDeleted);
void SubTreeDelete(TreeAddress Node);

/*--------- Info About The Tree -----------*/
int Depth(TreeAddress Node);
Infotype Min(TreeAddress Node);
Infotype Max(TreeAddress Node);
void Leaf(TreeAddress Node);
int Height(TreeAddress Node);
int Size(TreeAddress Node);
int MaxDegree(TreeAddress Node);

/*--------- Info About The Node -----------*/
int Degree(TreeAddress Node);
int Level(TreeAddress Node); //
void Ancestor(TreeAddress Node);
void Descendant(TreeAddress Node);
void SubTree(TreeAddress Node);

/*--------- Get About The Node -----------*/
Infotype GetRoot(TreeAddress Node);
Infotype GetParent(TreeAddress Node);
Infotype GetSon(TreeAddress Node);
Infotype GetBrother(TreeAddress Node);

///*--------- Traversing -----------*/
void PreOrder(TreeAddress Node);
void PostOrder(TreeAddress Node);
void InOrder(TreeAddress Node);
void LevelOrder(TreeAddress Node);

#endif
