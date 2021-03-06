/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * FileName: /include/linux/mtd/hw_nve_interface.h
 * Description: define struct hw_nve_info_user and declear function
 * hw_nve_direct_access that will be used by other functions or files.
 * if you want to visit NV partition, i.e. read NV items or write NV
 * items in other files, you should include this .h file.
 * Author: Chengxiaoyi
 * Create: 2020-09-28
 */

#ifndef __HW_NVE_INTERFACE_H__
#define __HW_NVE_INTERFACE_H__

#include <linux/types.h>
#define NV_NAME_LENGTH 8     /* NV name maximum length */
#define NVE_NV_DATA_SIZE 104 /* NV data maximum length */

#define NV_WRITE 0 /* NV write operation */
#define NV_READ 1  /* NV read  operation */

#define NVE_IOCTL_PARA 25

struct hw_nve_info_user {
	uint32_t nv_operation;
	uint32_t nv_number;
	char nv_name[NV_NAME_LENGTH];
	uint32_t valid_size;
	u_char nv_data[NVE_NV_DATA_SIZE];
};
#define NVEACCESSDATA _IOWR('M', NVE_IOCTL_PARA, struct hw_nve_info_user)
extern int hw_nve_direct_access(struct hw_nve_info_user *user_info);

#endif
