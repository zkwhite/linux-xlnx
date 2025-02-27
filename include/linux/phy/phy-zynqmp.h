/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Xilinx ZynqMP PHY header
 *
 * Copyright (C) 2016 Xilinx, Inc.
 *
 * Author: Anurag Kumar Vulisha <anuragku@xilinx.com>
 * Author: Hyun Woo Kwon <hyunk@xilinx.com>
 */

#ifndef _PHY_ZYNQMP_H_
#define _PHY_ZYNQMP_H_

struct phy;

#if defined(CONFIG_PHY_XILINX_ZYNQMP)

extern int xpsgtr_override_deemph(struct phy *phy, u8 plvl, u8 vlvl);
extern int xpsgtr_margining_factor(struct phy *phy, u8 plvl, u8 vlvl);
extern int xpsgtr_wait_pll_lock(struct phy *phy);
int xpsgtr_usb_crst_assert(struct phy *phy);
int xpsgtr_usb_crst_release(struct phy *phy);
#else

static inline int xpsgtr_override_deemph(struct phy *base, u8 plvl, u8 vlvl)
{
	return -ENODEV;
}

static inline int xpsgtr_margining_factor(struct phy *base, u8 plvl, u8 vlvl)
{
	return -ENODEV;
}

extern inline int xpsgtr_wait_pll_lock(struct phy *phy)
{
	return -ENODEV;
}

extern inline int xpsgtr_usb_crst_assert(struct phy *phy)
{
	return -ENODEV;
}

extern inline int xpsgtr_usb_crst_release(struct phy *phy)
{
	return -ENODEV;
}

#endif

#endif /* _PHY_ZYNQMP_H_ */
