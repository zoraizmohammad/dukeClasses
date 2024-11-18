//Create LinkedList and complete 
//ECE250 - Mohammad Zoraiz

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player
{
    char name[64];
    int ppg;
    int ppgagainst;
    int difference;
    struct Player* next;

};

//Calculating the difference between the points
int difference(struct Player *player)
{
    return player->ppg - player->ppgagainst;
}


//Sorting the players by name
void sortName(struct Player** head)
{
    int is_sorted = 0;

    while(!is_sorted)
    {
        struct Player* current = *head;
        struct Player* previous = NULL;
        is_sorted = 1;

        while(current!=NULL && current->next!=NULL)
        {
            struct Player* next = current->next;
            
            if (strcmp(current->name, next->name) > 0)
            {
                is_sorted = 0;

                current->next = next->next;
                next->next = current;

                if (previous != NULL)
                {
                    previous->next = next;
                }

                else
                {
                    *head = next;
                }

            }

            previous = current;
            current = next;
           
        }

    }
}

//Sorting the players by number, similar logic to the name
void sortNumber(struct Player** head)
{
    int is_sorted = 0;

    while(!is_sorted)
    {
        struct Player* current = *head;
        struct Player* previous = NULL;
        is_sorted = 1;

        while(current!=NULL && current->next!=NULL)
        {
            struct Player* next = current->next;
            
            if (current->difference < next->difference)
            {
                is_sorted = 0;

                current->next = next->next;
                next->next = current;

                if (previous != NULL)
                {
                    previous->next = next;
                }

                else
                {
                    *head = next;
                }

            }

            previous = current;
            current = next;
           
        }

    }
}

//Print function for LinkedList -- CHECK
void print(struct Player* head)
{
   while(head != NULL)
   {
       printf("%s %d\n", head->name, head->difference);
       head = head->next;
   }
}

//Driver function
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return EXIT_FAILURE;
    }

    struct Player* head = NULL;
    struct Player* current;
    char string[64];


    //Opening file and checking for null cases

    //FIX FROM HERE -----

    FILE *data = fopen(argv[1], "r");
    if (data == NULL)
    {
        return EXIT_FAILURE;
    }

    //Reading the file and creating the LinkedList

    int one = 0;
    int two = 0;


    while(fscanf(data, "%s %d %d", string, &one, &two) == 3)
    {
        if(strcmp(string, "DONE") == 0)
        {
            break;
        }

        current = (struct Player*)malloc(sizeof(struct Player));
        
        fscanf(data, "%d %d", &one, &two);

        strcpy(current->name, string);
        current->ppg = one;
        current->ppgagainst = two;
        current->difference = difference(current);


        current->next = head;
        head = current;
   }
    

    //     while((current = (struct Player*)malloc(sizeof(struct Player))) != NULL)

    //     {
    //         if(fscanf(data, "%s %d %d", current->name, &current->ppg, &current->ppgagainst) != 3)
    //         {
    //             free(current);
    //             break;
    //         }
            
    //         current->difference = difference(current);
    //         printf("ofkmh");
            
    //         sortName(&current);
    //     }

    //     fclose(data);

    //     while (head != NULL)
    // {
    //     struct Player* localFree = head;
    //     printf("%s %d\n", head->name, head->ppg);

    //     head = head->next;

    //     // print(head);
    //     free(localFree);
    // }




    fclose(data);
    
    sortName(&head);
    sortNumber(&head);

    print(head);

    while(head != NULL)
    {
        struct Player* localFree = head;
        head = head->next;
        free(localFree);
    }


    return EXIT_SUCCESS;

    }
    
