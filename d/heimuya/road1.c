// Room: /d/heimuya/road1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "亂石坡");
	set("long", @LONG
這是一處亂石怪異的小山崗，向東北是通往平安州的小路。據說前
方經常有野獸出沒，不可久留。
LONG );
	set("outdoors", "heimuya");
	set("exits", ([
		"northeast" : __DIR__"road2",
		"southwest" : __DIR__"road4",
		"west"      : __DIR__"linjxd1",
		"east"      : __DIR__"dating4",
	]));
	set("objects",([  
//		__DIR__"npc/laozhe" : 1 ,
		"/clone/misc/dache" : 1,
	])); 
	set("coor/x", -3020);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
