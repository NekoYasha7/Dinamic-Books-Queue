//------------{Local Liraries}------------//
#include "library.h"
//------------{Sign Date}------------//
Date sign_date()
{
  Date d;

  printf("Put a date with format 'MM/DD//YYYY': \n");
  scanf("%d/%d/%d", &d.month, &d.day, &d.year);
  getchar();
  
  return d;
}
//------------{Sign Infos}------------//
Infos sign_infos()
{
  Infos i;

  printf("Put a Book IBSN: \n");
  scanf("%d", &i.IBSN);
  printf("Put the Book ID: \n");
  scanf("%d", &i.ID);
  printf("Put the Print number of the book: \n");
  scanf("%d", &i.print_number);
  getchar();

  return i;
}
//------------{Sign Book}------------//
Book sign_book()
{
  Book b;
  
  printf("Put the Book name: \n");
  fgets(b.name, 49, stdin);
  printf("Put the Author pen name: \n");
  fgets(b.author_name, 49, stdin);
  printf("Put the Book publicatio date: \n");
  b.publication_date = sign_date();
  b.general_info = sign_infos();
  
  getchar();  
  
  return b;
}
//------------{Print Date}------------//
void print_date(Date date)
{
  printf("%d/%d/%d\n", date.month, date.day, date.year);
  
  return EXIT_SUCCESS;
}
//------------{Print Infos}------------//
void print_infos(Infos infos)
{
  printf("Book IBSN: %d\n", infos.IBSN);
  printf("Book ID: %d\n", infos.ID);
  printf("Book Print Number: %d\n", infos.print_number);

  return EXIT_SUCCESS;
}
//------------{Print Book Informations}------------//
void printf_book_infomations(Book book)
{
  
  printf("\t\nBook Name: %s\n", book.name);
  printf("\tAuthor name: %s", book.author_name);
  printf("\tPublication date: ");
  print_date(book.publication_date);
  printf("\tGeneral Informations: \n");
  print_infos(book.general_info);

  return EXIT_SUCCESS;
}
//------------{Create Queue}------------//
void create_queue(Queue *queue)
{
  queue->start = NULL;
  queue->end = NULL;
  queue->queue_size = 0;

  return EXIT_SUCCESS;
}
//------------{Manpipulate Queue}------------//
int add_on_queue(Queue *queue, Book book)
{
  Node *aux, *new_node = malloc(sizeof(Node));
  if(new_node)
  {
    new_node->book = book;
    new_node->next = NULL;
    if(queue->start == NULL)
    {
      queue->start = new_node;
      queue->end = new_node;
    } else
      {
        aux = queue->start;
        while(aux->next)
          aux = aux->next;
        queue->end->next = aux;
        queue->end = aux;
      }
    queue->queue_size++;
  } else{
    printf("Memory Alloc Error!\n\n");
    return EXIT_FAILURE;
    }

  return EXIT_SUCCESS;
}

int remove_of_queue(Queue *queue)
{
  if(queue_underflow(*queue) == true)
  {
    printf("Empty Queue!\n\n");
    return EXIT_FAILURE;
  }
  Node *remove_var = malloc(sizeof(Node));
  if(remove_var)
  {
    remove_var = queue->start;
    queue->start = queue->start->next;
    printf("Removed: \n");
    printf_book_infomations(remove_var->book);
    queue->queue_size--;
    free(remove_var);
  } else
    {
      printf("Memory Alloc Error!\n\n");
      return EXIT_FAILURE;
    }

  return EXIT_SUCCESS;
}

//------------{Print Queue}------------//
int print_queue(Queue queue)
{
  if(queue_underflow(queue) == true)
  {
    printf("Empty Queue!\n\n");
    return EXIT_FAILURE;
  }
  
  printf("\n\t-----------Queue Size: %d------------\n", queue_size(queue));
  while(queue.start)
  {
    printf_book_infomations(queue.start->book);
    queue.start = queue.start->next;
    printf("\n\t-------------------\n");
  }
  printf("\n\t---------Queue End----------\n");
  return EXIT_SUCCESS;
}
//------------{Queue Size}------------//
bool queue_underflow(Queue queue)
{
  if(queue.start) return false;
  return true;
}
bool queue_overflow(Queue queue)
{
  return false;
}
int queue_size(Queue queue)
{
  return queue.queue_size;
}