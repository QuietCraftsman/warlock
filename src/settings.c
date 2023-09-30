#include "settings.h"

int loadSettings(const char *filename, void *settings, struct SettingData *settingsData, size_t settingsDataSize)
{
    FILE *file = fopen(filename, "r");
    if (!file)
        return 0;

    // TODO: Reconsider these size specifications.
    char line[256];
    char key[256];
    char value[256];

    while (fgets(line, sizeof(line), file))
    {
        if (sscanf(line, "%255[^=]=%255s", key, value) == 2)
        {
            for (size_t i = 0; i < settingsDataSize; i++)
            {
                if (strcmp(key, settingsData[i].key) == 0)
                {
                    switch (settingsData[i].type)
                    {
                        case SETTING_STRING:
                            strncpy((char *)settings + settingsData[i].offset, value, settingsData[i].size - 1);
                            ((char *)settings + settingsData[i].offset)[settingsData[i].size - 1] = '\0';
                            break;
                        case SETTING_INT:
                            *((int *)((char *)settings + settingsData[i].offset)) = atoi(value);
                            break;
                    }

                    break;
                }
            }
        }
    }

    fclose(file);
    return 1;
}