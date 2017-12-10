#include "user.h"

int add(char *menu,char *mda, movie *movieTmp, actor *actorTmp, director *directorTmp)
{
	movie *tmp_same; // 같은 목록 찾는용
	stack *stackTmp;  //stack형의 링크드리스트를 도는거
	stack *stackCircle; //movie_log파일에 저장할때 써야함
	char * charTmp = (char *)calloc(100,sizeof(char));
	char *p; // strtok()
	//추가@@//같은목록찾기성공하면 init_add에도추가하기
	movie *movieCircle = movieTmp;

	//설정부분//2번째링크부터 가능//첫번째도 설정해야함
	while(movieTmp -> next != NULL)  //1.movieTmp에 아무것도 연결안되어있다면 넘어감 2.movieTmp에 동적메모리할당이있다면 다음링크로연결 3.동적메모리가 할당되었어도 그제목이 없다면 그 동적메모리에 내용 추가.
	{
		if(movieTmp -> next -> title == NULL){
			movieTmp -> next -> next = (movie *)calloc(1,sizeof(movie));
			break; // 지금은 동적메모리를 남기지만 시간여유가 된다면 free함수로 메모리를반납하고 다시 링크연결하게끔 하자.
		}
		movieTmp = movieTmp -> next;
	}
	if(movieTmp -> next == NULL){movieTmp -> next = (movie *)calloc(1,sizeof(movie)); movieTmp -> next -> next = NULL;}


	//입출력부분//
	printf("title > ");
	movieTmp -> next -> title = (stack *)calloc(1,sizeof(stack));
	movieTmp -> next -> title -> str = (char *)calloc(30,sizeof(char));
	scanf("%s",(movieTmp -> next -> title -> str));


  printf("genre > ");
  movieTmp -> next -> genre = (stack *)calloc(1,sizeof(stack));
	movieTmp -> next -> genre -> str = (char *)calloc(30,sizeof(char));
  scanf("%s",(movieTmp -> next -> genre -> str));

  printf("director > ");
  movieTmp -> next -> director = (stack *)calloc(1, sizeof(stack));
	movieTmp -> next -> director -> str = (char *)calloc(30,sizeof(char));
 	scanf("%s",(movieTmp -> next -> director -> str));

 	printf("year > ");
  movieTmp -> next -> year = (stack *)calloc(1,sizeof(stack));
	movieTmp -> next -> year -> str = (char *)calloc(30,sizeof(char));
	scanf("%s",movieTmp -> next -> year -> str);

	printf("run time > ");
  movieTmp -> next -> time = (stack *)calloc(1,sizeof(stack));
	movieTmp -> next -> time -> str = (char *)calloc(30,sizeof(char));
 	scanf("%s",movieTmp -> next -> time -> str);

 	printf("actors > ");
  movieTmp -> next -> actors = (stack *)calloc(1,sizeof(stack));
	movieTmp -> next -> actors -> str = (char *)calloc(100,sizeof(char));
	getchar();
	scanf("%[^\n]",charTmp);
	getchar();

//strtok로 인자나누는 부분//
p = strtok(charTmp,",");
if(p) {
	stackTmp = movieTmp -> next -> actors;
	strcpy(stackTmp -> str, p);
}

while (p!=NULL){
	p = strtok(NULL,",");
	if(p){

		stackTmp -> next = (stack *)calloc(1,sizeof(stack));
		stackTmp -> next -> str = (char *)calloc(100,sizeof(char));
		stackTmp = stackTmp -> next;
		strcpy(stackTmp -> str, p);
	}
}

//같은제목일때 "You have the same record in  movie_list."출력//그대로 넣을건지 말건지 묻고 실행//추가@@
while(1)
{
	if(movieCircle == NULL) break;
	if(movieCircle != NULL)
	{
		//같은링크에 도착할때 안할때
		if(strcmp((movieTmp -> next -> title -> str),(movieCircle -> title -> str)) == 0)
		{
			{
				printf("@@ You have the same record in movie_list.\n");
				printf("숫자(serial함수되면넣을거):%s:%s:%s:%s:%s\n",movieCircle -> title -> str,movieCircle -> genre -> str,movieCircle -> director -> str, movieCircle -> year -> str,movieCircle -> time -> str);
				printf("@@ Do you want to add any way?(N,n/Y,y) ");
				char a;
				scanf("%c",&a);
				if(a == 'y'||a == 'Y') break;
				if(a == 'n'||a == 'N')
				{
					movieTmp -> next = NULL;
					return 1;
				}
			}
			if(strcmp((movieTmp -> next -> genre -> str),(movieCircle -> genre -> str)) == 0) break;
		}
		else
		{
			if(movieCircle -> next != NULL) movieCircle = movieCircle -> next;
			if(movieCircle -> next == NULL) break;
		}

	}
}

//log파일에 로그 올리기//추가@@
{
 	FILE *fp;
 	fp = fopen("movie_log.txt","a");
	fprintf(fp,"add:serialnumber:%s:%s:%s:%s:%s",movieTmp -> next -> title -> str,movieTmp -> next -> genre -> str,movieTmp -> next -> director -> str,movieTmp -> next -> year -> str,movieTmp -> next -> time -> str);
	stackCircle = movieTmp -> next -> actors;
	//actors의 링크드를 모두저장

	int tmp = 0;
	while(1)
	 {
		 tmp++;
		 if(tmp==1)
		 {
		 	if(stackCircle -> next == NULL) {fprintf(fp,":%s\n",stackCircle -> str); break;}
		 	if(stackCircle -> next != NULL) {fprintf(fp,":%s",stackCircle -> str); stackCircle = stackCircle -> next;}
		 }
		 if(stackCircle -> next == NULL) {fprintf(fp,",%s\n",stackCircle -> str); break;}
		 if(stackCircle -> next != NULL) {fprintf(fp,",%s",stackCircle -> str); stackCircle = stackCircle -> next;}
	 }
	 fclose(fp);
}
return 0;
}
