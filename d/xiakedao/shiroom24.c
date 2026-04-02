// /d/xiakedao/shishi24.c 俠客島 石室24

inherit ROOM;
#include <ansi.h>

int do_study(string arg);
void create()
{
        set("short", "石室");
        set("long", @LONG
這裏火光昏暗，只見那龍島主與木島主盤膝坐在錦墊之上，面對
石壁(wall)，凝神苦思。此石室已是山腹最深處，卻寬闊高大，足可
容下近百人。洞中火把亦是其他洞的二三倍之多。
LONG );
        set("exits", ([
                "east" : __DIR__"shihole6",
        ]));
        set("item_desc", ([
                "wall" : @WALL
牆的正上方刻着「白首太玄經」幾個大字。字的下方刻的是密密麻麻
的蝌蚪文，成千上萬。文字排列甚不整齊，或橫或豎，或直或斜。左
下的大片甚至混成一團難分次序，委實難以辨認。
WALL
        ]));
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_beg", 1);
	set("coor/x", -3100);
	set("coor/y", -25600);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_study","think");
        add_action("do_canwu","canwu");
}
int do_canwu(string arg)
{
	string swith,where;
	object me = this_player();

	if (sscanf(arg,"%s from %s",swith,where)!=2)
  	return notify_fail("指令格式：yanjiu 特殊技能 from wall\n");

  if (where != "wall") 
    return notify_fail("這裏沒有這個東西給你研究。\n");

  if (me->is_busy())
    return notify_fail("你現在正忙着呢。\n");

  if (me->is_fighting())
    return notify_fail("你在戰鬥哦？！小心，來了！！！\n");

  if ((int)me->query_skill("force", 1) < 300)
    return notify_fail("你的內功修為不夠，無法貫通石壁上的絕學！\n");

  if ((int)me->query("max_neili") < 3000)
    return notify_fail("你的內力修為不足，無法貫通石壁上的絕學！\n");

  if ((int)me->query("jing") < 100)
    return notify_fail("你的精力無法集中，無法領悟石壁上的絕學！\n");

  if (me->query_skill("taixuan-gong", 1) < 200)
    return notify_fail("你對太玄功所知實在有限，無法領悟石壁上的絕學！\n");

    me->receive_damage("jing", 95);

    me->start_busy(2 + random(4));
  if (swith == "taixuan" || swith == "白首太玄經")
  {
  	if (me->query("can_perform/taixuan-gong/taixuan"))
  	  return notify_fail("這項絕學你不是已經會了嗎？\n");
  	if (random(20)==1)
	{
		write(HIM "猛然間，你一聲長嘯，胸中豁然貫通，再無疑慮。\n" NOR);
		write(HIC "你終於通曉了絕學「白首太玄經」。\n" NOR);
		me->set("can_perform/taixuan-gong/taixuan",1);
		return 1;
	}
  }
  return notify_fail("你試圖從石壁上研究有關「白首太玄經」的內容，但卻沒什麼效果！\n");
}
int do_study(string arg)
{
	object me, where;
	int jing_cost, learn_pot, item, times, i, success;
	string skillname;

	me = this_player();
	if ( !me->query( "xkd/ling" ) )
		return notify_fail( "未經島主允許，不得擅自觀看石壁。\n" );
	if ( !me->query_temp( "winner" ) )
		return notify_fail( "未經島主允許，不得擅自觀看石壁。\n" );
	if( !arg ) return notify_fail("你要領悟什麼？\n");
	if(  arg != "wall"  )
		return notify_fail("指令格式：think wall <次數>\n");
	if ((int)me->query("combat_exp")<50000)
		return notify_fail("你的經驗太低, 沒法領悟石壁內容。\n");
	jing_cost = 30 + random(me->query_int());
	if( me->query("jing") < jing_cost || me->query("eff_qi") < 100)
		return notify_fail("你現在太累了，領悟不了這麼多次，休息一會兒再來吧。\n");
	me->receive_damage("jing",jing_cost);
	if((int)(me->query_skill("taixuan-gong",1) * 
		me->query_skill("taixuan-gong",1) * 
		me->query_skill("taixuan-gong",1)) /10 >= me->query("combat_exp"))
	{
		write("你對着石壁冥思苦想了一會，毫無收穫。\n");
		return 1;
	}
	success = 0;
	if (me->query_skill("taixuan-gong",1)<10)
	{
		if (random(20)==1)
		success = 1;
	}
	else if (me->query_skill("taixuan-gong",1)<50)
	{
		if (random(10)==1)
		success = 1;
	}
	else if (me->query_skill("taixuan-gong",1)<100)
	{
		if (random(5)==1)
		success = 1;
	}
	else if (me->query_skill("taixuan-gong",1)<200)
	{
		if (random(3)==1)
		success = 1;
	}
	else 	if (me->query_skill("taixuan-gong",1)>=200)
	{
		write("你望着石壁冥思苦想了一會，發覺上面的東西對你來説太淺薄了。\n");
		return 1;
	}
	learn_pot = (int)(me->query("combat_exp")/10000) + random(me->query("int")) - (int)(me->query_skill("literate",1)/2);
	if (success == 1)
	{
		message_vision(CYN"$N面對着石壁抱頭苦思，突然間，如同昇仙一般拔地而起，原來竟然領悟到了太玄神功的一些精髓！\n"NOR,me);
		me->improve_skill("taixuan-gong", learn_pot);
	}
	else
	{
		message_vision(HIR"$N面對着石壁抱頭苦思，突然間，如同昇仙一般拔地而起，不料一頭撞在了石壁上！\n"NOR,me);
		me->receive_wound("jing",10);
	}
	return 1;
}
