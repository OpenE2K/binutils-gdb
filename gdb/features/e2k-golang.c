/* THIS FILE IS GENERATED.  -*- buffer-read-only: t -*- vi:set ro:
  Original: e2k-golang.xml */

#include "defs.h"
#include "osabi.h"
#include "target-descriptions.h"

const struct target_desc *tdesc_e2k_golang;
static void
initialize_tdesc_e2k_golang (void)
{
  target_desc_up result = allocate_target_description ();
  set_tdesc_architecture (result.get (), bfd_scan_arch ("elbrus-v2-golang:64"));

  set_tdesc_osabi (result.get (), osabi_from_tdesc_string ("GNU/Linux"));

  struct tdesc_feature *feature;

  feature = tdesc_create_feature (result.get (), "org.mcst.gdb.e2k.golang");
  tdesc_create_reg (feature, "r0", 0, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "r1", 1, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "r2", 2, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "r3", 3, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "r4", 4, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "r5", 5, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "r6", 6, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "r7", 7, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "r8", 8, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "r9", 9, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "r10", 10, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "r11", 11, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "b0", 12, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "b1", 13, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "b2", 14, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "b3", 15, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "b4", 16, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "b5", 17, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "b6", 18, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "b7", 19, 1, NULL, 64, "uint64");
  tdesc_create_reg (feature, "pc", 20, 1, NULL, 64, "uint64");

  tdesc_e2k_golang = result.release ();
}
