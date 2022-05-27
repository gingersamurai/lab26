#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void udt_create(udt* q){
    q->front_id = 1;
    q->back_id = 0;
}

bool udt_is_empty(const udt* q){
    if (q->front_id > q->back_id) return true;
    else return false;
}

void udt_push_back(udt* q, item new_elem){
    if (udt_is_empty(q)) {
        q->front_id = q->back_id;
        q->arr[q->back_id] = new_elem;
    } else {
        q->back_id++;
        q->arr[q->back_id] = new_elem;
    }
}

void udt_pop_front(udt *q){
    if (udt_is_empty(q)) return;
    q->front_id++;
}

void udt_print(udt *q){
    printf("[ ");
    for (int i = q->front_id; i <= q->back_id; i++){
        printf("(%d:%d) ", q->arr[i].key,q->arr[i].value);
    }
    printf(" ]\n");
}

int udt_size(const udt *q){
    return q->back_id - q->front_id + 1;    
}

item udt_front(udt *q){
    return q->arr[q->front_id];
}