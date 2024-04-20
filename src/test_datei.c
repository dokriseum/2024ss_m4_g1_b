#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_TASK_LENGTH 50

struct TodoList {
    char tasks[MAX_TASKS][MAX_TASK_LENGTH];
    int num_tasks;
};

void initializeList(struct TodoList *list) {
    list->num_tasks = 0;
}

void addTask(struct TodoList *list, const char *task) {
    if (list->num_tasks < MAX_TASKS) {
        strcpy(list->tasks[list->num_tasks], task);
        list->num_tasks++;
        printf("Task added: %s\n", task);
    } else {
        printf("Todo list is full!\n");
    }
}

void printList(const struct TodoList *list) {
    printf("Todo List:\n");
    for (int i = 0; i < list->num_tasks; i++) {
        printf("%d. %s\n", i + 1, list->tasks[i]);
    }
}

int main() {
    struct TodoList todoList;
    initializeList(&todoList);

    char task[MAX_TASK_LENGTH];
    char choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add Task\n");
        printf("2. Print Tasks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter task: ");
                scanf(" %[^\n]", task);
                addTask(&todoList, task);
                break;
            case '2':
                printList(&todoList);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != '3');

    return 0;
}
