// Room: /d/shaolin/fzlou2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "方丈室");
	set("long", @LONG
方丈室陳設簡潔，正中一幾，一蒲團，一矮牀。北面牆上寫
着大大的一個『禪』字。一位慈眉善目的灰衣老僧正端坐於蒲團
上打坐。
LONG );
	set("exits", ([
		"south" : __DIR__"fzlou1",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/xuan-ci" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 850);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}