/**********************************************************************************************/
/***** Name: Youssef Abdelhakem          ********************************************************/
/***** Date: 6/2/2023                 ********************************************************/
/***** Component: app.c    ********************************************************/
/**********************************************************************************************/
#include "app.h"
struct Node *Book = NULL;
uint32_t UserChoice;
void AppStart(void){
    Lib_stat RetStat = L_NOK;
    uint32_t Counter = 0;
    uint32_t Book_Id;
    while (1) {
        Menu();

        printf("Enter User Chioce:");
        scanf("%i", &UserChoice);

        switch (UserChoice) {
            case 1:
                RetStat = AddBook(&Book);
                if(RetStat == L_OK){
                    lines();
                    printf("Book Added successfully\n");
                    lines();
                }else{
                    printf("Failed to Add Book\n");
                }
                break;
            case 2:
               RetStat= ViewBooks(Book);
               if(RetStat == L_Empty){
                   lines();
                   printf("Library is Empty!!,No Books To view\n");
                   lines();
               }else{/*Nothing*/}
                break;
            case 3:
                Counter =Num_of_Books(Book);
                if(Counter == 0){
                    lines();
                    printf("Library is Empty!!\n");
                    lines();
                }else{
                    printf("Num of Avaliable Books:%i\n",Counter);
                }
                break;
            case 4:
                Counter = Num_of_Books(Book);
                if(Counter == 1){
                    RetStat =DeleteBook_AtBeginning(&Book);
                    if(RetStat== L_Empty){
                        printf("No Books to Delete,Library is Empty!!\n");
                    }else{
                        printf("Book Deleted Successfully\n");
                    }
                }else{

                    if(Counter > 1){

                        printf("Enter Book Id:");
                        scanf("%i",&Book_Id);
                        if(Book_Id == 1){
                            RetStat =DeleteBook_AtBeginning(&Book);
                            if(RetStat== L_Empty){
                                printf("No Books to Delete,Library is Empty!!\n");
                            }else{
                                printf("Book Deleted Successfully\n");
                            }
                        }else{

                            RetStat = DeleteBook(Book,Book_Id);
                            if(RetStat == L_OK){
                                printf("Book Deleted Successfully\n");
                            }else{
                                printf("Failed to Delete\n");
                            }
                        }
                    }else{
                        printf("No Books to Delete,Library is Empty!!\n");
                    }


                }


                break;

            case 5:
                exit(0);
                break;

            default:
                printf("\nInvalid Choice!!");
                break;
        }
    }
}
