// /kaifeng/zhongyuan.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "中院");
	set("long", @LONG
中院分爲前後兩部分，院子的正中有座鐵製浮屠，高七層，雕刻着
精美花紋。前邊部分除中間的行道外，兩邊是花圃，各種一棵高大的菩
提樹。後邊鋪着青石，通向大雄寶殿。南邊是天王殿，東邊是素齋廚，
西面是浴室。
LONG
	);
	set("objects", ([
		__DIR__"npc/obj/tiefutu" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"tianwang",
		"north" : __DIR__"daxiong",
		"east"  : __DIR__"chufang",
		"west"  : __DIR__"yushi1",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
