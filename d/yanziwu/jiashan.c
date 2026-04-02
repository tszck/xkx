//ROOM: /d/yanziwu/jiashan.c

inherit ROOM;

void create()
{
	set("short", "假山");
	set("long",@LONG
怪石堆疊，巨石參差，你有些頭暈目眩，那麼多山洞你不知該鑽哪
一個。個個山洞都昏暗曲折，實在不知通向什麼地方。
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"west" : __DIR__"zuijing",
		"east" : __DIR__"shuiyun",
		"north": __DIR__"huayuan",
//		"south": __DIR__"huanshi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 840);
	set("coor/y", -1540);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}