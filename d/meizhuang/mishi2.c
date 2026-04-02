// /d/meizhuang/mishi2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "柳園");
	set("long", @LONG
這是一座小小的園子，裏面種滿了大大小小的柳樹，柳枝有的長可
及地，有的還是新枝嫩葉，但中間有一株灌木(guanmu)低低矮矮的，長
在那裏，非常惹人注目，你不禁朝那裏多看了兩眼。
LONG
	);
	set("exits", ([
		"west" : __DIR__"xiaoyuan",
	]));
	set("objects", ([
		__DIR__"obj/guanmu" : 1,
	]) );
	set("outdoors", "meizhuang");
	set("coor/x", 3520);
	set("coor/y", -1430);
	set("coor/z", 20);
	setup();
}
void reset()
{
	object *inv, con, item, guanmu;

	::reset();

	guanmu= present("guanmu", this_object());
	inv = all_inventory(guanmu);

	if( !sizeof(inv))
	{
		con = new(__DIR__"obj/honghua");
		item = new(NOSTRUM_DIR"zhuguo");
		item->move(con);
		con->move(guanmu);
	}
}
