#define cool_sequence
#include <kernel/interrupts.h>
#include <kernel/memory.h>
#include <drivers/keyboard.h>
#include <drivers/mouse.h>
#include <drivers/pcspk.h>
#include <kernel/multitasking.h>
#include <drivers/graphics.h>
#include <kernel/syscalls.h>
#include <kernel/filesystem.h>
#include <drivers/rtc.h>

extern "C" void main()
{
    InitHeap(0x100000, 0xFF000000);
    InitMouse();
    InitFs();
    InitFont();
    InitDoubleBuffering();
    rtc_wait_second();
    print("RaidouOS", 15, 960);
    print("by AptRock327", 1000, 960);
    SwapBuffers();
    #ifdef cool_sequence
        rtc_wait_second();
        rtc_wait_second();
        rtc_wait_second();
    #endif
    output_device_list();
    SwapBuffers();
    #ifdef cool_sequence
        rtc_wait_second();
        rtc_wait_second();
        rtc_wait_second();
    #endif
    sound(300);
    #ifdef cool_sequence
        rtc_wait_second();
    #endif
    sound(200);
    #ifdef cool_sequence
        rtc_wait_second();
    #endif
    nosound();
    InitIDT();
    InitMultitasking();
    while(1);
}
