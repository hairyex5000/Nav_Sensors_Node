#include "lib/serialib.h"
#include "lib/arduinojson.h"
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    serialib serial;
    if (serial.openDevice("COM3", 115200) != 1)
        return 1;

    serial.DTR(true);
    serial.RTS(false);

    ArduinoJson::JsonDocument latestInput;

    string newStr("");

    while (true)
    {
        char input;
        serial.readChar(&input, 500);

        if ((int)input == 2)
        {
            // printf("started\n");
        }
        else if ((int)input == 3)
        {
            ArduinoJson::deserializeJson(latestInput, newStr.c_str());
            ArduinoJson::serializeJsonPretty(latestInput, newStr);
            printf("ended: %s\n", newStr.c_str());
            newStr = "";
        }
        else
        {
            newStr += input;
        }
    }
    return 0;
}
