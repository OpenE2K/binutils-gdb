/* THIS FILE IS GENERATED.  -*- buffer-read-only: t -*- vi:set ro:
  Original: sparcv932-linux.xml */

#include "defs.h"
#include "osabi.h"
#include "target-descriptions.h"

struct target_desc *tdesc_sparcv932_linux;
static void
initialize_tdesc_sparcv932_linux (void)
{
  struct target_desc *result = allocate_target_description ();
  struct tdesc_feature *feature;

  set_tdesc_architecture (result, bfd_scan_arch ("sparc:v8plus"));

  feature = tdesc_create_feature (result, "org.gnu.gdb.sparc.cpu");
  tdesc_create_reg (feature, "g0", 0, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "g1", 1, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "g2", 2, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "g3", 3, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "g4", 4, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "g5", 5, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "g6", 6, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "g7", 7, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "o0", 8, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "o1", 9, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "o2", 10, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "o3", 11, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "o4", 12, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "o5", 13, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "sp", 14, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "o7", 15, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "l0", 16, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "l1", 17, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "l2", 18, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "l3", 19, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "l4", 20, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "l5", 21, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "l6", 22, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "l7", 23, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "i0", 24, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "i1", 25, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "i2", 26, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "i3", 27, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "i4", 28, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "i5", 29, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "fp", 30, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "i7", 31, 1, NULL, 32, "uint32");

  feature = tdesc_create_feature (result, "org.gnu.gdb.sparc.cp0");
  tdesc_create_reg (feature, "y", 64, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "psr", 65, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "wim", 66, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "tbr", 67, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "pc", 68, 1, NULL, 32, "code_ptr");
  tdesc_create_reg (feature, "npc", 69, 1, NULL, 32, "code_ptr");
  tdesc_create_reg (feature, "fsr", 70, 1, NULL, 32, "uint32");
  tdesc_create_reg (feature, "csr", 71, 1, NULL, 32, "uint32");

  feature = tdesc_create_feature (result, "org.gnu.gdb.sparc.fpu");
  tdesc_create_reg (feature, "f0", 32, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f1", 33, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f2", 34, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f3", 35, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f4", 36, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f5", 37, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f6", 38, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f7", 39, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f8", 40, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f9", 41, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f10", 42, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f11", 43, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f12", 44, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f13", 45, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f14", 46, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f15", 47, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f16", 48, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f17", 49, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f18", 50, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f19", 51, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f20", 52, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f21", 53, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f22", 54, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f23", 55, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f24", 56, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f25", 57, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f26", 58, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f27", 59, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f28", 60, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f29", 61, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f30", 62, 1, NULL, 32, "ieee_single");
  tdesc_create_reg (feature, "f31", 63, 1, NULL, 32, "ieee_single");

  feature = tdesc_create_feature (result, "org.mcst.gdb.sparc.v932");
  tdesc_create_reg (feature, "eg0", 64, 1, NULL, 64, "int64");
  tdesc_create_reg (feature, "eg1", 65, 1, NULL, 64, "int64");
  tdesc_create_reg (feature, "eg2", 66, 1, NULL, 64, "int64");
  tdesc_create_reg (feature, "eg3", 67, 1, NULL, 64, "int64");
  tdesc_create_reg (feature, "eg4", 68, 1, NULL, 64, "int64");
  tdesc_create_reg (feature, "eg5", 69, 1, NULL, 64, "int64");
  tdesc_create_reg (feature, "eg6", 70, 1, NULL, 64, "int64");
  tdesc_create_reg (feature, "eg7", 71, 1, NULL, 64, "int64");
  tdesc_create_reg (feature, "eo0", 72, 1, NULL, 64, "int64");
  tdesc_create_reg (feature, "eo1", 73, 1, NULL, 64, "int64");
  tdesc_create_reg (feature, "eo2", 74, 1, NULL, 64, "int64");
  tdesc_create_reg (feature, "eo3", 75, 1, NULL, 64, "int64");
  tdesc_create_reg (feature, "eo4", 76, 1, NULL, 64, "int64");
  tdesc_create_reg (feature, "eo5", 77, 1, NULL, 64, "int64");
  tdesc_create_reg (feature, "eo6", 78, 1, NULL, 64, "int64");
  tdesc_create_reg (feature, "eo7", 79, 1, NULL, 64, "int64");
  tdesc_create_reg (feature, "d32", 80, 1, NULL, 64, "float");
  tdesc_create_reg (feature, "d34", 81, 1, NULL, 64, "float");
  tdesc_create_reg (feature, "d36", 82, 1, NULL, 64, "float");
  tdesc_create_reg (feature, "d38", 83, 1, NULL, 64, "float");
  tdesc_create_reg (feature, "d40", 84, 1, NULL, 64, "float");
  tdesc_create_reg (feature, "d42", 85, 1, NULL, 64, "float");
  tdesc_create_reg (feature, "d44", 86, 1, NULL, 64, "float");
  tdesc_create_reg (feature, "d46", 87, 1, NULL, 64, "float");
  tdesc_create_reg (feature, "d48", 88, 1, NULL, 64, "float");
  tdesc_create_reg (feature, "d50", 89, 1, NULL, 64, "float");
  tdesc_create_reg (feature, "d52", 90, 1, NULL, 64, "float");
  tdesc_create_reg (feature, "d54", 91, 1, NULL, 64, "float");
  tdesc_create_reg (feature, "d56", 92, 1, NULL, 64, "float");
  tdesc_create_reg (feature, "d58", 93, 1, NULL, 64, "float");
  tdesc_create_reg (feature, "d60", 94, 1, NULL, 64, "float");
  tdesc_create_reg (feature, "d62", 95, 1, NULL, 64, "float");

  tdesc_sparcv932_linux = result;
}
