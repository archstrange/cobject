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

#include "Strs.h"
#include "co.h"

struct Strs {
	struct CO CO;

	Str *ptr;
	size_t size;
};

Strs Strs_new(size_t size)
{
	Strs self = CO_NEW(self);
	self->size = size;
	self->ptr = calloc(sizeof(Str), size);
	return self;
}

Strs Strs_newRef(Strs self)
{
	CO_NEWREF(self);
	return self;
}

static inline void Strs_free(Strs self)
{
	for (size_t i = 0; i < self->size; i++) {
		Str_freeRef(self->ptr[i]);
	}
	free(self->ptr);
	free(self);
}

void Strs_freeRef(Strs self)
{
	if (self) {
		CO_FREEREF(self, Strs_free);
	}
}

void Strs_set(Strs self, size_t index, Str str)
{
	if (index >= self->size)
		return;
	if (self->ptr[index]) {
		Str_freeRef(self->ptr[index]);
	}
	self->ptr[index] = str;
	Str_newRef(str);
}

Str Strs_get(Strs self, size_t index)
{
	if (index >= self->size)
		return NULL;
	return self->ptr[index];
}

