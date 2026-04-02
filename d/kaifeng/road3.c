// /kaifeng/road3.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "御街");
	set("long", @LONG
御街是條橫貫南北的大街道，也是皇帝出巡時的要道。兩邊的店鋪
樓閣不斷，實是人間一景。抬眼望去，層層疊疊的房屋已然望不到盡頭。
西面那一座大府第便是著名的天波楊府。
LONG);
	set("objects", ([
		__DIR__"npc/fujiazi" : 1,
	]));
	set("outdoors", "kaifeng");
	set("exits", ([
		"east" : __DIR__"yaqi",
		"west" : __DIR__"yangfu",
		"south" : __DIR__"road2",
		"northup" : __DIR__"road4",
	]));

	setup();
	replace_program(ROOM);
}
