#include "main.h"
#include "led_sw.h"
#include "usart0.h"
//실습 문제1
FILE x_stdout = FDEV_SETUP_STREAM(usart0_putchar, NULL, _FDEV_SETUP_WRITE);

void main(void)
{
	stdout = &x_stdout;	// printf() 함수 출력 관련 설정

	led_init();
	led_onoff(LED_ALL, 0.3);

	// USART0 설정: 9600 bps, no parity, 1 stop bit, 8-bit data
	usart0_init();

	printf("\033[H\033[J"); // 터미널 화면 지우기
	// 프로그램 실행 메세지 출력(컴파일 날짜와 시각 포함)
	printf("=== ATmega128 program(%s %s) ===\n\r", __TIME__, __DATE__);

	while(1) {
		char cRx = usart0_getchar();
		if(cRx == 'H' || cRx == 'h'){
			printf("#\n\r");
			led_onoff(LED1_4, 0.3);
		}
		else if(cRx == 'L' || cRx == 'l'){
			printf("@\n\r");
			led_onoff(LED5_8, 0.3);
		}
		else if(cRx >= '0' && cRx <='9'){
				printf("%c X 9 = %d\n\r",cRx, (cRx - '0')*9);
		}
		else{
			printf("?\n\r");
			led_onoff(LED_ALL, 0.3);
		}
	}
}
