// Room: /d/mingjiao/shanjiao.c
// Date: Java 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "崑崙山下");
	set("long", @LONG
這裏是千里崑崙的東麓，遠望蒼天浩浩，白雲悠悠。東方沃野千里，
楚天遼闊；西面高山巍巍，迤邐萬裏。叱吒武林八百年的明教就座落在
這羣山之中。明教----是多少武林豪傑所向往的地方，在那裏，有無數
生死相許的好兄弟，無論是正是邪。就在這西方的羣山之後，等待着你
去譜寫又一曲武林傳奇。
LONG );
	set("exits", ([
		"west"      : __DIR__"tomen2",
		"east"      : __DIR__"gebitan5",
		"northwest" : "/d/kunlun/zhenyuanqiao",
	]));

	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", 800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}