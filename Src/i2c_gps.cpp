#define I2CBUS 1
#define GPS_ADDR 0x42

#include <cstdio>
#include <string>

#include "i2c_access.h"

int main(int argc, char *argv[])
{
    i2c_access *i2c;

    try {
        char buf[256];

        i2c = new i2c_access();
        i2c->init(I2CBUS, GPS_ADDR);

        while(1) {
            i2c->readblock(buf, sizeof(buf));
            printf("%s", buf);
        }
    } catch(std::bad_alloc ex) {
        fprintf(stderr, "Error: allocation failed : %s\n", ex.what());
        return -1;
    } catch(std::string &err_mes) {
        fprintf(stderr, "Error: %s\n", err_mes.c_str());
        return -1;
    }

    return 0;
}
