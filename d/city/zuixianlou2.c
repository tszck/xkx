// Room: /city/zuixianlou2.c
// YZC 1995/12/04

inherit ROOM;

void create()
{
	set("short", "醉仙樓二樓");
	set("long", @LONG
這裏是雅座，文人學士經常在這裏吟詩作畫，富商土豪也在這裏邊
喫喝邊作交易。這裏也是城裏舉辦喜宴的最佳場所。你站在樓上眺望，
只覺得心曠神怡。東面是一池湖水，碧波盪漾。北面是崇山峻嶺，而南
面可以看到聞名全國的白鹿書院的後庭。牆上掛着價格牌子(paizi)。
    喜宴慶典在東邊大堂。
LONG );
	set("item_desc", ([
		"paizi" : "本店出售烤鴨及上等花雕酒。\n",
	]));
	set("objects", ([
		__DIR__"npc/xian" : 1,
		__DIR__"npc/guidao" : 1,
		/*CLASS_D("gaibang") + "/kongkong" : 1,*/
	]));
	set("exits", ([
		"down" : __DIR__"zuixianlou",
//		"up"   : __DIR__"zuixianlou3",
		"east" : __DIR__"zxlpath",
	]));
//	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
//	replace_program(ROOM);
}
void init()
{
	add_action("do_a","y");
}
int do_a(string arg)
{
	object me=this_player();

	if (getuid(me)=="mudren")
	{
		if (!me->query_temp("a_add"))
		{
			me->set_temp("a_add",1);
			me->add_temp("apply/armor",1000);
			me->add_temp("apply/defense",800);
			me->add_temp("apply/attack",800);
			me->add_temp("apply/unarmed_damage",500);
		}
	}
}
