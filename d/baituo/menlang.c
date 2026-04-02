// Room: /d/baituo/menlang.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","門廊");
	set("long", @LONG
這是個門廊，門廊的飛檐上掛着一串串的小銅鈴，在清風中發出清
脆動聽的鈴聲。
LONG	);
	set("exits",([
		"north" : __DIR__"tangwu",
		"south" : __DIR__"liangong",
	]));
	set("objects",([
		__DIR__"npc/guanjia" : 1,
	]));
	set("outdoors","baituo");
	set("coor/x", -50010);
	set("coor/y", 20050);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

