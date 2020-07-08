#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

/*	To insert the module: sudo insmod hellop.ko
 *	To insert the module with parameters: sudo insmod hellop.ko message="you!" count=5
 *	To remove the module: sudo rmmod hellop
 *	To check the messages in kernel log: dmesg or tail -p /var/log/kern.log
 */

static char *message = "world!";
static int count = 1;

/* S_IRUGO states that value of the parameter cannot be changed in sysfs (/sys/module/hellop/parameters) by others
 * Use S_IRUGO|S_IWUSR to change value of the parameter as root
 */


module_param(message, charp, S_IRUGO);	
module_param(count, int, S_IRUGO);	

static int __init hello_init(void)
{
	printk(KERN_INFO"Hello, %s\n", message);
	printk(KERN_INFO"count %d\n", count);
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO"Kernel module removed\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Spoorti Doddamani");
MODULE_DESCRIPTION("Hello world module with parameters");
