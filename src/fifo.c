#include "fifo.h"

void fifo_worker_handler(QueueHandle_t requests, QueueHandle_t results, int id)
{
    while(1)
    {
        struct request_msg message = {};
        xQueueReceive(requests, &message, portMAX_DELAY);
        
        message.output = message.input + 5;
        message.handled_by = id;

        xQueueSend(results, &message, portMAX_DELAY);
    }
}