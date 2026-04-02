// Room: /d/mingjiao/huangtulu2.c
// Date: Java 97/04/9

inherit ROOM;

void create()
{
	set("short", "黃土小路");
	set("long", @LONG
這裏是茂密松林中的一條黃土小路。松林極密，四面都是藍幽幽的
感覺，白白的冰雪反光耀眼。你來到一個山腰的危崖之邊，前邊有一個
小洞。
LONG );
	set("exits", ([
		"east"  : __DIR__"huangtulu1",
		"enter" : __DIR__"shandong",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52050);
	set("coor/y", 800);
	set("coor/z", 20);
	setup();
}

int valid_leave(object me, string dir)
{
 
	if ((dir == "enter") &&
		!wizardp(me) && !objectp(present("xiao zhao", environment(me))))
	{
		return notify_fail("那是明教聖地，擅入殺無赦。\n");
	}
	return ::valid_leave(me, dir);
}