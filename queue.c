#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void print_queue(node *back, node *front){
    node *now = front;
    printf("[ ");
    while(now != back) {

        printf("%d ", now->value);
        now = now->next;
    }
    if (now != NULL) printf("%d ", now->value);
    printf("]\n");
}

node *create_node(int _value){
    node *resnode = (node *) malloc(sizeof(node));
    resnode->value = _value;
    resnode->next = NULL;
    return resnode;
}

void push_back(node *now, node **back, node **front){
    if (now == NULL) printf("SUPERBAD\n");
    if (*front == NULL && *back == NULL) {
        printf("EMPTY\n");
        *front = now;
        *back = now;
    } else {
        (*back)->next = now;
        *back = now;
    }
}

void pop_back(node **back, node **front){
    node *ext = *front;
    
    if (*back == *front) {
        *back = NULL;
        *front = NULL; 
    } else {
        printf("%d -> %d\n", (*front)->value, (*front)->next->value);
        *front = (*front)->next;
    }
    free(ext);
}

void swap(node *a, node *b){
    int add = a->value;
    a->value = b->value;
    b->value = add;
}

void task (node *back, node *front){
    node *now = front;
    while (1) {
        if (now == NULL || now == back) {
            return;
        } else if (now->value < now->next->value) {
            break;
        }
        now = now->next;
    }

    while(1) {
        if (now == NULL || now == back) {
            return;
        } else if (now->value < now->next->value) {
            swap(now, now->next);
            now = now->next;
        } else {
            return;
        }
    }
}


