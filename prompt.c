#include "user.h" //구조체 따위를 쓰는곳이 있다면 어디든지 이 사용자 헤더파일을 사용해 주어야 한다.


//입력받는 함수 prompt
/*
< 각각 인자 형식 >
add m|d|a
update m|d|a [option] num
print m|d|a num
delete m|d|a num
save m|d|a [option] [-f file_name]
sort m|d|a [option] [-f file_name]
search [option] string
end
*/

//따라서 [option]이 있는 함수는 생략이 가능하도록 해야함.
//-f 뒤의 file_name도 마찬가지.

//@@@각 명령어 자리 리턴값 대신에 함수를 호출하는 형태가 괜찮을 듯.@@@ <- 적용완료.

/////////////////명령어//////m|d|a//////[option]/////string//////num
int prompt(char *menu, char *mda, char *option, char *str, char *num, char  *file_name)
{
  char *tmp = (char *)malloc(30*sizeof(char)); //순간순간 입력받는 값.
  char *p; //strtok()를 쓰기위한 포인터

  *menu = *mda = *option = *str = *num = *file_name = '\0'; //NULL로 초기화

  printf("(movie) ");
  gets(tmp); //gets() 정확한 설명은 책에 없지만 문자를 받는 것.


  if(*(tmp)=='s')
  {
    if(*(tmp+1)=='e') //search
    {
      p = strtok(tmp," "); //strtok(a,b) == a에서 b가 나오기 전 까지의 값을 리턴. 그후 넘어가짐.
      if(p)
      strcpy(menu, p);

      if(p!=NULL)
      {
        p = strtok(NULL," ");
        if(p)
        strcpy(option, p);
      }

      if(p==NULL) //option이 없는 경우를 위한 부분. str부분에 받아지는게 없으면 option부분이 str이였던거지.
      {
        strcpy(str,option);
        //search(); //search함수 실행.
      }

      if(p!=NULL)
      {
        p = strtok(NULL," ");
        if(p)
        strcpy(str, p);
      }
      // search(); //search함수 실행
    }


    if(*(tmp+1)=='o') //sort
    {
      p = strtok(tmp," ");
      if(p)
      strcpy(menu, p);

      if(p!=NULL)
      {
        p = strtok(NULL," ");
        if(p)
        strcpy(mda, p);
      }

      //여기부터 문제해결 필요. <- 완료
      if(p!=NULL)
      {
        p = strtok(NULL," ");
        if(p)
          if(*p != '-')
          strcpy(option, p);
      }

      //2번 반복.
      if(p!=NULL)
      {
        p = strtok(NULL, " ");
        if(p)
          if(*p != '-')
          strcpy(file_name, p);
      }
      if(p!=NULL)
      {
        p = strtok(NULL, " ");
        if(p)
          if(*p != '-')
          strcpy(file_name, p);
      }

      // sort(); //sort함수 실행.
    }


    if(*(tmp+1)=='a') //save
    {
      p = strtok(tmp," ");
      if(p)
      strcpy(menu, p);

      if(p!=NULL)
      {
        p = strtok(NULL," ");
        if(p)
        strcpy(mda, p);
      }

      //여기부터 문제해결 필요. <- 완료
      if(p!=NULL)
      {
        p = strtok(NULL," ");
        if(p)
          if(*p != '-')
          strcpy(option, p);
      }

      //2번 반복.
      if(p!=NULL)
      {
        p = strtok(NULL, " ");
        if(p)
          if(*p != '-')
          strcpy(file_name, p);
      }
      if(p!=NULL)
      {
        p = strtok(NULL, " ");
        if(p)
          if(*p != '-')
          strcpy(file_name, p);
      }
    // save(); //save함수 실행.
    }
  }


if(*(tmp)=='p')//  print
{
  p = strtok(tmp," ");
  if(p)
  strcpy(menu, p);

  if(p!=NULL)
  {
    p = strtok(NULL," ");
    if(p)
    strcpy(mda, p);
  }

  if(p!=NULL)
  {
    p = strtok(NULL," ");
    if(p)
    strcpy(num, p);
  }

  // print(); //print함수 실행.
}
//print()까지 명령받는데 이상 없음.


if(*(tmp)=='a')  //add
{
  p = strtok(tmp," ");
  if(p)
  strcpy(menu, p);

  if(p!=NULL)
  {
    p = strtok(NULL," ");
    if(p)
    strcpy(mda, p);
  }

 add(menu,mda,); //add함수 실행.
}


if(*(tmp)=='u')  //update
{
  p = strtok(tmp," "); //strtok(a,b) == a에서 b가 나오기 전 까지의 값을 리턴. 그후 넘어가짐.
  if(p)
  strcpy(menu, p);

  if(p!=NULL)
  {
    p = strtok(NULL," ");
    if(p)
    strcpy(option, p);
  }

  if(p==NULL) //option이 없는 경우를 위한 부분. num부분에 받아지는게 없으면 option부분이 num이였던거지.
  {
    strcpy(num,option);
    //update(); //update함수 실행.
  }

  if(p!=NULL)
  {
    p = strtok(NULL," ");
    if(p)
    strcpy(num, p);
  }

  // update(); //update함수 실행.
}


  if(*(tmp)=='d')  //delete
  {
    p = strtok(tmp," ");
    if(p)
    strcpy(menu, p);
    if(p!=NULL)
    {
      p = strtok(NULL," ");
      if(p)
      strcpy(mda, p);
    }
    if(p!=NULL)
    {
      p = strtok(NULL," ");
      if(p)
      strcpy(num, p);
    }

    // delete(); //delete함수 실행.
  }
}
