#include"user.h"
void justprint(movie *movieHead,int i)
{
	stack * stackTmp;
	while(1)
	{
		if(movieHead==NULL) break; //추가된부분을 출력하는 함수의 종단점
		//출력할 조건 : 다음 링크가 없다면 지금 링크를 출력
		if(movieHead -> next == NULL){
			 printf("%d\n%s:%s:%s:%s:%s",i,movieHead->title->str,movieHead->genre->str,movieHead->director->str,movieHead->year->str,movieHead->time->str);
			 //acotrs는 여러개의 링크로 연결되어있으므로 몇개의 acotr가 연결된지 찾고 출력해준다
			 //acotrs가 메모리를 할당받았을때 실행
			 if(movieHead -> actors != NULL)
		  	{
					stackTmp = movieHead -> actors;
					//actors의 링크드를 모두출력
					while(1)
					{
						if(stackTmp -> next == NULL) {printf(":%s\n\n",stackTmp -> str); break;}
						if(stackTmp -> next != NULL) {printf(":%s",stackTmp -> str); stackTmp = stackTmp -> next;}
					}
			 	}
			}
		movieHead = movieHead -> next;
		i++;
	}
	return ;
}
