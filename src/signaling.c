#include <stdio.h>
#include "signaling.h"

void signal_handle_calculation(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{
    printf("taken the sempahore. Performing the calculation\n");
    xSemaphoreTake(request, portMAX_DELAY);
    data->output = data->input + 5;
    //vTaskDelay(100);
    xSemaphoreGive(response);
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{
    xSemaphoreGive(request);
    BaseType_t res = xSemaphoreTake(response, 100);
    return res;
}
                                    