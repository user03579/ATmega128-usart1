#ifndef _USART_H_
#define _USART_H_

#include "main.h"

// UCSR0A �������� ���� ��Ʈ
#define DATA_REG_EMPTY	0x20
#define RX_COMPLETE		0x80

void usart0_init(void);
char usart0_getchar(void);
void usart0_putchar(char cData, FILE *stream);

#endif

