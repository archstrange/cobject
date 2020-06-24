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

#include <stdlib.h>
#include <stdio.h>
#include "Strs.h"

int main(int argc, const char *argv[])
{
	Strs strs = Strs_new(10);

	for (int i = 0; i < 10; i++) {
		Str str = Str_newFromCStr("Hello World!");
		Strs_set(strs, i, str);
		Str_freeRef(str);
	}

	Str str = Strs_get(strs, 5);
	Str_newRef(str);

	Strs_freeRef(strs);

	Str_freeRef(str);
	return 0;
}
