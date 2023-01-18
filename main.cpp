#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>

//Variant 13
// A4
// t = 15
// T=20
// B12
// t = 10	
// T=20


void delay(int mill) {
	for(int i=0;i< mill*0x010000;i++);
}

int main(void)
{  
  GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
	GPIO_SetBits(GPIOB, GPIO_Pin_12);
	GPIO_SetBits(GPIOA, GPIO_Pin_4);

	while (1) {
				  
		  GPIOB->ODR |= GPIO_Pin_12;  		  
		  GPIOA->ODR |= GPIO_Pin_4;  
		  
		  delay(15);		
		  GPIOB->ODR &= ~GPIO_Pin_12;		  
		  delay(16);		
		  GPIOA->ODR &= ~GPIO_Pin_4;     
		
		  delay(20);
  }
		
}