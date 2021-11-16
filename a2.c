/*
@Instructor: Prof. Alaa Mohammed Salih
@Autor: Alqassam Firwana
@id: 000000000
@course: PROG20799
@Assignment: 2
*/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declare user-defined fuctions prototypes
struct node *insertFirst(struct node *head, int d);
void insertLast(struct node *head, int d);
void insert_at_position(struct node *head, int d, int pos);
struct node *deleteFirst(struct node *head);
void deleteLast(struct node *head);
void delete_at_position(struct node **head, int pos);
void searchData(struct node *head, int d);
void printLL(struct node *head);
int getCount(struct node *head);

//Node structure of single linked list
struct node
{
    int data;
    struct node *next;
};

//insert node at beginning of list
struct node *insertFirst(struct node *head, int d)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = d;
    ptr->next = head;
    head = ptr;
    return head;
};

//insert node at end of list
void insertLast(struct node *head, int d)
{
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->next = NULL;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
};

//insert node at given position
void insert_at_position(struct node *head, int d, int pos)
{
    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data = d;
    ptr2->next = NULL;

    pos--;
    if (pos > getCount(head))
    {
        printf("\033[1;31m");
        printf("\nPostion out of range...\n");
        printf("\033[0m");
        return;
    }
    if(pos < 0){
        printf("\033[1;31m");
        printf("\nInvalid Postion...\n");
        printf("\033[0m");
        return;
    }
    if (pos == 0)
    {
        insertFirst(head, d);
    }
    else
    {
        // If position is more than number of nodes
        while (pos != 1)
        {
            ptr = ptr->next;
            pos--;
        }
        ptr2->next = ptr->next;
        ptr->next = ptr2;
    }
};

//Delete First
struct node *deleteFirst(struct node *head)
{
    if (head == NULL)
    {
        printf("\033[1;31m");
        printf("\nLinked list is empty\n");
        printf("\033[0m");
        return NULL;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
        printf("\033[0;32m");
        printf("\nItem deleted\n");
        printf("\033[0m");
    }
    return head;
};

//Delete Last
void deleteLast(struct node *head)
{
    //empty list
    if (head == NULL)
    {
          if (head == NULL)
    {
        printf("\033[1;31m");
        printf("\nLinked list is empty\n");
        printf("\033[0m");
        return;
    }
    }
    else if (head->next == NULL)
    { //list with one node "head"
        free(head);
        head = NULL;
        printf("\033[0;32m");
        printf("\nItem deleted\n");
        printf("\033[0m");
    }
    else
    {                            //list with multiple nodes
        struct node *ptr = head; //we need two pointers for the last two nodes
        struct node *ptr2 = head->next;

        while (ptr->next != NULL)
        {
            ptr2 = ptr;
            ptr = ptr->next;
        }
        ptr2->next = NULL;
        free(ptr);
        printf("\033[0;32m");
        printf("\nItem deleted\n");
        printf("\033[0m");
        ptr = NULL;
    }
};

//delet at nth node
void delete_at_position(struct node **head, int pos)
{
    struct node *thisNode = *head;
    struct node *prevNode = *head;
    if (*head == NULL)
    {
        printf("\033[1;31m");
        printf("Linked list is empty \n");
        printf("\033[0m");
        return;
    }
        
    if(pos < 1){
        printf("\033[1;31m");
        printf("\nInvalid Postion...\n");
        printf("\033[0m");
        return;
    }
    else if (pos == 1)
    {
        *head = thisNode->next;
        free(thisNode);
        thisNode = NULL;
        printf("\033[0;32m");
        printf("\nItem deleted\n");
        printf("\033[0m");
    }
    else
    {
        while (pos != 1 && thisNode->next != NULL) //moving two pointers togather
        {
            prevNode = thisNode;
            thisNode = thisNode->next;
            pos--;
        }
        // If position is more than number of nodes
        if (thisNode == NULL || thisNode->next == NULL)
        {
            printf("\033[1;31m");
            printf("Given position does not exist \n");
            printf("\033[0m");
            return;
        }

        prevNode->next = thisNode->next;
        free(thisNode);
        thisNode = NULL;
        printf("\033[0;32m");
        printf("\nItem deleted\n");
        printf("\033[0m");
    }
};

