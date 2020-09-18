#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Task
{
    int id;
    char * name;
    struct Task * nextTask;
}task_t;

int GetID();
int NumberOfMethods();
char* GetName();
void Update(task_t* head, char* name,  int id);
void Read(task_t* test);
void Interractive(int id);
task_t* Delete(task_t* head, int id);
task_t* Create(task_t* firstTask);
task_t* MethodsInterractive(task_t* head);


int main()
{
    task_t* firstTask = NULL;

    while(true)
    {
        Interractive(0);
        firstTask = MethodsInterractive(firstTask);
    }
}

task_t* Create(task_t* firstTask)
{
    
    if(firstTask == NULL)
    {
        firstTask = malloc(sizeof(task_t));

        firstTask->id = 0;
        firstTask->name = GetName();
        firstTask->nextTask = NULL;
    }
    else
    {
        static int i = 1;
        task_t* pointer = firstTask;

        while(pointer->nextTask != NULL)
        {
            pointer = pointer->nextTask;
        }

        pointer->nextTask = malloc(sizeof(task_t));
        pointer->nextTask->id = i++;

        pointer->nextTask->name = GetName();

        pointer->nextTask->nextTask = NULL;
    }
    return firstTask;
}


void Read(task_t* firstTask)
{
    task_t* pointer = firstTask;

    if(firstTask == NULL)
    {
        Interractive(5);
        return;
    }

    Interractive(6);
    while(pointer != NULL)
    {
        printf("[%d] %s\n", pointer->id, pointer->name);
        pointer = pointer->nextTask;
    }
}

void Update(task_t* head, char* name,  int id)
{
    task_t* pointer = head;
    while(pointer->id != id)
    {
        if(pointer->nextTask == NULL)
        {
            Interractive(7);
            return;
        }
        pointer = pointer->nextTask;
    }
    pointer->name = name;
}
task_t* Delete(task_t* firstTask, int id)
{
    task_t* pointer = firstTask;
    
    if(id == 0)
    {
        firstTask = pointer->nextTask;
        pointer->nextTask = firstTask;
        free(pointer);
    }
    else
    {
        while(pointer->id != id)
        {
            if(pointer->nextTask == NULL)
            {
                Interractive(7);
                return firstTask;
            }
            pointer = pointer->nextTask;
        }
        task_t* deleteTask = pointer->nextTask;
        pointer->nextTask = deleteTask->nextTask;
        free(deleteTask);
    }
    
    task_t* pointerID = firstTask;
    int i = 0;

    while(pointerID != NULL)
    {
        pointerID->id = i;
        pointerID = pointerID->nextTask;
        i++;
    }
    return firstTask;
}

int NumberOfMethods()
{
    char* userAnswer = malloc(sizeof(char));
    scanf("%s", userAnswer);

    if(strcmp(userAnswer, "Create") == 0 || strcmp(userAnswer, "create") == 0)
    {
        return 0;
    }
    if(strcmp(userAnswer, "Update") == 0 || strcmp(userAnswer, "update") == 0)
    {
        return 1;
    }
    if(strcmp(userAnswer, "Read") == 0 || strcmp(userAnswer, "read") == 0)
    {
        return 2;
    }
    if(strcmp(userAnswer, "Delete") == 0 || strcmp(userAnswer, "delete") == 0)
    {
        return 3;
    }

    Interractive(1);
    return -1;
}
void Interractive(int id)
{
    switch (id)
    {
        case 0:
            printf("\nInsert method [Create/Read/Upate/Delete]\n");
            break;
        case 1:
            printf("!!!No such method exists!!!\n");
            break;
        case 2:
            printf("<Insert name> \n");
            break;
        case 3:
            printf("<Insert update name>\n");
            break;
        case 4:
            printf("<Insert [id]>\n");
            break;
        case 5:
            printf("[Tasks are empty] \n");
            break;
        case 6:
            printf("\n[id] name:\n\n");
            break;
        case 7:
            printf("!!!No such [id] exists!!!\n");
            break;
    }
}
task_t* MethodsInterractive(task_t* firstTask)
{
    switch (NumberOfMethods())
    {
        case 0:
            firstTask = Create(firstTask);
            break;
        case 1:
            Update(firstTask, GetName(), GetID());
            break;
        case 2:
            Read(firstTask);
            break;
        case 3:
            firstTask = Delete(firstTask,GetID());
            break;
    }
    return firstTask;
}
int GetID()
{
            Interractive(4);
            int getID;
            scanf("%d", &getID);
            return getID;
}
char* GetName(int id)
{   
            Interractive(2);
            char* getName = malloc(sizeof(char));
            scanf("%s", getName);
            return getName;
}

