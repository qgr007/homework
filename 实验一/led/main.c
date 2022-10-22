#include "stm32f10x.h"

#define RCC_APB2ENR	*((unsigned volatile int*)0x40021018)
#define GPIOA_CRL	*((unsigned volatile int*)0x40010800)
#define	GPIOA_ODR	*((unsigned volatile int*)0x4001080C)
#define GPIOB_CRH	*((unsigned volatile int*)0x40010C04)
#define	GPIOB_ODR	*((unsigned volatile int*)0x40010C0C)
#define GPIOC_CRH	*((unsigned volatile int*)0x40011004)
#define	GPIOC_ODR	*((unsigned volatile int*)0x4001100C)
	
void SystemInit(){}

void delay(u32 time){
	u32 i = 0;
	while(time--){
		i = 2000;
		while(i--){
		}
	}
}

int main(void){
	
	RCC_APB2ENR |= (1<<2);	
	RCC_APB2ENR |= (1<<3);	
	RCC_APB2ENR |= (1<<4);	
	
	GPIOA_CRL &= 0xFF0FFFFF;	
	
	GPIOA_CRL |= 0x00300000;	
	//GPIOA_ODR &= ~(1<<5);		
	GPIOA_ODR |= 1<<5;				
	
	GPIOB_CRH &= 0xFFFFFF0F;
	GPIOB_CRH |= 0x00000020;	
	//GPIOA_ODR &= ~(1<<9);
	GPIOB_ODR |= 1<<9;
	
	
	GPIOC_CRH &= 0xF0FFFFFF;
	GPIOC_CRH |= 0x02000000;	
	//GPIOC_ODR &= ~(1<<14);
	GPIOC_ODR |= 1<<14;
	
	while(1){
		GPIOA_ODR &= ~(1<<5);	
		delay(1000);
		GPIOA_ODR |= 1<<5;		
		// ????????????????
		
		GPIOB_ODR &= ~(1<<9);
		delay(1000);
		GPIOB_ODR |= 1<<9;
		
		GPIOC_ODR &= ~(1<<14);
		delay(1000);
		GPIOC_ODR |= 1<<14;
	}
	
}