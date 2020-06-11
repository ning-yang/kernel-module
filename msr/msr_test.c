#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ning Yang");
MODULE_DESCRIPTION("A simple example Linux module which read/write MSR.");
MODULE_VERSION("0.01");

unsigned long long x86_get_msr(int msr)
{
    unsigned long msrl = 0, msrh = 0;

    /* NOTE: rdmsr is always return EDX:EAX pair value */
    asm volatile("rdmsr"
                 : "=a"(msrl), "=d"(msrh)
                 : "c"(msr));

    return ((unsigned long long)msrh << 32) | msrl;
}

static int __init msr_test_init(void)
{
    unsigned long long result;
    const unsigned int msr = 0x10;
    printk(KERN_INFO "-----------------------------------\n");
    printk(KERN_INFO "|           MSR test              |\n");
    printk(KERN_INFO "-----------------------------------\n");

    result = x86_get_msr(msr);
    printk(KERN_INFO "Read Msr:\t%#x\n", msr);
    printk(KERN_INFO "Result:\t%#llx\n", result);
    return 0;
}
static void __exit msr_test_exit(void)
{
    printk(KERN_INFO "Unload msr_test.\n");
}

module_init(msr_test_init);
module_exit(msr_test_exit);
