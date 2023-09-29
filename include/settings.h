#ifndef _WARLOCK_SETTINGS_H
#define _WARLOCK_SETTINGS_H

#include <stdio.h>
#include <string.h>

struct AudioSettings
{
    int soundVolume;
    int musicVolume;
};

struct DisplaySettings
{
    int screenWidth;
    int screenHeight;
};

struct StorageSettings
{
    char lastGameName[32];
    char lastRecordingName[32];
    char saveFileSuffix[16];
    char recordingFileSuffix[16];
    char annotationSuffix[4];
    char rngLogFileName[32];
    char screenshotSuffix[4];
};

struct GameSettings
{
    struct AudioSettings audioSettings;
    struct DisplaySettings displaySettings;
    struct StorageSettings storageSettings;
};

int loadSettings(const char *filename, GameSettings *settings);

#endif // _WARLOCK_SETTINGS_H