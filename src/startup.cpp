#include <cstdint>

extern "C" uint32_t _sidata;
extern "C" uint32_t _sdata;
extern "C" uint32_t _edata;

extern "C" uint32_t _sbss;
extern "C" uint32_t _ebss;

extern "C" void reset_handler_cpp()
{
    // copy of .data (FLASH -> RAM)
    uint32_t* src = &_sidata;
    uint32_t* dst = &_sdata;

    while (dst < &_edata)
    {
        *dst++ = *src++;
    }

    // assign zeros to .bss
    for (uint32_t* bss = &_sbss; bss < &_ebss; ++bss)
    {
        *bss = 0;
    }

    // TODO: init C++ runtime
    //extern void __libc_init_array();
    //_libc_init_array();

    // main
    extern int main(void);
    main();

    // fallback
    while (1) {}
}