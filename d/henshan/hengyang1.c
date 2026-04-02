// Room: /d/henshan/hengyang1.c
// Modified by Java on Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "衡陽西街");
	set("long", @LONG
你走在碎石鋪就的狹小街道上。街上時常有人持劍疾行，似乎這裏
出了啥事了。南邊是一家小店，北面一座大宇巍峨，重檐疊瓦，門口彩
燈高懸，管家家丁好象都是武林中人。
LONG );
	set("outdoors", "hengyang");
	set("exits", ([
		"east"   : __DIR__"hengyang",
		"west"   : __DIR__"hsroad4",
		"south"  : __DIR__"shop",
		"north"  : __DIR__"liufugate",
	]));

        set("no_clean_up", 0);
	set("coor/x", -400);
	set("coor/y", -1200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}