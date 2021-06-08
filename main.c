#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
  int info;
  struct List *next;
  
}List;

int EmptyList(struct List *Head)
{
  return(Head == NULL);
}

List * FormList(struct List *Head)
{
  struct List newEl, curr;
  int x;

  printf("Формирование списка. Окончание ввода - значение 999\n");

  do
  {
    scanf("%d", &x);

    if (x != 999)
    {
      List *newEl = (List*)malloc(sizeof(List));
      newEl->info = x;
      newEl->next = NULL;

      if (Head == NULL)
      {
        Head = newEl;
      }
      else
      {
        List *curr = Head;

        while (curr->next != NULL)
        {
          curr = curr->next;
          curr->next = newEl;
        }
      }
    }
  } 
  while (x != 999);
  {
    return Head;
  }

};

void ViewList(struct List *Head)
{
  struct List *newEl;

  if (!EmptyList(Head))
  {
    newEl = Head;
    while (newEl != NULL)
    {
      printf("%d", newEl->info);
      newEl = newEl->next;
    }
  }
  else
  {
    printf("Список пуст\n");
  }
};


int main(void)
{
  List *Head = NULL;

  Head = FormList(Head);

  ViewList(Head);

  return 0;
};