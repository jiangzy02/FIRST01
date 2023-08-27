/**
 ****************************************************************************************************
 * @file        atim.h
 * @author      ����ԭ���Ŷ�(ALIENTEK)
 * @version     V1.3
 * @date        2020-04-21
 * @brief       �߼���ʱ�� ��������
 * @license     Copyright (c) 2020-2032, �������������ӿƼ����޹�˾
 ****************************************************************************************************
 * @attention
 *
 * ʵ��ƽ̨:����ԭ�� STM32F103������
 * ������Ƶ:www.yuanzige.com
 * ������̳:www.openedv.com
 * ��˾��ַ:www.alientek.com
 * �����ַ:openedv.taobao.com
 *
 * �޸�˵��
 * V1.0 20200421
 * ��һ�η���
 * V1.1 20200421
 * 1, ����atim_timx_comp_pwm_init����, ʵ������Ƚ�ģʽPWM�������
 * V1.2 20200421
 * 1, ����atim_timx_cplm_pwm_init����
 * 2, ����atim_timx_cplm_pwm_set����
 * V1.3 20200421
 * 1, ����atim_timx_pwmin_chy_process����
 * 2, ����atim_timx_pwmin_chy_init����
 * 3, ����atim_timx_pwmin_chy_restart�Ⱥ���
 *
 ****************************************************************************************************
 */

#ifndef __ATIM_H
#define __ATIM_H

#include "./SYSTEM/sys/sys.h"

/******************************************************************************************/
/* �߼���ʱ�� ���� */

  /* TIMX ���ָ������PWM ���� 
 * ���������PWMͨ��PA8(TIM1_CH1)���, ���� ����TIM1_CH1����LED0������, ����һ�α�ʾһ��PWM��
 * Ĭ��ʹ�õ���TIM1_CH1.
 * ע��: ͨ���޸��⼸���궨��, ����֧��TIM1/TIM8��ʱ��, ����һ��IO�����ָ��������PWM
 */
#define ATIM_TIMX_NPWM_CHY_GPIO_PORT            GPIOA
#define ATIM_TIMX_NPWM_CHY_GPIO_PIN             GPIO_PIN_8
#define ATIM_TIMX_NPWM_CHY_GPIO_CLK_ENABLE()    do{  __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)   /* PA��ʱ��ʹ�� */

#define ATIM_TIMX_NPWM                          TIM1
#define ATIM_TIMX_NPWM_IRQn                     TIM1_UP_IRQn
#define ATIM_TIMX_NPWM_IRQHandler               TIM1_UP_IRQHandler
#define ATIM_TIMX_NPWM_CHY                      TIM_CHANNEL_1                               /* ͨ��Y,  1<= Y <=4 */
#define ATIM_TIMX_NPWM_CHY_CCRX                 ATIM_TIMX_NPWM->CCR1                        /* ͨ��Y������ȽϼĴ��� */
#define ATIM_TIMX_NPWM_CHY_CLK_ENABLE()         do{ __HAL_RCC_TIM1_CLK_ENABLE(); }while(0)  /* TIM1 ʱ��ʹ�� */

/* TIMX ����Ƚ�ģʽ ���� 
 * ����ͨ��TIM8������Ƚ�ģʽ,����PC6,PC7,PC8,PC9���4·PWM,ռ�ձ�50%,����ÿһ·PWM֮�����λ��Ϊ25%
 * �޸�CCRx�����޸���λ.
 * Ĭ�������TIM1
 * ע��: ͨ���޸���Щ�궨��,����֧��TIM1/TIM8����һ����ʱ��,����һ��IO��ʹ������Ƚ�ģʽ,���PWM
 */
#define ATIM_TIMX_COMP_CH1_GPIO_PORT            GPIOC
#define ATIM_TIMX_COMP_CH1_GPIO_PIN             GPIO_PIN_6
#define ATIM_TIMX_COMP_CH1_GPIO_CLK_ENABLE()    do{ __HAL_RCC_GPIOC_CLK_ENABLE(); }while(0)   /* PC��ʱ��ʹ�� */

#define ATIM_TIMX_COMP_CH2_GPIO_PORT            GPIOC
#define ATIM_TIMX_COMP_CH2_GPIO_PIN             GPIO_PIN_7
#define ATIM_TIMX_COMP_CH2_GPIO_CLK_ENABLE()    do{ __HAL_RCC_GPIOC_CLK_ENABLE(); }while(0)   /* PC��ʱ��ʹ�� */

#define ATIM_TIMX_COMP_CH3_GPIO_PORT            GPIOC
#define ATIM_TIMX_COMP_CH3_GPIO_PIN             GPIO_PIN_8
#define ATIM_TIMX_COMP_CH3_GPIO_CLK_ENABLE()    do{ __HAL_RCC_GPIOC_CLK_ENABLE(); }while(0)   /* PC��ʱ��ʹ�� */

#define ATIM_TIMX_COMP_CH4_GPIO_PORT            GPIOC
#define ATIM_TIMX_COMP_CH4_GPIO_PIN             GPIO_PIN_9
#define ATIM_TIMX_COMP_CH4_GPIO_CLK_ENABLE()    do{ __HAL_RCC_GPIOC_CLK_ENABLE(); }while(0)   /* PC��ʱ��ʹ�� */

