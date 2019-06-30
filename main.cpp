#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Binary_Tree.h"
#include "queue.h"
#include "stack.h"
#include "Heap.h"

int main() {
	int Elemen;
	int Value;
	Tree TreeCDT;
	CreateTree(&TreeCDT.Root);
	int angka;
	
	//Insert Secara Level Order
	printf("Masukan Jumlah Elemen : ");
	scanf("%d",&Elemen);	
	for(int i=0;i<Elemen;i++){
		printf("[%d] -> ",i+1);scanf("%d",&Value);
		TreeCDT.Root = Insert_Level_Order(TreeCDT.Root,Value);
	}
	printf("\n");
	//Get Element Tree Ke Queue
	LinkAddress Queue=GetElementTree(TreeCDT.Root);
	printf("Sebelum Di Sorting : "); Tampil_List(Queue);
	
	//Heapsort
	Queue = Heapsort(Queue,TreeCDT.Root);
	printf("Setelah Di Sorting : "); Tampil_List(Queue);
	
	printf("Angka yang di cari berad di index: %d",searching(Queue));		
	
	
}
