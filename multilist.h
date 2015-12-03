#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define last(L) ((L).last)

 struct Info_Member
{   int id;
    string nama;
    string email;
    string *menu;
};

struct Info_Group
{   int id;
    string nama;
    string tanggal;
};

typedef Info_Member infotypeanak;
typedef Info_Group infotypeinduk;
typedef struct element_induk *address;
typedef struct element_anak *address_anak;

struct element_anak
{   infotypeanak info;
    address_anak next;
    address_anak prev;
};

struct listanak
{   address_anak first;
	address_anak last;
};

struct element_induk
{   infotypeinduk info;
    listanak lanak;
    address next;
};

struct listinduk
{   address first;
};

void create_list(listinduk &L);
void create_list_anak(listanak &l);
//Additional
bool list_empty(listinduk L);
bool list_empty_anak(listanak l);
//
address alokasi_induk(infotypeinduk X);
address_anak alokasi_anak(infotypeanak X);
address find_element(listinduk L, infotypeinduk X);
address_anak find_element_anak(listanak L, infotypeanak X);

void insert_first(listinduk &L, address P);
void insert_after(listinduk &L, address P);
void insert_last(listinduk &L, address P);

void insert_first_anak(listanak &L, address_anak P);
void insert_after_anak(listanak &L, address_anak P);
void insert_last_anak(listanak &L, address_anak P);

void delete_first(listinduk &L);
void delete_last(listinduk &L);
void delete_after(listinduk &L);

void delete_first_anak(listanak &L);
void delete_last_anak(listanak &L);
void delete_after_anak(listanak &L);

void print_info(listinduk L);
void print_info_anak(listinduk L);

void insert_group(listinduk &L);
void insert_member(listinduk &L);
void delete_group(listinduk &L);
void delete_member(listinduk &L);
void input_data_group(infotypeinduk &X);
void input_data_member(infotypeanak &X);

void edit_group(listinduk &L);
#endif // MULTILIST_H_INCLUDED
