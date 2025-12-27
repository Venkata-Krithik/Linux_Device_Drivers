#include<linux/init.h>
#include<linux/module.h>
#include<linux/proc_fs.h>

MODULE_LICENSE("GPL");
ssize_t	custom_proc_read(struct file *file_pointer,
                           char *user_buff,
                           size_t count,
                           loff_t* offset)//This will not be printed in user space and these arguments will be sent by kernel we dont need to send any
{
    printk("entered read statement ");
    char s[]="printing in user space\n";
    int result=strlen(s);
    if(*offset>0) return 0;//basically while using cat, it needs no of bytes to read
    copy_to_user(user_buff,s,result);
    *offset+=strlen(s);
     return result;//so since we need to print it only one for the first time we send the no of bytes
                        //and since cat comes back to this function we then send 0 
                        //indicating it does not need to print anything
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