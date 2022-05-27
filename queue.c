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

int subtask(udt *q){
    for (int i = q->front_id + 1; i <= q->back_id; i++) {
        if (q->arr[i].value < q->arr[i-1].value) {
            while(i > q->front_id) {
                printf("%d -> %d\n", q->arr[i].value, q->arr[i-1].value);
                if (q->arr[i].value < q->arr[i-1].value) {
                    item aa = q->arr[i];
                    q->arr[i] = q->arr[i-1];
                    q->arr[i-1] = aa;
                    i--;
                } else {
                    break;
                }
            }
            return 1;
        }
    }
    return 0;
}

void task(udt *q){
    while(subtask(q) == 1);
}