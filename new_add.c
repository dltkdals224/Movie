#include "user.h"

int prompt_add(char *menu,char *mda)
{

  FILE *movie_log = NULL;
  FILE *director_log = NULL;
  FILE *acotr_log = NULL;

  if( *menu == 'a' && *(menu + 1) == 'd' && *(menu + 2) == 'd' )
    if( *mda == 'm' )
    {
    char *title;
    char *genre;
    char *director;
    char *year;
    char *times;
    char *actors;

    title = (char *)malloc(sizeof(char));
    genre = (char *)malloc(sizeof(char));
    director = (char *)malloc(sizeof(char));
    year = (char *)malloc(sizeof(char));
    times = (char *)malloc(sizeof(char));
    actors = (char *)malloc(sizeof(char));

    printf("title > ");
    scanf("%s", title);
    getchar();
    printf("\ngenre > ");
    scanf("%s", genre);
    getchar();
    printf("\ndirector > ");
    scanf("%s", director);
    getchar();
    printf("\nyear > ");
    scanf("%s", year);
    getchar();
    printf("\ntime > ");
    scanf("%s", times);
    getchar();
    printf("\nactors > ");
    scanf("%[^\n]", actors);
    getchar();

    movie_log = fopen("movie_log.txt","a");

    //serial_number 적용 함수 적용되지 않아서 임의로 이렇게 두었습니다.
    fprintf(movie_log,"add:i:%s:%s:%s:%s:%s:%s\n",title,genre,director,year,times,actors);

    fclose(movie_log);

    }

    if( *mda == 'd' )
    {
      char *name;
      char *sex;
      char *birth;
      char *best_movies;

      name = (char *)malloc(sizeof(char));
      sex = (char *)malloc(sizeof(char));
      birth = (char *)malloc(sizeof(char));
      best_movies= (char *)malloc(sizeof(char));

    printf("name > ");
    scanf("%s",name);
    getchar();
    printf("\nsex > ");
    scanf("%s",sex);
    getchar();
    printf("\nbirth > ");
    scanf("%s",birth);
    getchar();
    printf("\nbest_movies > ");
    scanf("%[^\n]",best_movies);
    getchar();

    director_log = fopen("director_log.txt","a");

    //serial_number 적용 함수 적용되지 않아서 임의로 이렇게 두었습니다.
    fprintf(director_log,"add:i:%s:%s:%s:%s\n",name,sex,birth,best_movies);

    fclose(director_log);


    }

    if( *mda == 'a' )
    {

      char *name;
      char *sex;
      char *birth;
      char *best_movies;

      name = (char *)malloc(sizeof(char));
      sex = (char *)malloc(sizeof(char));
      birth = (char *)malloc(sizeof(char));
      best_movies= (char *)malloc(sizeof(char));


      printf("name > ");
      scanf("%s",name);
      getchar();
      printf("\nsex > ");
      scanf("%s",sex);
      getchar();
      printf("\nbirth > ");
      scanf("%s",birth);
      getchar();
      printf("\nbest_movies > ");
      scanf("%[^\n]",best_movies);
      getchar();

      actor_log = fopen("actor_log.txt","a");

      //serial_number 적용 함수 적용되지 않아서 임의로 이렇게 두었습니다.
      fprintf(actor_log,"add:i:%s:%s:%s:%s\n",name,sex,birth,best_movies);

      fclose(actor_log);

    }

}

//아래는 main함수 형식. (동적메모리 할당 필요.)
/*
int main(void)
{
  char *menu;
  char *mda;

  menu = (char *)malloc(sizeof(char));
  mda = (char *)malloc(sizeof(char));

  scanf("%s %s",menu,mda);
  prompt_add(menu,mda);
  return 0;
}
*/
