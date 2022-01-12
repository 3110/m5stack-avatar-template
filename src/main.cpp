#include <AquesTalkTTS.h>
#include <Avatar.h>
#include <M5Stack.h>
#include <tasks/LipSync.h>

using namespace m5avatar;

const char* AQUESTALK_KEY = "XXXX-XXXX-XXXX-XXXX";
Avatar avatar;

void setup() {
    M5.begin();
    avatar.init();

    TTS.create(AQUESTALK_KEY);
    avatar.init();
    avatar.addTask(lipSync, "lipSync");
}

void loop() {
    M5.update();
    if (M5.BtnA.wasPressed()) {
        TTS.play("konnichiwa", 80);
    }
}