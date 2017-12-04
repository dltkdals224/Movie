#include "user.h"

//이거 end
void cntrl_c() // Control + C를 눌렀을 때 물어보게 하는 함수
{
  signal(SIGINT,cntrl_c);

  char answer[4];
  printf("Get Interrupt Signal\n");
  while(1)
  {
  printf("Do you want to exit myMOVIE program ? (Y/N)");
  scanf("%s",&answer);

    if((answer[0] == 'Y') || (answer[0] == 'y'))
    {
      printf("\nexit myMOVIE...");
      exit(0);
    }
    if((answer[0] == 'N') || (answer[0] == 'n'))
    {
      printf("만세"); //이자리 수정 필요.
      break;
    }
  }
}

 //확인을 위해 main()을 임의의 반복문으로 설정해둠.
int main(){
  signal(SIGINT,ctrl_c); //인터럽트 발생시 ctrl_c() 함수가 호출된다.
  while(1)
  {
    int i;
    printf("%d",i++);

  }
  return 0;
}

// 형식만 올림 걍 이렇게 하면 됨.
