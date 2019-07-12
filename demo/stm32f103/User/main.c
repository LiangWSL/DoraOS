/**
  ******************************************************************************
  * @file    main.c
  * @author  jiejie
  * @version V1.0
  * @date    2018-xx-xx
  * @brief   main
  ******************************************************************************
  */ 
#include "include.h"
#include "task.h"
#include "queue.h"
#include <sem.h>
#include <mutex.h>
#include <event.h>

/**
  ******************************************************************
													   变量声明
  ******************************************************************
  */ 


DOS_TaskCB_t task = DOS_NULL;
DOS_TaskCB_t task2 = DOS_NULL;
DOS_TaskCB_t task1 = DOS_NULL;


Dos_Queue_t queue = DOS_NULL;
Dos_Sem_t sem = DOS_NULL;
Dos_Mutex_t mutex = DOS_NULL;
Dos_Event_t event = DOS_NULL;
/**
  ******************************************************************
														函数声明
  ******************************************************************
  */ 
  
static void BSP_Init(void);

void test_task(void *Parameter)
{
  dos_err ret;
//  dos_uint8 buff[20];
//  Dos_TaskSleep(1800);
////  Dos_TaskSleep(30);
//  Dos_EventWait(event, 1, WAIT_ANY_EVENT, DOS_WAIT_FOREVER - 1);
  
//  printf("task event end\n");
////  printf("task sem delete\n");
////  Dos_SemDelete(sem);
////  sem = DOS_NULL;
////  Dos_QueueDelete(queue);
////  queue = DOS_NULL;
//  printf("task sem start\n");
//  
//  Dos_SemWait(sem, 1000);
//  
//  printf("task sem end\n");
//  
//  printf("task queue start\n");
//  
//  Dos_QueueRead(queue,buff,10,5500);
//  
//  printf("task queue end\n");
//  printf("task sem start\n");
//  Dos_SemWait(sem, DOS_WAIT_FOREVER);
//  printf("task sem end\n");
  while(1)
  {
//    Dos_Interrupt_Disable();
    printf("task pend mutex\n");
//    Dos_Interrupt_Enable(0);
//    ret = Dos_MutexPend(mutex, DOS_WAIT_FOREVER);
//    Dos_Interrupt_Disable();
//    if(ret == DOS_OK)
//    {
//      printf("task runing\n");
//    }
//    else
//    {
//      printf("task err\n");
//    }
//    
////    Dos_Interrupt_Disable();
////    DOS_PRINT_DEBUG("ABC\n");
////    Dos_Interrupt_Enable(0);
////    Delay_ms(1000);
//    
//    printf("task post mutex\n");
//    Dos_Interrupt_Enable(0);
//    ret = Dos_MutexPost(mutex);
//    if(ret != DOS_OK)
//    {
//      Dos_Interrupt_Disable();
//      printf("task err\n");
//      Dos_Interrupt_Enable(0);
//    }
//    
    Dos_TaskSleep(3000);
    
  }
}
void test1_task(void *Parameter)
{
//  dos_uint8 buff[20] = "ASFASF";
//  
//  Dos_TaskSleep(1800);
  
//  Dos_EventWait(event, 2, WAIT_ANY_EVENT, 5000);
  
  Dos_EventSet(event, 5);
//  printf("task1 write queue1\n");
//  
////  Dos_TaskDelete(task);
//  Dos_QueueWrite(queue,buff,10,0);
//  
//  printf("task1 write queue2\n");
//  
////  Dos_TaskDelete(task);
//  Dos_QueueWrite(queue,buff,10,0);

//  printf("task1 write sem\n");
//  printf("task1 sem start\n");
//  Dos_SemPost(sem);
//  Dos_SemPost(sem);
//  printf("task1 sem end\n");
//  Dos_SemWait(sem, DOS_WAIT_FOREVER);
  while(1)
  {
//    Dos_Interrupt_Disable();
////    DOS_PRINT_DEBUG("123\n");
    printf("task1 runing\n");
//    Dos_Interrupt_Enable(0);
////    Delay_ms(1000);
    Dos_TaskSleep(2000);
  }
}
void test2_task(void *Parameter)
{
  dos_err ret;
//  Dos_TaskSleep(1800);
//  Dos_EventWait(event, 4, WAIT_ANY_EVENT, DOS_WAIT_FOREVER);
  
//  static uint32_t i;
//  printf("task2 event end\n");
//  Dos_SemWait(sem, DOS_WAIT_FOREVER);
//  printf("task2 sem end\n");
//  dos_uint8 buff[20];
//  
//  Dos_TaskSleep(1000);
//  
//  printf("task2 queue start\n");
//  
//  Dos_QueueRead(queue,buff,10,DOS_WAIT_FOREVER);

//  printf("task2 queue end\n");
//  Dos_TaskSleep(500);
//  
//  printf("task2 queue start1\n");
  while(1)
  {
//    Dos_Interrupt_Disable();
    printf("task2 pend mutex\n");
//    Dos_Interrupt_Enable(0);
//    ret = Dos_MutexPend(mutex, DOS_WAIT_FOREVER);
//    Dos_Interrupt_Disable();
//    if(ret == DOS_OK)
//    {
//      printf("task2 runing\n");
//    }
//    else
//    {
//      printf("task2 err\n");
//    }
//    Dos_Interrupt_Enable(0);
////    Dos_Interrupt_Disable();
////    DOS_PRINT_DEBUG("456\n");
////    Dos_Interrupt_Enable(0);
////    Delay_ms(1000);
//    
//    for(i=0;i<2000000;i++)
//		{
//			DOS_TASK_YIELD();
//		}
//    
//    Dos_Interrupt_Disable();
//    printf("task2 post mutex\n");
//    Dos_Interrupt_Enable(0);
//    
//    ret = Dos_MutexPost(mutex);
//    if(ret != DOS_OK)
//    {
//      Dos_Interrupt_Disable();
//      printf("task2 err\n");
//      Dos_Interrupt_Enable(0);
//    }

    Dos_TaskSleep(1000);
  }
}
/**
  ******************************************************************
  * @brief   主函数
  * @author  jiejie
  * @version V1.0
  * @date    2019-xx-xx
  ******************************************************************
  */ 
