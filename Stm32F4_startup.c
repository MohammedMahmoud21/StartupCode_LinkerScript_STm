/***************************************************************************************/
/***************************************************************************************/
/**************************** Author : Mohammed Elsayaad *******************************/
/**************************** Date :   1 July,2023         *****************************/
/**************************** Describtion: STM32F446 Startup Code     ******************/
/***************************************************************************************/
/***************************************************************************************/

#include <stdint.h>

#define SRAM_START		(0x20000000UL)
#define SRAM_SIZE		((128)*(1024))
#define SRAM_END		((SRAM_START) + (SRAM_SIZE))
#define MSP				(SRAM_END)

extern uint32_t _etext;		// end of text in flash
extern uint32_t _sdata;		// start of .data in sram
extern uint32_t _edata;		// end of .data in sram
extern uint32_t _sbss;		// start of bss 
extern uint32_t _ebss;		// end of bss

void main(void);

void Reset_Handler (void)
{
	uint8_t *pSrc  = (uint8_t *)&_etext; // & here is a must as these are symbols
	uint8_t *pDest = (uint8_t *)&_sdata;
	uint32_t Size  = (uint32_t)(&_edata) - (uint32_t)(&_sdata);
	uint32_t LoopCounter;
	/*1.Copy .data from flash to SRAM*/
	for(LoopCounter=0;LoopCounter < Size;LoopCounter++)
	{
		pDest[LoopCounter] = pSrc[LoopCounter];
	}
	/*2. Init .bss with zero*/
	pDest = (uint8_t *)&_sbss;
	Size  = (uint32_t)(&_ebss) - (uint32_t)(&_sbss);
	for(LoopCounter=0;LoopCounter < Size;LoopCounter++)
	{
		pDest[LoopCounter] = 0;
	}
	/*3. Call Main*/
	main();
}
void Default_Handler (void)
{
	while(1);
}
void Reset_Handler				(void) __attribute__((weak,alias("Default_Handler")));
void NMI_Handler				(void) __attribute__((weak,alias("Default_Handler")));
void HardFault_Handler			(void) __attribute__((weak,alias("Default_Handler")));
void MemManage_Handler			(void) __attribute__((weak,alias("Default_Handler")));
void BusFault_Handler			(void) __attribute__((weak,alias("Default_Handler")));
void UsageFault_Handler			(void) __attribute__((weak,alias("Default_Handler")));
void SVC_Handler				(void) __attribute__((weak,alias("Default_Handler")));
void DebugMon_Handler			(void) __attribute__((weak,alias("Default_Handler")));
void PendSV_Handler				(void) __attribute__((weak,alias("Default_Handler")));
void SysTick_Handler			(void) __attribute__((weak,alias("Default_Handler")));
void WWDG_IRQHandler      		(void) __attribute__((weak,alias("Default_Handler")));
void PVD_IRQHandler       		(void) __attribute__((weak,alias("Default_Handler")));
void TAMP_STAMP_IRQHandler		(void) __attribute__((weak,alias("Default_Handler")));
void RTC_WKUP_IRQHandler  		(void) __attribute__((weak,alias("Default_Handler")));
void FLASH_IRQHandler     		(void) __attribute__((weak,alias("Default_Handler")));
void RCC_IRQHandler       		(void) __attribute__((weak,alias("Default_Handler")));
void EXTI0_IRQHandler     		(void) __attribute__((weak,alias("Default_Handler")));
void EXTI1_IRQHandler     		(void) __attribute__((weak,alias("Default_Handler")));
void EXTI2_IRQHandler     		(void) __attribute__((weak,alias("Default_Handler")));
void EXTI3_IRQHandler     		(void) __attribute__((weak,alias("Default_Handler")));
void EXTI4_IRQHandler     		(void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream0_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream1_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream2_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream3_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream4_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream5_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream6_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void ADC_IRQHandler             (void) __attribute__((weak,alias("Default_Handler")));
void CAN1_TX_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void CAN1_RX0_IRQHandler        (void) __attribute__((weak,alias("Default_Handler")));
void CAN1_RX1_IRQHandler        (void) __attribute__((weak,alias("Default_Handler")));
void CAN1_SCE_IRQHandler        (void) __attribute__((weak,alias("Default_Handler")));
void EXTI9_5_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler   (void) __attribute__((weak,alias("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler   (void) __attribute__((weak,alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandl(void) __attribute__((weak,alias("Default_Handler")));
void TIM1_CC_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void TIM2_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void TIM3_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void TIM4_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void I2C1_EV_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void I2C1_ER_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void I2C2_EV_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void I2C2_ER_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void SPI1_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void SPI2_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void USART1_IRQHandler          (void) __attribute__((weak,alias("Default_Handler")));
void USART2_IRQHandler          (void) __attribute__((weak,alias("Default_Handler")));
void USART3_IRQHandler          (void) __attribute__((weak,alias("Default_Handler")));
void EXTI15_10_IRQHandler       (void) __attribute__((weak,alias("Default_Handler")));
void RTC_Alarm_IRQHandler       (void) __attribute__((weak,alias("Default_Handler")));
void OTG_FS_WKUP_IRQHandler     (void) __attribute__((weak,alias("Default_Handler")));
void TIM8_BRK_TIM12_IRQHandler  (void) __attribute__((weak,alias("Default_Handler")));
void TIM8_UP_TIM13_IRQHandler   (void) __attribute__((weak,alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_IRQHandl(void) __attribute__((weak,alias("Default_Handler")));
void TIM8_CC_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream7_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void FMC_IRQHandler             (void) __attribute__((weak,alias("Default_Handler")));
void SDIO_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void TIM5_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void SPI3_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void UART4_IRQHandler       	(void) __attribute__((weak,alias("Default_Handler")));
void UART5_IRQHandler       	(void) __attribute__((weak,alias("Default_Handler")));
void TIM6_DAC_IRQHandler    	(void) __attribute__((weak,alias("Default_Handler")));
void TIM7_IRQHandler        	(void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream0_IRQHandler	(void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream1_IRQHandler	(void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream2_IRQHandler	(void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream3_IRQHandler	(void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream4_IRQHandler	(void) __attribute__((weak,alias("Default_Handler")));
void CAN2_TX_IRQHandler       	(void) __attribute__((weak,alias("Default_Handler")));
void CAN2_RX0_IRQHandler      	(void) __attribute__((weak,alias("Default_Handler")));
void CAN2_RX1_IRQHandler      	(void) __attribute__((weak,alias("Default_Handler")));
void CAN2_SCE_IRQHandler      	(void) __attribute__((weak,alias("Default_Handler")));
void OTG_FS_IRQHandler        	(void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream5_IRQHandler  	(void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream6_IRQHandler  	(void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream7_IRQHandler  	(void) __attribute__((weak,alias("Default_Handler")));
void USART6_IRQHandler        	(void) __attribute__((weak,alias("Default_Handler")));
void I2C3_EV_IRQHandler       	(void) __attribute__((weak,alias("Default_Handler")));
void I2C3_ER_IRQHandler       	(void) __attribute__((weak,alias("Default_Handler")));
void OTG_HS_EP1_OUT_IRQHandler	(void) __attribute__((weak,alias("Default_Handler")));
void OTG_HS_EP1_IN_IRQHandler 	(void) __attribute__((weak,alias("Default_Handler")));
void OTG_HS_WKUP_IRQHandler   	(void) __attribute__((weak,alias("Default_Handler")));
void OTG_HS_IRQHandler        	(void) __attribute__((weak,alias("Default_Handler")));
void DCMI_IRQHandler          	(void) __attribute__((weak,alias("Default_Handler")));
void FPU_IRQHandler       		(void) __attribute__((weak,alias("Default_Handler")));
void SPI4_IRQHandler      		(void) __attribute__((weak,alias("Default_Handler")));
void SAI1_IRQHandler      		(void) __attribute__((weak,alias("Default_Handler")));
void SAI2_IRQHandler      		(void) __attribute__((weak,alias("Default_Handler")));
void QUADSPI_IRQHandler   		(void) __attribute__((weak,alias("Default_Handler")));
void CEC_IRQHandler       		(void) __attribute__((weak,alias("Default_Handler")));
void SPDIF_RX_IRQHandler  		(void) __attribute__((weak,alias("Default_Handler")));
void FMPI2C1_EV_IRQHandler		(void) __attribute__((weak,alias("Default_Handler")));
void FMPI2C1_ER_IRQHandler		(void) __attribute__((weak,alias("Default_Handler")));

uint32_t	Vectors[]  __attribute__ ((section (".isr_vector"))) =
{
	STACK_START,
	(uint32_t)Reset_Handler,
	(uint32_t)NMI_Handler				   ,
	(uint32_t)HardFault_Handler			,
	(uint32_t)MemManage_Handler			,
	(uint32_t)BusFault_Handler			,
	(uint32_t)UsageFault_Handler			,
	0,
	0,
	0,
	0,
    (uint32_t)SVC_Handler				   ,
    (uint32_t)DebugMon_Handler			,
	0,
    (uint32_t)PendSV_Handler				,
    (uint32_t)SysTick_Handler			   ,
    (uint32_t)WWDG_IRQHandler      		,
    (uint32_t)PVD_IRQHandler       		,
    (uint32_t)TAMP_STAMP_IRQHandler		,
    (uint32_t)RTC_WKUP_IRQHandler  		,
    (uint32_t)FLASH_IRQHandler     		,
    (uint32_t)RCC_IRQHandler       		,
    (uint32_t)EXTI0_IRQHandler     		,
    (uint32_t)EXTI1_IRQHandler     		,
    (uint32_t)EXTI2_IRQHandler     		,
    (uint32_t)EXTI3_IRQHandler     		,
    (uint32_t)EXTI4_IRQHandler     		,
    (uint32_t)DMA1_Stream0_IRQHandler    ,
    (uint32_t)DMA1_Stream1_IRQHandler    ,
    (uint32_t)DMA1_Stream2_IRQHandler    ,
    (uint32_t)DMA1_Stream3_IRQHandler    ,
    (uint32_t)DMA1_Stream4_IRQHandler    ,
    (uint32_t)DMA1_Stream5_IRQHandler    ,
    (uint32_t)DMA1_Stream6_IRQHandler    ,
    (uint32_t)ADC_IRQHandler             ,
    (uint32_t)CAN1_TX_IRQHandler         ,
    (uint32_t)CAN1_RX0_IRQHandler        ,
    (uint32_t)CAN1_RX1_IRQHandler        ,
    (uint32_t)CAN1_SCE_IRQHandler        ,
    (uint32_t)EXTI9_5_IRQHandler         ,
    (uint32_t)TIM1_BRK_TIM9_IRQHandler   ,
    (uint32_t)TIM1_UP_TIM10_IRQHandler   ,
    (uint32_t)TIM1_TRG_COM_TIM11_IRQHandl,
    (uint32_t)TIM1_CC_IRQHandler         ,
    (uint32_t)TIM2_IRQHandler            ,
    (uint32_t)TIM3_IRQHandler            ,
    (uint32_t)TIM4_IRQHandler            ,
    (uint32_t)I2C1_EV_IRQHandler         ,
    (uint32_t)I2C1_ER_IRQHandler         ,
    (uint32_t)I2C2_EV_IRQHandler         ,
    (uint32_t)I2C2_ER_IRQHandler         ,
    (uint32_t)SPI1_IRQHandler            ,
    (uint32_t)SPI2_IRQHandler            ,
    (uint32_t)USART1_IRQHandler          ,
    (uint32_t)USART2_IRQHandler          ,
    (uint32_t)USART3_IRQHandler          ,
    (uint32_t)EXTI15_10_IRQHandler       ,
    (uint32_t)RTC_Alarm_IRQHandler       ,
    (uint32_t)OTG_FS_WKUP_IRQHandler     ,
    (uint32_t)TIM8_BRK_TIM12_IRQHandler  ,
    (uint32_t)TIM8_UP_TIM13_IRQHandler   ,
    (uint32_t)TIM8_TRG_COM_TIM14_IRQHandl,
    (uint32_t)TIM8_CC_IRQHandler          ,
    (uint32_t)DMA1_Stream7_IRQHandler     ,
    (uint32_t)FMC_IRQHandler              ,
    (uint32_t)SDIO_IRQHandler             ,
    (uint32_t)TIM5_IRQHandler             ,
    (uint32_t)SPI3_IRQHandler             ,
    (uint32_t)UART4_IRQHandler       	    ,
    (uint32_t)UART5_IRQHandler       	    ,
    (uint32_t)TIM6_DAC_IRQHandler    	    ,
    (uint32_t)TIM7_IRQHandler        	    ,
    (uint32_t)DMA2_Stream0_IRQHandler	    ,
    (uint32_t)DMA2_Stream1_IRQHandler	    ,
    (uint32_t)DMA2_Stream2_IRQHandler	    ,
    (uint32_t)DMA2_Stream3_IRQHandler	    ,
    (uint32_t)DMA2_Stream4_IRQHandler	    ,
	0,
	0,
    (uint32_t)CAN2_TX_IRQHandler       	,
    (uint32_t)CAN2_RX0_IRQHandler      	,
    (uint32_t)CAN2_RX1_IRQHandler      	,
    (uint32_t)CAN2_SCE_IRQHandler      	,
    (uint32_t)OTG_FS_IRQHandler        	,
    (uint32_t)DMA2_Stream5_IRQHandler  	,
    (uint32_t)DMA2_Stream6_IRQHandler  	,
    (uint32_t)DMA2_Stream7_IRQHandler  	,
    (uint32_t)USART6_IRQHandler        	,
    (uint32_t)I2C3_EV_IRQHandler       	,
    (uint32_t)I2C3_ER_IRQHandler       	,
    (uint32_t)OTG_HS_EP1_OUT_IRQHandler	,
    (uint32_t)OTG_HS_EP1_IN_IRQHandler 	,
    (uint32_t)OTG_HS_WKUP_IRQHandler   	,
    (uint32_t)OTG_HS_IRQHandler        	,
    (uint32_t)DCMI_IRQHandler          	,
	0,
	0,
    (uint32_t)FPU_IRQHandler       		,
	0,
	0,
    (uint32_t)SPI4_IRQHandler      		,
	0,
	0,
    (uint32_t)SAI1_IRQHandler      		,
	0,
	0,
	0,
    (uint32_t)SAI2_IRQHandler      		,
    (uint32_t)QUADSPI_IRQHandler   		,
    (uint32_t)CEC_IRQHandler       		,
    (uint32_t)SPDIF_RX_IRQHandler  		,
    (uint32_t)FMPI2C1_EV_IRQHandler		,
    (uint32_t)FMPI2C1_ER_IRQHandler		
};