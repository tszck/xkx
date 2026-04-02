// Room: /yangzhou/shiliji7.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","十里長街");
	set("long",@LONG
這裏就是煙花三月的十里長街。長街寬達三十丈，青磚鋪地，東邊
一道泄水溝。街中心種有槐樹，分行人以左右而行。西邊是官河，岸邊
相間種有綠柳碧桃，倒影水面，搖曳風中。東邊是一家新入江湖的少年
常去的武館。西邊是一家打鐵鋪，叮叮噹噹的聲音老遠就能聽到。北面
通向中心廣場，南面一直走就出南門了。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"datiepu",
		"east"  : "/d/wuguan/wg_guanmen",
		"south" : __DIR__"nanmendajie",
		"north" : __DIR__"shilijie6",
	]));
	set("objects", ([
		CLASS_D("shaolin") + "/tuoboseng" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
