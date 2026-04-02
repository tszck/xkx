// Room: /d/baituo/changlang.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","長廊");
	set("long", @LONG
這裏是非常氣派的長廊。北邊是間休息室。南邊有間藥房，裏面傳
來一陣器皿碰擊的聲音。西邊是扇拱月形小敞門。東邊是練功場。
LONG	);

	set("exits",([
		"west"  : __DIR__"ximen",
		"north" : __DIR__"restroom",
		"east"  : __DIR__"liangong",
		"south" : __DIR__"yaofang",
	]));
	set("outdoors","baituo");
	set("no_clean_up", 0);
	set("coor/x", -50020);
	set("coor/y", 20040);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
