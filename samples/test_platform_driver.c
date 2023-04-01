

#define pr_fmt(fmt)				"test_platform " fmt

#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>

#define TEST_PLATFORM_NAME                 "test_platform"

static int test_platform_driver_probe(struct platform_device *dev)
{
	pr_info("probe\n");
	return 0;
}

static int test_platform_driver_remove(struct platform_device *dev)
{
	pr_info("remove\n");
	return 0;
}

static struct platform_driver test_platform_driver = {
	.driver = {
		.owner = THIS_MODULE,
		.name = TEST_PLATFORM_NAME,
	},
	.probe = test_platform_driver_probe,
	.remove = test_platform_driver_remove,
};

static struct platform_device test_platfrom_device = {
	.name = TEST_PLATFORM_NAME,
	.id = 0,
	.dev = {
	},
};

static int __init test_platform_init(void)
{
	int ret = 0;

	ret = platform_driver_register(&test_platform_driver);
	if (ret < 0)
		goto err;

	ret = platform_device_register(&test_platfrom_device);
	if (ret < 0)
		goto err_device;

	return 0;

err_device:
	platform_driver_unregister(&test_platform_driver);
err:
	return ret;
}

static void __exit test_platform_exit(void)
{
	platform_device_unregister(&test_platfrom_device);
	platform_driver_unregister(&test_platform_driver);
}

module_init(test_platform_init)
module_exit(test_platform_exit)

MODULE_AUTHOR("wuliyong3155@163.com");
MODULE_LICENSE("GPL");

