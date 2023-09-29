#include "settings.h"

int loadSettings(const char *filename, struct GameSettings *settings)
{
    FILE *file = fopen(filename, "r");

    if (!file)
    {
        return 0;
    }

    char line[256];
    struct StorageSettings *currentStorage = NULL;
    struct AudioSettings *currentAudio = NULL;
    struct DisplaySettings *currentDisplay = NULL;

    while (fgets(line, sizeof(line), file))
    {
        char key[256];
        int value;

        if (sscanf(line, "[%255[^]]", key) == 1)
        {
            // New section.
            if (strcmp(key, "audio") == 0)
            {
                currentAudio = &settings->audioSettings;
            }
            else if (strcmp(key, "display") == 0)
            {
                currentDisplay = &settings->displaySettings;
            }
            else if (strcmp(key, "storage") == 0)
            {
                currentStorage = &settings->storageSettings;
            }
        }
        else if (sscanf(line, "%255[^=]=%d", key, &value) == 2)
        {
            // Key-value pair.
            if (currentAudio)
            {
                if (strcmp(key, "musicVolume") == 0)
                {
                    currentAudio->musicVolume = value;
                }
                else if (strcmp(key, "soundVolume") == 0)
                {
                    currentAudio->soundVolume = value;
                }
            }
            else if (currentDisplay)
            {
                        }
        }
    }

    fclose(file);
    return 1;
}