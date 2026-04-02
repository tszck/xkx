// Room: /d/nanshaolin/dxshijie.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "臺階");
	set("long", @LONG
大雄寶殿前的石階，三道平行的青石階展向前方。北面是一條石板
路，隱隱飄來陣陣清煙。香客們大都在此屏息默禱，然後一步一拜到大
雄寶殿去。
LONG );
	set("exits", ([
		"northup" : __DIR__ "pingtai",
		"south"   : __DIR__ "miaofadian",
	]));
	set("objects", ([
		CLASS_D("nanshaolin")+"/first" : 1,
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6220);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

