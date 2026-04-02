//shenshe.c
inherit ITEM;
void create()
{
	set_name("引路神蛇", ({ "shen she", "snake"}));
	set_weight(100);
	set("count", 10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一條有識路能力的神蛇，可以把主人帶到白
		      駝山。(玩家鍵入home即可)\n");
		set("unit", "條");
		set("value", 0);
	}
}
void init()
{
	add_action("do_home","home");
}
int do_home()
{
//	string dir;
	object me = this_player();

	if(!present(this_object(), me))
		return notify_fail("你要喚什麼？\n");
	if( me->is_busy() )
		return notify_fail("別急，慢慢喚。\n");

	if (query("count") < 0)
	{
		message_vision("「引路神蛇」疲倦地擺了擺尾巴，掙脫出$N的手掌，滑入草叢不見了。\n", me);
		destruct(this_object());
		return 1;
	}
	else add("count", -1);
//if( !SKILL_D(skill_name[item])->valid_learn(me) )
//return SKILL_D(skill_name[item])->valid_learn(me);

	if (me->query_temp("block_msg/all"))
		return notify_fail("你現在正忙着呢，哪有空使喚神蛇？\n");
	if (me->is_busy())
		return notify_fail("你現在正忙着呢，哪有空使喚神蛇？\n");
	if (me->is_fighting())
		return notify_fail("你現在打架還來不及，哪有空使喚神蛇？\n");
	if (environment(me)->query("no_quit"))
		return notify_fail("你現在所在的地方，無法使喚神蛇！\n");
	if (!environment(me)->valid_leave(me,"up"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"down"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"enter"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"out"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"east"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"west"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"south"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"north"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"southeast"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"southwest"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"northeast"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"northwest"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"eastup"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"westup"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"southup"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"northup"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"eastdown"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"westdown"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"southdown"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");
	if (!environment(me)->valid_leave(me,"northdown"))
		return notify_fail("你身上偷藏了什麼？神蛇不聽你使喚啦。\n");

	if(me->query("family/family_name") != "白駝山派")
	return notify_fail("你不是白駝山派弟子，「引路神蛇」不聽你使喚。\n");
	message_vision("$N從懷中掏出「引路神蛇」，口裏不知唸了些什麼，\n
	就見「引路神蛇」吐吐芯子，搖頭擺尾地把$N往白駝山帶去￣￣￣\n",me);
	me->move("/d/baituo/damen");
	return 1;
}