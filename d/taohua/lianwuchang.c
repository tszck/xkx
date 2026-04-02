// Room: /d/taohua/lianwuchang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

int do_jump(string arg);
string look_zhuang();

void create()
{
	set("short","練武場");
	set("long",@LONG
這是供桃花島上弟子們練功的場子。場邊擺了兩排兵器架，上面插
着各種兵器，最多的還是各式各樣的劍。在場子正中豎着一根很高的木
樁(zhuang)，看起來象是練功用的。北邊是男弟子休息室，而南邊則是
女弟子休息室。西邊是弟子們喫飯和喝茶的地方。
LONG
);
	set("exits",([
		"north" : __DIR__"liangongfang",
		"south" : __DIR__"xiaowu",
		"east"  : __DIR__"zoulang3",
		"west"  : __DIR__"fanting1",
	]) );
	set("item_desc",([
		"zhuang" : (: look_zhuang :),
	]) );
	set("no_clean_up",0);
	set("valid_startroom", 1);
	set("outdoors","taohua");
	set("coor/x", 8980);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "tiao");
}

int do_jump(string arg)
{
	object me = this_player();
	int level, qicost;

	level = me->query_skill("dodge", 1);
	if (arg == "zhuang")
	{
		if (me->query_temp("thd_zhuang"))
		{
			write("你已經在樁上了，別是站久了頭昏吧？\n");
			return 1;
		}
		qicost = level / 4 + random(level / 3);
		if (me->query("qi") <= qicost)
		{
			write("你太累了，先歇歇吧！\n");
			return 1;
		}
		if (level < 50)
		{
			write("你聳身作勢，向樁上躍去，可惜的是腳尖還差一些才能夠到。\n");
			return 1;
		}
		me->receive_damage("qi", qicost);
		if (level < 100)
		{
			message_vision("$N吸了口氣，縱上了木樁，這似乎是鍛鍊輕功的好方法。\n", me);
			me->improve_skill("dodge", me->query_int());
		}
		else
			message_vision("$N腳下微一運勁，輕輕地一縱就上了木樁，這兩根木樁對$P而言也太矮了。\n", me);
		me->set_temp("thd_zhuang", 1);
		return 1;
	}
	if (arg == "down")
	{
		if (!me->query_temp("thd_zhuang"))
		{
			message_vision("$N想挖個坑跳進去，四處比劃了一番，卻發現周圍的人都用異樣的眼光看着你。\n", me);
			return 1;
		}
		qicost = level / 5 + random(level / 4);
		if (me->query("qi") <= qicost)
		{
			write("你太累了，先歇歇吧！\n");
			return 1;
		}
		me->receive_damage("qi", qicost);
		if (level < 100)
		{
			message_vision("$N笨手笨腳地從樁上跌了下來，發現這很象是普通輕功的一式“平沙落雁”。\n", me);
			me->improve_skill("dodge", me->query_int() / 3);
		}
		else
			message_vision("$N輕輕一縱落到了地上，覺得這兩根木樁對$P而言也太矮了。\n", me);
		me->delete_temp("thd_zhuang");
		return 1;
	}
	return notify_fail("你要往哪裏跳？\n");
}

string look_zhuang()
{
	if (this_player()->query_temp("thd_zhuang"))
		return "你往腳下的木樁看去，覺得有點暈眩，怎麼這木樁好象自己在長呀？！\n";
	else
		return "木樁離地大概三米左右，恐怕只有高手才能跳上去。\n";
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("thd_zhuang"))
		return notify_fail("先從木樁上跳下來(down)再説吧！\n");

	return ::valid_leave(me, dir);
}
