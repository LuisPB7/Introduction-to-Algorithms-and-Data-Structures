#ifndef _QUEUE_H
#define _QUEUE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"


#define MSG_DIM 501


typedef struct node *link;

struct node{
 Item item;
 link next;
};


typedef struct queue *Queue;

struct queue{
 link head, tail;
 int size;
};


void initializeVector(Queue vec, int N);
void insertItem(Item i, Queue vec);
void deleteHead(int u, Queue vec);
void kill(int u, Queue vec);
void printHead(int u, Queue vec);
void listMessages(int u, Queue vec);
void getItems(int u, Queue vec, Item items);
void deleteQueues(int users, Queue vec);

#endif
