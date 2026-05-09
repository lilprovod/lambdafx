#ifndef CHORD_H
#define CHORD_H

#include <stddef.h>

#include "common.h"
#include "interval.h"
#include "io.h"

#define MAX_ITERATIONS 100

ChordResult chord_method(const InputData* data, const Interval* interval);

#endif