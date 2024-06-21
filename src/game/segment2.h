#ifndef SEGMENT2_H
#define SEGMENT2_H

#include <PR/ultratypes.h>
#include <PR/gbi.h>

extern u8 seg2_course_name_table[];
extern u8 seg2_act_name_table[];
extern Gfx dl_rgba16_text_begin[];
extern Gfx dl_rgba16_text_end[];
extern Gfx dl_ia_text_begin[];
extern Gfx dl_ia_text_end[];
extern u8 texture_transition_star_half[];
extern u8 texture_transition_circle_half[];
extern u8 texture_transition_mario[];
extern u8 texture_transition_bowser_half[];
extern u8 texture_waterbox_water[];
extern u8 texture_waterbox_mist[];
extern u8 texture_waterbox_jrb_water[];
extern u8 texture_waterbox_unknown_water[];
extern u8 texture_waterbox_lava[];
extern Gfx dl_proj_mtx_fullscreen[];
extern Gfx dl_draw_quad_verts_0123[];
extern Gfx dl_screen_transition_end[];
extern Gfx dl_transition_draw_filled_region[];
extern Gfx dl_shadow_begin_decal[];
extern Gfx dl_shadow_begin_non_decal[];
extern Gfx dl_shadow_circle[];
extern Gfx dl_shadow_square[];
extern Gfx dl_shadow_spike[];
extern Gfx dl_shadow_9_verts[];
extern Gfx dl_shadow_4_verts[];
extern Gfx dl_shadow_end[];
extern Gfx dl_skybox_begin[];
extern Gfx dl_skybox_tile_tex_settings[];
extern Gfx dl_skybox_end[];
extern Gfx dl_waterbox_ia16_begin[];
extern Gfx dl_waterbox_rgba16_begin[];
extern Gfx dl_waterbox_end[];
extern Gfx dl_paintings_draw_ripples[];
extern Gfx dl_paintings_rippling_begin[];
extern Gfx dl_paintings_rippling_end[];
extern Gfx dl_paintings_env_mapped_begin[];
extern Gfx dl_paintings_env_mapped_end[];
extern u8 seg2_painting_triangle_mesh[];
extern u8 seg2_painting_mesh_neighbor_tris[];
extern u8* main_hud_lut[58];
extern Gfx dl_hud_img_load_tex_block[];
extern Gfx dl_hud_img_begin[];
extern Gfx dl_hud_img_end[];
extern void *main_font_lut[];
extern Gfx dl_ia_text_tex_settings[];
extern Gfx dl_rgba16_load_tex_block[];
extern void *main_credits_font_lut[];
extern u8* main_hud_camera_lut[6];
extern Gfx dl_shade_screen_begin[];
extern Gfx dl_shade_screen_end[];
extern Gfx dl_draw_text_bg_box[];
extern Gfx dl_draw_triangle[];
extern void *seg2_dialog_table[];
extern Gfx dl_billboard_num_0[];
extern Gfx dl_billboard_num_1[];
extern Gfx dl_billboard_num_2[];
extern Gfx dl_billboard_num_3[];
extern Gfx dl_billboard_num_4[];
extern Gfx dl_billboard_num_5[];
extern Gfx dl_billboard_num_6[];
extern Gfx dl_billboard_num_7[];
extern Gfx dl_billboard_num_8[];
extern Gfx dl_billboard_num_9[];

