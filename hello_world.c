#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

// To compile this kernel module: make
// To insert this kernel module: sudo insmod hello_world.ko
// To remove this kernel module: sudo rmmod hello_world
// To check the log messages "Hello, world! or Goodbye, cruel world": dmesg or sudo tail -f /valog/kern.log

static int hello_init(void)		// function invoked on kernel module insertion 
{
	printk(KERN_INFO"Hello, world!\n");	// printk -- function defined and exported by kernel
	return 0;
}

static void hello_exit(void)	// function invoked on kernel module removal
{
	printk(KERN_INFO"Goodbye, cruel world\n");	// KERN_INFO -- priority of the log message
}

module_init(hello_init);		// kernel macro indicates function invoked on module insertion
module_exit(hello_exit)			// kernel macro indicates function invoked on module removal
