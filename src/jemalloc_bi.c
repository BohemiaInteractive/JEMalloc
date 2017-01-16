#if _WIN32

#define VC_EXTRALEAN
#include <windows.h>
#ifndef __cplusplus
typedef BOOL bool;
#endif
#include "..\include\jemalloc\jemalloc.h"

int malloc_init_hard_needed(void);
int malloc_init_hard(void);

JEMALLOC_EXPORT size_t __stdcall MemTotalReserved() {
  size_t stats_total_reserved();
  return stats_total_reserved();
}

JEMALLOC_EXPORT size_t __stdcall MemTotalCommitted() {
  size_t stats_total_commited();
  return stats_total_commited();
}

JEMALLOC_EXPORT size_t __stdcall MemFlushCache(size_t size) {
  /* TODO: purge arenas */return 0;
}

JEMALLOC_EXPORT void __stdcall MemFlushCacheAll() {
  /*No cleanup seems to be needed for JEMalloc*/
}

JEMALLOC_EXPORT size_t __stdcall MemSize(void *mem) {
  return je_malloc_usable_size(mem);
}

JEMALLOC_EXPORT void *__stdcall MemAlloc(size_t size) {
  return je_malloc(size);
}

JEMALLOC_EXPORT void __stdcall MemFree(void *mem) {
  je_free(mem);
}

JEMALLOC_EXPORT size_t __stdcall MemSizeA(void *mem, size_t aligment) {
  return je_malloc_usable_size(mem);
}

JEMALLOC_EXPORT void * __stdcall MemAllocA(size_t size, size_t aligment) {
  return je_aligned_alloc(aligment, size);
}

JEMALLOC_EXPORT void  __stdcall MemFreeA(void *mem) {
  je_free(mem);
}

BOOL WINAPI DllMain( HINSTANCE hInst, DWORD callReason, LPVOID c)
{
  if (callReason==DLL_PROCESS_ATTACH)
  {
    if (malloc_init_hard_needed()) 
      malloc_init_hard();
  }
  else if (callReason==DLL_THREAD_DETACH)
  {
    //mallocThreadShutdownNotification(NULL);
  }
  else if (callReason==DLL_PROCESS_DETACH)
  {
    //mallocProcessShutdownNotification();
  }
  return TRUE;
}

#endif
