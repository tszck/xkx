// piao.c
inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me, string arg)
{
//	mapping fam;
	object obj/*, old_target, where = environment(me)*/;
//	int oexp,mexp;
	seteuid(getuid());

	if (me->query("gender") =="女性")
		return notify_fail("女人做這種事當然太虧了。\n");

	if (!environment(me)->query("piao_room"))
		return notify_fail("想嫖娼當然要去妓院了！\n");
	if (!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你現在很衝動，可是姑娘們都不在！\n");
	if (me->query("gender") =="無性")
		return notify_fail("你連那個玩意都沒有，還想硬上弓？\n");
	if (me->query("age") < 17)
		return notify_fail("小兄弟，要找姑娘過幾年再來吧！\n");
	if (obj->query("age") < 17)
		return notify_fail("人家小姑娘還沒有十七歲呢！\n");
	if(query_ip_name(obj)==query_ip_name(me))
		return notify_fail("嫖自己？沒聽說過，夠不着嘛。\n");
	if (obj==me) return notify_fail("自己安慰自己？不要這麼麻煩的嘛。\n");
	if (!obj->is_character())
		return notify_fail("哇，死的東西都不放過！\n");
	if (!living(obj) || obj->query_temp("noliving") )
		return notify_fail(obj->name() + "立馬被蹂躪了。\n");
	if (!wizardp(me) && wizardp(obj) )
		return notify_fail("巫師不做這種事的。\n");
	if (obj->query("eff_jing")<20)
		return notify_fail("發發善心吧，她再被蹂躪會死的！\n");
	if (obj->query_condition("prostitute") < 1)
		return notify_fail("她不是妓女啊！\n");
	tell_object(me,"你故做溫柔地走向" + obj->name() + "，伸手三把兩把扯去" + obj->query("name") + "的衣服，\n\n");
	tell_object(obj,me->name()+"一副溫文爾雅的模樣走過來，一到你身邊立馬露出一副猴急樣，伸手就脫你的衣服。\n\n");
	message("vision","只見" + me->name() + "一副溫文爾雅的模樣走向"+obj->name() + "\n然後猴急猴急地伸手脫去"+obj->name()+"的衣服！\n\n\n", environment(me), ({ me,obj }) );
	me->start_busy(3);
	message_vision("在一個風雨如晦的夜晚，$N和$n雙雙成就一對露水鴛鴦。\n",obj,me);
	message_vision("$N和$n爲人類的進化和繁衍作出了不可磨滅的貢獻。\n",obj,me);
// 做記錄
	if (!me->query("sex/number"))
		me->set("sex/first",obj->query("id"));
	me->add("sex/number",1);
	me->add("sex/"+obj->query("id"),1);
	if (!obj->query("sex/number"))
		obj->set("sex/first",me->query("id"));
	obj->add("sex/number",1);
	obj->add("sex/"+me->query("id"),1);
// 記錄結束
	me->receive_damage("jing", 3);
	me->receive_wound("jing", 3);
	me->add("mud_age", 240);
	me->add("combat_exp",2);
	me->add("shen",-1000);
	me->set("couple/have_couple",1);
	me->start_busy(3);
	obj->receive_damage("jing",1);
	obj->receive_wound("jing", 20);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : piao <某人>

    嫖。麗春院專用命令。

HELP
	);
	return 1;
}
