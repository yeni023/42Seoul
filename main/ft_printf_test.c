/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:48:05 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/07/06 18:48:08 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
    ft_printf("----------내가 만든 프엪----------\n");
    ft_printf("4, 10, 20, 30\n");
    ft_printf("%d, %d\n", 1, 2);
    ft_printf("%u\n", 10);
    ft_printf("%d\n", -20);     // -20: 부호 있는 10진 정수
    ft_printf("%i\n", -20);     // -20: 부호 있는 10진 정수
    ft_printf("%x\n", 10);      //  a: 부호 있는 16진수 (소문자)
    ft_printf("%X\n", 10);
    ft_printf("%c\n", 'a');    // a: 문자
    ft_printf("%s\n", "Hello, world!"); 
    printf("----------여기서부터는 찐 프엪----------\n");
    printf("4, 10, 20, 30\n");
    printf("%d, %d\n", 1, 2);
    printf("%u\n", 10);
    printf("%d\n", -20);     // -20: 부호 있는 10진 정수
    printf("%i\n", -20);     // -20: 부호 있는 10진 정수
    printf("%x\n", 10);      //  a: 부호 있는 16진수 (소문자)
    printf("%X\n", 10);
    printf("%c\n", 'a');    // a: 문자
    printf("%s\n", "Hello, world!"); 
    ft_printf("----------포인터와 %% 기호 실행 결과----------\n");
    // 포인터
    int num1;
    void *ptr = &num1;
    printf("%s %p\n", "찐 printf 실행 결과: ", ptr);// 008BFB6C: 포인터의 메모리 주소
                        // 0x8bfb6c: 리눅스, OS X에서는 앞에 0x가 붙고, A~F는 소문자로 출력
                        // 높은 자릿수의 0은 생략
    ft_printf("%s %p\n", "내가 만든 printf 실행 결과: ", ptr);

    // % 기호
    printf("%%\n");    // %: % 기호 출력
    ft_printf("%%\n");
	
	ft_printf("-----test2, printf-----\n");
	printf("%d", -1);
	printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\n");
	printf("%c \n", 'a');
	printf("%s \n", "abc");
	printf("%p \n", (void *)42);
	printf("%d %i \n", 42, 42);
	printf("%u \n", 42);
	printf("%x %X \n", 42, 42);
	printf("%% \n\n");
	ft_printf("-----test2, ft_printf-----\n");
	ft_printf("%d\n", -1);
	ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	ft_printf("\n");
	ft_printf("%c \n", 'a');
	ft_printf("%s \n", "abc");
	ft_printf("%p \n", (void *)42);
	ft_printf("%d %i \n", 42, 42);
	ft_printf("%u \n", 42);
	ft_printf("%x %X \n", 42, 42);
	ft_printf("%% \n");
}
