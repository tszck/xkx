// Room: /d/nanshaolin/xiaoxi.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
int do_jump(string arg);

void create()
{
	set("short", "小溪");
	set("long", @LONG
這是一條由後山流下來的溪流，小溪並不寬，縱身一躍似乎就可蹦
到對岸。溪旁兩岸的青草長得極是茂盛，且無雜亂之感，好象經人整理
過。溪流的水質清澈，可以清晰的看到水底的鵝卵石和來回遊動的小魚。
小溪對面的空地上有一座兩層的小樓。
LONG );
	set("exits", ([
		"west" : __DIR__"xiaolu4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1870);
	set("coor/y", -6150);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "yue");
}

int do_jump(string arg)
{
	object me = this_player();

	if (arg == "river" || arg == "xiaoxi")
	{
		if (me->query_skill("dodge", 1) >= 60)
		{
			message("vision", me->name() + "吸了口氣，縱身向對面躍去。\n", environment(me), ({me}) );
			write("你吸了口氣，縱身向對面躍去。\n");
			me->move(__DIR__"xiaoxi1");
			message("vision", "只見人影一閃，" + me->name() +  "縱身躍了過來。\n", environment(me), ({me}) );
			return 1;
		}
		else
		{
			message("vision", me->name()+"縱身向對面躍去，只聽“撲通”一聲，"+me->name()+"摔入溪中，狼狽的爬了回來。\n",environment(me),({me}) );
			write( "你縱身向對面躍去，只聽“撲通”一聲，你摔入溪中，狼狽的爬了回來。\n");
                        me->receive_damage("qi",30);
                        return 1;
		}
	}
	return 0;
}

