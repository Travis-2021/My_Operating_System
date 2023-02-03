
#include "types.h"
#include "gdt.h"

void printf(char* str)
{
    uint16_t* VideoMem = (uint16_t*)0xb8000;
    // DOS界面 宽80，高25
    static uint8_t x=0, y=0;
    
    for(int i = 0; str[i]!='\0';++i)
    {
        switch (str[i])
        {
            case '\n':
                y++;
                x=0;
                break;
            default:
                VideoMem[80*y + x] = (VideoMem[80*y + x]&0xFF00)|str[i];
                x++;
                break;
        }

        if(x >= 80)
        {
            y++;
            x=0;
        }
        if(y >=25 )
        {
            for(int y=0;y<25;y++)
                for(int x=0;x<80;x++)
                    VideoMem[80*y + x] = (VideoMem[80*y + x]&0xFF00)|' ';
            x = 0;
            y = 0;
        }

    }
}







// 定义 void()类型函数指针constructor   没懂
typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors(){
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}






// extern "C" : 按照C的方式编译函数，而不是C++； C语言编译时只储存函数名，C++还储存参数，因此C++支持函数重载
extern "C" void kernelMain(void* multiboot_structure, uint32_t magicnumber)
{
    printf("Hello world!\n");
    printf("Hello world!");

    GlobalDescriptorTable gdt;

    while(1);
}