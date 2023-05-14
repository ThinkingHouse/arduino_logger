/*!
 *  \file      logger.h
 *
 *  \brief     Заголовочный файл класса логгера
 *
 *  \detailed  Позволяет выводить различную отладочную информацию
 *
 *  \author    Андрей Алексеев <andrey@thinking-house.ru>
 *
 *  \copyright Лаборатория Умного Дома (ИП Алексеев А.П. ИНН 780725728171), 2019. Все права защищены.
 */
 
#ifndef LOGGER_H
#define LOGGER_H

//! Подключение заголовочных файлов
#include "Arduino.h"

//! Макроопределения

//! Глобальные типы данных
typedef enum
{
    LOG_LEVEL_NONE,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR
} log_level_t;

typedef enum
{
    LOG_TO_NONE,
    LOG_TO_SERIAL,
    LOG_TO_SERIAL_1,
    LOG_TO_SD_CARD
} log_out_type_t;

bool logInit();  
bool logInit(int32_t serial_baund);
bool logInit(log_out_type_t output, int serial_tx_pin, int serial_rx_pin, int32_t serial_baund);
bool logInit(log_out_type_t output, int spi_sck_pin, int spi_mosi_pin, int spi_miso_pin, int sd_card_size);
void logInfoSend(String format, ...);
void logInfoSend(char *format, ...);
void logWarningSend(char *format, ...);
void logErrorSend(char *format, ...);
void logOff();
void logOn();
#endif
