/* Copyright (c) 2009-2025 AO MCST.
   Copyright (C) 1991-2025 Free Software Foundation, Inc.
   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this program; if not, see
   <https://www.gnu.org/licenses/>.  */

{
	static e2k_alf1_opcode_templ dummy =
		{"adds", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x10, {1, 1, 1, 1, 1, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"addd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x11, {1, 1, 1, 1, 1, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"subs", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x12, {1, 1, 1, 1, 1, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"subd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x13, {1, 1, 1, 1, 1, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"udivx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x44, {0, 0, 0, 0, 0, 1}, ARGS_DSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"umodx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x45, {0, 0, 0, 0, 0, 1}, ARGS_DSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"sdivx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x46, {0, 0, 0, 0, 0, 1}, ARGS_DSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"smodx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x47, {0, 0, 0, 0, 0, 1}, ARGS_DSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"udivs", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x40, {0, 0, 0, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"udivd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x41, {0, 0, 0, 0, 0, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"sdivs", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x42, {0, 0, 0, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"sdivd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x43, {0, 0, 0, 0, 0, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ands", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x0, {1, 1, 1, 1, 1, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"andd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x1, {1, 1, 1, 1, 1, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"andns", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x2, {1, 1, 1, 1, 1, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"andnd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x3, {1, 1, 1, 1, 1, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ors", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x4, {1, 1, 1, 1, 1, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ord", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x5, {1, 1, 1, 1, 1, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"orns", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x6, {1, 1, 1, 1, 1, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ornd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x7, {1, 1, 1, 1, 1, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"xors", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x8, {1, 1, 1, 1, 1, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"xord", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x9, {1, 1, 1, 1, 1, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"xorns", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0xa, {1, 1, 1, 1, 1, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"xornd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0xb, {1, 1, 1, 1, 1, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"shls", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x18, {1, 1, 1, 1, 1, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"shld", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x19, {1, 1, 1, 1, 1, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"shrs", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x1a, {1, 1, 1, 1, 1, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"shrd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x1b, {1, 1, 1, 1, 1, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"scls", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x14, {1, 1, 1, 1, 1, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"scld", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x15, {1, 1, 1, 1, 1, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"scrs", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x16, {1, 1, 1, 1, 1, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"scrd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x17, {1, 1, 1, 1, 1, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"sars", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x1c, {1, 1, 1, 1, 1, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"sard", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x1d, {1, 1, 1, 1, 1, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"getfs", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x1e, {1, 1, 1, 1, 1, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"getfd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x1f, {1, 1, 1, 1, 1, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"sxt", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0xc, {1, 1, 1, 1, 1, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"merges", 0xff, parse_alf_args, NULL, MERGE, NO_MAS, 0xe, {1, 1, 1, 1, 1, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"merged", 0xff, parse_alf_args, NULL, MERGE, NO_MAS, 0xf, {1, 1, 1, 1, 1, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fadds", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x30, {1, 1, 0, 1, 1, 0}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"faddd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x31, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fsubs", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x32, {1, 1, 0, 1, 1, 0}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fsubd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x33, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fmins", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x34, {1, 1, 0, 1, 1, 0}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fmind", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fmaxs", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fmaxd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x37, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fmuls", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x38, {1, 1, 0, 1, 1, 0}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fmuld", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x39, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxaddss", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x40, {1, 1, 0, 1, 1, 0}, ARGS_DSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxadddd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x41, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxaddsx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x42, {1, 1, 0, 1, 1, 0}, ARGS_DSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxadddx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x43, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxaddxx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x47, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxaddxd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x45, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxaddxs", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x44, {1, 1, 0, 1, 1, 0}, ARGS_DDS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxsubss", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x48, {1, 1, 0, 1, 1, 0}, ARGS_DSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxsubdd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x49, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxsubsx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x4a, {1, 1, 0, 1, 1, 0}, ARGS_DSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxsubdx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x4b, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxsubxx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x4f, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxsubxd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x4d, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxsubxs", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x4c, {1, 1, 0, 1, 1, 0}, ARGS_DDS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxrsubss", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x58, {1, 1, 0, 1, 1, 0}, ARGS_DSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxrsubdd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x59, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxrsubsx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x5a, {1, 1, 0, 1, 1, 0}, ARGS_DSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxrsubdx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x5b, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxmulss", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_DSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxmuldd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxmulsx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x52, {1, 1, 0, 1, 1, 0}, ARGS_DSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxmuldx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x53, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxmulxx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x57, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxmulxd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x55, {1, 1, 0, 1, 1, 0}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxmulxs", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x54, {1, 1, 0, 1, 1, 0}, ARGS_DDS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxdivss", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x48, {0, 0, 0, 0, 0, 1}, ARGS_DSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxdivdd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x49, {0, 0, 0, 0, 0, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxdivsx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x4a, {0, 0, 0, 0, 0, 1}, ARGS_DSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxdivdx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x4b, {0, 0, 0, 0, 0, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxdivxx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x4f, {0, 0, 0, 0, 0, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxdivxd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x4d, {0, 0, 0, 0, 0, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxdivxs", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x4c, {0, 0, 0, 0, 0, 1}, ARGS_DDS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxdivtss", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x60, {0, 0, 0, 0, 0, 1}, ARGS_DSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxdivtdd", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x61, {0, 0, 0, 0, 0, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxdivtsx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x62, {0, 0, 0, 0, 0, 1}, ARGS_DSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxdivtdx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x63, {0, 0, 0, 0, 0, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxsqrtusx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x5a, {0, 0, 0, 0, 0, 1}, ARGS_DSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxsqrtudx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x5b, {0, 0, 0, 0, 0, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxsqrtuxx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x59, {0, 0, 0, 0, 0, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxsqrttsx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x5e, {0, 0, 0, 0, 0, 1}, ARGS_DSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxsqrttdx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x5f, {0, 0, 0, 0, 0, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"fxsqrttxx", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x5d, {0, 0, 0, 0, 0, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"movif", 0xff, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x5e, {0, 1, 0, 0, 1, 0}, ARGS_DSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"vfsi", 0x01, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x63, {0, 1, 0, 0, 1, 0}, ARGS_SDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldcsb", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x68, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"lddsb", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x6c, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldesb", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x70, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldfsb", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x74, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldgsb", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x78, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldssb", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x7c, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldcsh", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x69, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"lddsh", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x6d, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldesh", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x71, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldfsh", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x75, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldgsh", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x79, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldssh", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x7d, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldcsw", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x6a, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"lddsw", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x6e, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldesw", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x72, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldfsw", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x76, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldgsw", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x7a, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldssw", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x7e, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldcsd", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x6b, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"lddsd", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x6f, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldesd", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x73, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldfsd", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x77, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldgsd", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x7b, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldssd", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x7f, {1, 0, 1, 1, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldb", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x64, {1, 0, 1, 1, 0, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldh", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x65, {1, 0, 1, 1, 0, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldw", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x66, {1, 0, 1, 1, 0, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"ldd", 0xff, parse_alf_args, NULL, ALOPF1, MAS | LOAD, 0x67, {1, 0, 1, 1, 0, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fxsqrtisx", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x52, {0, 0, 0, 0, 0, 1}, ARGS_SD, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fxsqrtidx", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x53, {0, 0, 0, 0, 0, 1}, ARGS_DD, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fxsqrtixx", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x57, {0, 0, 0, 0, 0, 1}, ARGS_DD, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"movfi", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x5c, {0, 1, 0, 0, 1, 0}, ARGS_DS, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"movts", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"movtcs", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0xc1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"movtrs", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0xc2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"movtrcs", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0xc3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"movtd", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x61, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"movtcd", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x61, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xc1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"movtrd", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x61, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xc2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"movtrcd", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x61, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xc3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fstois", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fstoid", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_SD, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fdtois", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DS, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fdtoid", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fxtois", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DS, 0xc1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fxtoid", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xc1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fstoistr", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0xc2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fdtoistr", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DS, 0xc2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"istofs", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0xc4};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"istofd", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_SD, 0xc4};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"idtofs", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DS, 0xc4};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"idtofd", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xc4};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"istofx", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_SD, 0xc5};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"idtofx", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xc5};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fstofd", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_SD, 0xc6};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fdtofs", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DS, 0xc6};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fxtofd", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xc6};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fstofx", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_SD, 0xc7};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fxtofs", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DS, 0xc7};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fdtofx", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xc7};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"pfdtois", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DS, 0xc8};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"pfstois", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xc8};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"pfdtoistr", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DS, 0xca};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"pfstoistr", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xca};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"pistofs", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xcc};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"pfstofd", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_SD, 0xce};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"pfdtofs", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DS, 0xce};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"getpl", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x63, {1, 0, 0, 1, 0, 0}, ARGS_SD, 0xf0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"getsap", 0xff, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x62, {1, 1, 0, 0, 0, 0}, ARGS_SQ, 0xec};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"cudtoap", 0x3f, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_SQ, 0xf0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"gdtoap", 0x3f, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_SQ, 0xf2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"cudincr", 0xc0, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_DQ, 0xf0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"gdincr", 0xc0, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_DQ, 0xf2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stcsb", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x28, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stdsb", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x2c, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stesb", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x30, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stfsb", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x34, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stgsb", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x38, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stssb", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x3c, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stcsh", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x29, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stdsh", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x2d, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stesh", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x31, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stfsh", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x35, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stgsh", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x39, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stssh", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x3d, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stcsw", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x2a, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stdsw", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x2e, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stesw", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x32, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stfsw", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x36, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stgsw", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x3a, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stssw", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x3e, {0, 0, 1, 0, 0, 1}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stcsd", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x2b, {0, 0, 1, 0, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stdsd", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x2f, {0, 0, 1, 0, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stesd", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x33, {0, 0, 1, 0, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stfsd", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x37, {0, 0, 1, 0, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stgsd", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x3b, {0, 0, 1, 0, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stssd", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x3f, {0, 0, 1, 0, 0, 1}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stb", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x24, {0, 0, 1, 0, 0, 1}, ARGS_DDS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"sth", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x25, {0, 0, 1, 0, 0, 1}, ARGS_DDS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"stw", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x26, {0, 0, 1, 0, 0, 1}, ARGS_DDS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf3_opcode_templ dummy =
		{"std", 0xff, parse_alf_args, NULL, ALOPF3, MAS | STORE, 0x27, {0, 0, 1, 0, 0, 1}, ARGS_DDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmposb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x0, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpbsb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x1, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpesb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x2, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpbesb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x3, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpssb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x4, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmppsb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x5, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmplsb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x6, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmplesb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x7, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpodb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x0, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpbdb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x1, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpedb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x2, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpbedb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x3, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpsdb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x4, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmppdb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x5, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpldb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x6, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpledb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x7, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpandesb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x2, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpandssb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x4, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpandpsb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x5, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpandlesb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x7, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpandedb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x2, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpandsdb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x4, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpandpdb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x5, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"cmpandledb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x7, 2, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fcmpeqsb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x0, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fcmpltsb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x1, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fcmplesb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x2, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fcmpuodsb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x3, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fcmpneqsb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x4, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fcmpnltsb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x5, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fcmpnlesb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x6, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fcmpodsb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x7, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fcmpeqdb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x0, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fcmpltdb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x1, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fcmpledb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x2, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fcmpuoddb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x3, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fcmpneqdb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x4, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fcmpnltdb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x5, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fcmpnledb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x6, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fcmpoddb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x7, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpeqsb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x0, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpltsb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x1, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmplesb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x2, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpuodsb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x3, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpneqsb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x4, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpnltsb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x5, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpnlesb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x6, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpodsb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0x7, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpeqdb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x0, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpltdb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x1, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpledb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x2, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpuoddb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x3, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpneqdb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x4, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpnltdb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x5, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpnledb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x6, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpoddb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x7, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpeqxb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x0, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpltxb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x1, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmplexb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x2, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpuodxb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x3, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpneqxb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x4, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpnltxb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x5, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpnlexb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x6, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"fxcmpodxb", 0xff, parse_alf_args, NULL, ALOPF7, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0x7, 4, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf8_opcode_templ dummy =
		{"cctopo", 0xff, parse_alf_args, NULL, ALOPF8, NO_MAS, 0x24, {1, 0, 0, 1, 0, 0}, ARGS_S, 0x0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf8_opcode_templ dummy =
		{"cctopb", 0xff, parse_alf_args, NULL, ALOPF8, NO_MAS, 0x24, {1, 0, 0, 1, 0, 0}, ARGS_S, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf8_opcode_templ dummy =
		{"cctope", 0xff, parse_alf_args, NULL, ALOPF8, NO_MAS, 0x24, {1, 0, 0, 1, 0, 0}, ARGS_S, 0x2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf8_opcode_templ dummy =
		{"cctopbe", 0xff, parse_alf_args, NULL, ALOPF8, NO_MAS, 0x24, {1, 0, 0, 1, 0, 0}, ARGS_S, 0x3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf8_opcode_templ dummy =
		{"cctops", 0xff, parse_alf_args, NULL, ALOPF8, NO_MAS, 0x24, {1, 0, 0, 1, 0, 0}, ARGS_S, 0x4};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf8_opcode_templ dummy =
		{"cctopp", 0xff, parse_alf_args, NULL, ALOPF8, NO_MAS, 0x24, {1, 0, 0, 1, 0, 0}, ARGS_S, 0x5};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf8_opcode_templ dummy =
		{"cctopl", 0xff, parse_alf_args, NULL, ALOPF8, NO_MAS, 0x24, {1, 0, 0, 1, 0, 0}, ARGS_S, 0x6};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf8_opcode_templ dummy =
		{"cctople", 0xff, parse_alf_args, NULL, ALOPF8, NO_MAS, 0x24, {1, 0, 0, 1, 0, 0}, ARGS_S, 0x7};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf10_opcode_templ dummy =
		{"staab", 0xff, parse_alf_args, NULL, ALOPF10, MAS | STORE, 0x1c, {0, 0, 1, 0, 0, 1}, ARGS_S};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf10_opcode_templ dummy =
		{"staah", 0xff, parse_alf_args, NULL, ALOPF10, MAS | STORE, 0x1d, {0, 0, 1, 0, 0, 1}, ARGS_S};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf10_opcode_templ dummy =
		{"staaw", 0xff, parse_alf_args, NULL, ALOPF10, MAS | STORE, 0x1e, {0, 0, 1, 0, 0, 1}, ARGS_S};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf10_opcode_templ dummy =
		{"staad", 0xff, parse_alf_args, NULL, ALOPF10, MAS | STORE, 0x1f, {0, 0, 1, 0, 0, 1}, ARGS_D};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf10_opcode_templ dummy =
		{"staaq", 0xff, parse_alf_args, NULL, ALOPF10, MAS | STORE, 0x3f, {0, 0, 1, 0, 0, 1}, ARGS_Q};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf10_opcode_templ dummy =
		{"aaurw", 0xff, parse_alf_args, NULL, AAURW, NO_MAS, 0x1e, {0, 0, 1, 0, 0, 1}, ARGS_S};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf10_opcode_templ dummy =
		{"aaurws", 0xff, parse_alf_args, NULL, AAURW, NO_MAS, 0x1e, {0, 0, 1, 0, 0, 1}, ARGS_S};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf10_opcode_templ dummy =
		{"aaurwd", 0xff, parse_alf_args, NULL, AAURW, NO_MAS, 0x1f, {0, 0, 1, 0, 0, 1}, ARGS_D};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf10_opcode_templ dummy =
		{"aaurwq", 0xff, parse_alf_args, NULL, AAURW, NO_MAS, 0x3f, {0, 0, 1, 0, 0, 1}, ARGS_Q};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf9_opcode_templ dummy =
		{"ldaab", 0xff, parse_alf_args, NULL, ALOPF19, MAS | LOAD, 0x5c, {0, 0, 1, 0, 0, 1}, ARGS_S};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf9_opcode_templ dummy =
		{"ldaah", 0xff, parse_alf_args, NULL, ALOPF19, MAS | LOAD, 0x5d, {0, 0, 1, 0, 0, 1}, ARGS_S};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf9_opcode_templ dummy =
		{"ldaaw", 0xff, parse_alf_args, NULL, ALOPF19, MAS | LOAD, 0x5e, {0, 0, 1, 0, 0, 1}, ARGS_S};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf9_opcode_templ dummy =
		{"ldaad", 0xff, parse_alf_args, NULL, ALOPF19, MAS | LOAD, 0x5f, {0, 0, 1, 0, 0, 1}, ARGS_D};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf9_opcode_templ dummy =
		{"ldaaq", 0xff, parse_alf_args, NULL, ALOPF19, MAS | LOAD, 0x7f, {0, 0, 1, 0, 0, 1}, ARGS_Q};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf9_opcode_templ dummy =
		{"aaurr", 0xff, parse_alf_args, NULL, AAURR, NO_MAS, 0x5e, {0, 0, 1, 0, 0, 1}, ARGS_S};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf9_opcode_templ dummy =
		{"aaurrd", 0xff, parse_alf_args, NULL, AAURR, NO_MAS, 0x5f, {0, 0, 1, 0, 0, 1}, ARGS_D};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf9_opcode_templ dummy =
		{"aaurrq", 0xff, parse_alf_args, NULL, AAURR, NO_MAS, 0x7f, {0, 0, 1, 0, 0, 1}, ARGS_Q};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"muls", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_SSS, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"muld", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"umulx", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_SSD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"smulx", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_SSD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fdivs", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x48, {0, 0, 0, 0, 0, 1}, ARGS_SSS, NONE, {0, 0, 0, 0, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fdivd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x49, {0, 0, 0, 0, 0, 1}, ARGS_DDD, NONE, {0, 0, 0, 0, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fsqrttd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x51, {0, 0, 0, 0, 0, 1}, ARGS_DDD, NONE, {0, 0, 0, 0, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfmuls", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x38, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfmuld", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x39, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"paddb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x8, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"paddh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x9, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"paddw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xe, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"paddd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xf, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"paddsb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xa, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"paddsh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xb, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"paddusb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xc, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"paddush", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xd, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psubb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x10, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psubh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x11, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psubw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x16, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psubd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x17, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psubsb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x12, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psubsh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x13, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psubusb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x14, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psubush", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x15, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmaxsh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmaxub", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pminsh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pminub", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x0, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psadbw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1c, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmulhuh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1b, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmulhh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x18, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmullh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x19, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmaddh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1a, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pslld", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4e, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psllw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x14, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psllh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x15, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psrld", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4c, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psrlw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x10, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psrlh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x11, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psraw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x12, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psrah", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x13, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfadds", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x30, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfaddd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x31, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfsubs", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x32, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfsubd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x33, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"aptoap", 0x01, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_QSQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"aptoapb", 0x01, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_QSQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"getva", 0x01, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x52, {1, 0, 0, 1, 0, 0}, ARGS_QSD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pandd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x48, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pandnd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x49, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pord", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4a, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pxord", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4b, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldrd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS | LOAD, 0x5b, {1, 0, 1, 1, 0, 1}, ARGS_DDD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldosrrd", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS | LOAD, 0x5b, {1, 0, 1, 1, 0, 1}, ARGS_DDD, 0xdc, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"puttc", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x25, {1, 0, 0, 0, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, 0, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pavgusb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1e, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pavgush", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1f, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfdivs", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4a, {0, 0, 0, 0, 0, 1}, ARGS_SSS, NONE, {0, 0, 0, 0, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfdivd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4b, {0, 0, 0, 0, 0, 1}, ARGS_DDD, NONE, {0, 0, 0, 0, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfmins", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x34, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfmind", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfmaxs", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfmaxd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x37, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfsqrttd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x53, {0, 0, 0, 0, 0, 1}, ARGS_DDD, NONE, {0, 0, 0, 0, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_lit8_opcode_templ dummy =
		{"pextrh", 0xff, parse_alf_args, NULL, ALOPF11_LIT8, NO_MAS, 0x1e, {0, 1, 0, 0, 1, 0}, ARGS_DDS, NONE, {0, EXT, 0, 0, EXT, 0}, 0, 7, "use of 'pextrh' with count > 7 leads to an undefined result"};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_lit8_opcode_templ dummy =
		{"pinsh", 0xff, parse_alf_args, NULL, ALOPF11_LIT8, NO_MAS, 0x1f, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0, 4, "use of 'pinsh' with count > 4 leads to an undefined result"};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_lit8_opcode_templ dummy =
		{"psllqh", 0xff, parse_alf_args, NULL, ALOPF11_LIT8, NO_MAS, 0xe, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0, 15, "use of 'psllqh' with count > 15 leads to a zero result"};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_lit8_opcode_templ dummy =
		{"psllql", 0xff, parse_alf_args, NULL, ALOPF11_LIT8, NO_MAS, 0xf, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0, 7, "use of 'psllql' with count > 7 leads to a zero result"};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_lit8_opcode_templ dummy =
		{"psrlqh", 0xff, parse_alf_args, NULL, ALOPF11_LIT8, NO_MAS, 0xc, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0, 7, "use of 'psrlqh' with count > 7 leads to a zero result"};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_lit8_opcode_templ dummy =
		{"psrlql", 0xff, parse_alf_args, NULL, ALOPF11_LIT8, NO_MAS, 0xd, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0, 15, "use of 'psrlql' with count > 15 leads to a zero result"};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"cast", 0x01, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x55, {1, 1, 0, 1, 1, 0}, ARGS_QQQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"tdtomp", 0x01, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x53, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"odtoap", 0x01, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x54, {1, 1, 0, 1, 1, 0}, ARGS_QDQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"puttags", 0xff, parse_alf_args, NULL, ALOPF11, MAS, 0xa, {0, 0, 1, 0, 0, 1}, ARGS_SSS, NONE, {0, 0, EXT, 0, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"puttagd", 0xff, parse_alf_args, NULL, ALOPF11, MAS, 0xb, {0, 0, 1, 0, 0, 1}, ARGS_DSD, NONE, {0, 0, EXT, 0, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpeqs", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_SSS, 0xc0, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmplts", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_SSS, 0xc1, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmples", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_SSS, 0xc2, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpuods", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_SSS, 0xc3, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpneqs", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_SSS, 0xc4, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpnlts", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_SSS, 0xc5, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpnles", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_SSS, 0xc6, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpods", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_SSS, 0xc7, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpeqd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc0, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpltd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc1, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpled", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc2, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpuodd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc3, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpneqd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc4, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpnltd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc5, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpnled", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc6, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpodd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc7, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfcmpeqs", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc0, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfcmplts", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc1, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfcmples", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc2, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfcmpuods", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc3, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfcmpneqs", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc4, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfcmpnlts", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc5, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfcmpnles", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc6, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfcmpods", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc7, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfcmpeqd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc0, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfcmpltd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc1, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfcmpled", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc2, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfcmpuodd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc3, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfcmpneqd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc4, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfcmpnltd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc5, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfcmpnled", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc6, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfcmpodd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDD, 0xc7, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpodsf", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_SSS, 0xc7, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpudsf", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_SSS, 0xc3, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpoddf", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DDS, 0xc7, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fcmpuddf", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DDS, 0xc3, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fxcmpodsf", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_DSS, 0xc7, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fxcmpudsf", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_DSS, 0xc3, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fxcmpoddf", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDS, 0xc7, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fxcmpuddf", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDS, 0xc3, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fxcmpodxf", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DDS, 0xc7, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fxcmpudxf", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DDS, 0xc3, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pcmpeqb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x18, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pcmpeqh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x19, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pcmpeqw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1a, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pcmpgtb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1b, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pcmpgth", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1c, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pcmpgtw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1d, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmovmskb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xb, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmovmskps", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x6, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmovmskpd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"packsshb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x8, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"packushb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x9, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_lit8_opcode_templ dummy =
		{"pshufw", 0xff, parse_alf_args, NULL, ALOPF11_LIT8, NO_MAS, 0x16, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0, 15, "'pshufw' uses only four low-order bits of literal8"};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"packsswh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xa, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"punpckhbh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x0, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"punpckhhw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"punpckhwd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"punpcklbh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"punpcklhw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"punpcklwd", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x5, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldgdb", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x64, {1, 0, 1, 1, 0, 1}, ARGS_SSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldgdh", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x65, {1, 0, 1, 1, 0, 1}, ARGS_SSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldgdw", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x66, {1, 0, 1, 1, 0, 1}, ARGS_SSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldgdd", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x67, {1, 0, 1, 1, 0, 1}, ARGS_SSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldgdq", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x79, {1, 0, 1, 1, 0, 1}, ARGS_SSQ, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldcudb", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x60, {1, 0, 1, 1, 0, 1}, ARGS_SSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldcudh", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x61, {1, 0, 1, 1, 0, 1}, ARGS_SSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldcudw", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x62, {1, 0, 1, 1, 0, 1}, ARGS_SSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldcudd", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x63, {1, 0, 1, 1, 0, 1}, ARGS_SSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldcudq", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x78, {1, 0, 1, 1, 0, 1}, ARGS_SSQ, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldapb", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x68, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldaph", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x69, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldapw", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x6a, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldapd", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x6b, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldapq", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x7a, {1, 0, 1, 1, 0, 1}, ARGS_QSQ, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodwb", 0x01, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x70, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodwd", 0x01, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x73, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodwh", 0x01, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x71, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodwq", 0x01, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x7c, {1, 0, 1, 1, 0, 1}, ARGS_QSQ, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodww", 0x01, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x72, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodpb", 0x01, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x74, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodpd", 0x01, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x77, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodph", 0x01, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x75, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodpq", 0x01, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x7d, {1, 0, 1, 1, 0, 1}, ARGS_QSQ, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodpw", 0x01, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x76, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodrb", 0x01, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x6c, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodrd", 0x01, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x6f, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodrh", 0x01, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x6d, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodrq", 0x01, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x7b, {1, 0, 1, 1, 0, 1}, ARGS_QSQ, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodrw", 0x01, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x6e, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldcsq", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x42, {1, 0, 1, 1, 0, 1}, ARGS_DDQ, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"lddsq", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x43, {1, 0, 1, 1, 0, 1}, ARGS_DDQ, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldesq", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x44, {1, 0, 1, 1, 0, 1}, ARGS_SSQ, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldfsq", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x45, {1, 0, 1, 1, 0, 1}, ARGS_DDQ, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldgsq", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x46, {1, 0, 1, 1, 0, 1}, ARGS_DDQ, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldssq", 0xff, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x47, {1, 0, 1, 1, 0, 1}, ARGS_DDQ, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"adds_fb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x10, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLB, 0, 0, FLB, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"adds_fh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x10, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLH, 0, 0, FLH, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"adds_fw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x10, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLW, 0, 0, FLW, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"subs_fb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x12, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLB, 0, 0, FLB, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"subs_fh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x12, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLH, 0, 0, FLH, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"subs_fw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x12, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLW, 0, 0, FLW, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"umulx_fb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x22, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLB, 0, 0, FLB, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"umulx_fh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x22, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLH, 0, 0, FLH, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"umulx_fw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x22, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLW, 0, 0, FLW, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"smulx_fb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x23, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLB, 0, 0, FLB, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"smulx_fh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x23, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLH, 0, 0, FLH, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"smulx_fw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x23, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLW, 0, 0, FLW, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ands_fb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x0, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLB, 0, 0, FLB, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ands_fh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x0, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLH, 0, 0, FLH, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ands_fw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x0, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLW, 0, 0, FLW, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"andns_fb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLB, 0, 0, FLB, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"andns_fh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLH, 0, 0, FLH, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"andns_fw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLW, 0, 0, FLW, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ors_fb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLB, 0, 0, FLB, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ors_fh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLH, 0, 0, FLH, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ors_fw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLW, 0, 0, FLW, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"orns_fb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x6, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLB, 0, 0, FLB, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"orns_fh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x6, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLH, 0, 0, FLH, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"orns_fw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x6, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLW, 0, 0, FLW, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"xors_fb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x8, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLB, 0, 0, FLB, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"xors_fh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x8, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLH, 0, 0, FLH, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"xors_fw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x8, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLW, 0, 0, FLW, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"xorns_fb", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xa, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLB, 0, 0, FLB, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"xorns_fh", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xa, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLH, 0, 0, FLH, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"xorns_fw", 0xff, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xa, {1, 0, 0, 1, 0, 0}, ARGS_SSS, NONE, {FLW, 0, 0, FLW, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"frcps", 0xff, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x50, {0, 0, 0, 0, 0, 1}, ARGS_SS, 0xc0, 0xc0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"fsqrts", 0xff, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x4c, {0, 0, 0, 0, 0, 1}, ARGS_SS, 0xc0, 0xc0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"fsqrtid", 0xff, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x4d, {0, 0, 0, 0, 0, 1}, ARGS_DD, 0xc0, 0xc0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"frsqrts", 0xff, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x54, {0, 0, 0, 0, 0, 1}, ARGS_SS, 0xc0, 0xc0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"pfsqrts", 0xff, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x4e, {0, 0, 0, 0, 0, 1}, ARGS_SS, 0xc0, 0xc0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"gettd", 0x01, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x56, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xc0, 0xc0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"gettags", 0xff, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x8, {0, 0, 1, 0, 0, 1}, ARGS_SS, 0xc0, 0xc0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"gettagd", 0xff, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x9, {0, 0, 1, 0, 0, 1}, ARGS_DS, 0xc0, 0xc0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"gettc", 0xff, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x24, {1, 0, 0, 0, 0, 0}, ARGS_SD, 0xc0, 0xc0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"invtc", 0xff, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x26, {1, 0, 0, 0, 0, 0}, ARGS_SD, 0xc0, 0xc0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"getsod", 0x01, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x5a, {1, 1, 0, 0, 0, 0}, ARGS_QQ, 0xec, 0xc0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"getsp", 0xff, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x58, {1, 0, 0, 0, 0, 0}, ARGS_SD, 0xec, 0xc0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"pshufh", 0xff, parse_alf_args, NULL, ALOPF12_PSHUFH, NO_MAS, 0x17, {0, 1, 0, 0, 1, 0}, ARGS_DD, 0xc0, 0x0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stcsq", 0xff, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x2, {0, 0, 1, 0, 0, 1}, ARGS_SSQ, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stdsq", 0xff, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x3, {0, 0, 1, 0, 0, 1}, ARGS_SSQ, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stesq", 0xff, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x4, {0, 0, 1, 0, 0, 1}, ARGS_SSQ, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stfsq", 0xff, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x5, {0, 0, 1, 0, 0, 1}, ARGS_SSQ, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stgsq", 0xff, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x6, {0, 0, 1, 0, 0, 1}, ARGS_SSQ, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stssq", 0xff, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x7, {0, 0, 1, 0, 0, 1}, ARGS_SSQ, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"strd", 0xff, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x1b, {0, 0, 1, 0, 0, 1}, ARGS_DDD, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stosrrd", 0xc0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x1b, {0, 0, 1, 0, 0, 1}, ARGS_DDD, 0xdc, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stgdb", 0xff, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x24, {0, 0, 1, 0, 0, 1}, ARGS_SSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stgdh", 0xff, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x25, {0, 0, 1, 0, 0, 1}, ARGS_SSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stgdw", 0xff, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x26, {0, 0, 1, 0, 0, 1}, ARGS_SSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stgdd", 0xff, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x27, {0, 0, 1, 0, 0, 1}, ARGS_SSD, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stgdq", 0xff, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x39, {0, 0, 1, 0, 0, 1}, ARGS_SSQ, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stapb", 0xff, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x28, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"staph", 0xff, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x29, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stapw", 0xff, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x2a, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stapd", 0xff, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x2b, {0, 0, 1, 0, 0, 1}, ARGS_QSD, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stapq", 0xff, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x3a, {0, 0, 1, 0, 0, 1}, ARGS_QSQ, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodpb", 0x01, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x34, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodpd", 0x01, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x37, {0, 0, 1, 0, 0, 1}, ARGS_QSD, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodph", 0x01, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x35, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodpq", 0x01, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x3d, {0, 0, 1, 0, 0, 1}, ARGS_QSQ, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodpw", 0x01, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x36, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodrb", 0x01, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x2c, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodrd", 0x01, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x2f, {0, 0, 1, 0, 0, 1}, ARGS_QSD, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodrh", 0x01, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x2d, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodrq", 0x01, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x3b, {0, 0, 1, 0, 0, 1}, ARGS_QSQ, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodrw", 0x01, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x2e, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodwb", 0x01, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x30, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodwd", 0x01, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x33, {0, 0, 1, 0, 0, 1}, ARGS_QSD, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodwh", 0x01, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x31, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodwq", 0x01, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x3c, {0, 0, 1, 0, 0, 1}, ARGS_QSQ, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodww", 0x01, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x32, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf15_opcode_templ dummy =
		{"rws", 0xff, parse_alf_args, NULL, ALOPF15, NO_MAS, 0x3c, {1, 0, 0, 0, 0, 0}, ARGS_S, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf15_opcode_templ dummy =
		{"rwd", 0xff, parse_alf_args, NULL, ALOPF15, NO_MAS, 0x3d, {1, 0, 0, 0, 0, 0}, ARGS_D, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf15_opcode_templ dummy =
		{"rwshd", 0xc0, parse_alf_args, NULL, ALOPF15, NO_MAS, 0x3d, {1, 0, 0, 0, 0, 0}, ARGS_D, 0xc1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf16_opcode_templ dummy =
		{"rrs", 0xff, parse_alf_args, NULL, ALOPF16, NO_MAS, 0x3e, {1, 0, 0, 0, 0, 0}, ARGS_S, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf16_opcode_templ dummy =
		{"rrd", 0xff, parse_alf_args, NULL, ALOPF16, NO_MAS, 0x3f, {1, 0, 0, 0, 0, 0}, ARGS_D, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf16_opcode_templ dummy =
		{"rrshd", 0xc0, parse_alf_args, NULL, ALOPF16, NO_MAS, 0x3f, {1, 0, 0, 0, 0, 0}, ARGS_D, 0xc1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"incs_fb", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLB};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"incs_fh", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLH};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"incs_fw", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLW};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"decs_fb", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLB};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"decs_fh", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLH};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"decs_fw", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLW};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shls_fb", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLB};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shls_fh", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLH};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shls_fw", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLW};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shrs_fb", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLB};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shrs_fh", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLH};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shrs_fw", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLW};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scls_fb", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLB};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scls_fh", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLH};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scls_fw", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLW};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scrs_fb", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLB};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scrs_fh", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLH};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scrs_fw", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLW};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sars_fb", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLB};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sars_fh", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLH};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sars_fw", 0xff, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {1, 0, 0, 1, 0, 0}, ARGS_SSS, FLW};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"movtq", 0xff, parse_alf_args, NULL, ALOPF22, NO_MAS, 0x57, {1, 1, 0, 1, 1, 0}, ARGS_QQ, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"movtcq", 0xff, parse_alf_args, NULL, ALOPF22, NO_MAS, 0x57, {1, 1, 0, 1, 1, 0}, ARGS_QQ, 0xc1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"movtrq", 0xff, parse_alf_args, NULL, ALOPF22, NO_MAS, 0x57, {1, 1, 0, 1, 1, 0}, ARGS_QQ, 0xc2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"movtrcq", 0xff, parse_alf_args, NULL, ALOPF22, NO_MAS, 0x57, {1, 1, 0, 1, 1, 0}, ARGS_QQ, 0xc3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"movif", 0xfe, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x5e, {1, 0, 0, 1, 0, 0}, ARGS_DSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"vfsi", 0x02, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x63, {0, 1, 0, 0, 1, 0}, ARGS_SDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"movfi", 0xfe, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x5c, {1, 0, 0, 1, 0, 0}, ARGS_DS, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"bitrevs", 0xfe, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x26, {1, 1, 0, 1, 1, 0}, ARGS_SS, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"bitrevd", 0xfe, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x27, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"lzcnts", 0xfe, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x64, {0, 1, 0, 0, 1, 0}, ARGS_SS, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"lzcntd", 0xfe, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x65, {0, 1, 0, 0, 1, 0}, ARGS_DD, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"popcnts", 0xfe, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x66, {0, 1, 0, 0, 1, 0}, ARGS_SS, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"popcntd", 0xfe, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x67, {0, 1, 0, 0, 1, 0}, ARGS_DD, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fstoidtr", 0xfe, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_SD, 0xc2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fdtoidtr", 0xfe, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xc2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fxtoistr", 0xfe, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DS, 0xc3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"fxtoidtr", 0xfe, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xc3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"movx", 0xfe, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x5f, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"movxa", 0xfe, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x5f, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xc1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"movxc", 0xfe, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x5f, {1, 1, 0, 1, 1, 0}, ARGS_DD, 0xc2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"aptoap", 0x02, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_QSQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"aptoapb", 0x02, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_QSQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"getva", 0x02, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x52, {1, 0, 0, 1, 0, 0}, ARGS_QSD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmulubhh", 0xfe, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1d, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"cast", 0x02, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x55, {1, 1, 0, 1, 1, 0}, ARGS_QQQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"tdtomp", 0x02, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x53, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"odtoap", 0x02, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x54, {1, 1, 0, 1, 1, 0}, ARGS_QDQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodwb", 0x02, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x70, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodwd", 0x02, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x73, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodwh", 0x02, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x71, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodwq", 0x02, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x7c, {1, 0, 1, 1, 0, 1}, ARGS_QSQ, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodww", 0x02, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x72, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodpb", 0x02, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x74, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodpd", 0x02, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x77, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodph", 0x02, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x75, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodpq", 0x02, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x7d, {1, 0, 1, 1, 0, 1}, ARGS_QSQ, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodpw", 0x02, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x76, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodrb", 0x02, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x6c, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodrd", 0x02, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x6f, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodrh", 0x02, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x6d, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodrq", 0x02, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x7b, {1, 0, 1, 1, 0, 1}, ARGS_QSQ, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldodrw", 0x02, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x6e, {1, 0, 1, 1, 0, 1}, ARGS_QSD, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"gettd", 0x02, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x56, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xc0, 0xc0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"getsod", 0x02, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x5a, {1, 1, 0, 0, 0, 0}, ARGS_QQ, 0xec, 0xc0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodpb", 0x02, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x34, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodpd", 0x02, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x37, {0, 0, 1, 0, 0, 1}, ARGS_QSD, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodph", 0x02, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x35, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodpq", 0x02, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x3d, {0, 0, 1, 0, 0, 1}, ARGS_QSQ, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodpw", 0x02, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x36, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodrb", 0x02, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x2c, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodrd", 0x02, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x2f, {0, 0, 1, 0, 0, 1}, ARGS_QSD, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodrh", 0x02, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x2d, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodrq", 0x02, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x3b, {0, 0, 1, 0, 0, 1}, ARGS_QSQ, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodrw", 0x02, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x2e, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodwb", 0x02, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x30, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodwd", 0x02, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x33, {0, 0, 1, 0, 0, 1}, ARGS_QSD, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodwh", 0x02, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x31, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodwq", 0x02, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x3c, {0, 0, 1, 0, 0, 1}, ARGS_QSQ, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stodww", 0x02, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x32, {0, 0, 1, 0, 0, 1}, ARGS_QSS, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"vfsi", 0x04, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x63, {0, 1, 0, 0, 1, 0}, ARGS_SDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psllw", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x14, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psllh", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x15, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psrlw", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x10, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psrlh", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x11, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psraw", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x12, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psrah", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x13, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"aptoap", 0x04, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_QSQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"aptoapb", 0x04, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_QSQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"getva", 0x04, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x52, {1, 0, 0, 1, 0, 0}, ARGS_QSD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fstoifs", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x6c, {1, 1, 0, 1, 1, 0}, ARGS_SSS, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fdtoifd", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"umulhd", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x70, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"smulhd", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x71, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pminuw", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x20, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pminsw", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x21, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmaxuw", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x22, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmaxsw", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x23, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"mpsadbh", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x58, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"packuswh", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x6b, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pcmpeqd", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4d, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pcmpgtd", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4f, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfhadds", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x72, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfhsubs", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x73, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfaddsubs", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x77, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pminsb", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pminuh", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x5, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmaxsb", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x6, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmaxuh", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfstoifs", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x6e, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfdtoifd", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x6f, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"phaddh", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x29, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"phaddw", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2a, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"phaddsh", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2b, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"phsubh", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2d, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"phsubw", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2e, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"phsubsh", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2f, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psignb", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x30, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psignh", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x31, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psignw", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x32, {1, 0, 0, 1, 0, 0}, ARGS_DDD, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmaddubsh", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x68, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmulhrsh", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x69, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"phminposuh", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x6a, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"addd_fd", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x11, {1, 0, 0, 1, 0, 0}, ARGS_DDS, NONE, {FLD, 0, 0, FLD, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"subd_fd", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x13, {1, 0, 0, 1, 0, 0}, ARGS_DDS, NONE, {FLD, 0, 0, FLD, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"andd_fd", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1, {1, 0, 0, 1, 0, 0}, ARGS_DDS, NONE, {FLD, 0, 0, FLD, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"andnd_fd", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3, {1, 0, 0, 1, 0, 0}, ARGS_DDS, NONE, {FLD, 0, 0, FLD, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ord_fd", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x5, {1, 0, 0, 1, 0, 0}, ARGS_DDS, NONE, {FLD, 0, 0, FLD, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ornd_fd", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7, {1, 0, 0, 1, 0, 0}, ARGS_DDS, NONE, {FLD, 0, 0, FLD, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"xord_fd", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x9, {1, 0, 0, 1, 0, 0}, ARGS_DDS, NONE, {FLD, 0, 0, FLD, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"xornd_fd", 0xfc, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xb, {1, 0, 0, 1, 0, 0}, ARGS_DDS, NONE, {FLD, 0, 0, FLD, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"puttst", 0xfc, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x25, {0, 0, 0, 1, 0, 0}, ARGS_DD, 0xc0, 0xc0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"gettst", 0xfc, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x24, {0, 0, 0, 1, 0, 0}, ARGS_DD, 0xc0, 0xc0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"incd_fd", 0xfc, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {1, 0, 0, 1, 0, 0}, ARGS_DDS, FLD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"decd_fd", 0xfc, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x33, {1, 0, 0, 1, 0, 0}, ARGS_DDS, FLD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shld_fd", 0xfc, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {1, 0, 0, 1, 0, 0}, ARGS_DDS, FLD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shrd_fd", 0xfc, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1b, {1, 0, 0, 1, 0, 0}, ARGS_DDS, FLD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scld_fd", 0xfc, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x15, {1, 0, 0, 1, 0, 0}, ARGS_DDS, FLD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scrd_fd", 0xfc, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x17, {1, 0, 0, 1, 0, 0}, ARGS_DDS, FLD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sard_fd", 0xfc, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1d, {1, 0, 0, 1, 0, 0}, ARGS_DDS, FLD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"vfsi", 0x08, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x63, {0, 1, 0, 0, 1, 0}, ARGS_SDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfmuls", 0xf8, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x38, {0, 0, 1, 0, 0, 1}, ARGS_DDD, NONE, {0, 0, EXT, 0, 0, EXT}, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfadds", 0xf8, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x30, {0, 0, 1, 0, 0, 1}, ARGS_DDD, NONE, {0, 0, EXT, 0, 0, EXT}, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfaddd", 0xf8, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x31, {0, 0, 1, 0, 0, 1}, ARGS_DDD, NONE, {0, 0, EXT, 0, 0, EXT}, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfsubs", 0xf8, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x32, {0, 0, 1, 0, 0, 1}, ARGS_DDD, NONE, {0, 0, EXT, 0, 0, EXT}, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfsubd", 0xf8, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x33, {0, 0, 1, 0, 0, 1}, ARGS_DDD, NONE, {0, 0, EXT, 0, 0, EXT}, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"aptoap", 0x08, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_QSQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"aptoapb", 0x08, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_QSQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"getva", 0x08, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x52, {1, 0, 0, 1, 0, 0}, ARGS_QSD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fscales", 0xf8, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x24, {0, 1, 0, 0, 1, 0}, ARGS_SSS, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fscaled", 0xf8, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x25, {0, 1, 0, 0, 1, 0}, ARGS_DSD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fxscalesx", 0xf8, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x27, {0, 1, 0, 0, 1, 0}, ARGS_DSD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfhadds", 0xf8, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x72, {0, 0, 1, 0, 0, 1}, ARGS_DDD, NONE, {0, 0, EXT, 0, 0, EXT}, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfhsubs", 0xf8, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x73, {0, 0, 1, 0, 0, 1}, ARGS_DDD, NONE, {0, 0, EXT, 0, 0, EXT}, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pfaddsubs", 0xf8, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x77, {0, 0, 1, 0, 0, 1}, ARGS_DDD, NONE, {0, 0, EXT, 0, 0, EXT}, 1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fadds", 0xf8, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x30, {0, 0, 1, 0, 0, 1}, ARGS_SSS, NONE, {0, 0, EXT1, 0, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"faddd", 0xf8, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x31, {0, 0, 1, 0, 0, 1}, ARGS_DDD, NONE, {0, 0, EXT1, 0, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fsubs", 0xf8, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x32, {0, 0, 1, 0, 0, 1}, ARGS_SSS, NONE, {0, 0, EXT1, 0, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fsubd", 0xf8, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x33, {0, 0, 1, 0, 0, 1}, ARGS_DDD, NONE, {0, 0, EXT1, 0, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fmuls", 0xf8, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x38, {0, 0, 1, 0, 0, 1}, ARGS_SSS, NONE, {0, 0, EXT1, 0, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"fmuld", 0xf8, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x39, {0, 0, 1, 0, 0, 1}, ARGS_DDD, NONE, {0, 0, EXT1, 0, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"vfsi", 0x10, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x63, {0, 1, 0, 0, 1, 0}, ARGS_SDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf10_opcode_templ dummy =
		{"staaqp", 0xf0, parse_alf_args, NULL, ALOPF10, MAS | STORE, 0x20, {0, 0, 1, 0, 0, 1}, ARGS_P};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf9_opcode_templ dummy =
		{"ldaaqp", 0xf0, parse_alf_args, NULL, ALOPF19, MAS | LOAD, 0x60, {0, 0, 1, 0, 0, 1}, ARGS_P};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"aptoap", 0x10, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_QSQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"aptoapb", 0x10, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_QSQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"getva", 0x10, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x52, {1, 0, 0, 1, 0, 0}, ARGS_QSD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpand", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x8, {1, 1, 0, 1, 1, 0}, ARGS_PPP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpandn", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x9, {1, 1, 0, 1, 1, 0}, ARGS_PPP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpor", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xa, {1, 1, 0, 1, 1, 0}, ARGS_PPP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpxor", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xb, {1, 1, 0, 1, 1, 0}, ARGS_PPP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpaddb", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x48, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpaddh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x49, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpaddsb", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4a, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpaddsh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4b, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpaddusb", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4c, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpaddush", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4d, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpaddw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4e, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpaddd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4f, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsubb", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x50, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsubh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x51, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsubsb", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x52, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsubsh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x53, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsubusb", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x54, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsubush", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x55, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsubw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x56, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsubd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x57, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfadds", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x70, {1, 1, 1, 1, 1, 1}, ARGS_PPP, NONE, {EXT1, EXT1, EXT1, EXT1, EXT1, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfaddd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x71, {1, 1, 1, 1, 1, 1}, ARGS_PPP, NONE, {EXT1, EXT1, EXT1, EXT1, EXT1, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfhadds", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7c, {1, 1, 1, 1, 1, 1}, ARGS_PPP, NONE, {EXT1, EXT1, EXT1, EXT1, EXT1, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfhsubs", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7d, {1, 1, 1, 1, 1, 1}, ARGS_PPP, NONE, {EXT1, EXT1, EXT1, EXT1, EXT1, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfaddsubs", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7e, {1, 1, 1, 1, 1, 1}, ARGS_PPP, NONE, {EXT1, EXT1, EXT1, EXT1, EXT1, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfaddsubd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7f, {1, 1, 1, 1, 1, 1}, ARGS_PPP, NONE, {EXT1, EXT1, EXT1, EXT1, EXT1, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfstoifs", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x6e, {1, 1, 0, 1, 1, 0}, ARGS_DPP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfdtoifd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x6f, {1, 1, 0, 1, 1, 0}, ARGS_DPP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfmins", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x74, {1, 1, 0, 1, 1, 0}, ARGS_PPP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfmind", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x75, {1, 1, 0, 1, 1, 0}, ARGS_PPP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfmaxs", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x76, {1, 1, 0, 1, 1, 0}, ARGS_PPP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfmaxd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x77, {1, 1, 0, 1, 1, 0}, ARGS_PPP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfmuls", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x78, {1, 1, 1, 1, 1, 1}, ARGS_PPP, NONE, {EXT1, EXT1, EXT1, EXT1, EXT1, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfmuld", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x79, {1, 1, 1, 1, 1, 1}, ARGS_PPP, NONE, {EXT1, EXT1, EXT1, EXT1, EXT1, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfsubs", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x72, {1, 1, 1, 1, 1, 1}, ARGS_PPP, NONE, {EXT1, EXT1, EXT1, EXT1, EXT1, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfsubd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x73, {1, 1, 1, 1, 1, 1}, ARGS_PPP, NONE, {EXT1, EXT1, EXT1, EXT1, EXT1, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpmsk2sgnb", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x34, {1, 1, 0, 1, 1, 0}, ARGS_PSP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qppackdl", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DDP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsllh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x5, {1, 1, 0, 1, 1, 0}, ARGS_PDP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsllw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4, {1, 1, 0, 1, 1, 0}, ARGS_PDP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpslld", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7, {1, 1, 0, 1, 1, 0}, ARGS_PDP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsrlh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1, {1, 1, 0, 1, 1, 0}, ARGS_PDP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsrlw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_PDP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsrld", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x6, {1, 1, 0, 1, 1, 0}, ARGS_PDP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsrah", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3, {1, 1, 0, 1, 1, 0}, ARGS_PDP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsraw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x2, {1, 1, 0, 1, 1, 0}, ARGS_PDP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpacksshb", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x48, {0, 1, 0, 0, 1, 0}, ARGS_PPP, NONE, {0, EXT1, 0, 0, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpacksswh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4a, {0, 1, 0, 0, 1, 0}, ARGS_PPP, NONE, {0, EXT1, 0, 0, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpackushb", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x49, {0, 1, 0, 0, 1, 0}, ARGS_PPP, NONE, {0, EXT1, 0, 0, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpackuswh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4b, {0, 1, 0, 0, 1, 0}, ARGS_PPP, NONE, {0, EXT1, 0, 0, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpavgusb", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x5e, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpavgush", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x5f, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpcmpeqb", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x58, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpcmpeqd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x18, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpcmpeqh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x59, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpcmpeqw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x5a, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpcmpgtb", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x5b, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpcmpgtd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1c, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpcmpgth", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x5c, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpcmpgtw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x5d, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qphaddh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x19, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qphaddsh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1b, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qphaddw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1a, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qphsubh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1d, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qphsubsh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1f, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qphsubw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x1e, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpmaxsb", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x46, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpmaxsh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x43, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpmaxsw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xf, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpmaxub", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x42, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpmaxuh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x47, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpmaxuw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xe, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpminsb", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x44, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpminsh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x41, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpminsw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xd, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpminub", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x40, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpminuh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x45, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpminuw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0xc, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpmulhh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x58, {0, 1, 0, 0, 1, 0}, ARGS_PPP, NONE, {0, EXT1, 0, 0, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpmulhrsh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x69, {0, 1, 0, 0, 1, 0}, ARGS_PPP, NONE, {0, EXT1, 0, 0, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpmulhuh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x5b, {0, 1, 0, 0, 1, 0}, ARGS_PPP, NONE, {0, EXT1, 0, 0, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpmullh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x59, {0, 1, 0, 0, 1, 0}, ARGS_PPP, NONE, {0, EXT1, 0, 0, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpmulubhh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x5d, {0, 1, 0, 0, 1, 0}, ARGS_DPP, NONE, {0, EXT1, 0, 0, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsignb", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x38, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsignh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x39, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsignw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3a, {1, 0, 0, 1, 0, 0}, ARGS_PPP, NONE, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qphminposuh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x6a, {0, 1, 0, 0, 1, 0}, ARGS_PPD, NONE, {0, EXT1, 0, 0, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpmaddh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x5a, {0, 1, 0, 0, 1, 0}, ARGS_PPP, NONE, {0, EXT1, 0, 0, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpmaddubsh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x68, {0, 1, 0, 0, 1, 0}, ARGS_PPP, NONE, {0, EXT1, 0, 0, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpmpsadbh", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x6b, {0, 1, 0, 0, 1, 0}, ARGS_PSP, NONE, {0, EXT1, 0, 0, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsadbw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x5c, {0, 1, 0, 0, 1, 0}, ARGS_PPP, NONE, {0, EXT1, 0, 0, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsrcd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x27, {1, 1, 0, 1, 1, 0}, ARGS_PDP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsrcw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x26, {1, 1, 0, 1, 1, 0}, ARGS_PDP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psrcd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x17, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"psrcw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"getfzs", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x74, {1, 1, 1, 1, 1, 1}, ARGS_SSS, NONE, {EXT, EXT, EXT, EXT, EXT, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"getfzd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x75, {1, 1, 1, 1, 1, 1}, ARGS_DDD, NONE, {EXT, EXT, EXT, EXT, EXT, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"puttagqp", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x6c, {1, 1, 0, 1, 1, 0}, ARGS_PSP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmullw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x26, {0, 1, 0, 0, 1, 0}, ARGS_DDD, NONE, {0, EXT, 0, 0, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpmullw", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x5e, {0, 1, 0, 0, 1, 0}, ARGS_PPP, NONE, {0, EXT1, 0, 0, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfcmpeqs", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc0, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfcmplts", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc1, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfcmples", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc2, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfcmpuods", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc3, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfcmpneqs", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc4, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfcmpnlts", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc5, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfcmpnles", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc6, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfcmpods", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc7, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfcmpeqd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc0, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfcmpltd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc1, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfcmpled", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc2, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfcmpuodd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc3, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfcmpneqd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc4, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfcmpnltd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc5, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfcmpnled", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc6, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfcmpodd", 0xf0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc7, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldq", 0xf0, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x41, {1, 0, 1, 1, 0, 1}, ARGS_DDQ, NONE, {EXT, 0, EXT, EXT, 0, EXT}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldqp", 0xf0, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x61, {1, 0, 1, 1, 0, 1}, ARGS_DDP, NONE, {EXT1, 0, EXT1, EXT1, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldgdqp", 0xf0, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x69, {1, 0, 1, 1, 0, 1}, ARGS_SSP, NONE, {EXT1, 0, EXT1, EXT1, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldcudqp", 0xf0, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x68, {1, 0, 1, 1, 0, 1}, ARGS_SSP, NONE, {EXT1, 0, EXT1, EXT1, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldcsqp", 0xf0, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x62, {1, 0, 1, 1, 0, 1}, ARGS_DDP, NONE, {EXT1, 0, EXT1, EXT1, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"lddsqp", 0xf0, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x63, {1, 0, 1, 1, 0, 1}, ARGS_DDP, NONE, {EXT1, 0, EXT1, EXT1, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldesqp", 0xf0, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x64, {1, 0, 1, 1, 0, 1}, ARGS_SSP, NONE, {EXT1, 0, EXT1, EXT1, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldfsqp", 0xf0, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x65, {1, 0, 1, 1, 0, 1}, ARGS_DDP, NONE, {EXT1, 0, EXT1, EXT1, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldgsqp", 0xf0, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x66, {1, 0, 1, 1, 0, 1}, ARGS_DDP, NONE, {EXT1, 0, EXT1, EXT1, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldssqp", 0xf0, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x67, {1, 0, 1, 1, 0, 1}, ARGS_DDP, NONE, {EXT1, 0, EXT1, EXT1, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldapqp", 0xf0, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x6a, {1, 0, 1, 1, 0, 1}, ARGS_QSP, NONE, {EXT1, 0, EXT1, EXT1, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldrqp", 0xf0, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x6b, {1, 0, 1, 1, 0, 1}, ARGS_DDP, NONE, {EXT1, 0, EXT1, EXT1, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"ldosrrqp", 0xc0, parse_alf_args, NULL, ALOPF11, MAS | LOAD, 0x6b, {1, 0, 1, 1, 0, 1}, ARGS_DDP, 0xdc, {EXT1, 0, EXT1, EXT1, 0, EXT1}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpsgn2mskb", 0xf0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_PS, NONE, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpswitchw", 0xf0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_PP, NONE, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpswitchd", 0xf0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_PP, NONE, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpfstois", 0xf0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_PP, 0xc8, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpfstoistr", 0xf0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_PP, 0xca, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpistofs", 0xf0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_PP, 0xcc, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpfstoid", 0xf0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DP, 0xd8, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpfstoidtr", 0xf0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DP, 0xda, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpistofd", 0xf0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DP, 0xdc, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpfstofd", 0xf0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DP, 0xde, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpfdtois", 0xf0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_PD, 0xe8, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpfdtoistr", 0xf0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_PD, 0xea, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpidtofs", 0xf0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_PD, 0xec, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpfdtofs", 0xf0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_PD, 0xee, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpfdtoid", 0xf0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_PP, 0xf8, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpfdtoidtr", 0xf0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_PP, 0xfa, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpidtofd", 0xf0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_PP, 0xfc, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stq", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x1, {0, 0, 1, 0, 0, 1}, ARGS_DDQ, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stgdmqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x19, {0, 0, 1, 0, 0, 1}, ARGS_SSP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stgdqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x29, {0, 0, 1, 0, 0, 1}, ARGS_SSP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stapqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x2a, {0, 0, 1, 0, 0, 1}, ARGS_QSP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stapmqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x1a, {0, 0, 1, 0, 0, 1}, ARGS_QSP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stmqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x11, {0, 0, 1, 0, 0, 1}, ARGS_DDP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x21, {0, 0, 1, 0, 0, 1}, ARGS_DDP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stcsmqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x12, {0, 0, 1, 0, 0, 1}, ARGS_DDP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stcsqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x22, {0, 0, 1, 0, 0, 1}, ARGS_DDP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stdsmqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x13, {0, 0, 1, 0, 0, 1}, ARGS_DDP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stdsqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x23, {0, 0, 1, 0, 0, 1}, ARGS_DDP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stesmqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x14, {0, 0, 1, 0, 0, 1}, ARGS_SSP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stesqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x24, {0, 0, 1, 0, 0, 1}, ARGS_SSP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stfsmqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x15, {0, 0, 1, 0, 0, 1}, ARGS_DDP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stfsqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x25, {0, 0, 1, 0, 0, 1}, ARGS_DDP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stgsmqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x16, {0, 0, 1, 0, 0, 1}, ARGS_DDP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stgsqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x26, {0, 0, 1, 0, 0, 1}, ARGS_DDP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stssmqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x17, {0, 0, 1, 0, 0, 1}, ARGS_DDP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stssqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x27, {0, 0, 1, 0, 0, 1}, ARGS_DDP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"strqp", 0xf0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x2b, {0, 0, 1, 0, 0, 1}, ARGS_DDP, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf13_opcode_templ dummy =
		{"stosrrqp", 0xc0, parse_alf_args, NULL, ALOPF13, MAS | STORE, 0x2b, {0, 0, 1, 0, 0, 1}, ARGS_DDP, 0xdc, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"addcd", 0xf0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {0, 1, 0, 0, 1, 0}, ARGS_DDSD, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"addcd_c", 0xf0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x61, {0, 1, 0, 0, 1, 0}, ARGS_DDSD, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"subcd", 0xf0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {0, 1, 0, 0, 1, 0}, ARGS_DDSD, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"subcd_c", 0xf0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x63, {0, 1, 0, 0, 1, 0}, ARGS_DDSD, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"vfsi", 0x20, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x63, {0, 1, 0, 0, 1, 0}, ARGS_SDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"vfbgv", 0xe0, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x68, {0, 1, 0, 0, 1, 0}, ARGS_SSS};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"mkfsw", 0xe0, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x6a, {0, 1, 0, 0, 1, 0}, ARGS_SSD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"modbgv", 0xe0, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x69, {0, 1, 0, 0, 1, 0}, ARGS_SS, 0xc0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"pcmpeqbop", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x28, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xc0, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"pcmpeqhop", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x28, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xc1, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"pcmpeqwop", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x28, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xc2, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"pcmpeqdop", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x28, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xc3, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"pcmpgtbop", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x28, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xc4, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"pcmpgthop", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x28, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xc5, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"pcmpgtwop", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x28, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xc6, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"pcmpgtdop", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x28, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xc7, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"pcmpeqbap", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x28, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xc8, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"pcmpeqhap", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x28, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xc9, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"pcmpeqwap", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x28, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xca, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"pcmpeqdap", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x28, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xcb, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"pcmpgtbap", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x28, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xcc, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"pcmpgthap", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x28, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xcd, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"pcmpgtwap", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x28, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xce, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"pcmpgtdap", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x28, {1, 0, 0, 1, 0, 0}, ARGS_DD, 0xcf, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"qpcmpeqbop", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x2c, {1, 0, 0, 1, 0, 0}, ARGS_PP, 0xc0, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"qpcmpeqhop", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x2c, {1, 0, 0, 1, 0, 0}, ARGS_PP, 0xc1, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"qpcmpeqwop", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x2c, {1, 0, 0, 1, 0, 0}, ARGS_PP, 0xc2, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"qpcmpeqdop", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x2c, {1, 0, 0, 1, 0, 0}, ARGS_PP, 0xc3, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"qpcmpgtbop", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x2c, {1, 0, 0, 1, 0, 0}, ARGS_PP, 0xc4, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"qpcmpgthop", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x2c, {1, 0, 0, 1, 0, 0}, ARGS_PP, 0xc5, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"qpcmpgtwop", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x2c, {1, 0, 0, 1, 0, 0}, ARGS_PP, 0xc6, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"qpcmpgtdop", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x2c, {1, 0, 0, 1, 0, 0}, ARGS_PP, 0xc7, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"qpcmpeqbap", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x2c, {1, 0, 0, 1, 0, 0}, ARGS_PP, 0xc8, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"qpcmpeqhap", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x2c, {1, 0, 0, 1, 0, 0}, ARGS_PP, 0xc9, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"qpcmpeqwap", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x2c, {1, 0, 0, 1, 0, 0}, ARGS_PP, 0xca, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"qpcmpeqdap", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x2c, {1, 0, 0, 1, 0, 0}, ARGS_PP, 0xcb, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"qpcmpgtbap", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x2c, {1, 0, 0, 1, 0, 0}, ARGS_PP, 0xcc, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"qpcmpgthap", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x2c, {1, 0, 0, 1, 0, 0}, ARGS_PP, 0xcd, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"qpcmpgtwap", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x2c, {1, 0, 0, 1, 0, 0}, ARGS_PP, 0xce, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf7_opcode_templ dummy =
		{"qpcmpgtdap", 0xe0, parse_alf_args, NULL, ALOPF17, NO_MAS, 0x2c, {1, 0, 0, 1, 0, 0}, ARGS_PP, 0xcf, 2, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"aptoap", 0x20, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_QSQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"aptoapb", 0x20, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_QSQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"getva", 0x20, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x52, {1, 0, 0, 1, 0, 0}, ARGS_QSD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsrad", 0xe0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x25, {1, 1, 0, 1, 1, 0}, ARGS_PDP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"pmrgp", 0xe0, parse_alf_args, NULL, ALOPF11_MERGE, NO_MAS, 0x40, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpmrgp", 0xe0, parse_alf_args, NULL, ALOPF11_MERGE, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_PPP, NONE, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"clmulh", 0xe0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x15, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT2, EXT2, 0, EXT2, EXT2, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"clmull", 0xe0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x14, {1, 1, 0, 1, 1, 0}, ARGS_DDD, NONE, {EXT2, EXT2, 0, EXT2, EXT2, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpchecks", 0xe0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x33, {1, 0, 0, 1, 0, 0}, ARGS_SSS, QPCHECKS, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpcheckd", 0xe0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x33, {1, 0, 0, 1, 0, 0}, ARGS_DDD, QPCHECKD, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpcheckq", 0xe0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x33, {1, 0, 0, 1, 0, 0}, ARGS_PPP, QPCHECKQ, {EXT1, 0, 0, EXT1, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"ibranchd", 0xe0, parse_alf_args, NULL, ALOPF12_IBRANCHD, NO_MAS, 0x53, {1, 0, 0, 0, 0, 0}, ARGS_DD, NONE, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"icalld", 0xe0, parse_alf_args, NULL, ALOPF12_ICALLD, NO_MAS, 0x54, {1, 0, 0, 0, 0, 0}, ARGS_DD, NONE, NONE, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpcext_0x00", 0xe0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DP, NONE, 0xc0, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpcext_0x7f", 0xe0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DP, NONE, 0xc2, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpcext_0x80", 0xe0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DP, NONE, 0xc4, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpcext_0xff", 0xe0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DP, NONE, 0xc6, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fmas", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {1, 1, 1, 1, 1, 1}, ARGS_SSSS, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fmss", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {1, 1, 1, 1, 1, 1}, ARGS_SSSS, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fnmas", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {1, 1, 1, 1, 1, 1}, ARGS_SSSS, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fnmss", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {1, 1, 1, 1, 1, 1}, ARGS_SSSS, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fmad", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {1, 1, 1, 1, 1, 1}, ARGS_DDDD, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fmsd", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {1, 1, 1, 1, 1, 1}, ARGS_DDDD, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fnmad", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5, {1, 1, 1, 1, 1, 1}, ARGS_DDDD, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fnmsd", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7, {1, 1, 1, 1, 1, 1}, ARGS_DDDD, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmas", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmss", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xa, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfnmas", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xc, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfnmss", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xe, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmad", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmsd", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xb, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfnmad", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xd, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfnmsd", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xf, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmass", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x10, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmsas", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x12, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmasd", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x11, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmsad", 0xe0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x13, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf1_opcode_templ dummy =
		{"vfsid", 0xc0, parse_alf_args, NULL, ALOPF1, NO_MAS, 0x6b, {0, 1, 0, 0, 1, 0}, ARGS_SDD};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alf2_opcode_templ dummy =
		{"getpl", 0xc0, parse_alf_args, NULL, ALOPF2, NO_MAS, 0x63, {0, 1, 0, 0, 1, 0}, ARGS_SD, 0xf0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"getptr", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x52, {1, 0, 0, 1, 0, 0}, ARGS_QSD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"getptrc", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x52, {1, 0, 0, 1, 0, 0}, ARGS_QSD, 0xc1, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"getmi", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4e, {1, 0, 0, 1, 0, 0}, ARGS_QSD, NONE, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"getind", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x4e, {1, 0, 0, 1, 0, 0}, ARGS_QSD, 0xc1, {EXT, 0, 0, EXT, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"apincr", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_QDQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"apincrc", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_QDQ, 0xc1, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"subarr", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_QDQ, NONE, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"subarrc", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_QDQ, 0xc1, {EXT, EXT, 0, EXT, EXT, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsbgltrlo", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x33, {0, 1, 0, 0, 0, 0}, ARGS_PPP, NONE, {0, EXT1, 0, 0, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpsbgltrhi", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x33, {0, 1, 0, 0, 0, 0}, ARGS_PPP, 0xc1, {0, EXT1, 0, 0, 0, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qps2mb", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_PPS, QPB, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qps2mh", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_PPS, QPH, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qps2mw", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_PPS, QPW, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qps2md", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_PPS, QPD, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qps2cmh", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x37, {1, 1, 0, 1, 1, 0}, ARGS_PPS, QPH, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qps2cmw", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x37, {1, 1, 0, 1, 1, 0}, ARGS_PPS, QPW, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qps2cmd", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x37, {1, 1, 0, 1, 1, 0}, ARGS_PPS, QPD, {EXT1, EXT1, 0, EXT1, EXT1, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpfstobf", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x17, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xce, {EXT2, EXT2, 0, EXT2, EXT2, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpackhbss", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc0, {EXT2, EXT2, 0, EXT2, EXT2, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpackhbus", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc1, {EXT2, EXT2, 0, EXT2, EXT2, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpackwhss", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc2, {EXT2, EXT2, 0, EXT2, EXT2, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf11_opcode_templ dummy =
		{"qpackwhus", 0xc0, parse_alf_args, NULL, ALOPF11, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_PPP, 0xc3, {EXT2, EXT2, 0, EXT2, EXT2, 0}, 0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"getspd", 0xc0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x59, {1, 0, 0, 0, 0, 0}, ARGS_DD, 0xec, 0xc0, 0x1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpkuzltr", 0xc0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x32, {0, 1, 0, 0, 1, 0}, ARGS_PP, NONE, NONE, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpcm2b", 0xc0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_SP, NONE, QPB, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpcm2h", 0xc0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_SP, NONE, QPH, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpcm2w", 0xc0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_SP, NONE, QPW, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf12_opcode_templ dummy =
		{"qpcm2d", 0xc0, parse_alf_args, NULL, ALOPF12, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_SP, NONE, QPD, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpmgme", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x27, {1, 0, 0, 0, 0, 0}, ARGS_PPPP, EXT};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpaesebgn", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x34, {0, 0, 1, 0, 0, 1}, ARGS_PPPP, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpaesltr", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {0, 1, 0, 0, 1, 0}, ARGS_PPPP, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpaesdbgn", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x35, {0, 0, 1, 0, 0, 1}, ARGS_PPPP, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpaesiltr", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {0, 1, 0, 0, 1, 0}, ARGS_PPPP, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpkuzebgn", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x36, {0, 0, 1, 0, 0, 1}, ARGS_PPPP, EXT1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpidotsbwss", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpidotsbwus", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpidotsbwuu", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpidotshdss", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpidotshduu", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpidotshwss", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpbfdots", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qptbl_0", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qptbl_0x0", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qptbl_1", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qptbl_0x1", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qptbl_2", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qptbl_0x2", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qptbl_3", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qptbl_0x3", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qptbl_4", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qptbl_0x4", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qptbl_5", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qptbl_0x5", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qptbl_6", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qptbl_0x6", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qptbl_7", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qptbl_0x7", 0xc0, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, EXT2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_ands", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_andd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_ands", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_andd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_ands", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_andd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_ands", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_andd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_ands", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_andd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_ands", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xa, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_andd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xb, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_ands", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0xe, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_andd", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0xf, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_ands", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x10, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_andd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x11, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_ands", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x12, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_andd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x13, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_ands", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_andd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x15, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_ands", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_andd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x17, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_ands", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_andd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_ands", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_andd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_ands", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_andd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1d, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_ands", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_andd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_andns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_andnd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_andns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_andnd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_andns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_andnd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x25, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_andns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_andnd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x27, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_andns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_andnd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_andns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_andnd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_andns", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x2e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_andnd", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x2f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_andns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_andnd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_andns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_andnd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x33, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_andns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x34, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_andnd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x35, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_andns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x36, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_andnd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x37, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_andns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x38, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_andnd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x39, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_andns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_andnd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_andns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3c, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_andnd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3d, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_andns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_andnd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_ors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_ord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x41, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_ors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_ord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x43, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_ors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_ord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x45, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_ors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_ord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x47, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_ors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_ord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x49, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_ors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_ord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_ors", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x4e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_ord", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x4f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_ors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x50, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_ord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x51, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_ors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x52, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_ord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x53, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_ors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x54, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_ord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x55, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_ors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x56, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_ord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x57, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_ors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_ord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x59, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_ors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_ord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_ors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5c, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_ord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5d, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_ors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_ord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_orns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_ornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x61, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_orns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_ornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x63, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_orns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_ornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x65, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_orns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_ornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x67, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_orns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_ornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x69, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_orns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_ornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_orns", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x6e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_ornd", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x6f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_orns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x70, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_ornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x71, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_orns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x72, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_ornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x73, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_orns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x74, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_ornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x75, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_orns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x76, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_ornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x77, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_orns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x78, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_ornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x79, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_orns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_ornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_orns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7c, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_ornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7d, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_orns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_ornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_merges", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x60, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_merged", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x61, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_merges", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x62, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_merged", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x63, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_merges", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x64, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_merged", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x65, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_merges", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x66, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_merged", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x67, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_merges", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x68, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_merged", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x69, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_merges", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x6a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_merged", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x6b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_merges", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x6e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_merged", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x6f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_merges", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x70, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_merged", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x71, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_merges", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x72, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_merged", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x73, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_merges", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x74, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_merged", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x75, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_merges", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x76, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_merged", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x77, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_merges", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x78, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_merged", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x79, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_merges", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x7a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_merged", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x7b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_merges", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x7c, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_merged", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x7d, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_merges", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x7e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_merged", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x7f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_xors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_xord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_xors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_xord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_xors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_xord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_xors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_xord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_xors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_xord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_xors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xa, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_xord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xb, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_xors", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0xe, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_xord", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0xf, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_xors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x10, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_xord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x11, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_xors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x12, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_xord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x13, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_xors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_xord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x15, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_xors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_xord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x17, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_xors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_xord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_xors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_xord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_xors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_xord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1d, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_xors", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_xord", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_xorns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_xornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_xorns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_xornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_xorns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_xornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x25, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_xorns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_xornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x27, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_xorns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_xornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_xorns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_xornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_xorns", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x2e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_xornd", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x2f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_xorns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_xornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_xorns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_xornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x33, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_xorns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x34, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_xornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x35, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_xorns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x36, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_xornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x37, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_xorns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x38, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_xornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x39, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_xorns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_xornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_xorns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3c, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_xornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3d, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_xorns", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_xornd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_rsubs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_rsubd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x41, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_rsubs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_rsubd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x43, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_rsubs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_rsubd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x45, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_rsubs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_rsubd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x47, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_rsubs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_rsubd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x49, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_rsubs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_rsubd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_rsubs", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x4e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_rsubd", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x4f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_rsubs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x50, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_rsubd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x51, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_rsubs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x52, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_rsubd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x53, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_rsubs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x54, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_rsubd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x55, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_rsubs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x56, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_rsubd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x57, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_rsubs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_rsubd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x59, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_rsubs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_rsubd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_rsubs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5c, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_rsubd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5d, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_rsubs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_rsubd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_scls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_scld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x41, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_scls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_scld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x43, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_scls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_scld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x45, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_scls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_scld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x47, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_scls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_scld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x49, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_scls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_scld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_scls", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x4e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_scld", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x4f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_scls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x50, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_scld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x51, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_scls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x52, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_scld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x53, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_scls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x54, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_scld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x55, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_scls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x56, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_scld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x57, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_scls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_scld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x59, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_scls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_scld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_scls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5c, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_scld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5d, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_scls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_scld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_scrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_scrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x61, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_scrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_scrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x63, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_scrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_scrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x65, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_scrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_scrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x67, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_scrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_scrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x69, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_scrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_scrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_scrs", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x6e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_scrd", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x6f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_scrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x70, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_scrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x71, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_scrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x72, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_scrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x73, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_scrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x74, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_scrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x75, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_scrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x76, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_scrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x77, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_scrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x78, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_scrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x79, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_scrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_scrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_scrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7c, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_scrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7d, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_scrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_scrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_adds", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_addd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_adds", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_addd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_adds", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_addd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_adds", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_addd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_adds", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_addd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_adds", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xa, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_addd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xb, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_adds", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0xe, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_addd", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0xf, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_adds", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x10, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_addd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x11, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_adds", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x12, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_addd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x13, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_adds", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_addd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x15, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_adds", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_addd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x17, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_adds", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_addd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_adds", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_addd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_adds", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_addd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1d, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_adds", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_addd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_subs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_subd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_subs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_subd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_subs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_subd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x25, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_subs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_subd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x27, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_subs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_subd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_subs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_subd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_subs", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x2e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_subd", 0x7f, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x2f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_subs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_subd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_subs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_subd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x33, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_subs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x34, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_subd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x35, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_subs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x36, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_subd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x37, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_subs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x38, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_subd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x39, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_subs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_subd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_subs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3c, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_subd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3d, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_subs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_subd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB2};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_shls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_shld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_shls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_shld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_shls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_shld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_shls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_shld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_shls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_shld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_shls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xa, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_shld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xb, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_shls", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0xe, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_shld", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0xf, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_shls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x10, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_shld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x11, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_shls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x12, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_shld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x13, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_shls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_shld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x15, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_shls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_shld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x17, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_shls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_shld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_shls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_shld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_shls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_shld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1d, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_shls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_shld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_shrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_shrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_shrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_shrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_shrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_shrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x25, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_shrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_shrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x27, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_shrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_shrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_shrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_shrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_shrs", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x2e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_shrd", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x2f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_shrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_shrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_shrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_shrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x33, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_shrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x34, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_shrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x35, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_shrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x36, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_shrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x37, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_shrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x38, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_shrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x39, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_shrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_shrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_shrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3c, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_shrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3d, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_shrs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_shrd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_sars", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_sard", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x41, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_sars", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_sard", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x43, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_sars", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_sard", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x45, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_sars", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_sard", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x47, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_sars", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_sard", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x49, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_sars", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_sard", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_sars", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x4e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_sard", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x4f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_sars", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x50, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_sard", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x51, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_sars", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x52, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_sard", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x53, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_sars", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x54, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_sard", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x55, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_sars", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x56, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_sard", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x57, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_sars", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_sard", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x59, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_sars", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_sard", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_sars", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5c, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_sard", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5d, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_sars", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_sard", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_getfs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"and_getfd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x61, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_getfs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"andn_getfd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x63, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_getfs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"or_getfd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x65, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_getfs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"orn_getfd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x67, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_getfs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xor_getfd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x69, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_getfs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"xorn_getfd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_getfs", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x6e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"merge_getfd", 0x01, parse_alf_args, NULL, ALOPF21_MERGE, NO_MAS, 0x6f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_getfs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x70, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"add_getfd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x71, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_getfs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x72, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sub_getfd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x73, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_getfs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x74, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scl_getfd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x75, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_getfs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x76, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"scr_getfd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x77, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_getfs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x78, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shl_getfd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x79, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_getfs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7a, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"shr_getfd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7b, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_getfs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7c, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"sar_getfd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7d, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_getfs", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {0, 1, 0, 0, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"getf_getfd", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7f, {0, 1, 0, 0, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"insfs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6c, {1, 1, 0, 1, 1, 0}, ARGS_SSSS, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"insfd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, ICMB3};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fmul_adds", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {1, 1, 0, 1, 1, 0}, ARGS_SSSS, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fmul_addd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fmul_subs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_SSSS, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fmul_subd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fadd_adds", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_SSSS, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fadd_addd", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fsub_adds", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {1, 1, 0, 1, 1, 0}, ARGS_SSSS, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fsub_addd", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fadd_subs", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_SSSS, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fadd_subd", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fsub_subs", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_SSSS, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fsub_subd", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fadd_adds", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {0, 0, 1, 0, 0, 1}, ARGS_SSSS, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fadd_addd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fsub_adds", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {0, 0, 1, 0, 0, 1}, ARGS_SSSS, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fsub_addd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fmul_adds", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {0, 0, 1, 0, 0, 1}, ARGS_SSSS, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fmul_addd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fadd_subs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {0, 0, 1, 0, 0, 1}, ARGS_SSSS, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fadd_subd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fsub_subs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {0, 0, 1, 0, 0, 1}, ARGS_SSSS, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fsub_subd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fmul_subs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {0, 0, 1, 0, 0, 1}, ARGS_SSSS, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fmul_subd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, FCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fadd_muls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_SSSS, FCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fadd_muld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, FCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fsub_muls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {1, 1, 0, 1, 1, 0}, ARGS_SSSS, FCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fsub_muld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, FCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fmul_rsubs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_SSSS, FCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fmul_rsubd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, FCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fadd_rsubs", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_SSSS, FCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fadd_rsubd", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, FCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fsub_rsubs", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_SSSS, FCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fsub_rsubd", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, FCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fadd_rsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {0, 0, 1, 0, 0, 1}, ARGS_SSSS, FCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fadd_rsubd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, FCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fsub_rsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {0, 0, 1, 0, 0, 1}, ARGS_SSSS, FCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fsub_rsubd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, FCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fmul_rsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {0, 0, 1, 0, 0, 1}, ARGS_SSSS, FCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"fmul_rsubd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, FCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_adds", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_addd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_subs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_subd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_adds", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_addd", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_adds", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_addd", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_subs", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_subd", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_subs", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_subd", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhadd_adds", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhsub_adds", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfaddsub_adds", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xe, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhadd_subs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhsub_subs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfaddsub_subs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_hadds", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_hadds", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhadd_hadds", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhsub_hadds", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_hadds", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfaddsub_hadds", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_hsubs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_hsubs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhadd_hsubs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhsub_hsubs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_hsubs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfaddsub_hsubs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_adds", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_addd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_adds", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_addd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhadd_adds", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhsub_adds", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_adds", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_addd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfaddsub_adds", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xe, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_subs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_subd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_subs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_subd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhadd_subs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhsub_subs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_subs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_subd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfaddsub_subs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_hadds", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_hadds", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhadd_hadds", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhsub_hadds", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_hadds", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfaddsub_hadds", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_hsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_hsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhadd_hsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhsub_hsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_hsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfaddsub_hsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_muls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_muld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_muls", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_muld", 0x01, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_rsubs", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_rsubd", 0x7f, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_rsubs", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_rsubd", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_rsubs", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_rsubd", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pshufb", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pmerge", 0x7e, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhadd_rsubs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhsub_rsubs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfaddsub_rsubs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_addsubs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_addsubs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhadd_addsubs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhsub_addsubs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_addsubs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfaddsub_addsubs", 0x7c, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_rsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_rsubd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_rsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_rsubd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhadd_rsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhsub_rsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_rsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_rsubd", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfaddsub_rsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfadd_addsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfsub_addsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhadd_addsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfhsub_addsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfmul_addsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"pfaddsub_addsubs", 0x78, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, PFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfadd_adds", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfadd_addd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfsub_adds", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfsub_addd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfhadd_adds", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfhsub_adds", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmul_adds", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmul_addd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfaddsub_adds", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xe, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfaddsub_addd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xf, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfadd_subs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfadd_subd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfsub_subs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfsub_subd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfhadd_subs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfhsub_subs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmul_subs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmul_subd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfaddsub_subs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfaddsub_subd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2f, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfadd_hadds", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfsub_hadds", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfhadd_hadds", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfhsub_hadds", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmul_hadds", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfaddsub_hadds", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4e, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfadd_hsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfsub_hsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfhadd_hsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfhsub_hsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmul_hsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfaddsub_hsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qppermb", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xd, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qppermb_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xd, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfadd_rsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfadd_rsubd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfsub_rsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfsub_rsubd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfhadd_rsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfhsub_rsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmul_rsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmul_rsubd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfaddsub_rsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfaddsub_rsubd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2f, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpshufb", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4d, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfadd_addsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfadd_addsubd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x61, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfsub_addsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfsub_addsubd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x63, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfhadd_addsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfhsub_addsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmul_addsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfmul_addsubd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x69, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpmerge", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfaddsub_addsubs", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpfaddsub_addsubd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6f, {1, 1, 1, 1, 1, 1}, ARGS_PPPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpinss", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_PSPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpinss_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_PSPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpinsd", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_PDPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qpinsd_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_PDPP, QPFCMB1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_1", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_2", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_3", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_4", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_5", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_6", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_7", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_8", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_9", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_10", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xa, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_11", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xb, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_12", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xc, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_13", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xd, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_14", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xe, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_15", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xf, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_16", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x10, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_17", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x11, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_18", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x12, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_19", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x13, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_20", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_21", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x15, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_22", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_23", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x17, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_24", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_25", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_26", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_27", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_28", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_29", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_30", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_31", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_32", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_33", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_34", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_35", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_36", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_37", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x25, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_38", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_39", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x27, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_40", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_41", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_42", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_43", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_44", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_45", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_46", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_47", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_48", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_49", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_50", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_51", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x33, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_52", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x34, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_53", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_54", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_55", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x37, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_56", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x38, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_57", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x39, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_58", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_59", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_60", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_61", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_62", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_63", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_64", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_65", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x41, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_66", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_67", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x43, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_68", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_69", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x45, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_70", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_71", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x47, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_72", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_73", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x49, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_74", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_75", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_76", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_77", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_78", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_79", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_80", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_81", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_82", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x52, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_83", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x53, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_84", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x54, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_85", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x55, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_86", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x56, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_87", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x57, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_88", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_89", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x59, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_90", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_91", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_92", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_93", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_94", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_95", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_96", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_97", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x61, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_98", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_99", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x63, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_100", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_101", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x65, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_102", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_103", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x67, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_104", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_105", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x69, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_106", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_107", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_108", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_109", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_110", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_111", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_112", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x70, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_113", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x71, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_114", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x72, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_115", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x73, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_116", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x74, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_117", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x75, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_118", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x76, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_119", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x77, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_120", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x78, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_121", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x79, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_122", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_123", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_124", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_125", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_126", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_127", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x00", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x01", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x02", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x03", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x04", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x05", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x06", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x07", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x08", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x09", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x0a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xa, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x0b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xb, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x0c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xc, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x0d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xd, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x0e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xe, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x0f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xf, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x10", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x10, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x11", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x11, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x12", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x12, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x13", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x13, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x14", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x15", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x15, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x16", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x17", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x17, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x18", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x19", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x1a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x1b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x1c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x1d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x1e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x1f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x20", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x21", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x22", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x23", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x24", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x25", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x25, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x26", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x27", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x27, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x28", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x29", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x2a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x2b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x2c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x2d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x2e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x2f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x30", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x31", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x32", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x33", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x33, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x34", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x34, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x35", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x36", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x37", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x37, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x38", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x38, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x39", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x39, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x3a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x3b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x3c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x3d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x3e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x3f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x40", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x41", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x41, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x42", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x43", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x43, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x44", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x45", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x45, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x46", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x47", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x47, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x48", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x49", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x49, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x4a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x4b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x4c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x4d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x4e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x4f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x50", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x51", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x52", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x52, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x53", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x53, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x54", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x54, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x55", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x55, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x56", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x56, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x57", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x57, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x58", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x59", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x59, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x5a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x5b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x5c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x5d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x5e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x5f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x60", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x61", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x61, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x62", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x63", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x63, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x64", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x65", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x65, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x66", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x67", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x67, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x68", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x69", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x69, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x6a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x6b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x6c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x6d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x6e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x6f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x70", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x70, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x71", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x71, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x72", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x72, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x73", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x73, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x74", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x74, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x75", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x75, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x76", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x76, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x77", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x77, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x78", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x78, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x79", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x79, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x7a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x7b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x7c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x7d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x7e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x7f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_128", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_129", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_130", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_131", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_132", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_133", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_134", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_135", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_136", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_137", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_138", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xa, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_139", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xb, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_140", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xc, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_141", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xd, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_142", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xe, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_143", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xf, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_144", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x10, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_145", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x11, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_146", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x12, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_147", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x13, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_148", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_149", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x15, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_150", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_151", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x17, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_152", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_153", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_154", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_155", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_156", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_157", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_158", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_159", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_160", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_161", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_162", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_163", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_164", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_165", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x25, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_166", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_167", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x27, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_168", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_169", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_170", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_171", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_172", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_173", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_174", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_175", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_176", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_177", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_178", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_179", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x33, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_180", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x34, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_181", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_182", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_183", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x37, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_184", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x38, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_185", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x39, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_186", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_187", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_188", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_189", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_190", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_191", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_192", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_193", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x41, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_194", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_195", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x43, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_196", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_197", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x45, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_198", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_199", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x47, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_200", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_201", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x49, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_202", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_203", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_204", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_205", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_206", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_207", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_208", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_209", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_210", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x52, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_211", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x53, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_212", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x54, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_213", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x55, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_214", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x56, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_215", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x57, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_216", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_217", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x59, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_218", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_219", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_220", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_221", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_222", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_223", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_224", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_225", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x61, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_226", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_227", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x63, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_228", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_229", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x65, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_230", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_231", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x67, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_232", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_233", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x69, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_234", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_235", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_236", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_237", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_238", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_239", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_240", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x70, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_241", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x71, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_242", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x72, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_243", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x73, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_244", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x74, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_245", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x75, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_246", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x76, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_247", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x77, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_248", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x78, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_249", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x79, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_250", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_251", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_252", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_253", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_254", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_255", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x80", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x81", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x82", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x83", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x84", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x85", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x86", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x87", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x88", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x89", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x8a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xa, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x8b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xb, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x8c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xc, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x8d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xd, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x8e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xe, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x8f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xf, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x90", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x10, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x91", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x11, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x92", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x12, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x93", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x13, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x94", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x95", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x15, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x96", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x97", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x17, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x98", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x99", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x9a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x9b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x9c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x9d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x9e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0x9f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xa0", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xa1", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xa2", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xa3", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xa4", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xa5", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x25, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xa6", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xa7", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x27, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xa8", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xa9", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xaa", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xab", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xac", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xad", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xae", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xaf", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xb0", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xb1", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xb2", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xb3", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x33, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xb4", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x34, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xb5", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xb6", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xb7", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x37, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xb8", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x38, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xb9", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x39, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xba", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xbb", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xbc", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xbd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xbe", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xbf", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xc0", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xc1", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x41, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xc2", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xc3", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x43, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xc4", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xc5", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x45, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xc6", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xc7", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x47, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xc8", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xc9", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x49, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xca", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xcb", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xcc", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xcd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xce", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xcf", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xd0", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xd1", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xd2", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x52, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xd3", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x53, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xd4", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x54, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xd5", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x55, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xd6", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x56, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xd7", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x57, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xd8", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xd9", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x59, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xda", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xdb", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xdc", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xdd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xde", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xdf", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xe0", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xe1", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x61, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xe2", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xe3", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x63, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xe4", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xe5", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x65, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xe6", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xe7", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x67, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xe8", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xe9", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x69, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xea", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xeb", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xec", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xed", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xee", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xef", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xf0", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x70, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xf1", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x71, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xf2", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x72, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xf3", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x73, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xf4", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x74, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xf5", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x75, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xf6", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x76, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xf7", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x77, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xf8", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x78, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xf9", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x79, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xfa", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xfb", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xfc", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xfd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xfe", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_0xff", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_and", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_xor", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_sel3", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_mjr", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"plog_or", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBD1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_1", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_1_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_2", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_2_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_3", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_3_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_4", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_4_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_5", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_5_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_6", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_6_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_7", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_7_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_8", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_8_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x8, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_9", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_9_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x9, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_10", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xa, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_10_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xa, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_11", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xb, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_11_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xb, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_12", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xc, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_12_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xc, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_13", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xd, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_13_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xd, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_14", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xe, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_14_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xe, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_15", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xf, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_15_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xf, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_16", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x10, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_16_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x10, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_17", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x11, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_17_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x11, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_18", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x12, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_18_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x12, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_19", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x13, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_19_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x13, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_20", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_20_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x14, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_21", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x15, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_21_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x15, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_22", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_22_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_23", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x17, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_23_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x17, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_24", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_24_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x18, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_25", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_25_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x19, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_26", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_26_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_27", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_27_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_28", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_28_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_29", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_29_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_30", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_30_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_31", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_31_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_32", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_32_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_33", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_33_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_34", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_34_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_35", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_35_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_36", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_36_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x24, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_37", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x25, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_37_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x25, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_38", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_38_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x26, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_39", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x27, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_39_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x27, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_40", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_40_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_41", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_41_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_42", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_42_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_43", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_43_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_44", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_44_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_45", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_45_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_46", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_46_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_47", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_47_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_48", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_48_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x30, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_49", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_49_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x31, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_50", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_50_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x32, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_51", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x33, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_51_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x33, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_52", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x34, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_52_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x34, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_53", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_53_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_54", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_54_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_55", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x37, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_55_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x37, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_56", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x38, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_56_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x38, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_57", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x39, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_57_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x39, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_58", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_58_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_59", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_59_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_60", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_60_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_61", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_61_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_62", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_62_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_63", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_63_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_64", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_64_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x40, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_65", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x41, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_65_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x41, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_66", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_66_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x42, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_67", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x43, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_67_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x43, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_68", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_68_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x44, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_69", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x45, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_69_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x45, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_70", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_70_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x46, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_71", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x47, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_71_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x47, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_72", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_72_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x48, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_73", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x49, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_73_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x49, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_74", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_74_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_75", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_75_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_76", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_76_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_77", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_77_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_78", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_78_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_79", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_79_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_80", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_80_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_81", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_81_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_82", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x52, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_82_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x52, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_83", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x53, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_83_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x53, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_84", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x54, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_84_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x54, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_85", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x55, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_85_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x55, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_86", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x56, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_86_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x56, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_87", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x57, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_87_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x57, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_88", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_88_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x58, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_89", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x59, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_89_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x59, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_90", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_90_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_91", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_91_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_92", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_92_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_93", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_93_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_94", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_94_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_95", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_95_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_96", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_96_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_97", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x61, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_97_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x61, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_98", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_98_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_99", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x63, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_99_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x63, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_100", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_100_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x64, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_101", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x65, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_101_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x65, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_102", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_102_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x66, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_103", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x67, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_103_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x67, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_104", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_104_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x68, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_105", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x69, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_105_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x69, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_106", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_106_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_107", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_107_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_108", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_108_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_109", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_109_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_110", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_110_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_111", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_111_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_112", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x70, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_112_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x70, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_113", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x71, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_113_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x71, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_114", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x72, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_114_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x72, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_115", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x73, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_115_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x73, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_116", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x74, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_116_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x74, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_117", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x75, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_117_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x75, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_118", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x76, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_118_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x76, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_119", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x77, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_119_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x77, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_120", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x78, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_120_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x78, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_121", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x79, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_121_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x79, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_122", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_122_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_123", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_123_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_124", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_124_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_125", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_125_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_126", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_126_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_127", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_127_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x0, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_1", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_1_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_2", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_2_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_3", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_3_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_4", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_4_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_5", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_5_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_6", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_6_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_7", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_7_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_8", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_8_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x8, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_9", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_9_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x9, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_10", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xa, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_10_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xa, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_11", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xb, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_11_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xb, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_12", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xc, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_12_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xc, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_13", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xd, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_13_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xd, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_14", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xe, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_14_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xe, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_15", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xf, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_15_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xf, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_16", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x10, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_16_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x10, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_17", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x11, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_17_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x11, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_18", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x12, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_18_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x12, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_19", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x13, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_19_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x13, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_20", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_20_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x14, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_21", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x15, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_21_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x15, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_22", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_22_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x16, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_23", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x17, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_23_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x17, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_24", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_24_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x18, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_25", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_25_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x19, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_26", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_26_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_27", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_27_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_28", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_28_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_29", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_29_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_30", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_30_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_31", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_31_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_32", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_32_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x20, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_33", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_33_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x21, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_34", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_34_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x22, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_35", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_35_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x23, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_36", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_36_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x24, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_37", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x25, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_37_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x25, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_38", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_38_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x26, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_39", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x27, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_39_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x27, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_40", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_40_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x28, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_41", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_41_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x29, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_42", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_42_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_43", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_43_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_44", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_44_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_45", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_45_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_46", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_46_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_47", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_47_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_48", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_48_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x30, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_49", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_49_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x31, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_50", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_50_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x32, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_51", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x33, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_51_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x33, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_52", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x34, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_52_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x34, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_53", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x35, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_53_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x35, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_54", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x36, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_54_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x36, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_55", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x37, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_55_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x37, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_56", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x38, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_56_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x38, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_57", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x39, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_57_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x39, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_58", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_58_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_59", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_59_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_60", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_60_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_61", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_61_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_62", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_62_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_63", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_63_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_64", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_64_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x40, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_65", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x41, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_65_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x41, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_66", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_66_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x42, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_67", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x43, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_67_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x43, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_68", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_68_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x44, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_69", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x45, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_69_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x45, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_70", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_70_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x46, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_71", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x47, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_71_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x47, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_72", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_72_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x48, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_73", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x49, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_73_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x49, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_74", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_74_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_75", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_75_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_76", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_76_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_77", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_77_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_78", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_78_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_79", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_79_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_80", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x50, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_80_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x50, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_81", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x51, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_81_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x51, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_82", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x52, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_82_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x52, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_83", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x53, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_83_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x53, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_84", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x54, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_84_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x54, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_85", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x55, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_85_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x55, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_86", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x56, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_86_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x56, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_87", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x57, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_87_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x57, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_88", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_88_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x58, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_89", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x59, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_89_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x59, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_90", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_90_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_91", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_91_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_92", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_92_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_93", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_93_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_94", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_94_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_95", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_95_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_96", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_96_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x60, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_97", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x61, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_97_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x61, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_98", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_98_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x62, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_99", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x63, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_99_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x63, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_100", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_100_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x64, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_101", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x65, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_101_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x65, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_102", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_102_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x66, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_103", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x67, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_103_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x67, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_104", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_104_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x68, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_105", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x69, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_105_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x69, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_106", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_106_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_107", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_107_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_108", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_108_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_109", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_109_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_110", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_110_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_111", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_111_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_112", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x70, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_112_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x70, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_113", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x71, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_113_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x71, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_114", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x72, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_114_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x72, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_115", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x73, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_115_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x73, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_116", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x74, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_116_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x74, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_117", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x75, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_117_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x75, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_118", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x76, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_118_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x76, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_119", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x77, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_119_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x77, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_120", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x78, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_120_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x78, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_121", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x79, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_121_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x79, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_122", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_122_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_123", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_123_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_124", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_124_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_125", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_125_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_126", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_126_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_127", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_127_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x00", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x00_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x01", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x01_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x02", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x02_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x03", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x03_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x04", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x04_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x05", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x05_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x06", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x06_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x07", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x07_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x08", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x08_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x8, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x09", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x09_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x9, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xa, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xa, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xb, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xb, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xc, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xc, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xd, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xd, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xe, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xe, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xf, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xf, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x10", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x10, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x10_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x10, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x11", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x11, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x11_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x11, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x12", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x12, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x12_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x12, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x13", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x13, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x13_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x13, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x14", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x14_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x14, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x15", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x15, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x15_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x15, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x16", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x16_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x17", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x17, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x17_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x17, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x18", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x18_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x18, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x19", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x19_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x19, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x20", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x20_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x21", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x21_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x22", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x22_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x23", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x23_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x24", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x24_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x24, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x25", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x25, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x25_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x25, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x26", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x26_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x26, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x27", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x27, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x27_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x27, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x28", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x28_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x29", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x29_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x30", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x30_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x30, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x31", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x31_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x31, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x32", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x32_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x32, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x33", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x33, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x33_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x33, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x34", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x34, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x34_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x34, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x35", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x35_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x36", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x36_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x37", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x37, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x37_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x37, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x38", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x38, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x38_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x38, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x39", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x39, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x39_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x39, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x40", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x40_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x40, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x41", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x41, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x41_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x41, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x42", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x42_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x42, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x43", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x43, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x43_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x43, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x44", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x44_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x44, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x45", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x45, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x45_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x45, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x46", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x46_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x46, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x47", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x47, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x47_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x47, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x48", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x48_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x48, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x49", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x49, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x49_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x49, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x50", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x50_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x51", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x51_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x52", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x52, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x52_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x52, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x53", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x53, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x53_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x53, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x54", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x54, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x54_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x54, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x55", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x55, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x55_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x55, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x56", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x56, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x56_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x56, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x57", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x57, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x57_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x57, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x58", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x58_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x58, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x59", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x59, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x59_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x59, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x60", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x60_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x61", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x61, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x61_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x61, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x62", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x62_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x63", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x63, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x63_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x63, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x64", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x64_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x64, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x65", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x65, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x65_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x65, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x66", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x66_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x66, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x67", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x67, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x67_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x67, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x68", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x68_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x68, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x69", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x69, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x69_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x69, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x70", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x70, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x70_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x70, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x71", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x71, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x71_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x71, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x72", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x72, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x72_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x72, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x73", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x73, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x73_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x73, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x74", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x74, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x74_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x74, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x75", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x75, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x75_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x75, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x76", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x76, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x76_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x76, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x77", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x77, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x77_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x77, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x78", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x78, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x78_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x78, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x79", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x79, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x79_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x79, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x00", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x00_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x0, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x01", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x01_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x02", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x02_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x03", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x03_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x04", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x04_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x05", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x05_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x06", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x06_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x07", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x07_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x08", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x08_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x8, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x09", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x09_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x9, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0a", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xa, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xa, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0b", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xb, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xb, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0c", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xc, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xc, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0d", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xd, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xd, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0e", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xe, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xe, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0f", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xf, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x0f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xf, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x10", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x10, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x10_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x10, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x11", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x11, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x11_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x11, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x12", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x12, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x12_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x12, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x13", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x13, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x13_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x13, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x14", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x14_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x14, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x15", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x15, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x15_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x15, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x16", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x16_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x16, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x17", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x17, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x17_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x17, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x18", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x18_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x18, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x19", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x19_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x19, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1a", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1b", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1c", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1d", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1e", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1f", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x1f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x20", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x20_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x20, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x21", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x21_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x21, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x22", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x22_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x22, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x23", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x23_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x23, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x24", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x24_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x24, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x25", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x25, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x25_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x25, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x26", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x26_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x26, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x27", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x27, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x27_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x27, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x28", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x28_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x28, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x29", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x29_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x29, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2a", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2b", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2c", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2d", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2e", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2f", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x2f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x30", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x30_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x30, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x31", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x31_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x31, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x32", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x32_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x32, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x33", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x33, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x33_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x33, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x34", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x34, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x34_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x34, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x35", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x35, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x35_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x35, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x36", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x36, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x36_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x36, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x37", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x37, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x37_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x37, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x38", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x38, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x38_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x38, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x39", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x39, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x39_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x39, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3a", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3b", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3c", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3d", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3e", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3f", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x3f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x40", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x40_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x40, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x41", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x41, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x41_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x41, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x42", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x42_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x42, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x43", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x43, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x43_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x43, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x44", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x44_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x44, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x45", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x45, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x45_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x45, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x46", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x46_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x46, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x47", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x47, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x47_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x47, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x48", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x48_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x48, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x49", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x49, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x49_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x49, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4a", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4b", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4c", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4d", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4e", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4f", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x4f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x50", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x50, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x50_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x50, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x51", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x51, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x51_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x51, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x52", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x52, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x52_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x52, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x53", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x53, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x53_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x53, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x54", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x54, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x54_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x54, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x55", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x55, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x55_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x55, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x56", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x56, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x56_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x56, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x57", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x57, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x57_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x57, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x58", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x58_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x58, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x59", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x59, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x59_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x59, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5a", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5b", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5c", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5d", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5e", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5f", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x5f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x60", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x60_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x60, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x61", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x61, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x61_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x61, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x62", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x62_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x62, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x63", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x63, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x63_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x63, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x64", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x64_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x64, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x65", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x65, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x65_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x65, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x66", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x66_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x66, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x67", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x67, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x67_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x67, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x68", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x68_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x68, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x69", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x69, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x69_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x69, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6a", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6b", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6c", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6d", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6e", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6f", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x6f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x70", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x70, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x70_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x70, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x71", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x71, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x71_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x71, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x72", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x72, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x72_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x72, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x73", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x73, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x73_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x73, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x74", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x74, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x74_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x74, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x75", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x75, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x75_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x75, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x76", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x76, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x76_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x76, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x77", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x77, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x77_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x77, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x78", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x78, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x78_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x78, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x79", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x79, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x79_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x79, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7a", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7b", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7c", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7d", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7e", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7f", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x7f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ0};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_128", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_128_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_129", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_129_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_130", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_130_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_131", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_131_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_132", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_132_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_133", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_133_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_134", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_134_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_135", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_135_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_136", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_136_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x8, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_137", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_137_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x9, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_138", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xa, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_138_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xa, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_139", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xb, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_139_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xb, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_140", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xc, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_140_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xc, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_141", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xd, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_141_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xd, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_142", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xe, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_142_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xe, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_143", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xf, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_143_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xf, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_144", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x10, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_144_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x10, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_145", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x11, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_145_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x11, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_146", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x12, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_146_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x12, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_147", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x13, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_147_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x13, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_148", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_148_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x14, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_149", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x15, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_149_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x15, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_150", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_150_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_151", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x17, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_151_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x17, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_152", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_152_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x18, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_153", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_153_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x19, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_154", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_154_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_155", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_155_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_156", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_156_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_157", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_157_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_158", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_158_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_159", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_159_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_160", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_160_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_161", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_161_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_162", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_162_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_163", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_163_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_164", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_164_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x24, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_165", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x25, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_165_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x25, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_166", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_166_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x26, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_167", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x27, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_167_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x27, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_168", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_168_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_169", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_169_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_170", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_170_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_171", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_171_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_172", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_172_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_173", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_173_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_174", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_174_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_175", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_175_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_176", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_176_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x30, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_177", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_177_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x31, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_178", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_178_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x32, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_179", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x33, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_179_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x33, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_180", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x34, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_180_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x34, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_181", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_181_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_182", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_182_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_183", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x37, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_183_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x37, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_184", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x38, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_184_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x38, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_185", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x39, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_185_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x39, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_186", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_186_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_187", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_187_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_188", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_188_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_189", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_189_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_190", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_190_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_191", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_191_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_192", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_192_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x40, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_193", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x41, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_193_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x41, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_194", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_194_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x42, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_195", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x43, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_195_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x43, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_196", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_196_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x44, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_197", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x45, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_197_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x45, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_198", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_198_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x46, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_199", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x47, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_199_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x47, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_200", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_200_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x48, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_201", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x49, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_201_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x49, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_202", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_202_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_203", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_203_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_204", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_204_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_205", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_205_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_206", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_206_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_207", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_207_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_208", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_208_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_209", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_209_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_210", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x52, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_210_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x52, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_211", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x53, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_211_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x53, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_212", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x54, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_212_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x54, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_213", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x55, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_213_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x55, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_214", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x56, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_214_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x56, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_215", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x57, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_215_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x57, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_216", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_216_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x58, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_217", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x59, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_217_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x59, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_218", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_218_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_219", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_219_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_220", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_220_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_221", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_221_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_222", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_222_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_223", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_223_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_224", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_224_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_225", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x61, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_225_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x61, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_226", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_226_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_227", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x63, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_227_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x63, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_228", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_228_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x64, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_229", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x65, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_229_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x65, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_230", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_230_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x66, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_231", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x67, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_231_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x67, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_232", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_232_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x68, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_233", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x69, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_233_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x69, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_234", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_234_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_235", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_235_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_236", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_236_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_237", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_237_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_238", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_238_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_239", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_239_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_240", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x70, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_240_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x70, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_241", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x71, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_241_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x71, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_242", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x72, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_242_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x72, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_243", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x73, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_243_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x73, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_244", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x74, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_244_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x74, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_245", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x75, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_245_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x75, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_246", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x76, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_246_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x76, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_247", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x77, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_247_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x77, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_248", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x78, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_248_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x78, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_249", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x79, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_249_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x79, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_250", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_250_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_251", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_251_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_252", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_252_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_253", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_253_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_254", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_254_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_255", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_255_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_128", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_128_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x0, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_129", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_129_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_130", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_130_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_131", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_131_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_132", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_132_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_133", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_133_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_134", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_134_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_135", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_135_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_136", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_136_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x8, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_137", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_137_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x9, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_138", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xa, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_138_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xa, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_139", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xb, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_139_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xb, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_140", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xc, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_140_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xc, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_141", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xd, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_141_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xd, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_142", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xe, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_142_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xe, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_143", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xf, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_143_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xf, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_144", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x10, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_144_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x10, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_145", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x11, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_145_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x11, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_146", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x12, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_146_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x12, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_147", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x13, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_147_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x13, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_148", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_148_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x14, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_149", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x15, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_149_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x15, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_150", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_150_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x16, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_151", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x17, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_151_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x17, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_152", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_152_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x18, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_153", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_153_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x19, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_154", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_154_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_155", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_155_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_156", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_156_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_157", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_157_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_158", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_158_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_159", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_159_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_160", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_160_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x20, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_161", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_161_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x21, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_162", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_162_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x22, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_163", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_163_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x23, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_164", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_164_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x24, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_165", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x25, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_165_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x25, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_166", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_166_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x26, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_167", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x27, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_167_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x27, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_168", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_168_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x28, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_169", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_169_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x29, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_170", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_170_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_171", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_171_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_172", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_172_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_173", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_173_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_174", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_174_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_175", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_175_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_176", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_176_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x30, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_177", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_177_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x31, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_178", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_178_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x32, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_179", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x33, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_179_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x33, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_180", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x34, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_180_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x34, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_181", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x35, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_181_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x35, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_182", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x36, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_182_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x36, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_183", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x37, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_183_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x37, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_184", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x38, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_184_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x38, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_185", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x39, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_185_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x39, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_186", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_186_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_187", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_187_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_188", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_188_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_189", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_189_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_190", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_190_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_191", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_191_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_192", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_192_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x40, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_193", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x41, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_193_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x41, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_194", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_194_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x42, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_195", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x43, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_195_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x43, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_196", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_196_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x44, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_197", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x45, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_197_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x45, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_198", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_198_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x46, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_199", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x47, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_199_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x47, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_200", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_200_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x48, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_201", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x49, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_201_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x49, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_202", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_202_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_203", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_203_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_204", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_204_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_205", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_205_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_206", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_206_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_207", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_207_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_208", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x50, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_208_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x50, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_209", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x51, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_209_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x51, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_210", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x52, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_210_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x52, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_211", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x53, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_211_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x53, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_212", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x54, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_212_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x54, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_213", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x55, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_213_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x55, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_214", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x56, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_214_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x56, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_215", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x57, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_215_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x57, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_216", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_216_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x58, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_217", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x59, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_217_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x59, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_218", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_218_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_219", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_219_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_220", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_220_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_221", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_221_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_222", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_222_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_223", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_223_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_224", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_224_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x60, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_225", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x61, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_225_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x61, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_226", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_226_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x62, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_227", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x63, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_227_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x63, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_228", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_228_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x64, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_229", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x65, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_229_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x65, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_230", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_230_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x66, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_231", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x67, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_231_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x67, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_232", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_232_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x68, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_233", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x69, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_233_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x69, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_234", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_234_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_235", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_235_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_236", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_236_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_237", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_237_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_238", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_238_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_239", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_239_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_240", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x70, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_240_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x70, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_241", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x71, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_241_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x71, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_242", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x72, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_242_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x72, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_243", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x73, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_243_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x73, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_244", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x74, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_244_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x74, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_245", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x75, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_245_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x75, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_246", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x76, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_246_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x76, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_247", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x77, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_247_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x77, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_248", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x78, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_248_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x78, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_249", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x79, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_249_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x79, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_250", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_250_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_251", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_251_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_252", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_252_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_253", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_253_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_254", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_254_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_255", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_255_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x80", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x80_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x81", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x81_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x82", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x82_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x83", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x83_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x84", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x84_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x85", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x85_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x86", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x86_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x87", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x87_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x88", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x88_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x8, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x89", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x89_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x9, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xa, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xa, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xb, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xb, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xc, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xc, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xd, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xd, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xe, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xe, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xf, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xf, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x90", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x10, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x90_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x10, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x91", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x11, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x91_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x11, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x92", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x12, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x92_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x12, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x93", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x13, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x93_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x13, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x94", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x94_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x14, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x95", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x15, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x95_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x15, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x96", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x96_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x97", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x17, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x97_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x17, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x98", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x98_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x18, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x99", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x99_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x19, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9a", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9b", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9c", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9d", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9e", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9f", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa0", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa0_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x20, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa1", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa1_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x21, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa2", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa2_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x22, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa3", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa3_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x23, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa4", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa4_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x24, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa5", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x25, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa5_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x25, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa6", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa6_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x26, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa7", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x27, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa7_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x27, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa8", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa8_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x28, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa9", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa9_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x29, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xaa", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xaa_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xab", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xab_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xac", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xac_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xad", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xad_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xae", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xae_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xaf", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xaf_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb0", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb0_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x30, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb1", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb1_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x31, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb2", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb2_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x32, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb3", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x33, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb3_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x33, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb4", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x34, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb4_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x34, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb5", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb5_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x35, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb6", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb6_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x36, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb7", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x37, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb7_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x37, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb8", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x38, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb8_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x38, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb9", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x39, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb9_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x39, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xba", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xba_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbb", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbb_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbc", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbc_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbd_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbe", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbe_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbf", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbf_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc0", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc0_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x40, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc1", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x41, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc1_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x41, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc2", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc2_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x42, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc3", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x43, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc3_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x43, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc4", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc4_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x44, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc5", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x45, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc5_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x45, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc6", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc6_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x46, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc7", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x47, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc7_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x47, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc8", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc8_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x48, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc9", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x49, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc9_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x49, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xca", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xca_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xcb", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xcb_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xcc", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xcc_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xcd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xcd_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xce", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xce_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xcf", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xcf_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd0", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd0_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x50, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd1", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd1_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x51, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd2", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x52, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd2_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x52, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd3", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x53, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd3_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x53, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd4", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x54, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd4_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x54, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd5", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x55, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd5_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x55, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd6", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x56, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd6_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x56, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd7", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x57, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd7_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x57, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd8", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd8_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x58, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd9", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x59, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd9_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x59, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xda", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xda_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xdb", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xdb_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xdc", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xdc_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xdd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xdd_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xde", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xde_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xdf", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xdf_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe0", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe0_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x60, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe1", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x61, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe1_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x61, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe2", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe2_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x62, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe3", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x63, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe3_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x63, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe4", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe4_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x64, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe5", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x65, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe5_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x65, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe6", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe6_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x66, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe7", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x67, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe7_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x67, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe8", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe8_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x68, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe9", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x69, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe9_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x69, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xea", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xea_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xeb", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xeb_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xec", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xec_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xed", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xed_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xee", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xee_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xef", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xef_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf0", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x70, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf0_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x70, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf1", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x71, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf1_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x71, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf2", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x72, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf2_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x72, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf3", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x73, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf3_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x73, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf4", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x74, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf4_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x74, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf5", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x75, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf5_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x75, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf6", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x76, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf6_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x76, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf7", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x77, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf7_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x77, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf8", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x78, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf8_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x78, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf9", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x79, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf9_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x79, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfa", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfa_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7a, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfb", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfb_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7b, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfc", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfc_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7c, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfd", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfd_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7d, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfe", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfe_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xff", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xff_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7f, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x80", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x80_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x0, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x81", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x81_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x82", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x82_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x83", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x83_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x84", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x84_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x85", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x85_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x86", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x86_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x87", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x87_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x88", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x8, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x88_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x8, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x89", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x9, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x89_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x9, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8a", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xa, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xa, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8b", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xb, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xb, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8c", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xc, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xc, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8d", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xd, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xd, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8e", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xe, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xe, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8f", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0xf, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x8f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0xf, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x90", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x10, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x90_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x10, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x91", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x11, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x91_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x11, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x92", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x12, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x92_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x12, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x93", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x13, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x93_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x13, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x94", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x14, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x94_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x14, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x95", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x15, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x95_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x15, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x96", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x96_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x16, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x97", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x17, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x97_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x17, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x98", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x18, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x98_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x18, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x99", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x19, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x99_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x19, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9a", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9a_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9b", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9b_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9c", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9c_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9d", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9d_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9e", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9e_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9f", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x1f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0x9f_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x1f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa0", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x20, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa0_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x20, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa1", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x21, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa1_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x21, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa2", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x22, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa2_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x22, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa3", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x23, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa3_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x23, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa4", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x24, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa4_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x24, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa5", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x25, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa5_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x25, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa6", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x26, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa6_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x26, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa7", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x27, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa7_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x27, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa8", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x28, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa8_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x28, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa9", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x29, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xa9_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x29, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xaa", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xaa_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xab", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xab_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xac", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xac_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xad", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xad_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xae", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xae_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xaf", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x2f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xaf_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x2f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb0", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x30, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb0_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x30, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb1", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x31, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb1_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x31, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb2", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x32, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb2_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x32, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb3", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x33, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb3_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x33, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb4", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x34, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb4_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x34, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb5", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x35, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb5_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x35, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb6", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x36, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb6_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x36, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb7", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x37, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb7_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x37, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb8", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x38, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb8_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x38, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb9", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x39, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xb9_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x39, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xba", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xba_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbb", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbb_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbc", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbc_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbd", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbd_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbe", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbe_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbf", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x3f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xbf_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x3f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc0", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x40, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc0_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x40, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc1", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x41, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc1_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x41, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc2", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x42, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc2_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x42, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc3", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x43, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc3_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x43, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc4", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x44, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc4_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x44, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc5", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x45, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc5_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x45, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc6", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x46, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc6_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x46, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc7", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x47, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc7_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x47, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc8", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x48, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc8_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x48, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc9", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x49, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xc9_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x49, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xca", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xca_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xcb", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xcb_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xcc", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xcc_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xcd", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xcd_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xce", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xce_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xcf", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x4f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xcf_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x4f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd0", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x50, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd0_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x50, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd1", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x51, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd1_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x51, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd2", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x52, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd2_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x52, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd3", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x53, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd3_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x53, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd4", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x54, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd4_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x54, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd5", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x55, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd5_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x55, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd6", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x56, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd6_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x56, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd7", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x57, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd7_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x57, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd8", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd8_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x58, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd9", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x59, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xd9_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x59, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xda", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xda_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xdb", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xdb_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xdc", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xdc_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xdd", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xdd_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xde", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xde_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xdf", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x5f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xdf_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x5f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe0", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x60, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe0_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x60, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe1", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x61, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe1_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x61, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe2", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x62, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe2_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x62, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe3", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x63, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe3_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x63, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe4", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x64, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe4_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x64, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe5", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x65, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe5_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x65, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe6", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x66, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe6_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x66, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe7", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x67, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe7_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x67, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe8", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe8_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x68, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe9", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x69, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xe9_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x69, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xea", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xea_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xeb", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xeb_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xec", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xec_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xed", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xed_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xee", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xee_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xef", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x6f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xef_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x6f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf0", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x70, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf0_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x70, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf1", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x71, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf1_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x71, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf2", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x72, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf2_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x72, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf3", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x73, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf3_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x73, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf4", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x74, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf4_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x74, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf5", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x75, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf5_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x75, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf6", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x76, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf6_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x76, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf7", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x77, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf7_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x77, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf8", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x78, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf8_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x78, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf9", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x79, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xf9_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x79, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfa", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfa_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7a, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfb", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfb_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7b, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfc", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfc_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7c, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfd", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfd_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7d, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfe", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xfe_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xff", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_0xff_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7f, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_and", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_and_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x0, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_xor", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_xor_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x16, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_sel3", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_sel3_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x58, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_mjr", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_mjr_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x68, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_or", 0x70, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_or_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7e, {1, 1, 0, 1, 1, 0}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_and", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x0, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_and_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x0, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_xor", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x16, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_xor_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x16, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_sel3", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x58, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_sel3_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x58, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_mjr", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x68, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_mjr_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x68, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_or", 0x40, parse_alf_args, NULL, ALOPF21, NO_MAS, 0x7e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
{
	static e2k_alopf21_opcode_templ dummy =
		{"qplog_or_lt3", 0x40, parse_alf_args, NULL, ALOPF21_LT_PACK_CODE, NO_MAS, 0x7e, {0, 0, 1, 0, 0, 1}, ARGS_DDDD, LCMBQ1};
	add_to_insn_table ((e2k_opcode_templ *) &dummy);
}
