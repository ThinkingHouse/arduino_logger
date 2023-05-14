/*!
 *  \file      logger.cpp
 *
 *  \brief     Реализация класса логгера
 *
 *  \detailed  Позволяет выводить различную отладочную информацию
 *
 *  \author    Андрей Алексеев <andrey@thinking-house.ru>
 *
 *  \copyright Лаборатория Умного Дома (ИП Алексеев А.П. ИНН 780725728171), 2019. Все права защищены.
 */

//! Подключение заголовочных файлов
#include "arduino_logger.h"
#include <SoftwareSerial.h>

//! Макроопределения

//! Локальные данные
int8_t serial_tx_pin = 0;
int8_t serial_rx_pin = 0;
int32_t serial_baund = 0; 
int8_t spi_sck_pin = 0;
int8_t spi_mosi_pin = 0;
int8_t spi_miso_pin = 0;
int32_t sd_card_size = 0;

log_out_type_t output_type = LOG_TO_NONE;

bool isLogEnable = true;

//! Локальные функции

String get_time_from_start()
{
  String temp = String(millis());
  for(int i = 0; i < 10 - temp.length(); i++)
  {
      temp += " ";
  }
  return temp;
}

void send_to_serial_1(String mess)
{
  Serial.println(get_time_from_start() + String(" ::: ") + mess);
}

//! Глобальные функции
bool logInit()
{
    bool result = true;
    output_type = LOG_TO_SERIAL;
    serial_baund = 115200;
    
    Serial.begin(serial_baund);
    
    return result;
}

bool logInit(int32_t serial_baund)
{
    bool result = true;
    output_type = LOG_TO_SERIAL;

    Serial.begin(serial_baund);
    
    return result;
}

bool logInit(log_out_type_t output, int serial_tx_pin, int serial_rx_pin, int32_t serial_baund)
{
    bool result = true;
    output_type = output;
    serial_baund = serial_baund;

    if ( output_type == LOG_TO_SERIAL )
    {
        Serial.begin(serial_baund);
    }
    else if ( output_type == LOG_TO_SERIAL_1 )
    {
        Serial1.begin(serial_baund);
    }
    else if ( output_type == LOG_TO_SOFTWARE_SERIAL )
    {
      
    }
    else
    {
        result = false;
    }
    
    return result;
}

bool logInit(log_out_type_t output, int spi_sck_pin, int spi_mosi_pin, int spi_miso_pin, int sd_card_size)
{
    bool result = true;

    return result;
}

void logInfoSend(String format, ...)
{
    if (!isLogEnable)
    {
        return;
    }

    va_list ap;                     //Указатель на список параметров
    va_start(ap,format);                 //Настроились на список параметров
    String output_message = "INFO  ::: ";
    for (const char *p=format.c_str();*p;p++)            //
    {
        if (*p=='%')                    //Если встретится символ %
        {
            p++;
            if (*p=='d') 
            {
                    int ival=va_arg(ap,int);      //Если это символ d, то значит параметр int
                    output_message += String(ival);        //Выводим параметр типа int на экран
            }  
            else if (*p=='s')
            {
                    char* cval = va_arg(ap, char*);
                    output_message += String(cval);        //Выводим параметр типа char на экран

            }
            else if (*p=='f')
            {
                    float fval = va_arg(ap, float);
                    output_message += String(fval);        //Выводим параметр типа char на экран

            }
        }
        else 
            output_message += *p;
    }
    va_end(ap); //Завершаем работу с макрокомандами

    send_to_serial_1(output_message);
}

void logInfoSend(char *format, ...)
{
    if (!isLogEnable)
    {
        return;
    }

    va_list ap;                     //Указатель на список параметров
    va_start(ap,format);                 //Настроились на список параметров
    String output_message = "INFO  ::: ";
    for (char *p=format;*p;p++)            //
    {
        if (*p=='%')                    //Если встретится символ %
        {
            p++;
            if (*p=='d') 
            {
                    int ival=va_arg(ap,int);      //Если это символ d, то значит параметр int
                    output_message += String(ival);        //Выводим параметр типа int на экран
            }  
            else if (*p=='s')
            {
                    char* cval = va_arg(ap, char*);
                    output_message += String(cval);        //Выводим параметр типа char на экран

            }
            else if (*p=='f')
            {
                    float fval = va_arg(ap, float);
                    output_message += String(fval);        //Выводим параметр типа char на экран

            }
        }
        else 
            output_message += *p;
    }
    va_end(ap); //Завершаем работу с макрокомандами

    send_to_serial_1(output_message);
}

void logWarningSend(char *format, ...)
{
    if (!isLogEnable)
    {
        return;
    }

    va_list ap;                     //Указатель на список параметров
    va_start(ap,format);                 //Настроились на список параметров
    String output_message = "WARN  ::: ";
    for (char *p=format;*p;p++)            //
    {
        if (*p=='%')                    //Если встретится символ %
        {
            p++;
            if (*p=='d') 
            {
                    int ival=va_arg(ap,int);      //Если это символ d, то значит параметр int
                    output_message += String(ival);        //Выводим параметр типа int на экран
            }  
            else if (*p=='s')
            {
                    char* cval = va_arg(ap, char*);
                    output_message += String(cval);        //Выводим параметр типа char на экран

            }
            else if (*p=='f')
            {
                    float fval = va_arg(ap, float);
                    output_message += String(fval);        //Выводим параметр типа char на экран

            }
        }
        else 
            output_message += *p;
    }
    va_end(ap); //Завершаем работу с макрокомандами

    send_to_serial_1(output_message);
}

void logErrorSend(char *format, ...)
{
    if (!isLogEnable)
    {
        return;
    }
    
    va_list ap;                     //Указатель на список параметров
    va_start(ap,format);                 //Настроились на список параметров
    String output_message = "ERROR ::: ";
    for (char *p=format;*p;p++)            //
    {
        if (*p=='%')                    //Если встретится символ %
        {
            p++;
            if (*p=='d') 
            {
                    int ival=va_arg(ap,int);      //Если это символ d, то значит параметр int
                    output_message += String(ival);        //Выводим параметр типа int на экран
            }  
            else if (*p=='s')
            {
                    char* cval = va_arg(ap, char*);
                    output_message += String(cval);        //Выводим параметр типа char на экран

            }
            else if (*p=='f')
            {
                    float fval = va_arg(ap, float);
                    output_message += String(fval);        //Выводим параметр типа char на экран

            }
        }
        else 
            output_message += *p;
    }
    va_end(ap); //Завершаем работу с макрокомандами

    send_to_serial_1(output_message);
}

void logOff()
{
    isLogEnable = false;
}

void logOn()
{
    isLogEnable = true;
}