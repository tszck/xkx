// Room: /d/baituo/shanlu.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","山路");
	set("long", @LONG
這裏是山上的泥路。四周是密密的叢林，偶有獸鳥蹤跡。東南邊一
條蜿蜒的小路通往山下的村莊。
LONG	);
	set("exits",([
		"northwest" : __DIR__"shanlu1",
		"southeast" : __DIR__"guangchang",
	]));
	set("outdoors", "baituo");
	set("no_clean_up", 0);
	set("coor/x", -50020);
	set("coor/y", 20000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
