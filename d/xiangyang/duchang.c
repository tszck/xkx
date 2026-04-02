// Room: /d/xiangyang/duchang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "賭場");
	set("long", @LONG
這裏本是襄陽最大的賭場。可是大戰當前，爲免守軍軍心
動搖、軍紀敗壞，郭大俠早已下令關閉了賭場。門可羅雀的大
院，可以想象當時的規模，閒置破敗的賭具，也不知道在無聲
地訴說什麼。
LONG );
	set("no_clean_up", 0);

	set("exits", ([
		"east" : __DIR__"southjie2",
	]));
	set("coor/x", -510);
	set("coor/y", -530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
