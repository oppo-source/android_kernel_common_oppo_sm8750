/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM vmscan

#define TRACE_INCLUDE_PATH trace/hooks

#if !defined(_TRACE_HOOK_VMSCAN_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_VMSCAN_H

#include <trace/hooks/vendor_hooks.h>

DECLARE_RESTRICTED_HOOK(android_rvh_set_balance_anon_file_reclaim,
			TP_PROTO(bool *balance_anon_file_reclaim),
			TP_ARGS(balance_anon_file_reclaim), 1);
DECLARE_HOOK(android_vh_tune_swappiness,
	TP_PROTO(int *swappiness),
	TP_ARGS(swappiness));
DECLARE_HOOK(android_vh_shrink_slab_bypass,
	TP_PROTO(gfp_t gfp_mask, int nid, struct mem_cgroup *memcg, int priority, bool *bypass),
	TP_ARGS(gfp_mask, nid, memcg, priority, bypass));
DECLARE_HOOK(android_vh_check_folio_look_around_ref,
	TP_PROTO(struct folio *folio, int *skip),
	TP_ARGS(folio, skip));
DECLARE_HOOK(android_vh_do_shrink_slab,
	TP_PROTO(struct shrinker *shrinker, long *freeable),
	TP_ARGS(shrinker, freeable));
DECLARE_HOOK(android_vh_vmscan_kswapd_done,
	TP_PROTO(int node_id, unsigned int highest_zoneidx, unsigned int alloc_order,
	        unsigned int reclaim_order),
	TP_ARGS(node_id, highest_zoneidx, alloc_order, reclaim_order));
DECLARE_HOOK(android_vh_shrink_folio_list,
	TP_PROTO(struct folio *folio, bool dirty, bool writeback,
		bool *activate, bool *keep),
	TP_ARGS(folio, dirty, writeback, activate, keep));
DECLARE_HOOK(android_vh_inode_lru_isolate,
	TP_PROTO(struct inode *inode, bool *skip),
	TP_ARGS(inode, skip));
DECLARE_HOOK(android_vh_invalidate_mapping_pagevec,
	TP_PROTO(struct address_space *mapping, bool *skip),
	TP_ARGS(mapping, skip));

enum scan_balance;
DECLARE_HOOK(android_vh_tune_scan_type,
	TP_PROTO(enum scan_balance *scan_type),
	TP_ARGS(scan_type));
DECLARE_HOOK(android_vh_page_referenced_check_bypass,
	TP_PROTO(struct folio *folio, unsigned long nr_to_scan, int lru, bool *bypass),
	TP_ARGS(folio, nr_to_scan, lru, bypass));
DECLARE_HOOK(android_vh_modify_scan_control,
	TP_PROTO(u64 *ext, unsigned long *nr_to_reclaim,
	struct mem_cgroup *target_mem_cgroup,
	bool *file_is_tiny, bool *may_writepage),
	TP_ARGS(ext, nr_to_reclaim, target_mem_cgroup, file_is_tiny, may_writepage));
DECLARE_HOOK(android_vh_should_continue_reclaim,
	TP_PROTO(u64 *ext, unsigned long *nr_to_reclaim,
	unsigned long *nr_reclaimed, bool *continue_reclaim),
	TP_ARGS(ext, nr_to_reclaim, nr_reclaimed, continue_reclaim));
DECLARE_HOOK(android_vh_file_is_tiny_bypass,
	TP_PROTO(bool file_is_tiny, bool *bypass),
	TP_ARGS(file_is_tiny, bypass));
#endif /* _TRACE_HOOK_VMSCAN_H */
/* This part must be outside protection */
#include <trace/define_trace.h>
