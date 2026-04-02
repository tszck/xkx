// hanshuitan.c 寒水潭
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_qian(string arg);

void create()
{
	set("short", "寒水潭");
	set("long", @LONG
這裏是草地的邊緣，青草已經很稀疏了，仍然有一二玉蜂來回地飛
過尋覓食物。你的面前是一個清波盪漾的大水潭 (tan)，陽光映照下，
水面泛起了一道七色彩虹，望着這般美景，你俗念盡消。
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"northwest" : __DIR__"caodi2",
	]));
	set("objects", ([
		__DIR__"npc/yufeng" : random(3),
	]));
	set("item_desc", ([
		"tan": "潭水很清，隱約可以見過水底的怪石嶙峋，一二遊魚倏地從水底遊過，又不知道躲到哪塊石頭後面藏身去了。\n",
	]) );
	set("coor/x", -3200);
	set("coor/y", 30);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

