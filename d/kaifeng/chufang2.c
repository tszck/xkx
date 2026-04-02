// /kaifeng/chufang2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "素齋廚");
	set("long", @LONG
素齋廚的幾個大竈燒得正旺，白色的蒸汽在室頂鋪了一層竈膛間擺
滿了松柴，和尚們很挑剔，説是用這種柴禾煮出的飯菜才去近佛。一邊
的桌上擺着一個飯桶。東面有個小門出去。
LONG);
	set("objects", ([
		__DIR__"npc/suzhai" : 1,
		__DIR__"npc/shaohuo" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"chufang",
		"east" : __DIR__"zoulang1",
	]));

	setup();
	replace_program(ROOM);
}
