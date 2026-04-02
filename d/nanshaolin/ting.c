// Room: /d/nanshaolin/ting.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"迎客亭"NOR);
	set("long", @LONG
蒼松掩映之中，一座石亭赫然眼中。只見亭上匾額中龍飛鳳舞的題
着『迎客亭』三個大字。凡江湖人士，在此需放下隨身所帶的兵器，才
可進入寺內。亭內有兩名知客僧正在忙碌的招待來往的香客。
LONG );
	set("exits", ([
		"westdown" : __DIR__"fxjing",
		"northup"  : __DIR__"shanlu2",
		"east"     : __DIR__"shanlu1",
	]));
	set("outdoors", "nanshaolin");
	set("no_fight", 1);
	set("objects",([
		CLASS_D("nanshaolin") + "/fangtong" : 1,
		CLASS_D("nanshaolin") + "/fangkong" : 1,
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", 1820);
	set("coor/y", -6350);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_quit","quit");
	add_action("do_quit","exit");
}

int do_quit()
{
	object ob = this_player();
	if (ob->query_condition("sl_lunzhi")>0)
	{
		write("你正在輪值，不能退出遊戲。\n");
		return 1;
	}
	return 0;
}

int valid_leave(object me, string dir)
{
	object *inv;
	mapping myfam/*, mygen*/;
	int i;

	myfam = (mapping)me->query("family");
	if (!me->query("luohan_winner") && !present("yingxiong ling", me))
	if (me->query("gender") == "女性" && dir == "northup" )
	{
		if(objectp(present("fang tong", environment(me))))
			return notify_fail("方通伸手攔住你白眼一翻説道：千年以來，少林向不許女流擅入。"+RANK_D->query_respect(me) +"\n請下山去吧，免得自討沒趣。\n");
		if(objectp(present("fang kong", environment(me))))
			return notify_fail("方空邁步擋在你身前，雙手合什説道：阿彌陀佛，這位" + RANK_D->query_respect(me) +"請留步，\n恕小寺不接待女客。女施主倘若一心向佛，何妨去峨眉山隨喜？\n");
	}
	if((!myfam ||
		myfam["family_name"] != "少林派" &&
		myfam["family_name"] != "南少林派" ) &&
		dir == "northup")
	{
		inv = all_inventory(me);
		for(i=sizeof(inv)-1; i>=0; i--)
			if(inv[i]->query("weapon_prop") &&
				(inv[i]->query("equipped")))
			{
				if(objectp(present("fang tong",environment(me))))
					return notify_fail("方通攔住你説道：這位"+RANK_D->query_respect(me) +"請放下兵刃。少林千年的規矩，外客\n不得持兵刃上山。\n");
				if(objectp(present("fang kong", environment(me))))
					return notify_fail("方空邁步擋在你身前，雙手合什説道：阿彌陀佛，這位"+RANK_D->query_respect(me) +"請收起\n兵刃。佛門清靜之地，不便隨意舞刀弄劍。還請施主鑑諒。\n");
			}
	}
	if (!me->query("muren_winner") && mapp(myfam) &&
		myfam["family_name"]== "南少林派" && 
		dir == "east" ) 
	{
		if(objectp(present("fang tong", environment(me))))
			return notify_fail("方通伸手攔住你躬身説道：這位師兄武功還未練好，不能下山，免得折了咱們南少林的名聲！\n");
		if(objectp(present("fang kong", environment(me))))
			return notify_fail("方空伸手攔住你躬身説道：這位師兄武功還未練好，不能下山，免得折了咱們少林的名聲！\n");
	}

	if (me->query_condition("sl_lunzhi")>0)
		return notify_fail("你正在輪值，不能離開！\n");

	return ::valid_leave(me, dir);
}
