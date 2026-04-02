// Room: /d/baituo/jiudian.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "酒店");
	set("long", @LONG
這裏是一家獨具特色的酒店，由於地處『白駝山』下，酒店可以供
應風味食品－－蛇肉。許多中原來客都愛來嚐嚐鮮，所以酒店生意興隆。
酒店還經營打散裝酒的業務。
LONG	);
	set("exits", ([
		"south" : __DIR__"xijie",
	]));
	set("objects",([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("resource/water", 1);
	set("coor/x", -49990);
	set("coor/y", 19990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

