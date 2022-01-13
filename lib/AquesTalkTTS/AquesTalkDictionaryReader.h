#pragma once

#if defined(ENABLE_SD_DIC) || defined(ENABLE_SPIFFS_DIC)

#include <FS.h>
#ifdef ENABLE_SPIFFS_DIC
#include <SPIFFS.h>
#endif
#ifdef ENABLE_SD_DIC
#include <SD.h>
#endif

class DictionaryReader {
public:
    static const size_t ADDR_ORG = 0x10001000;

    DictionaryReader(void);
    virtual ~DictionaryReader(void);

    virtual size_t open(const char* dic);
    virtual void close(void);
    virtual size_t read(size_t pos, size_t size, void* buf);

private:
    File _file;
};

#endif