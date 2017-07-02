/*
 * Copyright (C) 2011-2017 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef _UAPI_ASM_X86_SGX_H
#define _UAPI_ASM_X86_SGX_H
     
#ifdef __FreeBSD__
typedef uint64_t __u64;
typedef uint16_t __u16;
#else
#include <linux/types.h>
#include <linux/ioctl.h>
#endif

#define SGX_MAGIC 0xA4
     
#define SGX_IOC_ENCLAVE_CREATE \
         _IOW(SGX_MAGIC, 0x00, struct sgx_enclave_create)
#define SGX_IOC_ENCLAVE_ADD_PAGE \
         _IOW(SGX_MAGIC, 0x01, struct sgx_enclave_add_page)
#define SGX_IOC_ENCLAVE_INIT \
         _IOW(SGX_MAGIC, 0x02, struct sgx_enclave_init)
     
     /* SGX leaf instruction return values */
#define SGX_SUCCESS                 0
#define SGX_INVALID_SIG_STRUCT      1
#define SGX_INVALID_ATTRIBUTE       2
#define SGX_BLKSTATE                3
#define SGX_INVALID_MEASUREMENT     4
#define SGX_NOTBLOCKABLE            5
#define SGX_PG_INVLD                6
#define SGX_LOCKFAIL                7
#define SGX_INVALID_SIGNATURE       8
#define SGX_MAC_COMPARE_FAIL        9
#define SGX_PAGE_NOT_BLOCKED        10
#define SGX_NOT_TRACKED             11
#define SGX_VA_SLOT_OCCUPIED        12
#define SGX_CHILD_PRESENT           13
#define SGX_ENCLAVE_ACT             14
#define SGX_ENTRYEPOCH_LOCKED       15
#define SGX_INVALID_LICENSE         16
#define SGX_PREV_TRK_INCMPL         17
#define SGX_PG_IS_SECS              18
#define SGX_INVALID_CPUSVN          32
#define SGX_INVALID_ISVSVN          64
#define SGX_UNMASKED_EVENT          128
#define SGX_INVALID_KEYNAME         256
     
     /* IOCTL return values */
#define SGX_POWER_LOST_ENCLAVE  0x40000000
#define SGX_LE_ROLLBACK         0x40000001
     
     struct sgx_enclave_create  {
         __u64   src;
     } __attribute__((packed));
     
     struct sgx_enclave_add_page {
         __u64   addr;
         __u64   src;
         __u64   secinfo;
         __u16   mrmask;
     } __attribute__((packed));
     
     struct sgx_enclave_init {
         __u64   addr;
         __u64   sigstruct;
         __u64   einittoken;
     } __attribute__((packed));
     
#endif /* _UAPI_ASM_X86_SGX_H */

