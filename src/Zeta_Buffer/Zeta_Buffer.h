#ifndef ZETA_BUFFER_H
#define ZETA_BUFFER_H
#include <Arduino.h>
#include <param.h>

class ZetaBufferStore
{
public:
    ZetaBufferStore();
    void begin();
    void AddLog(String parametername, String Log);
    bool isFull();
    bool isEmpty();
    void DumpLogs();

private:
    String ParameterName;
    size_t head;
    size_t tail;
    bool is_full;
    String CircularBuffer[CIRCULAR_BUFFER_SIZE];
};

#endif // ZETA_BUFFER_H
