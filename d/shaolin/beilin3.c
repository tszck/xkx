// Room: /d/shaolin/beilin3.c
// Date: YZC 96/01/19

inherit ROOM;

int do_study(string arg);

void create()
{
	set("short", "地下室");
	set("long", @LONG
這裏是佛塔底下的地下密室。密室雖小，卻也五臟俱全，
石桌石椅，石几石牀，連室內放的幾件器皿，也都是石制的。
看來似乎很久以前有人在這裏住過。正中的石桌上平放着一塊
薄薄的石板，上面好象刻着些什麼。
LONG );
	set("objects",([
		"/clone/book/book-stone" : 1,
	]));
	set("item_desc", ([
		"table" : "這是一整塊巨石雕成的石桌，上面刻了些奇怪的圖形。\n",
	]));
//	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 810);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_study", "study");
}

int do_study(string arg)
{
	object me;

	me = this_player();

	if ( !arg || ( arg != "table" ) )
		return notify_fail("什麼？\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你是個文盲，先學點文化(literate)吧。\n");

	if ( me->query("jing") < 10 )
	{
		me->unconcious();
		return 1;
	}

	me->add("jing", (-1)*random(40));

	message_vision("$N正專心研讀石桌上的古怪圖形。\n", me);

	switch( random(5) ) 
	{
	    case 0:
		if ( (int)me->query_skill("finger", 1) < 100)
		{
			me->improve_skill("finger", me->query("int"));
			write("你對着石桌琢磨了一回兒，似乎對指法有點心得。\n");
			me->set_temp("stone_learned",1);
		}
	    case 1:
		if ( (int)me->query_skill("claw", 1) < 100)
		{
			me->improve_skill("claw", me->query("int"));
			write("你對着石桌琢磨了一回兒，似乎對爪法有點心得。\n");
			me->set_temp("stone_learned",1);
		}
	    case 2:
		if ( (int)me->query_skill("strike", 1) < 100)
		{
			me->improve_skill("strike", me->query("int"));
			write("你對着石桌琢磨了一回兒，似乎對掌法有點心得。\n");
			me->set_temp("stone_learned",1);
		}
	    case 3:
		if ( (int)me->query_skill("cuff", 1) < 100)
		{
			me->improve_skill("cuff", me->query("int"));
			write("你對着石桌琢磨了一回兒，似乎對拳法有點心得。\n");
			me->set_temp("stone_learned",1);
		}
	    case 4:
		if ( (int)me->query_skill("hand", 1) < 100)
		{
			me->improve_skill("hand", me->query("int"));
			write("你對着石桌琢磨了一回兒，似乎對手法有點心得。\n");
			me->set_temp("stone_learned",1);
		}
	}

	if ( !me->query_temp("stone_learned") )
	{
		write("你對着石桌琢磨了一回兒，發現上面所說的太過淺顯，對你來說已毫無意義了。\n");
	}
	return 1;
}
