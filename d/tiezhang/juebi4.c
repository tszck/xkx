// Room: /d/tiezhang/juebi4.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "絕壁");
	set("long", @LONG
光突突的石壁。你只聽見耳旁忽忽的風聲。
LONG	);
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2010);
	set("coor/y", -1880);
	set("coor/z", 80);
	setup();
}
void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
	object me;
	me=this_player();

	me->receive_damage("qi", 40);
	if ((int)me->query_skill("dodge",1)>100)
		write("你覺得很難從中領悟到輕功身法。\n");
	if ((int)me->query_skill("dodge",1)<100)
		me->improve_skill("dodge",me->query("int"));
	if ( (arg !="up") && (arg !="down") ) 
		return notify_fail("你要往哪兒爬？\n");
	if (arg =="up")  
	{
		write("你吸了口氣，小心的向上爬去。\n");
		message("vision",me->name() + "向上一縱突然不見了。\n", environment(me), ({me}) );
		me->move(__DIR__"juebi5");
		message("vision",me->name() + "爬了上來。\n", environment(me), ({me}) );
		return 1;
	}
	if (arg =="down")
	{
		write("你攀緣着石壁，緩緩向下爬去。\n");
		message("vision",me->name() + "向下爬去。\n", environment(me), ({me}) );
		me->move(__DIR__"juebi3");
		message("vision",me->name() + "爬了下來。\n", environment(me), ({me}) );
	}
	return 1;
}

