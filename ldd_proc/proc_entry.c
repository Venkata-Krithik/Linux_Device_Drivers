#include<linux/init.h>
#include<linux/module.h>
#include<linux/proc_fs.h>

MODULE_LICENSE("GPL");
ssize_t	custom_proc_read(struct file *, char __user *, size_t, loff_t *)//This will not be printed in user space and these arguments will be sent by kernel we dont need to send any
{
    printk("entered read statement ");
    return 0;
}
struct proc_ops random_NULL={.proc_read=custom_proc_read};
static struct proc_dir_entry *new_entry;
static int init(void)
{
    new_entry= proc_create("First_proc_entry", 0, NULL, &random_NULL);
    
    return 0;
}
static void out(void){
    proc_remove(new_entry);
}
module_init(init);
module_exit(out);