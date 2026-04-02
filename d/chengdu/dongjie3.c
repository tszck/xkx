// Room: /d/chengdu/dongjie3.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "東大街");
	set("long", @LONG
這條街貫穿成都大街小巷，因這條街沿街都是有錢有勢的酒樓、茶
館，所以又稱為“美食街”。這裏店鋪林立，商賈成羣。白天這裏車馬
如龍，人聲鼎沸，夜裏星光伴月，燈火通明。南邊是個茶館，北邊有個
水井。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"eastgate",
		"west"  : __DIR__"dongjie2",
		"north" : __DIR__"shuijing",
		"south" : __DIR__"chaguan3",
	]));
	set("objects", ([
		__DIR__"npc/youke" : 1,
	]));
	set("coor/x", -8020);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

