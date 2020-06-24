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

#include "Str.h"
#include "co.h"
#include <string.h>

struct Str {
	struct CO CO;

	char *ptr;
	size_t len;
};

Str Str_newFromCStr(const char *cstr)
{
	Str self = CO_NEW(self);
	self->len = cstr ? strlen(cstr) : 0;
	self->ptr = malloc(self->len + 1);
	strcpy(self->ptr, cstr);
	return self;
}

Str Str_newRef(Str self)
{
	CO_NEWREF(self);
	return self;
}

static inline void Str_free(Str self)
{
	free(self->ptr);
	free(self);
}

void Str_freeRef(Str self)
{
	if (self) {
		CO_FREEREF(self, Str_free);
	}
}

