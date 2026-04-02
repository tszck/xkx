// /beijing/weifu_men.c
// Last modified by winder 2003.10.10

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","韋府大門");
	set("long", @LONG
這裏便是當朝第一寵臣，被康熙帝御封爲“一等鹿鼎公”的韋公爺
的居宅。來到這裏，一座富麗堂皇的高大建築出現在你的眼前，大門兩
側是兩頭高大的石獅子。門上橫着一塊大匾，上面是當朝首輔、戶部尚
書兼保和殿李大學士親筆工楷的“鹿鼎公府”四個金筆大字。
    門前站着個韋府的侍衛。
LONG );
	set("exits", ([
		"north" : __DIR__"weifu_zoulang1",
		"south" : __DIR__"xisi2",
	]));
	set("objects", ([
		__DIR__"npc/shiwei2" : 1,
	]));
	set("coor/x", -220);
	set("coor/y", 4090);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("shi wei", environment(me))) && dir == "north")
		return notify_fail("侍衛喝道：別亂逛，公爺今天不見客。\n\n");
	return ::valid_leave(me, dir);
}
