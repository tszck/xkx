// ROOM liangunshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "棍窠");
	set("long", @LONG
這裏是玄兵古洞造棍的地方。周圍整齊的堆放着造棍用的原料，一
個年輕小夥手裏拿着一本玄天棍法，正在仔細的研讀着。看到你走了過
來，連忙放下手中的書，帶着一臉純真衝你憨憨的一笑，臉不由又紅了。
LONG );
	set("exits", ([
		"east" : "/d/xueshan/shenghu",
	]));
	set("objects", ([
		__DIR__"npc/shigun" : 1,
	]));
	set("coor/x", -30050);
	set("coor/y", -8010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
