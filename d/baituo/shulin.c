// Room: /d/baituo/shulin.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void init();
int cut(string);

void create()
{
	set("short","樹林");
	set("long", @LONG
這裏是一片茂密的樹林(wood)。常有樵夫來此勞作，砍了柴薪下山
貨賣。樹林裏的小路旁邊立着一張木牌(pai)。
LONG);
	set("exits",([
		"west" : __DIR__"shulin1",
		"south" : __DIR__"shanlu1",
	]));
	set("outdoors", "baituo");
	set("no_clean_up", 0);
	set_temp("times" , 1);
	set("item_desc", ([
		"pai" : "保護樹林  適量砍伐\n",
		"wood" :"一片可砍伐的樹林。\n",
	]) );
	set("coor/x", -50030);
	set("coor/y", 20020);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_cut","cut");
}

int do_cut(string arg)
{
	object me=this_player();
	object ob;
	if (!arg||arg!="wood") return notify_fail("你要砍什麼？\n");
	if (present("chai dao",me)) return notify_fail("沒有柴刀怎麼砍柴？\n");
	if (query_temp("times")==0) return notify_fail("請適量砍伐！\n");
	if(me->query("qi")<20) return notify_fail("你的氣太虛弱，不能砍柴！\n");
	ob=new(__DIR__"obj/chai");
	ob->move(environment(me));
	me->receive_wound("qi", 20);
	add_temp("times",-1);
	message_vision("$N砍了一捆柴，累得夠嗆。\n" , me);
	return 1;
}
