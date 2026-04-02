// /kaifeng/tinyuan.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "龍亭園");
	set("long", @LONG
這裏是一片花木蔥鬱的園林。園林的南北兩邊分別是楊家湖和潘家
湖，湖中碧波盪漾，湖邊垂柳依依，芳草如茵。從此向北是龍亭大殿，
西面是西大街道。
LONG
	);
	set("exits", ([
		"east" : __DIR__"road5",
		"west" : __DIR__"wroad3",
		"north" : __DIR__"longting",
	]));

	set("no_clean_up", 0);
	set("outdoors", "kaifeng");
	setup();
	replace_program(ROOM);
}
