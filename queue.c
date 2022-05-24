#include <stdio.h>
#include <stdlib.h>

#include "queue.h"


node *create_node(int _value){
    node *resnode = (node *) malloc(sizeof(node));
    resnode->value = _value;
    resnode->next = NULL;
    return resnode;
}

node *print_queue(node *back, node *front){
    node *now = front;
    printf("[ ");
    while(now != back) {
        if (now == NULL) {
            printf("\nBAD\n");
        }
        printf("%d ", now->value);
        now = now->next;
    }
    printf("%d ]", now->value);
}
