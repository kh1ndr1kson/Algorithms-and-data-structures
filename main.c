#include <stdio.h>
#include <stdlib.h>

typedef struct TList
{
  int info;
  struct TList *next;
  
}TList;

int EmptyList(struct TList *Head)
{
  return(Head == NULL);
}

TList * FormList(struct TList *Head)
{
  struct TList newEl, curr;
  int x;

  printf("Формирование списка. Окончание ввода - значение 999\n");

  do
  {
    scanf("%d", &x);

    if (x != 999)
    {
      TList *newEl = (TList*)malloc(sizeof(TList));
      newEl->info = x;
      newEl->next = NULL;

      if (Head == NULL)
      {
        Head = newEl;
      }
      else
      {
        TList *curr = Head;

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

void ViewList(struct TList *Head)
{
  struct TList *newEl;

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
  TList *Head = NULL;

  Head = FormList(Head);

  ViewList(Head);

  return 0;
};