// 3D Skybox Mesh
extern u8 skybox_bitdw_1_ci8[];
extern u8 skybox_bitdw_1_pal_rgba16[];
extern u8 skybox_bitdw_2_ci8[];
extern u8 skybox_bitdw_2_pal_rgba16[];
extern u8 skybox_bitdw_3_ci8[];
extern u8 skybox_bitdw_3_pal_rgba16[];
extern u8 skybox_bitdw_4_ci8[];
extern u8 skybox_bitdw_4_pal_rgba16[];
extern u8 skybox_bitdw_5_ci8[];
extern u8 skybox_bitdw_5_pal_rgba16[];
extern u8 skybox_bitdw_6_ci8[];
extern u8 skybox_bitdw_6_pal_rgba16[];
extern u8 skybox_bitdw_7_ci8[];
extern u8 skybox_bitdw_7_pal_rgba16[];
extern u8 skybox_bitdw_8_ci8[];
extern u8 skybox_bitdw_8_pal_rgba16[];
extern u8 skybox_bitdw_9_ci8[];
extern u8 skybox_bitdw_9_pal_rgba16[];
extern u8 skybox_bitdw_10_ci8[];
extern u8 skybox_bitdw_10_pal_rgba16[];
extern u8 skybox_bitdw_11_ci8[];
extern u8 skybox_bitdw_11_pal_rgba16[];
extern u8 skybox_bitdw_12_ci8[];
extern u8 skybox_bitdw_12_pal_rgba16[];
extern u8 skybox_bitdw_13_ci8[];
extern u8 skybox_bitdw_13_pal_rgba16[];
extern u8 skybox_bitdw_14_ci8[];
extern u8 skybox_bitdw_14_pal_rgba16[];
extern u8 skybox_bitdw_15_ci8[];
extern u8 skybox_bitdw_15_pal_rgba16[];
extern u8 skybox_bitdw_16_ci8[];
extern u8 skybox_bitdw_16_pal_rgba16[];
extern u8 skybox_bitdw_17_ci8[];
extern u8 skybox_bitdw_17_pal_rgba16[];
extern u8 skybox_bitdw_18_ci8[];
extern u8 skybox_bitdw_18_pal_rgba16[];
extern u8 skybox_bitdw_19_ci8[];
extern u8 skybox_bitdw_19_pal_rgba16[];
extern u8 skybox_bitdw_20_ci8[];
extern u8 skybox_bitdw_20_pal_rgba16[];
extern u8 skybox_bitdw_21_ci8[];
extern u8 skybox_bitdw_21_pal_rgba16[];
extern u8 skybox_bitdw_22_ci8[];
extern u8 skybox_bitdw_22_pal_rgba16[];
extern u8 skybox_bitdw_23_ci8[];
extern u8 skybox_bitdw_23_pal_rgba16[];
extern u8 skybox_bitdw_24_ci8[];
extern u8 skybox_bitdw_24_pal_rgba16[];
extern u8 skybox_bitdw_25_ci8[];
extern u8 skybox_bitdw_25_pal_rgba16[];
extern u8 skybox_bitdw_26_ci8[];
extern u8 skybox_bitdw_26_pal_rgba16[];
extern u8 skybox_bitdw_27_ci8[];
extern u8 skybox_bitdw_27_pal_rgba16[];
extern u8 skybox_bitdw_28_ci8[];
extern u8 skybox_bitdw_28_pal_rgba16[];
extern u8 skybox_bitdw_29_ci8[];
extern u8 skybox_bitdw_29_pal_rgba16[];
extern u8 skybox_bitdw_30_ci8[];
extern u8 skybox_bitdw_30_pal_rgba16[];
extern u8 skybox_bitdw_31_ci8[];
extern u8 skybox_bitdw_31_pal_rgba16[];
extern u8 skybox_bitdw_32_ci8[];
extern u8 skybox_bitdw_32_pal_rgba16[];
extern u8 skybox_bitdw_33_ci8[];
extern u8 skybox_bitdw_33_pal_rgba16[];
extern u8 skybox_bitdw_34_ci8[];
extern u8 skybox_bitdw_34_pal_rgba16[];
extern u8 skybox_bitdw_35_ci8[];
extern u8 skybox_bitdw_35_pal_rgba16[];
extern u8 skybox_bitdw_36_ci8[];
extern u8 skybox_bitdw_36_pal_rgba16[];
extern u8 skybox_bitdw_37_ci8[];
extern u8 skybox_bitdw_37_pal_rgba16[];
extern u8 skybox_bitdw_38_ci8[];
extern u8 skybox_bitdw_38_pal_rgba16[];
extern u8 skybox_bitdw_39_ci8[];
extern u8 skybox_bitdw_39_pal_rgba16[];
extern u8 skybox_bitdw_40_ci8[];
extern u8 skybox_bitdw_40_pal_rgba16[];
extern u8 skybox_bitdw_41_ci8[];
extern u8 skybox_bitdw_41_pal_rgba16[];
extern u8 skybox_bitdw_42_ci8[];
extern u8 skybox_bitdw_42_pal_rgba16[];
extern u8 skybox_bitdw_43_ci8[];
extern u8 skybox_bitdw_43_pal_rgba16[];
extern u8 skybox_bitdw_44_ci8[];
extern u8 skybox_bitdw_44_pal_rgba16[];
extern u8 skybox_bitdw_45_ci8[];
extern u8 skybox_bitdw_45_pal_rgba16[];
extern u8 skybox_bitdw_46_ci8[];
extern u8 skybox_bitdw_46_pal_rgba16[];
extern u8 skybox_bitdw_47_ci8[];
extern u8 skybox_bitdw_47_pal_rgba16[];
extern u8 skybox_bitdw_48_ci8[];
extern u8 skybox_bitdw_48_pal_rgba16[];
extern u8 skybox_bitdw_49_ci8[];
extern u8 skybox_bitdw_49_pal_rgba16[];
extern u8 skybox_bitdw_50_ci8[];
extern u8 skybox_bitdw_50_pal_rgba16[];
extern u8 skybox_bitdw_51_ci8[];
extern u8 skybox_bitdw_51_pal_rgba16[];
extern u8 skybox_bitdw_52_ci8[];
extern u8 skybox_bitdw_52_pal_rgba16[];
extern u8 skybox_bitdw_53_ci8[];
extern u8 skybox_bitdw_53_pal_rgba16[];
extern u8 skybox_bitdw_54_ci8[];
extern u8 skybox_bitdw_54_pal_rgba16[];
extern u8 skybox_bitdw_55_ci8[];
extern u8 skybox_bitdw_55_pal_rgba16[];
extern u8 skybox_bitdw_56_ci8[];
extern u8 skybox_bitdw_56_pal_rgba16[];
extern u8 skybox_bitdw_57_ci8[];
extern u8 skybox_bitdw_57_pal_rgba16[];
extern u8 skybox_bitdw_58_ci8[];
extern u8 skybox_bitdw_58_pal_rgba16[];
extern u8 skybox_bitdw_59_ci8[];
extern u8 skybox_bitdw_59_pal_rgba16[];
extern u8 skybox_bitdw_60_ci8[];
extern u8 skybox_bitdw_60_pal_rgba16[];
extern u8 skybox_bitdw_61_ci8[];
extern u8 skybox_bitdw_61_pal_rgba16[];
extern u8 skybox_bitdw_62_ci8[];
extern u8 skybox_bitdw_62_pal_rgba16[];
extern u8 skybox_bitdw_63_ci8[];
extern u8 skybox_bitdw_63_pal_rgba16[];
extern u8 skybox_bitdw_64_ci8[];
extern u8 skybox_bitdw_64_pal_rgba16[];
extern Vtx bitdw_skybox_vtx_0[48];
extern Gfx bitdw_skybox_tri_0[];
extern Vtx bitdw_skybox_vtx_1[8];
extern Gfx bitdw_skybox_tri_1[];
extern Vtx bitdw_skybox_vtx_2[8];
extern Gfx bitdw_skybox_tri_2[];
extern Vtx bitdw_skybox_vtx_3[8];
extern Gfx bitdw_skybox_tri_3[];
extern Vtx bitdw_skybox_vtx_4[8];
extern Gfx bitdw_skybox_tri_4[];
extern Vtx bitdw_skybox_vtx_5[8];
extern Gfx bitdw_skybox_tri_5[];
extern Vtx bitdw_skybox_vtx_6[8];
extern Gfx bitdw_skybox_tri_6[];
extern Vtx bitdw_skybox_vtx_7[8];
extern Gfx bitdw_skybox_tri_7[];
extern Vtx bitdw_skybox_vtx_8[8];
extern Gfx bitdw_skybox_tri_8[];
extern Vtx bitdw_skybox_vtx_9[8];
extern Gfx bitdw_skybox_tri_9[];
extern Vtx bitdw_skybox_vtx_10[8];
extern Gfx bitdw_skybox_tri_10[];
extern Vtx bitdw_skybox_vtx_11[8];
extern Gfx bitdw_skybox_tri_11[];
extern Vtx bitdw_skybox_vtx_12[8];
extern Gfx bitdw_skybox_tri_12[];
extern Vtx bitdw_skybox_vtx_13[8];
extern Gfx bitdw_skybox_tri_13[];
extern Vtx bitdw_skybox_vtx_14[8];
extern Gfx bitdw_skybox_tri_14[];
extern Vtx bitdw_skybox_vtx_15[8];
extern Gfx bitdw_skybox_tri_15[];
extern Vtx bitdw_skybox_vtx_16[11];
extern Gfx bitdw_skybox_tri_16[];
extern Vtx bitdw_skybox_vtx_17[11];
extern Gfx bitdw_skybox_tri_17[];
extern Vtx bitdw_skybox_vtx_18[12];
extern Gfx bitdw_skybox_tri_18[];
extern Vtx bitdw_skybox_vtx_19[12];
extern Gfx bitdw_skybox_tri_19[];
extern Vtx bitdw_skybox_vtx_20[11];
extern Gfx bitdw_skybox_tri_20[];
extern Vtx bitdw_skybox_vtx_21[11];
extern Gfx bitdw_skybox_tri_21[];
extern Vtx bitdw_skybox_vtx_22[11];
extern Gfx bitdw_skybox_tri_22[];
extern Vtx bitdw_skybox_vtx_23[11];
extern Gfx bitdw_skybox_tri_23[];
extern Vtx bitdw_skybox_vtx_24[10];
extern Gfx bitdw_skybox_tri_24[];
extern Vtx bitdw_skybox_vtx_25[12];
extern Gfx bitdw_skybox_tri_25[];
extern Vtx bitdw_skybox_vtx_26[13];
extern Gfx bitdw_skybox_tri_26[];
extern Vtx bitdw_skybox_vtx_27[12];
extern Gfx bitdw_skybox_tri_27[];
extern Vtx bitdw_skybox_vtx_28[11];
extern Gfx bitdw_skybox_tri_28[];
extern Vtx bitdw_skybox_vtx_29[11];
extern Gfx bitdw_skybox_tri_29[];
extern Vtx bitdw_skybox_vtx_30[11];
extern Gfx bitdw_skybox_tri_30[];
extern Vtx bitdw_skybox_vtx_31[11];
extern Gfx bitdw_skybox_tri_31[];
extern Vtx bitdw_skybox_vtx_32[10];
extern Gfx bitdw_skybox_tri_32[];
extern Vtx bitdw_skybox_vtx_33[12];
extern Gfx bitdw_skybox_tri_33[];
extern Vtx bitdw_skybox_vtx_34[13];
extern Gfx bitdw_skybox_tri_34[];
extern Vtx bitdw_skybox_vtx_35[12];
extern Gfx bitdw_skybox_tri_35[];
extern Vtx bitdw_skybox_vtx_36[11];
extern Gfx bitdw_skybox_tri_36[];
extern Vtx bitdw_skybox_vtx_37[11];
extern Gfx bitdw_skybox_tri_37[];
extern Vtx bitdw_skybox_vtx_38[11];
extern Gfx bitdw_skybox_tri_38[];
extern Vtx bitdw_skybox_vtx_39[11];
extern Gfx bitdw_skybox_tri_39[];
extern Vtx bitdw_skybox_vtx_40[10];
extern Gfx bitdw_skybox_tri_40[];
extern Vtx bitdw_skybox_vtx_41[11];
extern Gfx bitdw_skybox_tri_41[];
extern Vtx bitdw_skybox_vtx_42[12];
extern Gfx bitdw_skybox_tri_42[];
extern Vtx bitdw_skybox_vtx_43[12];
extern Gfx bitdw_skybox_tri_43[];
extern Vtx bitdw_skybox_vtx_44[11];
extern Gfx bitdw_skybox_tri_44[];
extern Vtx bitdw_skybox_vtx_45[11];
extern Gfx bitdw_skybox_tri_45[];
extern Vtx bitdw_skybox_vtx_46[12];
extern Gfx bitdw_skybox_tri_46[];
extern Vtx bitdw_skybox_vtx_47[12];
extern Gfx bitdw_skybox_tri_47[];
extern Vtx bitdw_skybox_vtx_48[10];
extern Gfx bitdw_skybox_tri_48[];
extern Vtx bitdw_skybox_vtx_49[10];
extern Gfx bitdw_skybox_tri_49[];
extern Vtx bitdw_skybox_vtx_50[10];
extern Gfx bitdw_skybox_tri_50[];
extern Vtx bitdw_skybox_vtx_51[10];
extern Gfx bitdw_skybox_tri_51[];
extern Vtx bitdw_skybox_vtx_52[10];
extern Gfx bitdw_skybox_tri_52[];
extern Vtx bitdw_skybox_vtx_53[10];
extern Gfx bitdw_skybox_tri_53[];
extern Vtx bitdw_skybox_vtx_54[10];
extern Gfx bitdw_skybox_tri_54[];
extern Vtx bitdw_skybox_vtx_55[10];
extern Gfx bitdw_skybox_tri_55[];
extern Vtx bitdw_skybox_vtx_56[10];
extern Gfx bitdw_skybox_tri_56[];
extern Vtx bitdw_skybox_vtx_57[10];
extern Gfx bitdw_skybox_tri_57[];
extern Vtx bitdw_skybox_vtx_58[10];
extern Gfx bitdw_skybox_tri_58[];
extern Vtx bitdw_skybox_vtx_59[10];
extern Gfx bitdw_skybox_tri_59[];
extern Vtx bitdw_skybox_vtx_60[10];
extern Gfx bitdw_skybox_tri_60[];
extern Vtx bitdw_skybox_vtx_61[10];
extern Gfx bitdw_skybox_tri_61[];
extern Vtx bitdw_skybox_vtx_62[10];
extern Gfx bitdw_skybox_tri_62[];
extern Vtx bitdw_skybox_vtx_63[10];
extern Gfx bitdw_skybox_tri_63[];
extern Gfx mat_skybox__1[];
extern Gfx mat_revert_skybox__1[];
extern Gfx mat_skybox__2[];
extern Gfx mat_revert_skybox__2[];
extern Gfx mat_skybox__3[];
extern Gfx mat_revert_skybox__3[];
extern Gfx mat_skybox__4[];
extern Gfx mat_revert_skybox__4[];
extern Gfx mat_skybox__5[];
extern Gfx mat_revert_skybox__5[];
extern Gfx mat_skybox__6[];
extern Gfx mat_revert_skybox__6[];
extern Gfx mat_skybox__7[];
extern Gfx mat_revert_skybox__7[];
extern Gfx mat_skybox__8[];
extern Gfx mat_revert_skybox__8[];
extern Gfx mat_skybox__9[];
extern Gfx mat_revert_skybox__9[];
extern Gfx mat_skybox__10[];
extern Gfx mat_revert_skybox__10[];
extern Gfx mat_skybox__11[];
extern Gfx mat_revert_skybox__11[];
extern Gfx mat_skybox__12[];
extern Gfx mat_revert_skybox__12[];
extern Gfx mat_skybox__13[];
extern Gfx mat_revert_skybox__13[];
extern Gfx mat_skybox__14[];
extern Gfx mat_revert_skybox__14[];
extern Gfx mat_skybox__15[];
extern Gfx mat_revert_skybox__15[];
extern Gfx mat_skybox__16[];
extern Gfx mat_revert_skybox__16[];
extern Gfx mat_skybox__17[];
extern Gfx mat_revert_skybox__17[];
extern Gfx mat_skybox__18[];
extern Gfx mat_revert_skybox__18[];
extern Gfx mat_skybox__19[];
extern Gfx mat_revert_skybox__19[];
extern Gfx mat_skybox__20[];
extern Gfx mat_revert_skybox__20[];
extern Gfx mat_skybox__21[];
extern Gfx mat_revert_skybox__21[];
extern Gfx mat_skybox__22[];
extern Gfx mat_revert_skybox__22[];
extern Gfx mat_skybox__23[];
extern Gfx mat_revert_skybox__23[];
extern Gfx mat_skybox__24[];
extern Gfx mat_revert_skybox__24[];
extern Gfx mat_skybox__25[];
extern Gfx mat_revert_skybox__25[];
extern Gfx mat_skybox__26[];
extern Gfx mat_revert_skybox__26[];
extern Gfx mat_skybox__27[];
extern Gfx mat_revert_skybox__27[];
extern Gfx mat_skybox__28[];
extern Gfx mat_revert_skybox__28[];
extern Gfx mat_skybox__29[];
extern Gfx mat_revert_skybox__29[];
extern Gfx mat_skybox__30[];
extern Gfx mat_revert_skybox__30[];
extern Gfx mat_skybox__31[];
extern Gfx mat_revert_skybox__31[];
extern Gfx mat_skybox__32[];
extern Gfx mat_revert_skybox__32[];
extern Gfx mat_skybox__33[];
extern Gfx mat_revert_skybox__33[];
extern Gfx mat_skybox__34[];
extern Gfx mat_revert_skybox__34[];
extern Gfx mat_skybox__35[];
extern Gfx mat_revert_skybox__35[];
extern Gfx mat_skybox__36[];
extern Gfx mat_revert_skybox__36[];
extern Gfx mat_skybox__37[];
extern Gfx mat_revert_skybox__37[];
extern Gfx mat_skybox__38[];
extern Gfx mat_revert_skybox__38[];
extern Gfx mat_skybox__39[];
extern Gfx mat_revert_skybox__39[];
extern Gfx mat_skybox__40[];
extern Gfx mat_revert_skybox__40[];
extern Gfx mat_skybox__41[];
extern Gfx mat_revert_skybox__41[];
extern Gfx mat_skybox__42[];
extern Gfx mat_revert_skybox__42[];
extern Gfx mat_skybox__43[];
extern Gfx mat_revert_skybox__43[];
extern Gfx mat_skybox__44[];
extern Gfx mat_revert_skybox__44[];
extern Gfx mat_skybox__45[];
extern Gfx mat_revert_skybox__45[];
extern Gfx mat_skybox__46[];
extern Gfx mat_revert_skybox__46[];
extern Gfx mat_skybox__47[];
extern Gfx mat_revert_skybox__47[];
extern Gfx mat_skybox__48[];
extern Gfx mat_revert_skybox__48[];
extern Gfx mat_skybox__49[];
extern Gfx mat_revert_skybox__49[];
extern Gfx mat_skybox__50[];
extern Gfx mat_revert_skybox__50[];
extern Gfx mat_skybox__51[];
extern Gfx mat_revert_skybox__51[];
extern Gfx mat_skybox__52[];
extern Gfx mat_revert_skybox__52[];
extern Gfx mat_skybox__53[];
extern Gfx mat_revert_skybox__53[];
extern Gfx mat_skybox__54[];
extern Gfx mat_revert_skybox__54[];
extern Gfx mat_skybox__55[];
extern Gfx mat_revert_skybox__55[];
extern Gfx mat_skybox__56[];
extern Gfx mat_revert_skybox__56[];
extern Gfx mat_skybox__57[];
extern Gfx mat_revert_skybox__57[];
extern Gfx mat_skybox__58[];
extern Gfx mat_revert_skybox__58[];
extern Gfx mat_skybox__59[];
extern Gfx mat_revert_skybox__59[];
extern Gfx mat_skybox__60[];
extern Gfx mat_revert_skybox__60[];
extern Gfx mat_skybox__61[];
extern Gfx mat_revert_skybox__61[];
extern Gfx mat_skybox__62[];
extern Gfx mat_revert_skybox__62[];
extern Gfx mat_skybox__63[];
extern Gfx mat_revert_skybox__63[];
extern Gfx mat_skybox__64[];
extern Gfx mat_revert_skybox__64[];
extern Gfx bitdw_skybox[];
extern u8 skybox_bits__64_ci8[];
extern u8 skybox_bits__64_pal_rgba16[];
extern u8 skybox_bits__63_ci8[];
extern u8 skybox_bits__63_pal_rgba16[];
extern u8 skybox_bits__62_ci8[];
extern u8 skybox_bits__62_pal_rgba16[];
extern u8 skybox_bits__61_ci8[];
extern u8 skybox_bits__61_pal_rgba16[];
extern u8 skybox_bits__60_ci8[];
extern u8 skybox_bits__60_pal_rgba16[];
extern u8 skybox_bits__59_ci8[];
extern u8 skybox_bits__59_pal_rgba16[];
extern u8 skybox_bits__58_ci8[];
extern u8 skybox_bits__58_pal_rgba16[];
extern u8 skybox_bits__57_ci8[];
extern u8 skybox_bits__57_pal_rgba16[];
extern u8 skybox_bits__56_ci8[];
extern u8 skybox_bits__56_pal_rgba16[];
extern u8 skybox_bits__55_ci8[];
extern u8 skybox_bits__55_pal_rgba16[];
extern u8 skybox_bits__54_ci8[];
extern u8 skybox_bits__54_pal_rgba16[];
extern u8 skybox_bits__53_ci8[];
extern u8 skybox_bits__53_pal_rgba16[];
extern u8 skybox_bits__52_ci8[];
extern u8 skybox_bits__52_pal_rgba16[];
extern u8 skybox_bits__51_ci8[];
extern u8 skybox_bits__51_pal_rgba16[];
extern u8 skybox_bits__50_ci8[];
extern u8 skybox_bits__50_pal_rgba16[];
extern u8 skybox_bits__49_ci8[];
extern u8 skybox_bits__49_pal_rgba16[];
extern u8 skybox_bits__48_ci8[];
extern u8 skybox_bits__48_pal_rgba16[];
extern u8 skybox_bits__47_ci8[];
extern u8 skybox_bits__47_pal_rgba16[];
extern u8 skybox_bits__46_ci8[];
extern u8 skybox_bits__46_pal_rgba16[];
extern u8 skybox_bits__45_ci8[];
extern u8 skybox_bits__45_pal_rgba16[];
extern u8 skybox_bits__44_ci8[];
extern u8 skybox_bits__44_pal_rgba16[];
extern u8 skybox_bits__43_ci8[];
extern u8 skybox_bits__43_pal_rgba16[];
extern u8 skybox_bits__42_ci8[];
extern u8 skybox_bits__42_pal_rgba16[];
extern u8 skybox_bits__41_ci8[];
extern u8 skybox_bits__41_pal_rgba16[];
extern u8 skybox_bits__40_ci8[];
extern u8 skybox_bits__40_pal_rgba16[];
extern u8 skybox_bits__39_ci8[];
extern u8 skybox_bits__39_pal_rgba16[];
extern u8 skybox_bits__38_ci8[];
extern u8 skybox_bits__38_pal_rgba16[];
extern u8 skybox_bits__37_ci8[];
extern u8 skybox_bits__37_pal_rgba16[];
extern u8 skybox_bits__36_ci8[];
extern u8 skybox_bits__36_pal_rgba16[];
extern u8 skybox_bits__35_ci8[];
extern u8 skybox_bits__35_pal_rgba16[];
extern u8 skybox_bits__34_ci8[];
extern u8 skybox_bits__34_pal_rgba16[];
extern u8 skybox_bits__33_ci8[];
extern u8 skybox_bits__33_pal_rgba16[];
extern u8 skybox_bits__32_rgba16[];
extern u8 skybox_bits__31_rgba16[];
extern u8 skybox_bits__30_rgba16[];
extern u8 skybox_bits__29_rgba16[];
extern u8 skybox_bits__28_rgba16[];
extern u8 skybox_bits__27_rgba16[];
extern u8 skybox_bits__26_rgba16[];
extern u8 skybox_bits__25_rgba16[];
extern u8 skybox_bits__24_rgba16[];
extern u8 skybox_bits__23_ci8[];
extern u8 skybox_bits__23_pal_rgba16[];
extern u8 skybox_bits__22_rgba16[];
extern u8 skybox_bits__21_ci8[];
extern u8 skybox_bits__21_pal_rgba16[];
extern u8 skybox_bits__20_ci8[];
extern u8 skybox_bits__20_pal_rgba16[];
extern u8 skybox_bits__19_ci8[];
extern u8 skybox_bits__19_pal_rgba16[];
extern u8 skybox_bits__18_ci8[];
extern u8 skybox_bits__18_pal_rgba16[];
extern u8 skybox_bits__17_ci8[];
extern u8 skybox_bits__17_pal_rgba16[];
extern u8 skybox_bits__16_ci8[];
extern u8 skybox_bits__16_pal_rgba16[];
extern u8 skybox_bits__15_ci8[];
extern u8 skybox_bits__15_pal_rgba16[];
extern u8 skybox_bits__14_ci8[];
extern u8 skybox_bits__14_pal_rgba16[];
extern u8 skybox_bits__13_ci8[];
extern u8 skybox_bits__13_pal_rgba16[];
extern u8 skybox_bits__12_ci8[];
extern u8 skybox_bits__12_pal_rgba16[];
extern u8 skybox_bits__11_ci8[];
extern u8 skybox_bits__11_pal_rgba16[];
extern u8 skybox_bits__10_ci8[];
extern u8 skybox_bits__10_pal_rgba16[];
extern u8 skybox_bits__9_ci8[];
extern u8 skybox_bits__9_pal_rgba16[];
extern u8 skybox_bits__8_ci8[];
extern u8 skybox_bits__8_pal_rgba16[];
extern u8 skybox_bits__7_ci8[];
extern u8 skybox_bits__7_pal_rgba16[];
extern u8 skybox_bits__6_ci8[];
extern u8 skybox_bits__6_pal_rgba16[];
extern u8 skybox_bits__5_ci8[];
extern u8 skybox_bits__5_pal_rgba16[];
extern u8 skybox_bits__4_ci8[];
extern u8 skybox_bits__4_pal_rgba16[];
extern u8 skybox_bits__3_ci8[];
extern u8 skybox_bits__3_pal_rgba16[];
extern u8 skybox_bits__2_ci8[];
extern u8 skybox_bits__2_pal_rgba16[];
extern u8 skybox_bits__1_ci8[];
extern u8 skybox_bits__1_pal_rgba16[];
extern Vtx bits_skybox_vtx_0[28];
extern Gfx bits_skybox_tri_0[];
extern Vtx bits_skybox_vtx_1[8];
extern Gfx bits_skybox_tri_1[];
extern Vtx bits_skybox_vtx_2[8];
extern Gfx bits_skybox_tri_2[];
extern Vtx bits_skybox_vtx_3[8];
extern Gfx bits_skybox_tri_3[];
extern Vtx bits_skybox_vtx_4[8];
extern Gfx bits_skybox_tri_4[];
extern Vtx bits_skybox_vtx_5[8];
extern Gfx bits_skybox_tri_5[];
extern Vtx bits_skybox_vtx_6[8];
extern Gfx bits_skybox_tri_6[];
extern Vtx bits_skybox_vtx_7[8];
extern Gfx bits_skybox_tri_7[];
extern Vtx bits_skybox_vtx_8[8];
extern Gfx bits_skybox_tri_8[];
extern Vtx bits_skybox_vtx_9[8];
extern Gfx bits_skybox_tri_9[];
extern Vtx bits_skybox_vtx_10[8];
extern Gfx bits_skybox_tri_10[];
extern Vtx bits_skybox_vtx_11[8];
extern Gfx bits_skybox_tri_11[];
extern Vtx bits_skybox_vtx_12[8];
extern Gfx bits_skybox_tri_12[];
extern Vtx bits_skybox_vtx_13[8];
extern Gfx bits_skybox_tri_13[];
extern Vtx bits_skybox_vtx_14[8];
extern Gfx bits_skybox_tri_14[];
extern Vtx bits_skybox_vtx_15[8];
extern Gfx bits_skybox_tri_15[];
extern Vtx bits_skybox_vtx_16[11];
extern Gfx bits_skybox_tri_16[];
extern Vtx bits_skybox_vtx_17[11];
extern Gfx bits_skybox_tri_17[];
extern Vtx bits_skybox_vtx_18[12];
extern Gfx bits_skybox_tri_18[];
extern Vtx bits_skybox_vtx_19[12];
extern Gfx bits_skybox_tri_19[];
extern Vtx bits_skybox_vtx_20[11];
extern Gfx bits_skybox_tri_20[];
extern Vtx bits_skybox_vtx_21[11];
extern Gfx bits_skybox_tri_21[];
extern Vtx bits_skybox_vtx_22[11];
extern Gfx bits_skybox_tri_22[];
extern Vtx bits_skybox_vtx_23[11];
extern Gfx bits_skybox_tri_23[];
extern Vtx bits_skybox_vtx_24[10];
extern Gfx bits_skybox_tri_24[];
extern Vtx bits_skybox_vtx_25[12];
extern Gfx bits_skybox_tri_25[];
extern Vtx bits_skybox_vtx_26[13];
extern Gfx bits_skybox_tri_26[];
extern Vtx bits_skybox_vtx_27[12];
extern Gfx bits_skybox_tri_27[];
extern Vtx bits_skybox_vtx_28[11];
extern Gfx bits_skybox_tri_28[];
extern Vtx bits_skybox_vtx_29[11];
extern Gfx bits_skybox_tri_29[];
extern Vtx bits_skybox_vtx_30[11];
extern Gfx bits_skybox_tri_30[];
extern Vtx bits_skybox_vtx_31[11];
extern Gfx bits_skybox_tri_31[];
extern Vtx bits_skybox_vtx_32[10];
extern Gfx bits_skybox_tri_32[];
extern Vtx bits_skybox_vtx_33[12];
extern Gfx bits_skybox_tri_33[];
extern Vtx bits_skybox_vtx_34[13];
extern Gfx bits_skybox_tri_34[];
extern Vtx bits_skybox_vtx_35[12];
extern Gfx bits_skybox_tri_35[];
extern Vtx bits_skybox_vtx_36[11];
extern Gfx bits_skybox_tri_36[];
extern Vtx bits_skybox_vtx_37[11];
extern Gfx bits_skybox_tri_37[];
extern Vtx bits_skybox_vtx_38[11];
extern Gfx bits_skybox_tri_38[];
extern Vtx bits_skybox_vtx_39[11];
extern Gfx bits_skybox_tri_39[];
extern Vtx bits_skybox_vtx_40[10];
extern Gfx bits_skybox_tri_40[];
extern Vtx bits_skybox_vtx_41[11];
extern Gfx bits_skybox_tri_41[];
extern Vtx bits_skybox_vtx_42[12];
extern Gfx bits_skybox_tri_42[];
extern Vtx bits_skybox_vtx_43[12];
extern Gfx bits_skybox_tri_43[];
extern Vtx bits_skybox_vtx_44[11];
extern Gfx bits_skybox_tri_44[];
extern Vtx bits_skybox_vtx_45[11];
extern Gfx bits_skybox_tri_45[];
extern Vtx bits_skybox_vtx_46[12];
extern Gfx bits_skybox_tri_46[];
extern Vtx bits_skybox_vtx_47[12];
extern Gfx bits_skybox_tri_47[];
extern Vtx bits_skybox_vtx_48[10];
extern Gfx bits_skybox_tri_48[];
extern Vtx bits_skybox_vtx_49[10];
extern Gfx bits_skybox_tri_49[];
extern Vtx bits_skybox_vtx_50[10];
extern Gfx bits_skybox_tri_50[];
extern Vtx bits_skybox_vtx_51[10];
extern Gfx bits_skybox_tri_51[];
extern Vtx bits_skybox_vtx_52[10];
extern Gfx bits_skybox_tri_52[];
extern Vtx bits_skybox_vtx_53[10];
extern Gfx bits_skybox_tri_53[];
extern Vtx bits_skybox_vtx_54[10];
extern Gfx bits_skybox_tri_54[];
extern Vtx bits_skybox_vtx_55[10];
extern Gfx bits_skybox_tri_55[];
extern Vtx bits_skybox_vtx_56[10];
extern Gfx bits_skybox_tri_56[];
extern Vtx bits_skybox_vtx_57[10];
extern Gfx bits_skybox_tri_57[];
extern Vtx bits_skybox_vtx_58[10];
extern Gfx bits_skybox_tri_58[];
extern Vtx bits_skybox_vtx_59[10];
extern Gfx bits_skybox_tri_59[];
extern Vtx bits_skybox_vtx_60[10];
extern Gfx bits_skybox_tri_60[];
extern Vtx bits_skybox_vtx_61[10];
extern Gfx bits_skybox_tri_61[];
extern Vtx bits_skybox_vtx_62[10];
extern Gfx bits_skybox_tri_62[];
extern Vtx bits_skybox_vtx_63[30];
extern Gfx bits_skybox_tri_63[];
extern Gfx mat_skybox_bits__1[];
extern Gfx mat_revert_skybox_bits__1[];
extern Gfx mat_skybox_bits__2[];
extern Gfx mat_revert_skybox_bits__2[];
extern Gfx mat_skybox_bits__3[];
extern Gfx mat_revert_skybox_bits__3[];
extern Gfx mat_skybox_bits__4[];
extern Gfx mat_revert_skybox_bits__4[];
extern Gfx mat_skybox_bits__5[];
extern Gfx mat_revert_skybox_bits__5[];
extern Gfx mat_skybox_bits__6[];
extern Gfx mat_revert_skybox_bits__6[];
extern Gfx mat_skybox_bits__7[];
extern Gfx mat_revert_skybox_bits__7[];
extern Gfx mat_skybox_bits__8[];
extern Gfx mat_revert_skybox_bits__8[];
extern Gfx mat_skybox_bits__9[];
extern Gfx mat_revert_skybox_bits__9[];
extern Gfx mat_skybox_bits__10[];
extern Gfx mat_revert_skybox_bits__10[];
extern Gfx mat_skybox_bits__11[];
extern Gfx mat_revert_skybox_bits__11[];
extern Gfx mat_skybox_bits__12[];
extern Gfx mat_revert_skybox_bits__12[];
extern Gfx mat_skybox_bits__13[];
extern Gfx mat_revert_skybox_bits__13[];
extern Gfx mat_skybox_bits__14[];
extern Gfx mat_revert_skybox_bits__14[];
extern Gfx mat_skybox_bits__15[];
extern Gfx mat_revert_skybox_bits__15[];
extern Gfx mat_skybox_bits__16[];
extern Gfx mat_revert_skybox_bits__16[];
extern Gfx mat_skybox_bits__17[];
extern Gfx mat_revert_skybox_bits__17[];
extern Gfx mat_skybox_bits__18[];
extern Gfx mat_revert_skybox_bits__18[];
extern Gfx mat_skybox_bits__19[];
extern Gfx mat_revert_skybox_bits__19[];
extern Gfx mat_skybox_bits__20[];
extern Gfx mat_revert_skybox_bits__20[];
extern Gfx mat_skybox_bits__21[];
extern Gfx mat_revert_skybox_bits__21[];
extern Gfx mat_skybox_bits__22[];
extern Gfx mat_revert_skybox_bits__22[];
extern Gfx mat_skybox_bits__23[];
extern Gfx mat_revert_skybox_bits__23[];
extern Gfx mat_skybox_bits__24[];
extern Gfx mat_revert_skybox_bits__24[];
extern Gfx mat_skybox_bits__25[];
extern Gfx mat_revert_skybox_bits__25[];
extern Gfx mat_skybox_bits__26[];
extern Gfx mat_revert_skybox_bits__26[];
extern Gfx mat_skybox_bits__27[];
extern Gfx mat_revert_skybox_bits__27[];
extern Gfx mat_skybox_bits__28[];
extern Gfx mat_revert_skybox_bits__28[];
extern Gfx mat_skybox_bits__29[];
extern Gfx mat_revert_skybox_bits__29[];
extern Gfx mat_skybox_bits__30[];
extern Gfx mat_revert_skybox_bits__30[];
extern Gfx mat_skybox_bits__31[];
extern Gfx mat_revert_skybox_bits__31[];
extern Gfx mat_skybox_bits__32[];
extern Gfx mat_revert_skybox_bits__32[];
extern Gfx mat_skybox_bits__33[];
extern Gfx mat_revert_skybox_bits__33[];
extern Gfx mat_skybox_bits__34[];
extern Gfx mat_revert_skybox_bits__34[];
extern Gfx mat_skybox_bits__35[];
extern Gfx mat_revert_skybox_bits__35[];
extern Gfx mat_skybox_bits__36[];
extern Gfx mat_revert_skybox_bits__36[];
extern Gfx mat_skybox_bits__37[];
extern Gfx mat_revert_skybox_bits__37[];
extern Gfx mat_skybox_bits__38[];
extern Gfx mat_revert_skybox_bits__38[];
extern Gfx mat_skybox_bits__39[];
extern Gfx mat_revert_skybox_bits__39[];
extern Gfx mat_skybox_bits__40[];
extern Gfx mat_revert_skybox_bits__40[];
extern Gfx mat_skybox_bits__41[];
extern Gfx mat_revert_skybox_bits__41[];
extern Gfx mat_skybox_bits__42[];
extern Gfx mat_revert_skybox_bits__42[];
extern Gfx mat_skybox_bits__43[];
extern Gfx mat_revert_skybox_bits__43[];
extern Gfx mat_skybox_bits__44[];
extern Gfx mat_revert_skybox_bits__44[];
extern Gfx mat_skybox_bits__45[];
extern Gfx mat_revert_skybox_bits__45[];
extern Gfx mat_skybox_bits__46[];
extern Gfx mat_revert_skybox_bits__46[];
extern Gfx mat_skybox_bits__47[];
extern Gfx mat_revert_skybox_bits__47[];
extern Gfx mat_skybox_bits__48[];
extern Gfx mat_revert_skybox_bits__48[];
extern Gfx mat_skybox_bits__49[];
extern Gfx mat_revert_skybox_bits__49[];
extern Gfx mat_skybox_bits__50[];
extern Gfx mat_revert_skybox_bits__50[];
extern Gfx mat_skybox_bits__51[];
extern Gfx mat_revert_skybox_bits__51[];
extern Gfx mat_skybox_bits__52[];
extern Gfx mat_revert_skybox_bits__52[];
extern Gfx mat_skybox_bits__53[];
extern Gfx mat_revert_skybox_bits__53[];
extern Gfx mat_skybox_bits__54[];
extern Gfx mat_revert_skybox_bits__54[];
extern Gfx mat_skybox_bits__55[];
extern Gfx mat_revert_skybox_bits__55[];
extern Gfx mat_skybox_bits__56[];
extern Gfx mat_revert_skybox_bits__56[];
extern Gfx mat_skybox_bits__57[];
extern Gfx mat_revert_skybox_bits__57[];
extern Gfx mat_skybox_bits__58[];
extern Gfx mat_revert_skybox_bits__58[];
extern Gfx mat_skybox_bits__59[];
extern Gfx mat_revert_skybox_bits__59[];
extern Gfx mat_skybox_bits__60[];
extern Gfx mat_revert_skybox_bits__60[];
extern Gfx mat_skybox_bits__61[];
extern Gfx mat_revert_skybox_bits__61[];
extern Gfx mat_skybox_bits__62[];
extern Gfx mat_revert_skybox_bits__62[];
extern Gfx mat_skybox_bits__63[];
extern Gfx mat_revert_skybox_bits__63[];
extern Gfx mat_skybox_bits__64[];
extern Gfx mat_revert_skybox_bits__64[];
extern Gfx bits_skybox[];

#endif // SEGMENT2_H
