# FreeRTOS-Arduino (Uno)

**FreeRTOSBasic** - uses FreeRTOS example 1 - just added some variable "sizeof" stuff (used as a starting point)

**MessageQueues** - sends some data between two tasks

**BasicTimers** - Just some basic software timers

**PeriodicTask** -calls a couple of tasks when a timer is done

**BasicInterrupt** - Interrupts one task with another task by triggering an ISR (connect a wire from PIN13 to PIN2).



## To Do: (if possible)

- Passing Structures in Message Queues
- Multiple Consumers Message Queues
- ~~Memory Pools - are not a bare bones FreeRTOS artefact - need CMSIS API~~
- Mutex
- Semaphore
- adding CMSIS? \#include "[cmsis_os2.h](https://docs.silabs.com/cmsis/latest/rtos2/cmsis-os2-h)"     

## Resources

- https://www.freertos.org/a00106.html - FreeRTOS API
- https://techtutorialsx.com/ - some tutorials

