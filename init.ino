# Code for Main

#include config.ino
#include config_output.ino

#ifdef enable_rtc
  #include rtc.ino
#endif

#ifdef enable_sdcard
  #include sdcard.ino
#endif

#ifdef enable_wifi
  #include wifi.ino

  #ifdef enable_ntp
    #include rtc.ino
  #endif

  #ifdef enable_webserver
    #include webserver.ino
  #endif
#endif
