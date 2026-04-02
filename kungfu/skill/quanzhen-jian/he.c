// he.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int skl_me, skl_you, extra_me, extra_you, i, damage;
	int FLAG=0;
	object you,ob,*obs,weapon;
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/he") &&
  !me->query("can_perform/quanzhen-jian/he") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的外功中沒有這種功能。");

	if( !objectp(target) ) target = offensive_target(me);
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	  !living(target) || target->query_temp("noliving") )
		return notify_fail("［雙劍合璧］只能對戰鬥中的對手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不對。\n");
        if(me->query("neili")<400)
                return notify_fail("你的內力不夠使用雙劍合璧。\n");
	if( !me->query_temp("murong/xingyi") )
	{
		if( (int)me->query_skill("xiantian-qigong", 1) < 100 )
			return notify_fail("你的先天氣功不夠嫺熟，不能用雙劍合璧。\n");
		if( (int)me->query_skill("quanzhen-jian", 1) < 100 )
			return notify_fail("你的全真劍法不夠嫺熟，不能用雙劍合璧。\n");
	}
	if(pointerp(obs=me->query_team()) )
	{
		FLAG=1;
		for(i=0;i<sizeof(obs);i++)
		{
			if(obs[i] == me) continue;
			if(!obs[i]) {FLAG=0;continue;}
			if(environment(obs[i]) != environment(me))
				{FLAG=0;continue;}
			if(obs[i]->query("neili") < 400)
				{FLAG=0;continue;}
			if(!obs[i]->query_skill("yunv-jian"))
				{FLAG=0;continue;}
			if(obs[i]->query_skill("yunv-jian",1) < 100)
				{FLAG=0;continue;}
			if(obs[i]->query_skill("yunv-xinfa",1) < 100)
				{FLAG=0;continue;}
			if (!objectp(ob = obs[i]->query_temp("weapon"))
				|| (string)ob->query("skill_type") != "sword")
				{FLAG=0;continue;}
			if(obs[i]->query_skill_mapped("sword")!="yunv-jian")
				{FLAG=0;continue;}
			if(obs[i]->is_busy())
				{FLAG=0;continue;}
		}
		if(sizeof(obs) !=2) FLAG=0;
	}
	skl_me=(int)me->query_skill("sword");
	extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/10;
	if(FLAG)
	{
	if(obs[0]==me) you=obs[1]; else you=obs[0];
	if(me->query("gender")!="男性" || you->query("gender")!="女性")
		return notify_fail("雙劍合璧必須男使全真劍法，同時女使玉女劍法方能激發。\n");
  	if(!userp(target))
		if (!target->accept_hit(me) || !target->accept_hit(you))
			return notify_fail("本門任務怎可假別人之手完成。\n");
		skl_you=(int)you->query_skill("sword");
		extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str();
		msg = HIY + "$N施展出全真劍法的厲害劍招，" + HIG + you->name()+"施展出玉女劍法的險惡家數，\n" + HIR +
		 "雙劍合璧，威力立時大得驚人，$n無法齊擋雙劍擊刺，向後急退，嗤嗤兩聲，身上兩劍齊中！\n"NOR ;

		message_combatd(msg, me, target);
		me->add_temp("apply/attack",(skl_you+skl_me)/5);
		me->add_temp("apply/damage",(extra_you+extra_me));
		you->add_temp("apply/attack",(skl_you+skl_me)/5);
		you->add_temp("apply/damage",(extra_you+extra_me));
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
		COMBAT_D->do_attack(you,target, you->query_temp("weapon"), TYPE_REGULAR,msg);
		you->add_temp("apply/attack",-(skl_you+skl_me)/5);
		you->add_temp("apply/damage",-(extra_you+extra_me));
                you->add("neili",-300);
                me->add("neili",-300);
		me->add_temp("apply/attack",-(skl_you+skl_me)/5);
		me->add_temp("apply/damage",-(extra_you+extra_me));
		me->start_busy(2+random(2));
		you->start_busy(2+random(2));
    if (target->query("qi") > 0 && target->query("jing") > 0)
    {
    	msg = HIC"虧得$n閃避得宜，劍鋒從兩脅掠過，只劃破了他衣服，但已嚇出了一身冷汗。\n"NOR;
			message_combatd(msg, me, target);
		}
	}
	else
	{
//		msg =HIY"$N"+HIG"欲與"HIY+you->name()+HIG"施展雙劍合璧，可是她沒法和你配合。\n" + NOR;
		msg =HIY"$N欲施展雙劍合璧，可是沒有合適的人一起配合。\n" + NOR;
		message_combatd(msg, me, target);
	}
	return 1;
}
int help(object me)
{
	write(WHT"\n全真劍法之雙劍合璧"NOR"\n");
	write(@HELP

	使用功效：
		大增己方攻擊力和防禦力，共同出手一招

	出手要求：
		男性
		先天氣功100級
		全真劍法100級
		內力100
	夥伴要求：
		女性
		玉女心法100級
		玉女劍法100級
		內力100
HELP
	);
	return 1;
}

