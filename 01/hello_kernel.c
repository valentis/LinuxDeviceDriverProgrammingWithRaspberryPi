#include <linux/init.h>   // module_init, module_exit 매크로
#include <linux/module.h> // MODULE_* 관련 매크로
#include <linux/kernel.h> // printk

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Hello World kernel module");

static int __init hello_init(void) {
    // 모듈이 로드될 때 호출됨
    printk(KERN_INFO "Hello, Kernel World!\n");
    return 0;
}

static void __exit hello_exit(void) {
    // 모듈이 제거될 때 호출됨
    printk(KERN_INFO "Goodbye, Kernel World.\n");
}

module_init(hello_init);
module_exit(hello_exit);
