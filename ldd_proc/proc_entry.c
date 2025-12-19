#include<linux/init.h>
#include<linux/module.h>
#include<linux/proc_fs.h>

MODULE_LICENSE("GPL");
static struct proc_dir_entry *new_entry;
struct proc_ops random_NULL={};
static int init(void)
{
    new_entry= proc_create("First proc entry", 0, NULL, &random_NULL);
    
    return 0;
}
static void out(void){
    proc_remove(new_entry);
}
module_init(init);
module_exit(out);