
void printf(char* str)
{
    unsigned short* VideoMem = (unsigned short*)0xb8000;

    for(int i = 0; str[i]!='\0';++i){
        VideoMem[i] = (VideoMem[i]&0xFF00)|str[i];
    }
}

// 定义 void () 类型函数指针constructor
typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors(){
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}






// extern "C" : 按照C的方式编译函数，而不是C++； C语言编译时只储存函数名，C++还储存参数，因此C++支持函数重载
extern "C" void kernelMain(void* multiboot_structure, unsigned int magicnumber)
{
    printf("Hello world!");

    while(1);
}