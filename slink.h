/* File        : linked.h */ 
/* Deskripsi   : ADT linked list dengan representasi fisik pointer */ 
/*   Representasi LinkAddress dengan pointer */ 
/*   InfoType adalah integer */ 
/* Dibuat oleh : Ade Chandra Nugraha */ 
 
#ifndef linked_H 
#define linked_H 

/*Definisi akses komponen type, standard kuliah Algoritma dan pemrograman*/ 
#define info(P) (P)->info 
#define next(P) (P)->next 
#define Nil NULL 

#include <stdio.h> 
#include <malloc.h> 
#include "boolean.h" 
#include "Binary_Tree.h"
 
typedef TreeAddress infotype; 
typedef struct tElmtList *LinkAddress; 
typedef struct tElmtList {  
	infotype info;  
	LinkAddress  next;  
	} ElmtList; 
 
boolean isEmpty(LinkAddress p); 
// Tujuan : memeriksa apakah linked masih kosong 
// Linked list kosong , jika Head == NULL 
 
void Create_Node (LinkAddress *p); 
// Tujuan : memesan memory dengan alokasi dinamis 
// Jika berhasil mengirimkan LinkAddress, dan jika gagal mengirimkan NULL 
// Parameter : P (parameter Output) 
 
void Isi_Node (LinkAddress *p , infotype nilai); 
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan 
// Periksa keberadaan P, Nilai diisi jika P tidak NULL 
//    *p.next diisi NULL 
// Parameter : P (parameter Input-Output); Nilai (parameter Input) 
 
void Tampil_List (LinkAddress p); 
// Tujuan : Menampilkan seluruh isi Linked List 
// Parameter : p (parameter input) 
 
void Ins_Awal (LinkAddress *p, LinkAddress PNew); 
// Tujuan : Insert 1 node baru (PNew) di awal Linked List 
// Parameter : P (input-output) 
//             PNew (input) 
 
void Ins_Akhir (LinkAddress *p, LinkAddress PNew); 
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */ 
/* IS : p mungkin Kosong */ 
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */ 
 
LinkAddress Search (LinkAddress p, infotype nilai); 
/* Mencari apakah ada elemen list dengan Info(P) = nilai */ 
/* Jika ada, mengirimkan LinkAddress elemen tsb. */ 
/* Jika tidak ada, mengirimkan Nil */ 
/* Menggunakan variabel bertype boolean */ 
 
void InsertAfter (LinkAddress * pBef, LinkAddress PNew); 
/* Tujuan : Menyambungkan 1 Node baru(PNew) stlah node tertentu(PBef) */ 
/* IS : pBef sudah dialokasi */ 
/* FS : Insert PNew sebagai elemen sesudah PBef */ 
/* Asumsi : pBef adalah posisi insert */ 
 
void Del_Awal (LinkAddress * p, infotype * X); 
/* IS : P TIDAK Kosong */ 
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */ 
/*  dan alamat elemen pertama di dealokasi */ 
 
void Del_Akhir (LinkAddress * p, infotype * X); 
/* IS : P TIDAK Kosong */ 
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */ 
/*  dan alamat elemen terakhir di dealokasi */ 
 
void Del_After (LinkAddress * pBef, infotype * X); 
/* IS : pBef TIDAK Kosong (hasil search posisi node sebelum yang didel)*/ 
/* FS : menghapus Node setelah pBef */ 
/*      nilai info node yang dihapus disimpan pada X */ 
/*    dan alamat elemen setelah pBef di dealokasi */ 
 
void DeAlokasi (LinkAddress * p); 
/* IS : P terdefinisi */ 
/* FS : P dikembalikan ke sistem */ 
/* Melakukan dealokasi / pengembalian LinkAddress P ke system */ 
 
int NbElmt (LinkAddress p); 
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */ 
// Recursif Mode 
 
infotype Min (LinkAddress p); 
/* Mengirimkan nilai Info(P) yang minimum */ 
 
infotype Rerata (LinkAddress p); 
/* Mengirimkan nilai rata-rata Info(P) */ 
 
LinkAddress BalikList (LinkAddress p); 
/* IS : p sembarang */ 
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst */ 
 
LinkAddress GetNodeSequenceTo(LinkAddress Queue,int count);

LinkAddress DeleteAllLinkedList(LinkAddress Node);
///*--------- Searching -------------*/
int searching(LinkAddress angka);
#endif 
