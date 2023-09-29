#ifndef _WARLOCK_H
#define _WARLOCK_H

#include <stdbool.h>
#include <stdint.h>

#include "static-texts.h"
#include "unicode-symbols.h"

// TODO: Move all settings to config.mk or so.
#define DEBUG

#ifdef DEBUG
#include <assert.h>
#endif

#define USE_UNICODE

#endif // _WARLOCK_H