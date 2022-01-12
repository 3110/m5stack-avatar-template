# M5Stack-AvatarでAquesTalkを使ってリップシンクをするテンプレート

[M5Stack-Avatar](https://github.com/meganetaaan/m5stack-avatar)でAquesTalkでリップシンクをするテンプレートです。Windows 11で動くVSCodeにPlatformIO拡張機能を入れた環境で動作確認をしています。

## 準備

* [AquesTalk ESP32](https://www.a-quest.com/download.html#a-etc)から[aquestalk-esp32_0221.zip](https://www.a-quest.com/archive/package/aquestalk-esp32_0221.zip)ダウンロードする。
* ZIPファイルを適当な場所に展開し，以下を`lib/AquesTalkTTS`にコピーする。  
  * `src/aquestalk.h`
  * `src/esp32/libaquestalk.a`
* 購入したライセンスキーを`src/main.cpp`の`AQUESTALK_KEY`に記入する。  
  ライセンスキーを指定しなかった場合は試用版になり，ナ行とマ行がすべてヌと発声されます。

## 参考

* [「AquesTalk-ESP32 Ver.2.0」を使う](http://blog-yama.a-quest.com/?eid=970195)
* [AquesTalk-ESPを簡単に使うクラス(プログラム)](http://blog-yama.a-quest.com/?eid=970191)
* [AquesTalk ESP32 使用ライセンス](https://store.a-quest.com/items/10524168)  
  税込1,980円。ライセンスはMACアドレスに紐づく形式になっている。
