// Room: /d/tiezhang/sslin2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "松樹林");
	set("long", @LONG
你走進一片黑壓壓的松樹林，這裏的松樹枝繁葉茂，樹冠相疊，遮
天蔽日。幾素陽光從樹梢間照射下來，在淡淡的霧氣中，形成條條白色
的光柱，煞是好看。你走着走着，忽然發現自己已迷失在這片松林中，
找不到出去的路了。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"sslin3",
		"south" : __FILE__,
		"west"  : __DIR__"sslin1",
		"east"  : "/d/npc/m_weapon/lianqiangshi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2030);
	set("coor/y", -1880);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
