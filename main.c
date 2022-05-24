#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void print_menu(){
    printf("┌─────────────────────────────────────┐\n");
    printf("│1.добавить Х в конец очереди вершину │\n");
    printf("│2.удалить из конца очереди вершину   │\n");
    printf("│3.выполнить задание                  │\n");
    printf("│4.напечатать очередь                 │\n");
    printf("│5.завершить работу программы         │\n");
    printf("└─────────────────────────────────────┘\n");
    printf("введите запрос: ");
}

int main(){
    node *front = NULL;
    node *back = NULL;
    int q = 0;
    while (q != 5){
        print_menu();
        scanf("%d", &q);
        if (q == 1){
            printf("введите Х:");
            int x;
            scanf("%d", &x);
            node *new_node = create_node(x);
            push_back(new_node, &back, &front);
        } else if (q == 2){
            pop_back(&back, &front);
        } else if (q == 3){
            task(back, front);
        } else if (q == 4){
            print_queue(back, front);
        }
    }
}