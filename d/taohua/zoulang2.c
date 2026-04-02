// Room: /d/taohua/zoulang2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "迴廊");
	set("long", @LONG
一條連接大廳和內室的迴廊。走廊外花木扶疏，桃花滿地，遠處碧
藍色的大海和翠綠的島嶼映襯着點點白帆，歷歷如畫。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("exits", ([
		"north": __DIR__"neishi1",
		"south": __DIR__"zoulang5",
	]) );

	set("coor/x", 9000);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}