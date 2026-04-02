// Room: /d/taohua/zoulang5.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "迴廊");
	set("long", @LONG
一條連接大廳和練武場的迴廊。走廊外花木扶疏，桃花滿地，遠處
碧藍色的大海和翠綠的島嶼映襯着點點白帆，歷歷如畫。東邊望去，是
一大片的海灘。
LONG
	);
	set("exits", ([
		"east" : __DIR__"haitan",
		"north": __DIR__"zoulang2",
		"south": __DIR__"zoulang1",
	]) );
	set("objects", ([
		__DIR__"npc/yapu": 1,
	]));
	set("outdoors","taohua");
	set("coor/x", 9000);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	set("coor/x", 9000);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}