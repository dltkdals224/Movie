#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack{
  char *str;
  struct stack *next;
}stack;
typedef struct director{
  int Serial_number;
  struct stack *name;
  struct stack *sex;
  struct stack *birth;
  struct stack *best_movies;
  struct stack *next;
}director;

typedef struct actor{
  int Serial_numer;
  struct stack *name;
  struct stack *sex;
  struct stack *birth;
  struct stack *best_movies;
  struct stack *next;
}actor;
typedef struct movie{
  int serial_num;
  struct stack *title; //title
  struct stack *genre; // genre
  struct stack *director; //director
  struct stack *year; //year
  struct stack *time; //runtime
  struct stack *actors; //actor
  struct movie *next;
}movie;
int add(char *,char *,movie *, actor *,director *);
void init_add(char *,char*,movie **,actor **,director **);
void justprint(movie *,int);
