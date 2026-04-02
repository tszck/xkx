// Room: /d/wudujiao/huating3.c

inherit ROOM;

void create()
{
	set("short", "騰蛟亭");
	set("long", @LONG
這裏是一個花園中的小亭子，雕樑畫棟，古色古香。壁上掛着一幅
《少女月下舞劍圖》(picture)。
LONG
	);
	set("outdoors", "wudujiao");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"huating1",
		"west" : __DIR__"huayuan3",
	]));
	set("item_desc",([
	    "picture":"只見畫中少女手持鋼鉤，含笑而立。恍惚間你似乎覺得有無數道劍氣撲面而來。\n這裏面似乎隱含着某種奧祕，你可以照着畫中的姿勢比劃(bihua)一下看看\n\n",
]));
	set("coor/x", -44890);
	set("coor/y", -81040);
	set("coor/z", 30);
	setup();
}

void init()
{
	add_action("do_bihua", "bihua");
}

int do_bihua(string arg)
{
	object weapon;
	object me=this_player();
	int hookskill=(int)me->query_skill("hook", 1);
 int  exp=(int)me->query("combat_exp");

	if( !arg || arg != "picture")
		return notify_fail("你亂比劃什麼？\n");
	if( me->query("qi") < (int)(me->query("max_qi")/5))
		return notify_fail("再練下去你會累死的！\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "hook")
		return notify_fail("不拿鉤劍你亂比劃什麼？\n");
	if (!((string)me->query("family/family_name")=="五毒教"))
	{
		message_vision("$N照着壁上的畫練了幾次，累了一身臭汗。\n", me);
	}
	else
	{
		message_vision("$N手捻劍訣，依照畫上少女的姿勢練了一趟。\n", me);
		if (exp*10 <= (hookskill*hookskill*hookskill))
		{
			me->receive_damage("qi", 30);
			return notify_fail("你的經驗不夠，已經不能從畫中領悟到什麼了。\n");
		}
		if (hookskill < 150)
		{
			me->improve_skill("hook", random((int)(me->query("int") +me->query_skill("literate"))));
			tell_object(me, "你從中領悟出一些基本鉤法方面的竅門。\n");
		}
		else
		{
			tell_object(me, "你費了半天勁，可是什麼也沒有學到。\n");
		}
	}
	me->receive_damage("qi", 30);
	return 1;
}
