#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct movie_list {
	int serial_num;
	struct linked_list *title;
	struct linked_list *genre;
	struct movie_to_director *director;
	int year;
	int time;
	struct movie_to_actor *actor;
	struct movie_list *next;
};
struct movie_log_s {
	int serial_num;
	char *str;
	struct movie_log_s *next;
};
struct director_list {
	int serial_num;
	struct linked_list *name;
	struct linked_list *sex;
	struct linked_list *birth;
	struct d_title_to_title *best_movies;
	struct director_list *next;
};
struct actor_list {
	int serial_num;
	struct linked_list *name;
	struct linked_list *sex;
	struct linked_list *birth;
	struct a_title_to_title *best_movies;
	struct actor_list *next;
};
struct linked_list {
	char *str;
	struct linked_list *next;
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
typedef struct movie_list movie;
typedef struct director_list director;
typedef struct actor_list actor;

int t_function(char *str, movie *movie_current, movie *head_m,int t, int g, int d, int y, int r, int a)
{
  FILE *ifp;
  ifp = fopen(str,"a");
  fprintf(ifp, "%s:", movie_current -> title -> str);
  if(t==1 && g==0 && d==0 && y==0 && r==0 && a==0)
  fprintf(ifp, "\n");
  fclose(ifp);
}

int g_function(char *str, movie *movie_current, movie *head_m,int t, int g, int d, int y, int r, int a)
{
  FILE *ifp;
  ifp = fopen(str,"a");
  fprintf(ifp, "%s:", movie_current -> genre -> str);
  if(g==1 && d==0 && y==0 && r==0 && a==0)
  fprintf(ifp, "\n");
  fclose(ifp);
}

int d_function(char *str, movie *movie_current, movie *head_m,int t, int g, int d, int y, int r, int a)
{
  FILE *ifp;
  ifp = fopen(str,"a");
  fprintf(ifp, "%s:", movie_current -> director -> str);
  if(d==1 && y==0 && r==0 && a==0)
  fprintf(ifp, "\n");
  fclose(ifp);
}

int y_function(char *str, movie *movie_current, movie *head_m,int t, int g, int d, int y, int r, int a)
{
  FILE *ifp;
  ifp = fopen(str,"a");
  fprintf(ifp, "%s:", movie_current -> year);
  if(y==1 && r==0 && a==0)
  fprintf(ifp, "\n");
  fclose(ifp);
}

int r_function(char *str, movie *movie_current, movie *head_m,int t, int g, int d, int y, int r, int a)
{
  FILE *ifp;
  ifp = fopen(str,"a");
  fprintf(ifp, "%s:", movie_current -> time);
  if(r==1 && a==0)
  fprintf(ifp, "\n");
  fclose(ifp);
}

int a_function(char *str, movie *movie_current, movie *head_m,int t, int g, int d, int y, int r, int a)
{
  FILE *ifp;
  ifp = fopen(str,"a");
    while(movie_current -> actor != NULL)
    {
    fprintf(ifp, "%s,", movie_current -> actor -> str);
    movie_current -> actor = movie_current -> actor -> next;
    }
  if(a==1)
  fprintf(ifp, "\n");
  fclose(ifp);
}


//////////////director 의 [option]//
int n_d_function(char *str, director *director_current, director *head_d, int n, int s, int b, int m)
{
  FILE *ifp;
  ifp = fopen(str,"a");
  fprintf(ifp, "%s:", director_current -> name -> str);
  if(n==1 && s==0 && b==0 && m==0)
  fprintf(ifp, "\n");
  fclose(ifp);
}

int s_d_function(char *str, director *director_current, director *head_d, int n, int s, int b, int m)
{
  FILE *ifp;
  ifp = fopen(str,"a");
  fprintf(ifp, "%s:", director_current -> sex -> str);
  if(s==1 && b==0 && m==0)
  fprintf(ifp, "\n");
  fclose(ifp);
}

int b_d_function(char *str, director *director_current, director *head_d, int n, int s, int b, int m)
{
  FILE *ifp;
  ifp = fopen(str,"a");
  fprintf(ifp, "%s:", director_current -> birth -> str);
  if(b==1 && m==0)
  fprintf(ifp, "\n");
  fclose(ifp);
}

int m_d_function(char *str, director *director_current, director *head_d, int n, int s, int b, int m)
{
  FILE *ifp;
  ifp = fopen(str,"a");
    if(director_current -> best_movies != NULL)
    {
    fprintf(ifp, "%s,", director_current -> best_movies -> str);
    director_current -> best_movies = director_current -> best_movies -> next;
    }
  if(m==1)
  fprintf(ifp, "\n");
  fclose(ifp);
}


//////////////actor 의 [option]//
int n_a_function(char *str, actor *actor_current, actor *head_a, int n, int s, int b, int m)
{
  FILE *ifp;
  ifp = fopen(str,"a");
  fprintf(ifp, "%s:", actor_current -> name->str);
  if(n==1 && s==0 && b==0 && m==0)
  fprintf(ifp, "\n");
  fclose(ifp);
}

int s_a_function(char *str, actor *actor_current, actor *head_a, int n, int s, int b, int m)
{
  FILE *ifp;
  ifp = fopen(str,"a");
  fprintf(ifp, "%s:", actor_current -> sex->str);
  if(s==1 && b==0 && m==0)
  fprintf(ifp, "\n");
  fclose(ifp);
}

int b_a_function(char *str, actor *actor_current, actor *head_a, int n, int s, int b, int m)
{
  FILE *ifp;
  ifp = fopen(str,"a");
  fprintf(ifp, "%s:", actor_current -> birth->str);
  if(b==1 && m==0)
  fprintf(ifp, "\n");
  fclose(ifp);
}

int m_a_function(char *str, actor *actor_current, actor *head_a, int n, int s, int b, int m)
{
  FILE *ifp;
  ifp = fopen(str,"a");
    if(actor_current -> best_movies != NULL)
    {
    fprintf(ifp, "%s,", actor_current -> best_movies -> str);
    actor_current -> best_movies = actor_current -> best_movies -> next;
    }
  if(m==1)
  fprintf(ifp, "\n");
  fclose(ifp);
}


//정원이의 prompt()에서 file_name 부분이 str로 나타내므로.
int save(char *menu, char *mda, char *option, char *str, movie *head_m, director *head_d, actor *head_a)
{
  FILE *ifp = NULL;

  int t = 0, g = 0, d = 0, y = 0, r = 0, a= 0;
  int n = 0, s = 0, b = 0, m = 0;

  //아래는 save함수의 본격적인 적용 시작.
  if( *menu == 's' && *(menu + 1) == 'a' && *(menu + 2) == 'v' && *(menu + 3) == 'e' )
  {
    if( *mda == 'm' )
      {
        //current가 돌아가면서 찾는 부분.
        movie *movie_current = head_m;

        //mda의 m에서 tgdyra값 올리는 것.
        for( int i = 0 ; i <= 7 ; i ++ )
        {
          if(*(option+i) == 't')
          t=1;
          if(*(option+i) == 'g')
          g=1;
          if(*(option+i) == 'd')
          d=1;
          if(*(option+i) == 'y')
          y=1;
          if(*(option+i) == 'r')
          r=1;
          if(*(option+i) == 'a')
          a=1;
        }


        //채은이 꺼에서 마무리?
        //확인중

        if( option == NULL && str == NULL )
          {
          while(movie_current != NULL)
          {
          t=1,g=1,d=1,y=1,r=1,a=1;
          str = "movie_list";

          t_function(str,movie_current,head_m,t,g,d,y,r,a);
          g_function(str,movie_current,head_m,t,g,d,y,r,a);
          d_function(str,movie_current,head_m,t,g,d,y,r,a);
          y_function(str,movie_current,head_m,t,g,d,y,r,a);
          r_function(str,movie_current,head_m,t,g,d,y,r,a);
          a_function(str,movie_current,head_m,t,g,d,y,r,a);

          if(movie_current -> next == NULL)
            break;

          movie_current = movie_current -> next;
          }

          }


          //아래 두 경우는 안해도 되는 것으로 밝혀짐.
          /*
        if( *option == NULL && *str != NULL )
          {

            //파일을 열어서 작성만(w는 새 작성시 기존내용 삭제.)
            ifp = fopen(str,"w");
            //str부분에 온 파일 이름을 따서 만들어진 파일에 내용 작성.
            fprintf()
          }

        if( *option != NULL && *str == NULL )
          {

          }
          */

          //그냥 편의상.
        if( option != NULL && str != NULL )
          {
            while(movie_current != NULL)
            {
            if(t == 1)
            t_function(str,movie_current,head_m,t,g,d,y,r,a);
            if(g == 1)
            g_function(str,movie_current,head_m,t,g,d,y,r,a);
            if(d == 1)
            d_function(str,movie_current,head_m,t,g,d,y,r,a);
            if(y == 1)
            y_function(str,movie_current,head_m,t,g,d,y,r,a);
            if(r == 1)
            r_function(str,movie_current,head_m,t,g,d,y,r,a);
            if(a == 1)
            a_function(str,movie_current,head_m,t,g,d,y,r,a);

            if(movie_current -> next == NULL)
              break;

            movie_current = movie_current -> next;

            }

          }


      }

      if( *mda == 'd' )
        {
          //current가 돌아가면서 찾는 부분.
          director *director_current = head_d;

          //mda의 m에서 tgdyra값 올리는 것.
          for( int i = 0 ; i <= 5 ; i ++ )
          {
            if(*(option+i) == 'n')
            n=1;
            if(*(option+i) == 's')
            s=1;
            if(*(option+i) == 'b')
            b=1;
            if(*(option+i) == 'm')
            m=1;
          }


          //채은이 꺼에서 마무리?
          if( option == NULL && str == NULL )
            {
            while(director_current != NULL)
            {
            n=1,s=1,b=1,m=1;
            str = "director_list";

            n_d_function(str,director_current,head_d,n,s,b,m);
            s_d_function(str,director_current,head_d,n,s,b,m);
            b_d_function(str,director_current,head_d,n,s,b,m);
            m_d_function(str,director_current,head_d,n,s,b,m);

            if(director_current -> next == NULL)
              break;

            director_current = director_current -> next;
            }

            }
            //아래 두 경우는 안해도 되는 것으로 밝혀짐.
            /*
          if( *option == NULL && *str != NULL )
            {

              //파일을 열어서 작성만(w는 새 작성시 기존내용 삭제.)
              ifp = fopen(str,"w");
              //str부분에 온 파일 이름을 따서 만들어진 파일에 내용 작성.
              fprintf()
            }

          if( *option != NULL && *str == NULL )
            {

            }
            */

            //그냥 편의상.
          if( option != NULL && str != NULL )
            {
              while(director_current != NULL)
              {
              if(n == 1)
              n_d_function(str,director_current,head_d,n,s,b,m);
              if(s == 1)
              s_d_function(str,director_current,head_d,n,s,b,m);
              if(b == 1)
              b_d_function(str,director_current,head_d,n,s,b,m);
              if(m == 1)
              m_d_function(str,director_current,head_d,n,s,b,m);


              if(director_current -> next == NULL)
                break;

              director_current = director_current -> next;

              }

            }


        }

      if( *mda == 'a' )
      {
        //current가 돌아가면서 찾는 부분.
        actor *actor_current = head_a;

        //mda의 m에서 tgdyra값 올리는 것.
        for( int i = 0 ; i <= 5 ; i ++ )
        {
          if(*(option+i) == 'n')
          n=1;
          if(*(option+i) == 's')
          s=1;
          if(*(option+i) == 'b')
          b=1;
          if(*(option+i) == 'm')
          m=1;
        }


        //채은이 꺼에서 마무리?
        if( option == NULL && str == NULL )
          {
          while(actor_current != NULL)
          {
          n=1,s=1,b=1,m=1;
          str = "actor_list";

          n_a_function(str,actor_current,head_a,n,s,b,m);
          s_a_function(str,actor_current,head_a,n,s,b,m);
          b_a_function(str,actor_current,head_a,n,s,b,m);
          m_a_function(str,actor_current,head_a,n,s,b,m);

          if(actor_current -> next == NULL)
            break;

          actor_current = actor_current -> next;
          }

          }

          //아래 두 경우는 안해도 되는 것으로 밝혀짐.
          /*
        if( *option == NULL && *str != NULL )
          {

            //파일을 열어서 작성만(w는 새 작성시 기존내용 삭제.)
            ifp = fopen(str,"w");
            //str부분에 온 파일 이름을 따서 만들어진 파일에 내용 작성.
            fprintf()
          }

        if( *option != NULL && *str == NULL )
          {

          }
          */

          //그냥 편의상.
        if( option != NULL && str != NULL )
          {
            while(actor_current != NULL)
            {
            if(n == 1)
            n_a_function(str,actor_current,head_a,n,s,b,m);
            if(s == 1)
            s_a_function(str,actor_current,head_a,n,s,b,m);
            if(b == 1)
            b_a_function(str,actor_current,head_a,n,s,b,m);
            if(m == 1)
            m_a_function(str,actor_current,head_a,n,s,b,m);


            if(actor_current -> next == NULL)
              break;

            actor_current = actor_current -> next;

            }

          }


      }



  }

}

/*
int main(void)
{
  char *menu;
  char *mda;
  char *option;
  char *str;

  menu = (char *)malloc(sizeof(char));
  mda = (char *)malloc(sizeof(char));
  option = (char *)malloc(sizeof(char));
  str = (char *)malloc(sizeof(char));

  printf(">> save m|d|a  [option] [-f file_name]\n")
  printf(">>");
  scanf("%s %s %s %s",menu,mda,option,str);

  save(menu,mda,option,str,)
}
*/
//어디함수에 넣어서 테스트 해야하는지 잘 모르겠음.
