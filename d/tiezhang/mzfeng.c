// Room: /d/tiezhang/mzfeng.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "拇指峯");
	set("long", @LONG
拇指峯是鐵掌五峯中最爲低矮的一峯，名爲峯，實則只是一座較高
的石山罷了。峯頂到處是又大又圓的岩石，在日曬雨淋下，被風蝕得十
分光滑。在岩石的縫隙中，長出許多松樹，其中一棵尤其引人注目。這
棵松名爲並蒂松(song)，乃同根而生，於距地一米高處，忽分爲二。這
兩根樹幹同粗同高，均長得高大挺拔，枝葉茂盛，尤如兄弟一般，因此
又名兄弟松。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"southdown" : __DIR__"sslu3",
	]));
	set("item_desc", ([ 
		"song" : "這棵松樹能長得如此奇特，必蘊涵了天地日月之精華。\n",
	]));
	set("outdoors", "tiezhang");
	set("no_clean_up", 0);
	set("coor/x", -2010);
	set("coor/y", -1900);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_caiqi", "caiqi");
}

int do_caiqi(string arg)
{
	mapping fam;
	object me = this_player();

	if (!living(me)) return 0;
	if ( !living(this_player()) || arg != "song" )
	{
		message_vision("你想幹什麼？\n",me);
		return 1;
	}

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "鐵掌幫")
		return notify_fail("你非本幫弟子，不能在此練功！\n");

	if ((int)me->query_skill("force",1)>100)
		return notify_fail("你的內功太高了，已經不能從樹中採氣了！\n");

	if ((int)me->query_skill("force", 1) < 30 )
		return notify_fail("你的內功太低了，還不能從樹中採氣！\n");

	if((int)me->query("jing")<20)
	{
		me->receive_damage("jing",10);
		write("你忽然覺得頭痛欲裂，無法控制體內的真氣！\n");
		me->unconcious();
		return 1;
	}

	me->receive_damage("jing", random(40));
	message_vision("$N雙手呈環狀，虛抱住一隻樹幹，緩緩吐吶練功。\n", me);
	me->improve_skill("force", me->query("int"));
	return 1;
}
