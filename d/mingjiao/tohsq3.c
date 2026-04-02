//TOHSQ3.C

inherit ROOM;

void create()
{
	set("short", "山林路");
	set("long", @LONG
這裏快接近谷低了，但北面瀑布擋住了去路。瀑布如一匹銀練奔流
而下，傾瀉在一深潭之中，水聲轟鳴，簾霧直上重霄。兩旁山石高聳，
陡壁斷崖，象是人工劈就而成。深潭前的青石被磨得鋥亮，好象總有人
在這裏來往。
LONG );
	set("exits", ([
		"southeast" :__DIR__"tohsq2",
	]));

	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 890);
	set("coor/z", 50);
	setup();
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me;
	me=this_player();
	if(!arg)
	{
message_vision("$N一閉眼，向潭中跳了下去，只覺冰冷刺骨，趕緊運氣相抗。\n",me);
		me->move("/d/mingjiao/hsqtan1");
		return notify_fail("\n");
	}
}


	