#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>


typedef struct {
    int key;
    int value;
} item;

typedef struct {
    int front_id;
    int back_id;
    item arr[100000];
} udt;

// создать очередь
void udt_create(udt *q);

// проверить на пустоту
bool udt_is_empty(const udt *q);

// добавить элемент в конец очереди
void udt_push_back(udt *q, item new_elem);

// удалить первый элемент из очереди
void udt_pop_front(udt *q);

// напечатать очередь
void udt_print(udt *q);

// вернуть размер очереди
int udt_size(const udt *q);

// вернуть первый элемент очереди
item udt_front(udt *q);

#endif