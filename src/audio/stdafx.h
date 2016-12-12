

//#include "targetver.h"
#include <windows.h>
#include <strsafe.h>
#include <objbase.h>

#include <mmdeviceapi.h>
#include <audiopolicy.h>

template <class T> void SafeRelease(T **ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}
