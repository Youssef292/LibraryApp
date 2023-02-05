/**********************************************************************************************/
/***** Name: Youssef Abdelhakem          ********************************************************/
/***** Date: 6/2/2023                 ********************************************************/
/***** Component:  LinkedList.c    ********************************************************/
/**********************************************************************************************/
#include "LinkedList.h"
void lines(void) { printf("==============================\n"); }
void Menu(void) {
    lines();
    printf("Welcome To library system.\n");
    lines();
    printf("1) Add New Book\n");
    printf("2) View Library Books\n");
    printf("3) View Num.of Avaliable Books\n");
    printf("4) Delete Book\n");
    printf("5) Exit\n");
    lines();
}
Lib_stat ViewBooks(struct Node *Book){
    struct Node *TempNode = Book;
    uint32_t BookCnt = 1;
    Lib_stat RetStat = L_NOK;
    if (NULL == TempNode) {
        RetStat = L_Empty;
    } else {
        while(TempNode != NULL){
            printf("Book Id-> %i\n", BookCnt);
            printf("Book Name: %s\n", (TempNode->Book_info).Book_Name);
            printf("Book Author: %s\n", (TempNode->Book_info).Auther);
            printf("Book Price: %i\n", (TempNode->Book_info).Book_price);
            BookCnt++;
            lines();
            TempNode = TempNode->NextNode;
        }
        RetStat = L_OK;
    }
    return RetStat;
}
Lib_stat AddBook(struct Node **Book){
    Lib_stat RetStat = L_NOK;
    struct Node *TempNode = NULL, *LastNode = NULL;

    TempNode = (struct Node *)malloc(sizeof(struct Node));
    if (NULL != TempNode) {

        printf("Enter Book Name:");
        fflush(stdin);
        gets((TempNode->Book_info).Book_Name);
        printf("Enter Book Auther:");
        fflush(stdin);
        gets((TempNode->Book_info).Auther);
        printf("Enter Book Price:");
        scanf("%i", &(TempNode->Book_info).Book_price);

        if (NULL == *Book) { /*if Library is empty*/
            *Book = TempNode;
            TempNode->NextNode = NULL;

        } else { /*Library not empty*/
            LastNode = *Book;
            while (LastNode->NextNode != NULL) {
                LastNode = LastNode->NextNode;
            }
            LastNode->NextNode = TempNode;
        }
        RetStat = L_OK;
    } else {
        RetStat = L_NOK;
    }

    return RetStat;
}

Lib_stat  DeleteBook(struct Node *Book , uint32_t B_Id){
    struct Node *ListCounter = Book;
    struct Node *BookNode = Book;
    uint32_t NodeCounter = 1;
    Lib_stat  RetState = L_NOK;

    while(NodeCounter < (B_Id-1)){
        NodeCounter++;
        ListCounter = ListCounter->NextNode;
    }
    BookNode = ListCounter->NextNode;
    ListCounter->NextNode = BookNode->NextNode;
    free(BookNode);

    RetState = L_OK;


    return RetState;
}

 Lib_stat DeleteBook_AtBeginning(struct Node** Book){
    Lib_stat  RetStat = L_NOK;
    struct Node *TempNode = *Book;
    uint32_t ListLen = 0;
    ListLen = Num_of_Books(*Book);

    if(ListLen == 0){
        RetStat = L_Empty;
    }else{
        *Book = TempNode->NextNode;
        TempNode->NextNode = NULL;
        free(TempNode);
        RetStat = L_OK;
    }
     return  RetStat;

}


uint32_t Num_of_Books(struct Node* Book){
    struct Node *TempNode = Book;
    uint32_t BookCounter = 0;

    while (NULL != TempNode) {

        TempNode = TempNode->NextNode;
        BookCounter++;
    }

    return BookCounter;
}