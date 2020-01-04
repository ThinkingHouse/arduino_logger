#include <logger.h>

void setup() 
{
    // Init logger to Serial on band 230400
    logInit(230400);

    logInfoSend("Logger is init");
}

void loop() 
{
    static int i = 0;

    // info log
    logInfoSend("INFO log %d", i);

    // warning log
    logWarningSend("INFO log %d", i);

    // error log
    logErrorSend("INFO log %d", i);

    delay(5000);
}
