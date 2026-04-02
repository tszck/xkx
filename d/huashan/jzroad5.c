// Room: /d/huashan/jzroad5.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
void create()
{
	set("short", "中條山密林");
	set("long", @LONG
山路越來越小，周圍茂密森林裏和腳下的茅草封住了路，上不見天
光，後不見歸路(road)，你簡直絕望了。
LONG );
	set("exits", ([
		"northdown" : __DIR__"jzroad4",
	]));
	set("item_desc", ([
		"road" : "路邊模模糊糊，好象有個碑。可是太暗了實在看不見。\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -920);
	set("coor/y", 200);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_use", "use");
	add_action("do_zuan", "zuan");
}

int do_use(string arg)
{
	object me = this_player();

	if( !arg || arg=="" ) return 0;
	if (!present("fire", me)) return 0;
	if( arg=="fire" )
	{
		write("你點燃了火折，發現是一圍大樹，被削去樹皮的樹幹上書“中條山”三字。\n側邊一個樹洞，似乎可以鑽(zuan)過去。\n");
		me->set_temp("marks/鑽1", 1);
		return 1;
	}
}

int do_zuan(string arg)
{
	object me;
	me = this_player();

	if (me->query_temp("marks/鑽1") )
	{
		message("vision", me->name() + "側身滋溜一下鑽進樹洞不見了。\n", environment(me), ({me}) );
		me->move(__DIR__"jzroad6");
		message("vision", me->name() + "從樹裏鑽了出來。\n", environment(me), ({me}) );
		this_player()->delete_temp("marks/鑽1");
		return 1;
	}
	else
	{
		write("你想往哪兒鑽?!\n");
		return 1;
	}
}
