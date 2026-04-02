// Room: /d/taohua/fanting.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "飯廳");
	set("long", @LONG
這是黃藥師一家人喫飯的地方。飯廳中央擺着大圓桌，周圍則放着
幾張竹椅。窗口還擺着幾盆水仙花。你吸了一下鼻子，啊．．．好香！
也不知到底是花香還是飯香。
LONG
	);
	set("exits", ([
		"east"  : __DIR__"neishi1",
		"north" : __DIR__"chufang",
	]));
	set("objects", ([
		__DIR__"npc/cheng" : 1,
	]));

	set("coor/x", 8990);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}