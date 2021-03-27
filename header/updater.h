#ifndef UPDATER_HEADER
#define UPDATER_HEADER

struct MemoryStruct;
static size_t WriteMemoryCallback(void* contents, size_t size, size_t nmemb, void *userp);
int updater(void);

#include "../source/updater.cpp"

#endif
