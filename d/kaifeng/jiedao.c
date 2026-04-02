// /kaifeng/jiedao.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "御街");
	set("long", @LONG
這條道橫貫南北，北到宣德門，南至南盈門，是以前皇上出巡時常
走的道，所以修得是格外平整。道兩邊店鋪不斷。向南再過去不遠。就
是開封府大堂。北面是大相國寺。
LONG
	);
	set("exits", ([
		"south" : __DIR__"jiedao1",
		"north" : __DIR__"xiangguosi",
	]));
	set("outdoors", "kaifeng");
	set("objects", ([
		__DIR__"npc/fujiazi" : 1,
		__DIR__"npc/qigai" : 1,
	]));

	setup();
	replace_program(ROOM);
}
