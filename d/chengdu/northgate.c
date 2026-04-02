// Room: /d/chengdu/northchengmen.c
// Date: Feb.14 1998 by Java

#include <ansi.h>
inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "北城門");
	set("long", @LONG
這是成都北城門，城門正上方刻着“北門”兩個楷書大字，城牆上
貼着幾張官府告示(gaoshi)。一條筆直的青石板大道向北延伸。北邊望
去，一片綠油油的田野夾着隨風搖曳的高樹，長竹。城門邊兩行官兵仔
細盤查進出人等。
LONG
	);
	set("outdoors", "chengdu");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"south"  : __DIR__"beijie",
		"north"  : __DIR__"fuheqiaon",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -8050);
	set("coor/y", -2960);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n成都提督\n吳天德\n";
}