#define ATIM_TIMX_COMP                          TIM8            
#define ATIM_TIMX_COMP_CH1_CCRX                 ATIM_TIMX_COMP->CCR1                          /* ͨ��1������ȽϼĴ��� */
#define ATIM_TIMX_COMP_CH2_CCRX                 ATIM_TIMX_COMP->CCR2                          /* ͨ��2������ȽϼĴ��� */
#define ATIM_TIMX_COMP_CH3_CCRX                 ATIM_TIMX_COMP->CCR3                          /* ͨ��3������ȽϼĴ��� */
#define ATIM_TIMX_COMP_CH4_CCRX                 ATIM_TIMX_COMP->CCR4                          /* ͨ��4������ȽϼĴ��� */
#define ATIM_TIMX_COMP_CLK_ENABLE()             do{ __HAL_RCC_TIM8_CLK_ENABLE(); }while(0)    /* TIM8 ʱ��ʹ�� */


/* TIMX �������ģʽ ���� 
 * �������û���������Ӳ������, CHY���������, CHYN���������
 * �޸�CCRx�����޸�ռ�ձ�.
 * Ĭ�������TIM1
 * ע��: ͨ���޸���Щ�궨��,����֧��TIM1/TIM8��ʱ��, ����һ��IO���������PWM(ǰ���Ǳ����л����������)
 */

/* ���ͨ������ */
#define ATIM_TIMX_CPLM_CHY_GPIO_PORT            GPIOA
#define ATIM_TIMX_CPLM_CHY_GPIO_PIN             GPIO_PIN_8
#define ATIM_TIMX_CPLM_CHY_GPIO_CLK_ENABLE()    do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)   /* PA��ʱ��ʹ�� */

/* �������ͨ������ */
#define ATIM_TIMX_CPLM_CHYN_GPIO_PORT           GPIOB
#define ATIM_TIMX_CPLM_CHYN_GPIO_PIN            GPIO_PIN_13
#define ATIM_TIMX_CPLM_CHYN_GPIO_CLK_ENABLE()   do{ __HAL_RCC_GPIOB_CLK_ENABLE(); }while(0)   /* PB��ʱ��ʹ�� */

/* ɲ���������� */
#define ATIM_TIMX_CPLM_BKIN_GPIO_PORT           GPIOB
#define ATIM_TIMX_CPLM_BKIN_GPIO_PIN            GPIO_PIN_12
#define ATIM_TIMX_CPLM_BKIN_GPIO_CLK_ENABLE()   do{ __HAL_RCC_GPIOE_CLK_ENABLE(); }while(0)   /* PB��ʱ��ʹ�� */

/* �������ʹ�õĶ�ʱ�� */
#define ATIM_TIMX_CPLM                          TIM1            
#define ATIM_TIMX_CPLM_CHY                      TIM_CHANNEL_1            
#define ATIM_TIMX_CPLM_CHY_CCRY                 ATIM_TIMX_CPLM->CCR1        
#define ATIM_TIMX_CPLM_CLK_ENABLE()             do{ __HAL_RCC_TIM1_CLK_ENABLE(); }while(0)    /* TIM1 ʱ��ʹ�� */

 /* TIMX PWM����ģʽ ���� 
 * ��������벶��ʹ�ö�ʱ��TIM1_CH1,����WK_UP����������
 * Ĭ�������TIM1/TIM8�ȸ߼���ʱ�� 
 * ע��: ͨ���޸��⼸���궨��,����֧��TIM1~TIM8����һ����ʱ����ͨ��1/ͨ��2
 */
#define ATIM_TIMX_PWMIN_CHY_GPIO_PORT           GPIOC
#define ATIM_TIMX_PWMIN_CHY_GPIO_PIN            GPIO_PIN_6
#define ATIM_TIMX_PWMIN_CHY_GPIO_CLK_ENABLE()   do{ __HAL_RCC_GPIOC_CLK_ENABLE(); }while(0)   /* PC��ʱ��ʹ�� */

#define ATIM_TIMX_PWMIN                         TIM8                       
#define ATIM_TIMX_PWMIN_IRQn                    TIM8_UP_IRQn
#define ATIM_TIMX_PWMIN_IRQHandler              TIM8_UP_IRQHandler
#define ATIM_TIMX_PWMIN_CHY                     TIM_CHANNEL_1
#define ATIM_TIMX_PWMIN_CHY_CLK_ENABLE()        do{ __HAL_RCC_TIM8_CLK_ENABLE(); }while(0)  /* TIM8 ʱ��ʹ�� */

 /* TIM1 / TIM8 �ж����Ĳ����жϷ�����,��Ҫ��������,����TIM2~5��,����Ҫ���¶��� */
#define ATIM_TIMX_PWMIN_CC_IRQn                 TIM8_CC_IRQn
#define ATIM_TIMX_PWMIN_CC_IRQHandler           TIM8_CC_IRQHandler

/******************************************************************************************/

void atim_timx_pwm_chy_init(uint16_t arr, uint16_t psc);    /* �߼���ʱ�� PWM��ʼ������ */
void atim_timx_npwm_chy_init(uint16_t arr, uint16_t psc);   /* �߼���ʱ�� ���ָ������PWM��ʼ������ */
void atim_timx_npwm_chy_set(uint32_t npwm);                 /* �߼���ʱ�� �������PWM�ĸ��� */
void atim_timx_comp_pwm_init(uint16_t arr, uint16_t psc);   /* �߼���ʱ�� ����Ƚ�ģʽ���PWM ��ʼ������ */
void atim_timx_cplm_pwm_init(uint16_t arr, uint16_t psc);   /* �߼���ʱ�� ������� ��ʼ������ */
void atim_timx_cplm_pwm_set(uint16_t ccr, uint8_t dtg);     /* �߼���ʱ�� ������� ��������Ƚ�ֵ & ����ʱ�� */
void atim_timx_pwmin_chy_init(void);                        /* �߼���ʱ�� PWM����ģʽ��ʼ�� */
void atim_timx_pwmin_chy_restart(void);                     /* �߼���ʱ�� ����PWM����ģʽ��� */

#endif
















