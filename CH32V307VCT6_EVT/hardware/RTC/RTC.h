#ifndef __RTC_H
#define __RTC_H
#include "debug.h"

//时间结构体
typedef struct
{
    vu8 hour;
    vu8 min;
    vu8 sec;
    //公历年月日周
    vu16 w_year;
    vu8  w_month;
    vu8  w_date;
    vu8  week;
}_calendar_obj;
extern _calendar_obj calendar;
void RCC_Configuration(void);
u8 RTC_Get_Week(u16 year, u8 month, u8 day);
void RTC_Init(void);
u8 RTC_Set(u16 year,u8 mon,u8 day,u8 hour,u8 min,u8 sec);
u8 RTC_Get(void);
#endif
