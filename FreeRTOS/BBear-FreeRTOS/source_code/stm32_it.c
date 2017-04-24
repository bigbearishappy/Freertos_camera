

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stm32_it.h"

void usartDmaTxISR(int port);
void usartDmaRxISR(int port);
void usartISR(int port);
void USB_Istr(void);


/******************************************************************************/
/*            Cortex-M Processor Exceptions Handlers                         */
/******************************************************************************/

/*******************************************************************************
* Function Name  : NMI_Handler
* Description    : This function handles NMI exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NMI_Handler(void)
{
}

/*******************************************************************************
* Function Name  : HardFault_Handler
* Description    : This function handles Hard Fault exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/*******************************************************************************
* Function Name  : MemManage_Handler
* Description    : This function handles Memory Manage exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/*******************************************************************************
* Function Name  : BusFault_Handler
* Description    : This function handles Bus Fault exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/*******************************************************************************
* Function Name  : UsageFault_Handler
* Description    : This function handles Usage Fault exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/*******************************************************************************
* Function Name  : SVC_Handler
* Description    : This function handles SVCall exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SVC_Handler(void)
{
}

/*******************************************************************************
* Function Name  : DebugMon_Handler
* Description    : This function handles Debug Monitor exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DebugMon_Handler(void)
{
}

/*******************************************************************************
* Function Name  : PendSV_Handler
* Description    : This function handles PendSVC exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void PendSV_Handler(void)
{
}

/*******************************************************************************
* Function Name  : SysTick_Handler
* Description    : This function handles SysTick Handler.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SysTick_Handler(void)
{
}

/*******************************************************************************
* Function Name  : USB_IRQHandler
* Description    : This function handles USB Low Priority interrupts
*                  requests.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
/*
void USB_LP_CAN1_RX0_IRQHandler(void)
{
	USB_Istr();
}
*/

/*******************************************************************************
* Function Name  : USB_FS_WKUP_IRQHandler
* Description    : This function handles USB WakeUp interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/

void USBWakeUp_IRQHandler(void)
{
}

/******************************************************************************/
/*                 STM32 Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32xxx.s).                                            */
/******************************************************************************/

/*******************************************************************************
* Function Name  : PPP_IRQHandler
* Description    : This function handles PPP interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
/*void PPP_IRQHandler(void)
{
}*/
	
void  DMA1_Channel4_IRQHandler(void)
{
	usartDmaTxISR(1);
}

void  DMA1_Channel5_IRQHandler(void)
{
	usartDmaRxISR(1);
}

void USART1_IRQHandler(void)
{
	usartISR(1);
}


void  DMA1_Channel7_IRQHandler(void)
{
	usartDmaTxISR(2);
}

void  DMA1_Channel6_IRQHandler(void)
{
	usartDmaRxISR(2);
}

void USART2_IRQHandler(void)
{
	usartISR(2);
}

/*
void  DMA1_Channel2_IRQHandler(void)
{
	usartDmaTxISR(3);
}

void  DMA1_Channel3_IRQHandler(void)
{
	usartDmaRxISR(3);
}

void USART3_IRQHandler(void)
{
	usartISR(3);
}
*/
/*
void spiRxIsr(void);
void spiTxIsr(void);
void spiSynchIsr(void);
void DMA1_Channel2_IRQHandler(void)
{
	spiRxIsr();
}

//TX 
void DMA1_Channel3_IRQHandler(void)
{
	spiTxIsr();
}

void EXTI3_IRQHandler(void)
{
	spiSynchIsr();
}
*/


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

