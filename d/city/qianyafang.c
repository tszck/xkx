// Room: zhengtang.c
#include <ansi.h>
inherit ROOM;
void bt_same(object who,object me);

void create()
{
	set("short", "簽押房");
	set("long", @LONG
這裏是揚州府的簽押房，平常捕頭衙役們都在這裏等候程大人的傳
招。出門的北面就是大堂了，許多人從這裏的門前進進出出，大堂上程
大人正在升堂問案。
LONG
	);
	set("exits", ([
		"west" : __DIR__"yamenyuan",
	]));
	set("objects", ([
		__DIR__"task3/shiye": 1,
	]));
	set("coor/x", -19);
	set("coor/y", 1);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
