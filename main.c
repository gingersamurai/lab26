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
    printf("your query: ");
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