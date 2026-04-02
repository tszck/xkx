inherit F_CLEAN_UP;

#include <ansi.h>



void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object where = environment(me);

	if (! me->query("is_vendor"))
		return notify_fail("只有從事商業的人才能擺攤。\n");
	if (! present("shang ling", me))
		return notify_fail("你未帶商令！如今世道亂，小心為妙。\n");

	if (me->is_fighting())
		return notify_fail("你還是好好打你的架吧。\n");

	if (me->query_temp("on_baitan"))
		return notify_fail("你現在已經佔了一個攤位，就適可而止吧。\n");
	if (me->is_busy() || me->query_temp("pending/deriving"))
		return notify_fail("你現在正忙着呢，沒功夫擺攤設點。\n");
	if (me->query_condition("killer"))
		return notify_fail("官府正到處追查你呢，難得還有心情擺攤？\n");
	if (where->query("no_trade"))
		return notify_fail("這裏常有官兵巡邏，最好換個地方做生意。\n");
	if (where->query("no_fight") && ! where->query("can_trade") && !wizardp(me))
		return notify_fail("此處過於嘈雜，還是換個地方做生意吧。\n");
	message_vision(WHT"$N"WHT"尋了塊空地，一屁股坐了下來，隨後掏出一塊布攤開在地。\n" NOR, me);
	tell_object(me, HIC"現在你可以擺上(" HIW "stock" HIC ")貨物或是收起(" HIW "unstock" HIC ")某種貨物。\n" NOR);

	me->set_temp("on_baitan", 1);
	me->set_temp("baitan_place",file_name(environment(me)));
	me->delete("vendor_goods");
//	me->set_short_desc("正在地上擺攤。");
//	me->start_busy((:baitan:),(:halt_baitan:));
	me->set_temp("apply/short",({me->name()+"正坐在地上擺地攤。"}));
	me->apply_condition("baitan",1);
//        me->start_call_out((:call_other,__FILE__,"baitan",me,3:), 10);
        return 1;
}

int baitan(object me)
{
//	switch (random(4))
	switch (random(15))
	{
		case 0:
			message_vision(CYN"$N"CYN"環顧了一下四周，笑眯眯地招呼着眾人。\n"NOR, me);
			break;
		case 1:
			message_vision(CYN"$N"CYN"吆喝道：走過路過不要錯過，大家快來看看貨。\n"NOR, me);
			break;
		case 2:
			message_vision(CYN"$N"CYN"吆喝道：大家來看看，我這裏貨物齊全，包您滿意。\n"NOR, me);
			break;
		case 3:
			message_vision(CYN"$N"CYN"吆喝道：來來來，現在所有物品賤價出售，別錯過。\n"NOR, me);
			break;
		default:
		  break;
	}

	return 1;
}

varargs int halt_baitan(object me,int silent)
{
	if (!silent)
	message_vision(WHT"$N"WHT"提起攤布的四個角，把貨物一股腦的收了起來，站起身來。\n" NOR, me);

	me->delete_temp("on_baitan");
	me->delete_temp("apply/short");
	me->delete_temp("baitan_place");
	me->delete("vendor_goods");
	me->set_short_desc(0);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : baitan

擺攤設點，兜售貨物。

HELP);
	return 1;
}
