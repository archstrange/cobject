# CObject

Using C to implement reference-counted object model.

See header [co.h](src/co.h)

## CObject Model

Object is referred by pointer only, reference counted.

### Main API

MUST-PROVIDED:
- new: create a new object
- newRef: create a new reference to an object
- freeRef: free one reference

OPTIONAL:
- clone: clone an object
- copy: copy one object to another

### When to call newRef

Only if you need to keep an object for a while, and if you
called newRef (or new) once, then you must call freeRef once
if you no longer need it.

### Implementation Detial

Object must have a reference counter, the following API
call change this counter:
- new: set to 1
- newRef: +1
- freeRef: -1
- clone: set to 1 (newed object, no change to cloned)

#### `struct` Model

```c
struct CObject {
    struct CO {
        size_t ref;
    } CO;

    // other data fields
    ...
};
```
