//ziweitang.c
inherit ROOM;

void create()
{
	set("short", "紫微堂");
	set("long", @LONG
這裏就是明教的紫微堂，堂上的大匾上 "紫微貫日" 四字並不因堂
主殷素素早逝而有絲毫減色。堂中陳設一如往昔。
LONG );
	set("exits", ([
		"east"  : __DIR__"tianweitang",
	]));
	set("objects",([
		__DIR__"npc/yinwushou":1,
	]));
	set("coor/x", -52040);
	set("coor/y", 1040);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}