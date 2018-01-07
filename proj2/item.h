#ifndef _ITEM_H
#define _ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSG_DIM 501

typedef struct mensagem *Item;

struct mensagem{ 
 int emissor,receptor;
 char* pmsg;
};

Item newItem(int sender, int receiver);
void readMessage(Item item, int max);
int compareItems(Item a, Item b);
void printItems(int size, Item items);

#endif
