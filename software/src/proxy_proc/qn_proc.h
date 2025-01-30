#ifndef __QN_PROC_H__
#define __QN_PROC_H__


#include <cstdlib>
#include <cstring>
#include <sys/select.h>
#include <thread>
#include <vector>
#include <cstdint>
#include <ctime>
#include <iostream>

#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/file.h>


// DPDK lib
#include <rte_eal.h>
#include <rte_errno.h>
#include <rte_lcore.h>
#include <rte_launch.h>
#include <rte_memory.h>
#include <rte_memzone.h>
#include <rte_mempool.h>
#include <rte_ether.h>
#include <rte_ip.h>
#include <rte_udp.h>


#include "common/log.h"
#include "common/app_thrd_info.h"
#include "simple-kvs/api.h"
#include "simple-kvs/app.h"
#include "simple-kvs/rmtp.h"
#include "mqnic/mqnic.h"



struct qn_ctxt {
    struct mqnic_eth_dev *eth_dev;
    struct rte_mempool *mp;
    uint16_t qid;
    nullptr_t *db; // only used in DB test
};

int qn_echo_proc(void *arg);




#endif // __QN_PROC_H__
