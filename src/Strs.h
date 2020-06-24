// cobject -- implements object in c
// Copyright (C) 2020  Arch Strange <arch.strange@foxmail.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef __COBJECT_SRC_STRS_H
#define __COBJECT_SRC_STRS_H
#include <stdlib.h>
#include "Str.h"

typedef struct Strs *Strs;

Strs Strs_new(size_t size);

Strs Strs_newRef(Strs self);

void Strs_freeRef(Strs self);

void Strs_set(Strs self, size_t index, Str str);

Str Strs_get(Strs self, size_t index);

#endif
