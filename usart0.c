#include "usart0.h"

// USART0 ���� : 9600bps, 8 Data, 1 Stop, No Parity
void usart0_init(void)
{
  	UBRR0H = 103 >> 8;// Baud rate = 9600 bps @ 16[MHz]
  	UBRR0L = 103;		// Baud rate = 9600 bps @ 16[MHz]
	UCSR0A = 0x00;		// 0000_0000: ���� �ӵ�=1��, ��Ƽ���μ��� ���=X
	UCSR0B = 0x18;		// 0001_1000: Rx & Tx ���
	UCSR0C = 0x06;		// 0000_0110: Async. , No Parity, 1 Stop bit, 8 Data bits
}

// ���� ����(UDR0)���� �� �� ���ڸ� �о ��ȯ
// ����: ���� ���۰� ����� ������ ���� ���� ����
char usart0_getchar(void)
{
	while( (UCSR0A & RX_COMPLETE) == 0 );

	return(UDR0);
}

// �۽� ����(UDR0)�� �� �� ���ڸ� ����
// FILE *stream: �������� ������ printf() �Լ��� ������ ���� �� �ʿ�
// ����: �۽� ���۰� ����� ������ ���� ���� ����
void usart0_putchar(char cData, FILE *stream)
{
	if(cData == '\n') {
		while( (UCSR0A & DATA_REG_EMPTY) == 0 );
		UDR0 = '\r';
	}

	while( (UCSR0A & DATA_REG_EMPTY) == 0 );
	UDR0 = cData;
}
 