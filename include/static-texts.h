#ifndef _WARLOCK_STATIC_TEXTS_H
#define _WARLOCK_STATIC_TEXTS_H

enum StringID
{
    STRING_MAIN_TITLE,
    STRING_PLAY_AGAIN,
    STRING_EXIT,

    // ... more strings
    STRING_COUNT
};

const char *englishStrings[STRING_COUNT] = {
    [STRING_MAIN_TITLE] = "Warlock",
    [STRING_PLAY_AGAIN] = "Press space to play again.",
    [STRING_EXIT] = "Press Esc to exit.",
    // ... more strings
};

static const char **currentLanguageStrings = englishStrings;

inline const char *getLocalizedString(enum StringID stringID)
{
    // Assuming currentLanguageStrings is defined and points to the desired table
    return currentLanguageStrings[stringID];
}

#endif // _WARLOCK_STATIC_TEXTS_H