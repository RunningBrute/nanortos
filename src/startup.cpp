#include <cstdint>

extern "C" uint32_t _sidata;
extern "C" uint32_t _sdata;
extern "C" uint32_t _edata;

extern "C" uint32_t _sbss;
extern "C" uint32_t _ebss;

extern int main(void);

void copy_memory(uint32_t* src, uint32_t* dst, uint32_t* dst_end)
{
    while (dst < dst_end)
    {
        *dst++ = *src++;
    }
}

void zero_memory(uint32_t* dst, uint32_t size)
{
    for (uint32_t i = 0; i < size; ++i)
    {
        dst[i] = 0;
    }
}

extern "C" void reset_handler()
{
    // copy of .data (FLASH -> RAM)
    uint32_t* src = &_sidata;
    uint32_t* dst = &_sdata;
    uint32_t* dst_end = &_edata;
    copy_memory(src, dst, dst_end);
    
    // assign zeros to .bss
    zero_memory(&_sbss, (&_ebss - &_sbss));

    // TODO: init C++ runtime
    //extern void __libc_init_array();
    //_libc_init_array();

    // main
    main();

    // fallback
    while (1) {}
}