#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define ARENA_ALIGNMENT 8
#define ALIGN_UP(n, align) (((n) + (align) - 1) & ~((align) - 1))
#define DEFAULT_CHUNK_SIZE (130 * 15 * 1024 * 1024)
#define MIN_CHUNK_SIZE (4 * 1024)

typedef struct s_arena_chunk
{
    struct s_arena_chunk* next;
    size_t size;
    size_t used;
    uintptr_t data[];
} t_arena_chunk;

typedef struct s_arena
{
    t_arena_chunk* current;
    t_arena_chunk* first;
    size_t chunk_size;
    size_t total_allocated;
    size_t total_used;
    bool allow_resize;
    void* (*alloc_fn)(size_t);
    void (*free_fn)(void*);
} t_arena;

typedef struct s_arena_save
{
    t_arena* arena;
    t_arena_chunk* saved_chunk;
    size_t saved_used;
    size_t saved_total;
} t_arena_save;

t_arena_chunk* arena_allocate_chunk(t_arena* arena, size_t min_size);
void* arena_alloc_from_chunk(t_arena_chunk* chunk, size_t size, size_t align);
t_arena* arena_create();
t_arena* arena_create_with_params(size_t chunk_size, bool allow_resize,
                              void* (*alloc_fn)(size_t), void (*free_fn)(void*));
t_arena_chunk* arena_allocate_chunk(t_arena* arena, size_t min_size);
void* arena_aligned_alloc(t_arena* arena, size_t size, size_t align);
void* arena_alloc(t_arena* arena, size_t size);
void* arena_alloc_from_chunk(t_arena_chunk* chunk, size_t size, size_t align);
void arena_reset(t_arena* arena);
void arena_destroy(t_arena* arena);
size_t arena_total_allocated(const t_arena* arena);
size_t arena_total_used(const t_arena* arena);
t_arena_save arena_save(t_arena* arena);
void arena_restore(t_arena_save save);
void arena_restore(t_arena_save save);
t_arena **get_arena(void);
void setup_arena();
#endif