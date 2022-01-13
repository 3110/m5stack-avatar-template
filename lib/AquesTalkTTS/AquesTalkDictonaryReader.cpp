#include "AquesTalkDictionaryReader.h"

#if defined(ENABLE_SD_DIC) || defined(ENABLE_SPIFFS_DIC)

DictionaryReader::DictionaryReader(void) {
}

DictionaryReader::~DictionaryReader(void) {
}

size_t DictionaryReader::open(const char* dic) {
#if defined(ENABLE_SPIFFS_DIC)
    if (!SPIFFS.begin(true)) {
        return 0;
    }
    this->_file = SPIFFS.open(dic, "r");
#endif
#if defined(ENABLE_SD_DIC)
    this->_file = SD.open(dic, "r");
#endif
    if (this->_file) {
        return ADDR_ORG;
    } else {
        return 0;
    }
}

void DictionaryReader::close(void) {
    if (this->_file) {
        this->_file.close();
    }
}

size_t DictionaryReader::read(size_t pos, size_t size, void* buf) {
    this->_file.seek(pos - ADDR_ORG);
    return this->_file.read(reinterpret_cast<uint8_t*>(buf), size);
}

#endif
