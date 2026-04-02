// Room: /yangzhou/dujiangqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","渡江橋");
	set("long",@LONG
一座三拱石橋橫臥在大運河上，橋的側欄上由知州歐陽修題着「渡
江橋」，橋下各色船隻穿流不息。東邊是揚州最大的碼頭，漕運的糧食，
兩淮產的鹽，多在此裝卸。過了橋就是揚州的南門：安定門。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"north"  : __DIR__"nanmen",
		"south"  : "/d/wudang/wdroad1",
	]));
	set("objects", ([
		"/d/beijing/npc/shisong" :1,
	]));
	set("coor/x", 10);
	set("coor/y", -110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
