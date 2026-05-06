/*"Concatenate list: create two linnked lists and concatenate the list2 in list1.

I/P:
list_1  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 
list_2  ---->   |_10_|_AAAA_|_10000_| --> |_20_|_BBBB_|_NULL_|

O/P: 
list_1  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_|
list_2  ---->   |_10_|_AAAA_|_10000_| --> |_20_|_BBBB_|_NULL_|
concatenated_list  ---->   |_1_|_AA_|_150_| --> |_2_|_BB_|_250_| --> |_3_|_CC_|_350_| --> |_4_|_DD_|_450_| --> |_10_|_AAAA_|_550_| --> |_20_|_BBBB_|_NULL_|"*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct singly   
{
    int Number;
    char Name[10];
    int standard;
    struct singly *next;
} node;

node *create();
node *concatenate(node *, node *);  
void display(node *);
void freeList(node *);  

int main()
{
    node *head1 = NULL, *head2 = NULL;
    printf("Creating List 1:\n");
    head1 = create();
    printf("Creating List 2:\n");
    head2 = create();
    
    printf("\nList 1:\n");
    display(head1);
    printf("\nList 2:\n");
    display(head2);
    
    node *concat = concatenate(head1, head2);
    
    printf("\nConcatenated List:\n");
    display(concat);
    
    freeList(concat);  
    return 0;
}

node *create()
{
    node *head = NULL, *newNode, *lastNode = NULL;
    int choice;
    do
    {
        newNode = (node *)malloc(sizeof(node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            return head;
        }
        printf("\nEnter the number:\n");
        scanf("%d", &newNode->Number);
        getchar();
        printf("Enter name: ");
        fgets(newNode->Name, sizeof(newNode->Name), stdin);
        newNode->Name[strcspn(newNode->Name, "\n")] = '\0';

        newNode->next = NULL;
        
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            lastNode->next = newNode;
        }
        lastNode = newNode;
        
        printf("Do you want to enter more records?(1 for yes/ 0 for NO):");
        scanf("%d", &choice);
    } while (choice == 1);
    return head;
}

node *concatenate(node *head1, node *head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    node *temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;  
    return head1;  
}

void display(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("|_%d_|_%s_| --> ", temp->Number, temp->Name);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(node *head) {
    node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}