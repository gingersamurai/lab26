#ifndef QUEUE_H
#define QUEUE_H

typedef struct _node node;

struct _node{
    int value;
    node *next;
};

// печатаем очередь
void print_queue(node *back, node *front);

// создаем вершину
node *create_node(int val);

// добавляем вершину в конец очереди
void push_back(node *now, node **back, node **front);

// удаляем вершину из начала очереди
void pop_back(node **back, node **front);

// выполняет 6 задание
void task(node *back, node *front);

#endif