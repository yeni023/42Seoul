// `cc -D name=definition`
// cc -D TEST=20 gnl_test2.c => 정상 출력값 : 20
// cc -D TEST gnl_test2.c => 정상 출력값 : 1

// CC 컴파일러의 -D 플래그는 컴파일 할 때 name 을 predefine(미리 정의) 하며
// definition(정의값)을 적어주지 않으면 1을 저장합니다.

#include <stdio.h>

int main()
{
  printf("%d", TEST);
  return (0);
}
