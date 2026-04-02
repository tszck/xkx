// Room: /d/taohua/zoulang3.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "迴廊");
	set("long", @LONG
一條連接大廳和練武場的迴廊。走廊外花木扶疏，桃花滿地，遠處
碧藍色的大海和翠綠的島嶼映襯着點點白帆，歷歷如畫。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("exits", ([
		"west" : __DIR__"lianwuchang",
		"east" : __DIR__"zoulang1",
		"north": __DIR__"daojufang",
		"south": __DIR__"bingqi",
	]) );

	set("coor/x", 8990);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir != "east" && me->query("family/family_name") != "桃花島")
		return notify_fail("一位啞僕攔住了你，用手勢比劃着表示那邊不能去。\n");
	
	return ::valid_leave(me, dir);
}