/**
 * @file
 * @brief        NVR库函数头文件
 * @author       YangZJ
 * @date         2023-01-02
 *  */

#ifndef __lks45x_NVR_H
#define __lks45x_NVR_H

///< Includes ------------------------------------------------------------------
#include "lks32mc45x.h"
#include "basic.h"
void NVR_EraseSector(u32 adr);
void NVR_Program(u32 adr, u32 *buf, u32 sz);
u32 NVR_Read(u32 adr);
#endif /*__lks45x_NVR_H */
