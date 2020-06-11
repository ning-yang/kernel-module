#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ning Yang");
MODULE_DESCRIPTION("A simple example Linux module which read/write MSR.");
MODULE_VERSION("0.01");

static int __init lkm_example_init(void) {
 printk(KERN_INFO "-----------------------------------\n");
 printk(KERN_INFO "|           MSR test              |\n");
 printk(KERN_INFO "-----------------------------------\n");
 return 0;
}
static void __exit lkm_example_exit(void) {
 printk(KERN_INFO "Goodbye, World!\n");
}

module_init(lkm_example_init);
module_exit(lkm_example_exit);
