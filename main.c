//------------{Libraries}------------//
#include "library.h"

int main(void) {
  /*---->Declarations<----*/
  int option;
  Book book;
  Queue queue;
  create_queue(&queue);

  /*---->Menu<----*/
  while(option != 0)
  {
    printf(
      "0 - Exit\n"
      "1 - Add on Queue\n"
      "2 - Remove of Queue\n"
      "3 - Print Queue\n"
    );
    scanf("%d", &option);
    getchar();
    
    switch(option)
    {
      case 1:
        book = sign_book();
        add_on_queue(&queue, book);
      break;
      case 2:
        remove_of_queue(&queue);
      break;
      case 3:
        print_queue(queue);
      break;
      default:
        if(option != 0 )
          printf("Invalid option!\n\n");
    }
  }

  printf("Exit Success!\n\n");
  system("pause");
  return EXIT_SUCCESS;
}