int main(void)
{
  dos_uint8 *p = DOS_NULL;
  dos_uint8 *p1 = DOS_NULL;
  dos_uint8 *p2 = DOS_NULL;
  dos_uint8 *p3 = DOS_NULL;
  BSP_Init();
  
  Dos_SystemInit();
  
  p = Dos_MemAlloc(16);
  p2 = Dos_MemAlloc(128);
  
  queue = Dos_QueueCreate(10,10);
  sem = Dos_BinarySem_Create(0);
  mutex = Dos_MutexCreate();
  event = Dos_EventCreate();
  
//  task = Dos_TaskCreate( "task",
//                  &test_task,
//                  DOS_NULL,
//                  512,
//                  2);
//  DOS_PRINT_DEBUG("&task = %#x",(dos_uint32)task);
//  DOS_PRINT_DEBUG("&task->StateItem = %#x",(dos_uint32)&(task->StateItem));
//  
//  task1 = Dos_TaskCreate( "task1",
//                &test1_task,
//                DOS_NULL,
//                512,
//                3);
//                
//  task2 = Dos_TaskCreate( "task2",
//                &test2_task,
//                DOS_NULL,
//                512,
//                4);
                
  p1 = Dos_MemAlloc(16);  
  p3 = Dos_MemAlloc(512);
  DOS_PRINT_DEBUG(" p = %x",(dos_uint32)p);
  DOS_PRINT_DEBUG(" p2 = %x",(dos_uint32)p2);
  DOS_PRINT_DEBUG(" p1 = %x",(dos_uint32)p1);
  DOS_PRINT_DEBUG(" p3 = %x",(dos_uint32)p3);

  
  Dos_MemFree(p1);
  p1=DOS_NULL;

  DOS_PRINT_DEBUG("----");
  
  Dos_MemFree(p3);
  p3=DOS_NULL; 
//  Dos_MemFree(p1);
//  Dos_MemFree(p2);
//  Dos_MemFree(p3);


  p1 = Dos_MemAlloc(16);
  p3 = Dos_MemAlloc(512);
//  p3 = Dos_MemAlloc(512);
//  p1 = Dos_MemAlloc(16);  
  DOS_PRINT_DEBUG(" p1 = %x",(dos_uint32)p1);
  DOS_PRINT_DEBUG(" p3 = %x",(dos_uint32)p3);
//  DOS_PRINT_DEBUG(" p = %x",(dos_uint32)p3);
//  DOS_PRINT_DEBUG(" p = %x",(dos_uint32)p1);
//  
//  Dos_MemFree(p);
//  Dos_MemFree(p1);
//  Dos_MemFree(p2);
//  Dos_MemFree(p3);
//  
  Dos_Start();
  
  while(1)                            
  {
        

  }
}



/**
  ******************************************************************
  * @brief   BSP_Init，用于所有板级初始化
  * @author  jiejie
  * @version V1.0
  * @date    2018-xx-xx
  ******************************************************************
  */ 
static void BSP_Init(void)
{
	/* LED 初始化 */
	LED_GPIO_Config();
	
#if USE_DWT_DELAY
	/* 内核精确定时器初始化 */
	CPU_TS_TmrInit();
#else
	/* 滴答定时器初始化 */
	SysTick_Init();
#endif
	
	/* 串口初始化 */
	USART_Config();
  
	/* 按键初始化 */
  Key_GPIO_Config();
  
//	/* 外部中断初始化 */
//	EXTI_Key_Config(); 
	
	/* 打印信息 */
	DOS_PRINT_INFO("welcome to learn jiejie stm32 library!\n");
	
}


/********************************END OF FILE***************************************/




