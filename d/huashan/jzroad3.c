// Room: /d/huashan/jzroad3.c

inherit ROOM;
void create()
{
	set("short", "中條山腳");
	set("long", @LONG
你來到中條山腳。仰望天空，山勢壓頂，天邊的紅霞映透了整個山
林，呼嘯的穿山風颳個不停。你不禁稍許有些懼意。向東有一條上山小
路。
LONG );
	set("outdoors", "zhongtiao");
	set("exits", ([
		"west"   : __DIR__"jzroad2",
		"eastup" : __DIR__"jzroad4",
	]));
	set("objects", ([
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", -930);
	set("coor/y", 210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
