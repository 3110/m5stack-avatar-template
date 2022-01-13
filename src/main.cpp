#include <AquesTalkTTS.h>
#include <Avatar.h>

#if defined(TARGET_M5CORE2)
#include <M5Core2.h>
#elif defined(TARGET_M5BASIC)
#include <M5Stack.h>
#endif

const bool ENABLE_LCD = true;
const bool ENABLE_SD = true;
const bool ENABLE_SERIAL = true;
const bool ENABLE_I2C = false;  // default: false

#if defined(TARGET_M5CORE2) || defined(TARGET_M5BASIC)
#define M5_BEGIN() M5.begin(ENABLE_LCD, ENABLE_SD, ENABLE_SERIAL, ENABLE_I2C)
#endif

#include <tasks/LipSync.h>

using namespace m5avatar;

const char* AQUESTALK_KEY = "XXXX-XXXX-XXXX-XXXX";
Avatar avatar;

void setup() {
    M5_BEGIN();
#if defined(TARGET_M5CORE2)
    M5.Axp.SetSpkEnable(true);
#endif
    avatar.init();

    TTS.createK(AQUESTALK_KEY);
    // TTS.create(AQUESTALK_KEY);
    avatar.init();
    avatar.addTask(lipSync, "lipSync");
}

void loop() {
    M5.update();
    if (M5.BtnA.wasPressed()) {
        TTS.playK("おはよう", 80);
        // TTS.play("konnichiwa", 80);
    }
}