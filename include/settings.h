#ifndef _WARLOCK_SETTINGS_H
#define _WARLOCK_SETTINGS_H

#include <stdio.h>
#include <string.h>

enum SettingType
{
    SETTING_INT,
    SETTING_STRING
};

struct SettingData
{
    const char *key;
    size_t offset;
    size_t size;
    enum SettingType type;
};

struct AudioSettings
{
    int soundVolume;
    int musicVolume;
};

struct SettingData audioSettingsData[] = 
{
    {"soundVolume", offsetof(struct AudioSettings, soundVolume), sizeof(int), SETTING_INT},
    {"musicVolume", offsetof(struct AudioSettings, musicVolume), sizeof(int), SETTING_INT}
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

int loadSettings(const char *filename, void *settings, struct SettingData *settingsData, size_t settingsDataSize);

#endif // _WARLOCK_SETTINGS_H