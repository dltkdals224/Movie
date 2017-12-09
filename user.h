//사용자 헤더파일 (std종류, 구조체, 함수원형)
//적용 방식 : 다른 기존파일에 #include "user.h" 해주면 된다!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>


#define MAN 0
#define FEMALE 1
#ifndef _USER_H_
#define _USER_H_ // _USER_H_가 정의되어 있지 않을 때 정의되도록.


typedef struct linked_list{
  char *str; //string(문장) 저장
  struct linked_list *next; //링크드 리스트를 위해 존재.
}stack; //정원이가 그냥 stack , 채은이가 struct linked_list

//파일이 아니고 구조체.
struct director_list{
  int serial_num;
  struct linked_list *name;
  struct linked_list *sex;
  struct linked_list *birth;
  struct d_title_to_title *best_movies;
  struct director_list *next;
};

//파일이 아니고 구조체.
struct actor_list{
  int serial_num;
  struct linked_list *name;
  struct linked_list *sex;
  struct linked_list *birth;
  struct a_title_to_title *best_movies;
  struct actor_list *next;
};

//파일이 아니고 구조체.
struct movie_list{
  int serial_num;
  struct linked_list *title;
  struct linked_list *genre;
  struct movie_to_director *director;
  int year;
  int time;
  struct movie_to_actor *actor;
  struct movie_list *next;
};

struct movie_to_director {
	char *str;
	struct director_list *pair;
	struct movie_to_director *next;
};

struct movie_to_actor {
	char *str;
	struct actor_list *pair;
	struct movie_to_actor *next;
};

struct a_title_to_title {
	char *str;
	struct movie_list *title;
	struct d_title_to_title *pair;
	struct a_title_to_title *next;
};

struct d_title_to_title {
	char *str;
	struct movie_list *title;
	struct a_title_to_title *pair;
	struct d_title_to_title *next;
};

//단순화 시킨 것.(정원이가 쓰는데 혹시 몰라서 <- 필요하대요)
typedef struct director_list director;
typedef struct actor_list actor;
typedef struct movie_list movie;
typedef struct movie_to_director movie_to_director;
typedef struct movie_to_acotr movie_to_actor;

//링크드 리스트 사용할때 쓸 것.
typedef struct linked_list linked_list; // 혹시몰라서.
typedef stack *LINK; // 왜 써 놨더라?

#endif // _USER_H_
