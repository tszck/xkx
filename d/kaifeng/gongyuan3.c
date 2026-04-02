// /kaifeng/gongyuan.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "開封貢院");
	set("long", @LONG
過了州橋，街道邊一處高深的大院，威武的石獅守衛兩邊門楣上『
貢院』兩字作深紅色，每月上旬，此處將進行舉人的開考，門邊牆上貼
了張告示。
LONG);
	set("objects", ([
		__DIR__"npc/zhukao3" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"road2",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
