#include <common.h>
#include <sizes.h>
#include <asm/barebox-arm-head.h>
#include <asm/barebox-arm.h>

extern char __dtb_imx6q_sabrelite_start[];

ENTRY_FUNCTION(start_imx6_sabrelite, r0, r1, r2)
{
	uint32_t fdt;

	arm_cpu_lowlevel_init();

	fdt = (uint32_t)__dtb_imx6q_sabrelite_start - get_runtime_offset();

	barebox_arm_entry(0x10000000, SZ_1G, fdt);
}
