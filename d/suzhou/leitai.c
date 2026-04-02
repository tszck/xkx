// Room: /d/suzhou/leitai.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "擂臺前廣場");
	set("long", @LONG
這裏是蘇州擂臺前面的一個大廣場，有許多人正在擂臺上比武，到
處是人山人海，如果你也想試試身手，那麼就請跳上擂臺比試比試吧。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"hutong2",
	]));
	set("coor/x", 870);
	set("coor/y", -980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

