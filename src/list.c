#include "include/list.h"

list_T* init_list(size_t item_size){
   list_T* list = calloc(1,sizeof(struct LIST_STRUCT));
   list->size = 0;
   list->item_size = item_size;
   list->size = 0;

   return list;
}

void list_push(list_T* list, void* item){
   list->size +=1;
   
   if(!list->items)
      list->items = calloc(1,list->item_size);
   else 
      list->items = realloc(list->items,(list->size * list->item_size));
   
   list->items[list->size-1] = item;
}

int list_index(list_T* list, void* item)
{

   for(int i=0;i<list->size;i++)
      if(list->items[i] == item)
         return i;
   
   return -1;
}

int list_pop(list_T* list, void* item)
{
   if(list->size == 0)
   {
      return -1;
   }

   list->size +=-1;
   int index = list_index(list,item);   
   //shift
   for (int i = index; i < list->size; i++)
   {
      list->items[i] = list->items[i+1];
   }
   
   list->items = realloc(list->items,(list->size * list->item_size));

   return index;
}
