// roar.c 佛門獅子吼
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/roar") &&
  !me->query("can_perform/yijinjing/roar") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if( ((int)me->query("neili") < 600 ) || ((int)me->query("max_neili") < 600 ) || ( (int)me->query_skill("yijinjing" ,1) < 100) )
		return notify_fail("你鼓足真氣＂喵＂的吼了一聲, 結果嚇走了幾隻老鼠。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("在這裏不能攻擊他人。\n");

	skill = me->query_skill("force");

	me->add("neili", -200);
	me->receive_damage("qi", 10);

	me->start_busy(5);
	message_combatd(
		HIY "$N深深地吸一囗氣，真力迸發，運起佛門獅子吼，發出一聲驚天動地的巨吼ⅵ\n" NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( !living(ob[i]) || ob[i]->query_temp("noliving") ||
			ob[i]==me ) continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 )
			continue;
	if (!userp(ob[i]) && !ob[i]->accept_hit(me)) continue;
		damage = skill - ((int)ob[i]->query("max_neili") / 10);
		if( damage > 0 )
		{
			ob[i]->receive_damage("jing", damage * 2 );
			if( (int)ob[i]->query("neili") < skill * 2 )
				ob[i]->receive_wound("jing", damage);
			tell_object(ob[i], "你覺得眼前一陣金星亂冒，耳朵痛得像是要裂開一樣！\n");
		}

		if( userp(ob[i]) ) ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
	}
	return 1;
}

int help(object me)
{
	write(WHT"\n易筋經神功之佛門獅子吼："NOR"\n");
	write(@HELP

	使用功效：
		傷害自己周圍的所有生物的精氣

	出手要求：
		易筋經神功100級
	        內力600
HELP
	);
	return 1;
}

