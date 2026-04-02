// Room: /d/taohua/zoulang4.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "迴廊");
	set("long", @LONG
一條連接大廳和書房的迴廊。走廊外花木扶疏，桃花滿地，遠處碧
藍色的大海和翠綠的島嶼映襯着點點白帆，歷歷如畫。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("exits", ([
		"west" : __DIR__"dating",
		"east" : __DIR__"bookroom",
		"north": __DIR__"tanzhige",
		"south": __DIR__"pikonglang",
	]) );

	set("coor/x", 9020);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "桃花島") && dir != "west")
		return notify_fail("一位啞僕攔住了你，用手勢比劃着表示那邊不能去。\n");

	return ::valid_leave(me, dir);
}