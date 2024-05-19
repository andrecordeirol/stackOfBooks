#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define size 5

struct tbook {
    int code;
    char name[50];
    char author[50];
};

struct pstack {
    struct tbook data[size];
    int start;
    int end;
};

struct tbook book;
struct pstack stack;
int start = 0;
int end = 0;
int op;

//Prototipation
void stack_in();
void stack_out();
void show_menu();
void show_stack();

int main(){
    setlocale(LC_ALL, "portuguese");
    op = 1;
    while (op != 0){
        system("cls");
        show_stack();
        show_menu();
        scanf("%d", &op);
        switch (op) {
            case 1:
                stack_in();
                break;
            case 2:
                stack_out();
                break;
        }
    }
    return (0);
}

void stack_in(){
    if (stack.start == size){
        printf("The stack has reached its maximum size.\n");
        system("pause");
    }
    else {
        printf("\nEnter the code of the book: ");
        scanf("%d", stack.data[stack.end].code);
        printf("\nEnter the name of the book: ");
        scanf("%s", stack.data[stack.end].name);
        printf("\nEnter the author of the book: ");
        scanf("%s", stack.data[stack.end].author);
        stack.end++;
    }
}

void stack_out(){
    if(stack.end == stack.start){
        printf("The stack is already empty.\n");
        system("pause");
    }
    else {
        stack.data[stack.end-1] = 0;
        stack.end--;
    }
}

void show_stack(){
    for (int i = 0; i < size; ++i) {
        printf("[ %d,",stack.data[i]);
    }
    printf("]");
}

void show_menu(){
    printf("Choose a alternative.\n\n");
    printf("1 - Stack in a value\n");
    printf("2 - Unstack a value\n");
    printf("0 - Quit\n");
}
