#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
static int vicky_init(void)
{
    printk("Hello_World\n");
    return 0;
}
static void vicky_exit(void)
{
    printk("I am getting out\n");
}
module_init(vicky_init);
module_exit(vicky_exit);