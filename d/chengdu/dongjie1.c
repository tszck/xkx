// Room: /d/chengdu/dongjie1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "東大街");
	set("long", @LONG
這條街貫穿成都大街小巷，因這條街沿街都是有錢有勢的酒樓、飯
館，所以又稱爲“美食街”。這裏店鋪林立，商賈成羣。白天這裏車馬
如龍，人聲鼎沸，夜裏星光伴月，燈火通明。南邊便是成都著名的商業
中心：春熙路。北邊有個客棧。
LONG	);
	set("outdoors","chengdu");
	set("exits", ([
		"west"  : __DIR__"guangchang",
		"east"  : __DIR__"dongjie2",		
		"north" : __DIR__"kedian",
		"south" : __DIR__"chunxilu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8040);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
 
