// 먼저 search

  if(*(menu)=='search')
  {
    if(*(mda)=='-' && (*(mda+1) == 'm'|| *(mda+1)=='d'|| *(mda+1)=='a') )
    {
      if(*(mda+1)=='m')
        {
            for(int i = 0 ; *(str + i) != '\0' ; i++ ) //일단 '\0'나오기 전까지 입력받은 string검색하는건 동일.
            {
              //다 해놓고 나머지 다 오류해버리면 됨. 아닌가?
                // '*' 있어
                if ( *(str + i) == '*')
                  //if ( *(str + i - 1) !=  && *(str + i + 1) != '\0') //틀린거 같은데 어딘지 모르겠음.
                    printf("\n잘못된 입력입니다.");
                    goto escape; //goto문으로 검색결과없음 그 이상의 밖으로 나가야 한다. break로 나가면 바로 검색결과없음이다.

                  else


                // '*'없이 기본 + '?'
                if ( *(str + i) != '*' )
                  if ( *(str + i) == '?')
                    ; //continue?
                  else if ( *(str + i) != '?')
                    if ( *(str + i) == *( head->title->str + i))
                      ; //continue?
                    if ( *(str + i) != *( head->title->str + i)
                      break; // 입력받은 str과 저장된 제목의 이름이 한 자리라도 틀리면 break; 발동 -> 검색결과 없음.
                    if( i == strlen(*head->title->str) ) //NULL문자 전 까지의 문자길이(띄어쓰기 포함)가 i랑 같아질 때
                    printf(" ")//해당 :::의 영화정보 출력

            }
            //break로 나왔을 때
            printf("\n검색결과없음.");

            escape : //작성

        }
        //(struct_movie)movie *head에서.
        //head->title->str에서 값을 1씩 올리면서 strcmp로 찾는다. string을 찾는 일.
        //

      if(*(mda+1)=='d')
      {

      }

      if(*(mda+1)=='a')
      {

      }

      //아래 나중에 바꿔야 하긴 할듯. ~ 나중에 바꾸고
      if(*(mda)=='-md'||'-dm')
      if(*(mda)=='-ma'||'-am')
      if(*(mda)=='-da'||'-ad')
      if(*(mda)=='-mda'||'-mad'||'-dma'||'-dam'||'-adm'||'-amd')
    }
    else //이때는 -mda옵션 다 사용한 거랑 같겠지.

  }
}
