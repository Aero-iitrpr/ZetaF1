#include <Arduino.h>
#include <Zeta_Buffer/Zeta_Buffer.h>

ZetaBufferStore::ZetaBufferStore()
    : ParameterName(""), head(0), tail(0), is_full(false) {}

void ZetaBufferStore::begin()
{
    ParameterName = "";
    // add the support for sd card
}

void ZetaBufferStore::AddLog(String parametername, String Log)
{
    ParameterName = parametername;
    String fullLog = ParameterName + ":" + Log;
    CircularBuffer[head] = fullLog;
    head = (head + 1) % CIRCULAR_BUFFER_SIZE;
    if (isFull())
    {
        tail = (tail + 1) % CIRCULAR_BUFFER_SIZE;
        DumpLogs();
    }
    is_full = head == tail;
}

bool ZetaBufferStore::isFull()
{
    return is_full;
}

bool ZetaBufferStore::isEmpty()
{
    return (!is_full && (head == tail));
}

void ZetaBufferStore::DumpLogs()
{
    // later we will be dumping this data into the sd card
    for (size_t i = 0; i < CIRCULAR_BUFFER_SIZE; i++)
    {
        if (CircularBuffer[i] != "")
        {
            Serial.println(CircularBuffer[i]);
        }
    }
    Serial.println("-------------------------------");
}
