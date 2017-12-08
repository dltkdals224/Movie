#include "user.h"

//해당 배열(포인터) 값들에 전부 '/0' (NULL) 값 배정해버리면 됨.
int delete(char *menu, char *mda, char *num, movie *movieTmp, actor *actorTmp, director *directorTmp)
{
//  linked_list *stackTmp;
//  linked_list *stackCircle;

  movie *extra_movie;
  director *extra_director;
  actor *extra_actor;
  // movie *movieCircle = movieTmp;
  FILE *ifp = NULL;


  if(*mda == 'm')
  {
    //delete하는게 처음에 있을 때( @ -> a -> a 형태.)
    if( atoi(num) == 1 ) //(==1)
    {
      //하나 저장되어 있을 때.
      if( movieTmp -> next == NULL )
      {

          {
          ifp = fopen("movie_log.txt","w");
          //아래 두줄은 안열릴경우 확인.
          if((ifp) = fopen("movie_log.txt","w") == NULL)
          printf("오류 : 파일을 열 수 없습니다.\n");

          fprintf(ifp,"delete:%d:=:=:=:=:=:=", movieTmp -> serial_number );
          //아래부터 actors 저장 방식 인용. (by 김정원)[필요없음]

          fclose(ifp);
          }

      movieTmp = NULL;
      }

      //하나 저장 아닐때.
      else if ( movieTmp -> next != NULL )
      {
      extra_movie = movieTmp -> next;
      //free( movieTmp );
      {
      ifp = fopen("movie_log.txt","w");
      //아래 두줄은 안열릴경우 확인.
      if((ifp) = fopen("movie_log.txt","w") == NULL)
      printf("오류 : 파일을 열 수 없습니다.\n");

      fprintf(ifp,"delete:%d:=:=:=:=:=:=", movieTmp -> serial_number );
      //아래부터 actors 저장 방식 인용. (by 김정원)[필요없음]

      fclose(ifp);
      }
      movieTmp = NULL; // 이 부분 질문.
      movieTmp = extra_movie;
      }
    }


    while(1)
    {
      if( atoi(num) == movieTmp -> next -> serial_number )
      {
        //delete하는게 중간에 있을 때( a -> @ -> a 형태.)
        if( movieTmp -> next -> next != NULL )
        {
          extra_movie = movieTmp -> next -> next; //이부분 맞는지 모르겠음
          //free( movieTmp -> next );
          {
          ifp = fopen("movie_log.txt","w");
          //아래 두줄은 안열릴경우 확인.
          if((ifp) = fopen("movie_log.txt","w") == NULL)
          printf("오류 : 파일을 열 수 없습니다.\n");

          fprintf(ifp,"delete:%d:=:=:=:=:=:=", movieTmp -> next -> serial_number );
          //아래부터 actors 저장 방식 인용. (by 김정원)[필요없음]

          fclose(ifp);
          }
          movieTmp -> next = NULL;
          movieTmp -> next = extra_movie; //이부분 맞는지 모르겠음
          //free나 NULL로 extra_movie 값을 비워놓는다?가 좋다?
          break;
        }

        //delete하는게 끝에 있을 때( a -> a -> @ 형태.)
        else if( movieTmp -> next -> next == NULL )
        {
          //free( movieTmp -> next );
          {
          ifp = fopen("movie_log.txt","w");
          //아래 두줄은 안열릴경우 확인.
          if((ifp) = fopen("movie_log.txt","w") == NULL)
          printf("오류 : 파일을 열 수 없습니다.\n");

          fprintf(ifp,"delete:%d:=:=:=:=:=:=", movieTmp -> next -> serial_number );
          //아래부터 actors 저장 방식 인용. (by 김정원)[필요없음]

          fclose(ifp);
          }
          movieTmp -> next = NULL;
          break;
        }

      }

      //이부분은 사실 중요하다!
      if(movieTmp -> next != NULL)
      movieTmp = movieTmp -> next;
      if(movieTmp -> next == NULL)
      {
      printf("No such record");
      break;
      }
    }

  //여기부터 ???_log파일에 태그를 갖는 레코드 삽입.
  //이것도 serial_number가 n번째 에냐에 따라 다름.
  }



  else if(*mda == 'd')
  {
    //delete하는게 처음에 있을 때( @ -> a -> a 형태.)
    if( atoi(num) == 1 ) //(==1)
    {
      //하나 저장되어 있을 때.
      if( directorTmp -> next == NULL )
      {

          {
          ifp = fopen("director_log.txt","w");
          //아래 두줄은 안열릴경우 확인.
          if((ifp) = fopen("director_log.txt","w") == NULL)
          printf("오류 : 파일을 열 수 없습니다.\n");

          fprintf(ifp,"delete:%d:=:=:=:=:=:=", directorTmp -> serial_number );
          //아래부터 actors 저장 방식 인용. (by 김정원)[필요없음]

          fclose(ifp);
          }

      directorTmp = NULL;
      }

      //하나 저장 아닐때.
      else if ( directorTmp -> next != NULL )
      {
      extra_director = directorTmp -> next;
      //free( movieTmp );
      {
      ifp = fopen("director_log.txt","w");
      //아래 두줄은 안열릴경우 확인.
      if((ifp) = fopen("director_log.txt","w") == NULL)
      printf("오류 : 파일을 열 수 없습니다.\n");

      fprintf(ifp,"delete:%d:=:=:=:=:=:=", directorTmp -> serial_number );
      //아래부터 actors 저장 방식 인용. (by 김정원)[필요없음]

      fclose(ifp);
      }
      directorTmp = NULL; // 이 부분 질문.
      directorTmp = extra_movie;
      }
    }


    while(1)
    {
      if( atoi(num) == directorTmp -> next -> serial_number )
      {
        //delete하는게 중간에 있을 때( a -> @ -> a 형태.)
        if( directorTmp -> next -> next != NULL )
        {
          extra_director = directorTmp -> next -> next; //이부분 맞는지 모르겠음
          //free( movieTmp -> next );
          {
          ifp = fopen("director_log.txt","w");
          //아래 두줄은 안열릴경우 확인.
          if((ifp) = fopen("director_log.txt","w") == NULL)
          printf("오류 : 파일을 열 수 없습니다.\n");

          fprintf(ifp,"delete:%d:=:=:=:=:=:=", directorTmp -> next -> serial_number );
          //아래부터 actors 저장 방식 인용. (by 김정원)[필요없음]

          fclose(ifp);
          }
          directorTmp -> next = NULL;
          directorTmp -> next = extra_director; //이부분 맞는지 모르겠음
          //free나 NULL로 extra_movie 값을 비워놓는다?가 좋다?
          break;
        }

        //delete하는게 끝에 있을 때( a -> a -> @ 형태.)
        else if( directorTmp -> next -> next == NULL )
        {
          //free( movieTmp -> next );
          {
          ifp = fopen("director_log.txt","w");
          //아래 두줄은 안열릴경우 확인.
          if((ifp) = fopen("director_log.txt","w") == NULL)
          printf("오류 : 파일을 열 수 없습니다.\n");

          fprintf(ifp,"delete:%d:=:=:=:=:=:=", directorTmp -> next -> serial_number );
          //아래부터 actors 저장 방식 인용. (by 김정원)[필요없음]

          fclose(ifp);
          }
          directorTmp -> next = NULL;
          break;
        }

      }

      //이부분은 사실 중요하다!
      if(directorTmp -> next != NULL)
      directorTmp = directorTmp -> next;
      if(directorTmp -> next == NULL)
      {
      printf("No such record");
      break;
      }
    }

  //여기부터 ???_log파일에 태그를 갖는 레코드 삽입.
  //이것도 serial_number가 n번째 에냐에 따라 다름.
  }



  else if(*mda == 'a')
  {
    //delete하는게 처음에 있을 때( @ -> a -> a 형태.)
    if( atoi(num) == 1 ) //(==1)
    {
      //하나 저장되어 있을 때.
      if( actorTmp -> next == NULL )
      {

          {
          ifp = fopen("actor_log.txt","w");
          //아래 두줄은 안열릴경우 확인.
          if((ifp) = fopen("actor_log.txt","w") == NULL)
          printf("오류 : 파일을 열 수 없습니다.\n");

          fprintf(ifp,"delete:%d:=:=:=:=:=:=", actorTmp -> serial_number );
          //아래부터 actors 저장 방식 인용. (by 김정원)[필요없음]

          fclose(ifp);
          }

      actorTmp = NULL;
      }

      //하나 저장 아닐때.
      else if ( actorTmp -> next != NULL )
      {
      extra_actor = actorTmp -> next;
      //free( movieTmp );
      {
      ifp = fopen("actor_log.txt","w");
      //아래 두줄은 안열릴경우 확인.
      if((ifp) = fopen("actor_log.txt","w") == NULL)
      printf("오류 : 파일을 열 수 없습니다.\n");

      fprintf(ifp,"delete:%d:=:=:=:=:=:=", actorTmp -> serial_number );
      //아래부터 actors 저장 방식 인용. (by 김정원)[필요없음]

      fclose(ifp);
      }
      actorTmp = NULL; // 이 부분 질문.
      actorTmp = extra_actor;
      }
    }


    while(1)
    {
      if( atoi(num) == actorTmp -> next -> serial_number )
      {
        //delete하는게 중간에 있을 때( a -> @ -> a 형태.)
        if( actorTmp -> next -> next != NULL )
        {
          extra_actor = actorTmp -> next -> next; //이부분 맞는지 모르겠음
          //free( movieTmp -> next );
          {
          ifp = fopen("actor_log.txt","w");
          //아래 두줄은 안열릴경우 확인.
          if((ifp) = fopen("actor_log.txt","w") == NULL)
          printf("오류 : 파일을 열 수 없습니다.\n");

          fprintf(ifp,"delete:%d:=:=:=:=:=:=", actorTmp -> next -> serial_number );
          //아래부터 actors 저장 방식 인용. (by 김정원)[필요없음]

          fclose(ifp);
          }
          actorTmp -> next = NULL;
          actorTmp -> next = extra_actor; //이부분 맞는지 모르겠음
          //free나 NULL로 extra_movie 값을 비워놓는다?가 좋다?
          break;
        }

        //delete하는게 끝에 있을 때( a -> a -> @ 형태.)
        else if( actorTmp -> next -> next == NULL )
        {
          //free( movieTmp -> next );
          {
          ifp = fopen("actor_log.txt","w");
          //아래 두줄은 안열릴경우 확인.
          if((ifp) = fopen("actor_log.txt","w") == NULL)
          printf("오류 : 파일을 열 수 없습니다.\n");

          fprintf(ifp,"delete:%d:=:=:=:=:=:=", actorTmp -> next -> serial_number );
          //아래부터 actors 저장 방식 인용. (by 김정원)[필요없음]

          fclose(ifp);
          }
          actorsTmp -> next = NULL;
          break;
        }

      }

      //이부분은 사실 중요하다!
      if(actorTmp -> next != NULL)
      actorTmp = actorTmp -> next;
      if(actorTmp -> next == NULL)
      {
      printf("No such record");
      break;
      }
    }

  //여기부터 ???_log파일에 태그를 갖는 레코드 삽입.
  //이것도 serial_number가 n번째 에냐에 따라 다름.
  }

//각각의 리스트 상의 적절한 노드 정보를 삭제.(난이도 상)


}


//
//
//
//
//movie_log파일에 delete태그를 갖는 레코드 삽입 중 serial_number 가 1일때.
/* 파일 포인터 기본형식.
  {
  ifp = fopen("movie_log","w");
  //아래 두줄은 안열릴경우 확인.
  if((ifp) = fopen("movie_log.txt","w") == NULL)
  printf("오류 : 파일을 열 수 없습니다.\n");
  fprintf(ifp,"delete:serial_number:%s:%s:%s:%s:%s:", movieTmp->title, movieTmp->genre, movieTmp->director, movieTmp->year, movieTmp->time );
  //아래부터 actors 저장 방식 인용. (by 김정원)

      while(1)
      {

        if(movieTmp -> actors -> next == NULL)
        {
          fprintf(ifp,"%s", movieTmp -> actors -> str);
        }

        if(movieTmp -> actors -> next != NULL)
        {
          fprintf(ifp,"%s,", movieTmp -> actors -> str);
        }

        if(movieTmp -> actors == NULL )
        break;

        movieTmp -> actors = movieTmp -> actors -> next;

      }

    fclose(ifp);
  }*/

int main(void)
{
  int delete(char *menu, char *mda, char *num, movie *movieTmp, actor *actorTmp, director *directorTmp);

  return 0;
}
