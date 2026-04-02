// Room: /d/baituo/nongshe.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "農舍");
	set("long", @LONG
這裏是一間小農舍，傢俱很新。門邊掛着長慶對聯，屋檐下掛着一
串串辣椒。屋內壁上掛着犁和獵槍，看來主人比較富裕。
LONG );
	set("exits", ([
		"west" : __DIR__"guangchang",
	]));
	set("objects",([
		__DIR__"npc/woman" : 1,
	]));
	set("coor/x", -50000);
	set("coor/y", 19990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
