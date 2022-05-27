# Отчет по лабораторной работе N 26 по курсу
# "Фундаментальная информатика"

**студент группы:** М8О-110Б-21, Малышев Назим Бахтиярович\
**Контакты:** nazimmalyshev47@gmail.com\
**работа выполнена:** 14.05.2022\
**Преподаватель:** Никулин Сергей Петрович

## 1. Тема
Абстрактные типы данных. Рекурсия.Модульное программирование на
языке Си.

## 2. Цель работы
Овладеть навыками работы с абстрактными типами данных.

## 3. Задание
6 номер. Метод вставки.

## 4. Оборудование 
**CPU:** Intel Core i7-8550U\
**RAM:** 8 GB\
**SSD:** 256 GB\
**MONITOR:** 2560 x 1440

## 5. Программное обеспечивание 
**Операционная система семейства:** ubuntu, **версия** 20.04 LTS\
**Интерпретатор команд:** bash, **версия** 5.0.17(1)-release.\
**Система программирования**: --, **версия**-- \
**Редактор текстов:** vs code, **версия** 1.66.1\
**Утилиты операционной системы:** --\
**Прикладные системы и программы:** --

## 6. Идея, метод, алгоритм
1. создать очередь
2. прописать основные методы
3. в задании сначала найти элемент, у которого правый сосед больше
4. до тех пор пока п.3 выполняется менять значение с правым соседом 

# 7. Сценарий выполнения работы
1. реализация очереди в queue.c queue.h
4. реализация основного файла main.c
5. настройка сборки и запуска проекта в makefile
6. тестирование
7. написание отчета 

# 8. Распечатка протокола

**main.c**
```c
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void print_menu(){
    printf("-------------------------\n");
    printf("1 check if is empty\n");
    printf("2 push back elem\n");
    printf("3 pop front elem\n");
    printf("4 print queue\n");
    printf("5 queue size\n");
    printf("6 queue front\n");
    printf("7 my task - sort\n");
    printf("8 exit\n");
    printf("-------------------------\n");
}

int main(){
    udt *q = (udt *) malloc(sizeof(udt));

    udt_create(q);
    int query = 0;
    while (query != 8) {
        print_menu();
        scanf("%d", &query);
        if (query == 1) {
            bool res = udt_is_empty(q);
            if (res == true) {
                printf("empty\n");
            } else {
                printf("not empty\n");
            }
        } else if (query == 2) {
            printf("enter key and value: ");
            item x;
            scanf("%d %d", &x.key, &x.value);
            udt_push_back(q, x);
        } else if (query == 3) {
            udt_pop_front(q);
        } else if (query == 4) {
            udt_print(q);
        } else if (query == 5) {
            printf("%d\n", udt_size(q));
        } else if (query == 6){
            printf("(%d:%d)\n", udt_front(q).key, udt_front(q).value);
        } else if (query == 7){
            task(q);
        } else if (query == 8){
            return 0;
        } else {
            printf("ERROR\n");
        }
    }
 
}
```

**queue.h**
```c
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

#endif
```


**queue.c**
```c
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
```



**makefile**
```make
run: main
	./main
main: queue.o main.o
	gcc queue.o main.o -o main
queue.o: queue.c
	gcc -c queue.c -o queue.o
main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -f main.o queue.o main

```

### пример работы
```
gingersamurai@LY530:~/coding/lab/lab25-26$ make 
gcc -c queue.c -o queue.o
gcc queue.o main.o -o main
./main
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
2
enter key and value: 1 43
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
2
enter key and value: 4 12
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
4
[ (1:43) (4:12)  ]
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
5
2
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
1
not empty
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
4
[ (1:43) (4:12)  ]
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
2
enter key and value: 4 5467
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
2
enter key and value: 65 1
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
2
enter key and value: 654
9
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
4
[ (1:43) (4:12) (4:5467) (65:1) (654:9)  ]
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
3
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
4
[ (4:12) (4:5467) (65:1) (654:9)  ]
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
3
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
4
[ (4:5467) (65:1) (654:9)  ]
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
2
enter key and value: 4 2
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
2
enter key and value: -1
4
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
4
[ (4:5467) (65:1) (654:9) (4:2) (-1:4)  ]
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
7
1 -> 5467
9 -> 5467
9 -> 1
2 -> 5467
2 -> 9
2 -> 1
4 -> 5467
4 -> 9
4 -> 2
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
4
[ (65:1) (4:2) (-1:4) (654:9) (4:5467)  ]
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
2
enter key and value: 6 8
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
4
[ (65:1) (4:2) (-1:4) (654:9) (4:5467) (6:8)  ]
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
5
6
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
7
8 -> 5467
8 -> 9
8 -> 4
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------
4
[ (65:1) (4:2) (-1:4) (6:8) (654:9) (4:5467)  ]
-------------------------
1 check if is empty
2 push back elem
3 pop front elem
4 print queue
5 queue size
6 queue front
7 my task - sort
8 exit
-------------------------


```


## 9. Дневник отладки
--

## 10. Замечания автора
--
## 11. Выводы
Мной была изучена такая структура, как очередь.\
Очередь – очень полезная структура,
которая может решать различные задачи