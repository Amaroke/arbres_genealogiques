#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "base.h"

int compare(s_base_t t1, s_base_t t2)
{
  if (strcmp(t1.name, t2.name) == 0)
  {
    return strcmp(t1.title, t2.title);
  }
  else
  {
    return strcmp(t1.name, t2.name);
  }
}

void print(s_base_t t)
{
  printf("%s  -  %s", t.name, t.title);
}