// Search value at position
void searchData(struct node *head, int d)
{
    int i = 0;
    int j = 0;
    if (head == NULL)
    {
        printf("\033[1;31m");     //color
        printf("Linked list is empty\n");
        printf("\033[0m");        //reset color
    }

    struct node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == d)
        {
            j++;
            printf("\033[0;32m"); //color
            printf("Item found at index %d\n", i);
            printf("\033[0m");   //reset color
             
        }
        ptr = ptr->next;
        i++;
    }
    if (j == 0)
    {
        printf("\033[1;31m");
        printf("Item not found\n");
        printf("\033[0m");
    }
};

//print Linked List
void printLL(struct node *head)
{
    int num = 1;
    struct node *ptr = head;
    //ptr = ptr->next;//To start after head. Head left empty
    while (ptr != NULL)
    {
        printf("\x1b[33m Data at \x1b[35m %d \x1b[0m-- \x1b[34m%d \x1b[0m\n", num, ptr->data);
        ptr = ptr->next;
        num++;
    }
    if(num == 0 || getCount(head) == 0)
    {
        printf("\033[1;31m");
        printf("List is Empty \n");
        printf("\033[0m");
    }
    printf("\n");
};

//count nodes
int getCount(struct node *head)
{
    int count = 0;               // Initialize count
    struct node *current = head; // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

//validation
void validate(int x)
{

    if (x != 1)
    {
        char char_var;
        printf("\033[1;31m");
        printf("\nPlease Enter numbers only!, Press Enter to continue...\n");
        printf("\033[0m");
        //to erase all chrachters after scanf
        while ((char_var = getchar()) != '\n' && char_var != EOF)
            ;
        scanf("%c", &char_var);
        return;
    }
};


/*
*Notes: Application will always create and populate head first.
*Valid interger to validate scanf() user input.
*All labels used to repeat process and prevent program crach.
*/



int main()
{
    //Head node
    struct node *head = malloc(sizeof(struct node));

    // int data1;          //head data
    int nodeNum = getCount(head);
    char pass;          //to pass or not validation condition

head:                   //case of invlaid input for the head node
    printf("\nInput the data for node  %d ", nodeNum);
    int valid = scanf("%d", &head->data);
    
    
    if (valid != 1)     //validate if numeric value
    {
        printf("\033[1;31m");
        printf("\nPlease Enter numeric value only!, Press Enter to continue...\n");
        printf("\033[0m");
        while ((pass = getchar()) != '\n' && pass != EOF)
            ;
        scanf("%c", &pass);
        goto head;
    }

    int option;         //options list num
    int data;           //data for each node
    int pos;            //postition value for insert and delete at nth position
    int item;           //item value for search
    char yesNo;         //char value for 'y' or 'n'
    bool flag = true;   //flag to keep or break while loop

    while (flag)        //while start
    {
    start:              //start label in case of invalid input yes/no
        printf("Enter more \033[0;32m <y>es\033[0m/\033[0;31m<n>o\033[0m? ");
        validate(scanf(" %c", &yesNo));
        if (yesNo == 'y' || yesNo == 'Y')
        {
            nodeNum++;  //new node counter
        readValue:      //readValue input for node data
            printf("Input the data for node %d ", nodeNum);
            valid = scanf("%d", &data);
            //validate numeric value
            if (valid != 1)
            {
                printf("\033[1;31m"); //red color
                //validate user input
                printf("\nPlease Enter numeric value only!, Press Enter to continue...\n");
                printf("\033[0m");   //reset color
                while ((yesNo = getchar()) != '\n' && yesNo != EOF);
                scanf("%c", &yesNo);
                goto readValue;
            }
            insertLast(head, data);
            flag = true;
        }
        else if (yesNo == 'n' || yesNo == 'N')
        {
            goto list;
        }
        else
        {
            printf("\033[1;31m");
            //validate user input
            printf("\nPlease Enter y/n only!, Press Enter to continue...\n");
            printf("\033[0m");
            while ((yesNo = getchar()) != '\n' && yesNo != EOF)
                ;
            scanf("%c", &yesNo);
            goto start;
        }
    list:  //list label
        printf("\033[0;36m");      //Cyan color 
        printf("\n\t\t\t\t================\n");
        printf("\t\t\t\t1.Display\n");
        printf("\t\t\t\t2.Insert First\n");
        printf("\t\t\t\t3.Insert Last\n");
        printf("\t\t\t\t4.Insert Anywhere\n");
        printf("\t\t\t\t5.Delete First\n");
        printf("\t\t\t\t6.Delete Last\n");
        printf("\t\t\t\t7.Delete Anywhere\n");
        printf("\t\t\t\t8.Search\n");
        printf("\t\t\t\t0.Exit\n");
        printf("\t\t\t\tEnter your choice: ");
        printf("\033[0m");         //reset color
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printLL(head);
            break;
        case 2:
            nodeNum++;
            caseTwo:
            printf("Input the data for node %d ", nodeNum);

            valid = scanf("%d", &data);
            if (valid != 1)
            {
                printf("\033[1;31m");
                //validate user input
                printf("\nPlease Enter numeric value only!, Press Enter to continue...\n");
                printf("\033[0m");
                while ((yesNo = getchar()) != '\n' && yesNo != EOF)
                    ;
                scanf("%c", &yesNo);
                goto caseTwo;
            }
            head = insertFirst(head, data);
            printf("\nNode %d Enterd at the begining successfully\n", nodeNum);
            break;
        case 3:
            nodeNum++;
            caseThree:
            printf("Input the data for node %d ", nodeNum);
            valid = scanf("%d", &data);
            if (valid != 1)
            {
                printf("\033[1;31m");
                //validate user input
                printf("\nPlease Enter numeric value only!, Press Enter to continue...\n");
                printf("\033[0m");
                while ((yesNo = getchar()) != '\n' && yesNo != EOF)
                    ;
                scanf("%c", &yesNo);
                goto caseThree;
            }
            insertLast(head, data);
            break;
        case 4:
            nodeNum++;
            caseFour:
            printf("Input the data for node %d ", nodeNum);
            
            valid = scanf("%d", &data);
             if (valid != 1)
            {
                printf("\033[1;31m");
                //validate user input
                printf("\nPlease Enter numeric value only!, Press Enter to continue...\n");
                printf("\033[0m");
                while ((yesNo = getchar()) != '\n' && yesNo != EOF)
                    ;
                scanf("%c", &yesNo);
                goto caseFour;
            }
            printf("Please Enter a position: ");
            valid = scanf("%d", &pos);
            if (valid != 1)
            {
                printf("\033[1;31m");
                //validate user input
                printf("\nPlease Enter numeric value only!, Press Enter to continue...\n");
                printf("\033[0m");
                while ((yesNo = getchar()) != '\n' && yesNo != EOF)
                    ;
                scanf("%c", &yesNo);
                goto caseFour;
            }
            insert_at_position(head, data, pos);
            break;
        case 5:
            head = deleteFirst(head);
            break;
        case 6:
            deleteLast(head);
            break;
        case 7:
            caseSeven:
            printf("Please Enter a position: ");
            valid = scanf("%d", &pos);
            if (valid != 1)
            {
                printf("\033[1;31m");
                //validate user input
                printf("\nPlease Enter numeric value only!, Press Enter to continue...\n");
                printf("\033[0m");
                while ((yesNo = getchar()) != '\n' && yesNo != EOF)
                    ;
                scanf("%c", &yesNo);
                goto caseSeven;
            }
            delete_at_position(&head, pos);
            break;
        case 8:
            caseEight:
            printf("Please Enter a number to search for: ");
            valid = scanf("%d", &item);
             if (valid != 1)
            {
                printf("\033[1;31m");
                //validate user input
                printf("\nPlease Enter numeric value only!, Press Enter to continue...\n");
                printf("\033[0m");
                while ((yesNo = getchar()) != '\n' && yesNo != EOF)
                    ;
                scanf("%c", &yesNo);
                goto caseEight;
            }
            searchData(head, item);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("\033[1;31m");
            printf("Invalid Choise !\n");
            printf("\033[0m");
             printf("\033[1;31m");
                //validate user input
                printf("\nPress Enter to continue...\n");
                printf("\033[0m");
                while ((yesNo = getchar()) != '\n' && yesNo != EOF)
                    ;
                    getchar();
            goto list;
            break;
        }
        if (yesNo == 'y' || yesNo == 'Y')
        {
            goto start;
        }           //if end
    }               //while end
}                   //main  end
