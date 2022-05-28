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

// поиск в очереди первого несорт элем и сорт
int subtask(udt *q);

// сортировка вставкой
void task(udt *q);

// взять k-й элемент в очереди
item udt_get_kth(udt *q, int k);

// поменять местами arr[k1] и arr[k2]
void udt_swap_kth(udt *q, int k1, int k2);

#endif