// Room: /yangzhou/dongmenqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","小東門橋");
	set("long",@LONG
小東門橋由青石築成，橋面光滑平整，據説是前朝所建，年代久遠。
河中心的橋墩上爬滿了青苔，青青的河水從橋下悠然流過，滋潤着青苔，
孕育了揚州。你站在橋上，看着小秦淮河兩邊的密密的屋檐，聽着偶爾
傳出的兒童的嬉笑聲，你感受到揚州悠閒的一面。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"hejiajie",
		"east"  : __DIR__"jiaowai7",
	]));
	set("objects", ([
		"/d/village/npc/boy": random(5),
	]));
	set("coor/x", 30);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}