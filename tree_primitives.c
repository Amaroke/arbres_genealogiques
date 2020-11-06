#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "base.h"

typedef struct s_node
{
  s_base_t val;
  struct s_node *fg, *fd;
} s_node_t, *tree_t;

tree_t cons_empty()
{
  return NULL;
}

tree_t cons(s_base_t v, tree_t fg, tree_t fd)
{
  tree_t tree = (tree_t)malloc(sizeof(s_node_t));
  tree->val = v;
  tree->fg = fg;
  tree->fd = fd;
  return tree;
}

int is_empty(tree_t a)
{
  return a == NULL;
}

s_base_t value(tree_t a)
{
  return a->val;
}

tree_t left(tree_t a)
{
  return a->fg;
}

tree_t right(tree_t a)
{
  return a->fd;
}

void change_value(tree_t pa, s_base_t new_value)
{
  pa->val = new_value;
}

void change_left(tree_t pa, tree_t new_left)
{
  pa->fg = new_left;
}

void change_right(tree_t pa, tree_t new_right)
{
  pa->fd = new_right;
}

void free_tree(tree_t a)
{
  if (!is_empty(a))
  {
    free_tree(left(a));
    free_tree(right(a));
  }
  free(a);
}

void prefix(tree_t a)
{
  print(value(a));
  if (!is_empty(left(a)))
  {
    prefix(left(a));
  }
  if (!is_empty(right(a)))
  {
    prefix(right(a));
  }
}

void graphical_print(tree_t a, int depth)
{
  if (!is_empty(a))
  {
    for (int i = 0; i < depth; ++i)
    {
      printf(" ");
    }
    printf("+--");
    print(value(a));
    printf("\n");
    graphical_print(left(a), depth + 3);
    graphical_print(right(a), depth + 3);
  }
}

void graphical_print_link(tree_t a, int depth, int trace[])
{
  if (!is_empty(a))
  {
    trace[depth] = 0;
    graphical_print_link(left(a), depth + 1, trace);
    for (int i = 0; i < depth; ++i)
    {
      if (i > 0 && trace[i] != trace[i - 1])
      {
        printf("|");
      }
      else
      {
        printf(" ");
      }
      printf(" ");
    }
    printf("+--");
    print(value(a));
    printf("\n");
    trace[depth] = 1;
    graphical_print_link(right(a), depth + 1, trace);
  }
}

int size(tree_t a)
{
  if (is_empty(a))
  {
    return 0;
  }
  int taille = 0;
  taille += size(left(a));
  taille += size(right(a));
  return taille + 1;
}

int height(tree_t a)
{
  int height_a = 0;
  if (!is_empty(a))
  {
    int hfg = height(left(a));
    int hfd = height(right(a));
    height_a = 1 + ((hfg > (hfd) ? hfg : hfd));
  }
  return height_a;
}

int exists(tree_t a, s_base_t v)
{
  int existe = 0;
  if (is_empty(a))
  {
    return existe;
  }
  else
  {
    existe = compare(value(a), v);
    if (existe != 0)
    {
      existe = exists(left(a), v);
    }
    if (existe != 0)
    {
      existe = exists(right(a), v);
    }
  }
  return existe;
}