#include<linux/module.h>
#include<linux/kernal.h>
#include<linux/init.h>

int init_module(void)
{
	printk(KERN_NOTICE "SYSTIMER Found\n");
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_NOTICE "GOODBYE\n");
	return;
}
