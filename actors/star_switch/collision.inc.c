const Collision star_switch_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(20),
	COL_VERTEX(-32, 16, 39),
	COL_VERTEX(0, 16, 28),
	COL_VERTEX(-28, 16, 7),
	COL_VERTEX(28, 16, 7),
	COL_VERTEX(-17, 16, -26),
	COL_VERTEX(17, 16, -26),
	COL_VERTEX(0, 16, -58),
	COL_VERTEX(-37, 0, 11),
	COL_VERTEX(-52, 16, -21),
	COL_VERTEX(-23, 0, -33),
	COL_VERTEX(23, 0, -33),
	COL_VERTEX(52, 16, -21),
	COL_VERTEX(37, 0, 11),
	COL_VERTEX(32, 16, 39),
	COL_VERTEX(0, 0, 38),
	COL_VERTEX(-42, 0, 54),
	COL_VERTEX(-68, 0, -26),
	COL_VERTEX(0, 0, -76),
	COL_VERTEX(68, 0, -26),
	COL_VERTEX(42, 0, 54),
	COL_TRI_INIT(SURFACE_NOT_SLIPPERY, 28),
	COL_TRI(0, 1, 2),
	COL_TRI(3, 2, 1),
	COL_TRI(2, 3, 4),
	COL_TRI(5, 4, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(7, 0, 2),
	COL_TRI(8, 7, 2),
	COL_TRI(9, 8, 4),
	COL_TRI(6, 9, 4),
	COL_TRI(10, 6, 5),
	COL_TRI(11, 10, 5),
	COL_TRI(12, 11, 3),
	COL_TRI(13, 12, 3),
	COL_TRI(14, 13, 1),
	COL_TRI(0, 14, 1),
	COL_TRI(5, 3, 11),
	COL_TRI(2, 4, 8),
	COL_TRI(13, 3, 1),
	COL_TRI(7, 15, 0),
	COL_TRI(8, 16, 7),
	COL_TRI(9, 16, 8),
	COL_TRI(6, 17, 9),
	COL_TRI(10, 17, 6),
	COL_TRI(11, 18, 10),
	COL_TRI(12, 18, 11),
	COL_TRI(13, 19, 12),
	COL_TRI(14, 19, 13),
	COL_TRI(0, 15, 14),
	COL_TRI_STOP(),
	COL_END()
};
