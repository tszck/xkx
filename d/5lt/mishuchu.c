// Room: /d/5lt/msoffice.c

inherit ROOM;

void create()
{
	set("short", "祕書處");
	set("long", @LONG
這裏是電視臺的祕書處，屋內顯眼地擺着兩張大大的辦公桌，桌子
後面坐着兩位祕書。別看職位雖小，電視臺大大小小的事務基本上都由
她們把持。東面是臺長辦公室。
LONG);
	set("outdoors", "5lt");
	set("exits", ([
		"up"     : __DIR__"yanboting",
		"down"   : __DIR__"dating",
		"east"   : __DIR__"tzoffice",
	]));
        set("objects", ([
		__DIR__"npc/xueyuan"   : 1,
	        __DIR__"npc/singleblue": 1,
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("coor/x", -185);
	set("coor/y", 30);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
