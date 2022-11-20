//------------{ADT Date}------------//
typedef struct
{
  int month, day, year;
} Date;
//------------{ADT Infos}------------//
typedef struct
{
  int IBSN;
  int ID;
  int print_number;
} Infos;
//------------{ADT Book}------------//
typedef struct
{
  char name[50];
  char author_name[50];
  Date publication_date;
  Infos general_info;
} Book;
//------------{ADT Node}------------//
typedef struct node
{
  Book book;
  struct node *next;
} Node;
//------------{ADT Queue}------------//
typedef struct
{
  Node *start;
  Node *end;
  int queue_size;
} Queue;
//------------{Sign Date}------------//
Date sign_date();
//------------{Sign Infos}------------//
Infos sign_infos();
//------------{Sign Book}------------//
Book sign_book();
//------------{Print Date}------------//
void print_date(Date date);
//------------{Print Infos}------------//
void print_infos(Infos infos);
//------------{Print Book Informations}------------//
void printf_book_infomations(Book book);
//------------{Create Queue}------------//
void create_queue(Queue *queue);
//------------{Manpipulate Queue}------------//
int add_on_queue(Queue *queue, Book book);
int remove_of_queue(Queue *queue);
//------------{Print Queue}------------//
int print_queue(Queue queue);
//------------{Queue Size}------------//
bool queue_underflow(Queue queue);
bool queue_overflow(Queue queue);
int queue_size(Queue queue);