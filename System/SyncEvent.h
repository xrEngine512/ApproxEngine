#pragma once
#define WIN_32_LEAN_AND_MEAN
#include <Windows.h>
#include <atomic>


class SyncEvent
{
    HANDLE m_Event;
public:
    SyncEvent();
    void Wait();
    void Notify();
    ~SyncEvent();
};

