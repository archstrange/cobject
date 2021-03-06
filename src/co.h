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

#ifndef __COBJECT_SRC_OBJECT_H
#define __COBJECT_SRC_OBJECT_H
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define DEBUG 1

/// # CObject Model
///
/// Object is referred by pointer only, reference counted.
///
/// ## Main API
///
/// MUST-PROVIDED:
/// - new: create a new object
/// - newRef: create a new reference to an object
/// - freeRef: free one reference
///
/// OPTIONAL:
/// - clone: clone an object
/// - copy: copy one object to another
///
/// ## When to call newRef
///
/// Only if you need to keep an object for a while, and if you
/// called newRef (or new) once, then you must call freeRef once
/// if you no longer need it.
///
/// ## Implementation Detial
///
/// Object must have a reference counter, the following API
/// call change this counter:
/// - new: set to 1
/// - newRef: +1
/// - freeRef: -1
/// - clone: set to 1 (newed object, no change to cloned)
///
/// ### `struct` Model
///
/// ```c
/// struct CObject {
///     struct CO {
///         size_t ref;
///     } CO;
///
///     // other data fields
///     ...
/// };
/// ```

struct CO {
	size_t ref;
};

static inline void __co_new(size_t *ref)
{
#ifdef DEBUG
	fprintf(stderr, "Ref %p set to 1\n", ref);
#endif
	*ref = 1;
}

#define CO_NEW(self) \
	calloc(sizeof(*self), 1); \
	__co_new(&self->CO.ref)

static inline void __co_new_ref(size_t *ref)
{
	*ref += 1;
#ifdef DEBUG
	fprintf(stderr, "Ref %p incres 1 -> %lu\n", ref, *ref);
#endif
}

#define CO_NEWREF(self) __co_new_ref(&self->CO.ref)

static inline void __co_free_ref(size_t *ref)
{
	*ref -= 1;
#ifdef DEBUG
	fprintf(stderr, "Ref %p decres 1 -> %lu\n", ref, *ref);
#endif
}

#define CO_FREEREF(self, free_func) \
	__co_free_ref(&self->CO.ref); \
	if (self->CO.ref == 0) free_func(self)

/// Some qualifiers
#define MUT // mutable
#define NNUL // Not NULL

#endif
