// he.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "［雙劍合璧］"
int perform(object me, object target)
{
	string msg;
	int skl_me, skl_you, extra_me, extra_you, i, damage;
	int FLAG=0;
	object you,ob,*obs,weapon;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中沒有這種功能。\n");

	if( !objectp(target) ) {target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
 		return notify_fail("你使用的武器不對。\n");

        if(me->query("neili")<400)
                return notify_fail("你的內力不夠使用雙劍合璧！\n");

	fskill = "yunv-xinfa";
	bskill = "sword";
	pskill = "quanzhen-jian";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
		pskill = "shenyuan-gong";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"不夠嫺熟，不能用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，不能用"+PNAME+"。\n");

	if(pointerp(obs=me->query_team()) )
	{
		FLAG=1;
		for(i=0;i<sizeof(obs);i++)
		{
			if(obs[i] == me) continue;
			if(!obs[i]) {FLAG=0;continue;}
			if(environment(obs[i]) != environment(me))
				{FLAG=0;continue;}
			if(!obs[i]->query_skill("quanzhen-jian"))
				{FLAG=0;continue;}
			if(obs[i]->query_skill("quanzhen-jian",1) < 100)
				{FLAG=0;continue;}
			if(obs[i]->query("neili") < 400)
			  {FLAG=0;continue;}
			if (!objectp(ob = obs[i]->query_temp("weapon"))
				|| (string)ob->query("skill_type") != "sword")
				{FLAG=0;continue;}
			if(obs[i]->query_skill_mapped("sword")!="quanzhen-jian")
				{FLAG=0;continue;}
		}
		if(sizeof(obs) !=2) FLAG=0;
	}
	skl_me=(int)me->query_skill("sword");
	extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/10;
	if(FLAG)
	{
//		if(target->query("owner"))
//			return notify_fail("本門任務怎可假別人之手完成。\n");
		if(obs[0]==me) you=obs[1]; else you=obs[0];
	  if(me->query("gender")!="女性" || you->query("gender")!="男性")
		return notify_fail("雙劍合璧必須女使玉女劍法，同時男使全真劍法方能激發。\n");
  	if(!userp(target))
		if (!target->accept_hit(me) || !target->accept_hit(you))
			return notify_fail("本門任務怎可假別人之手完成。\n");
		skl_you=(int)you->query_skill("sword");
		extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str();
		msg = HIY + "$N施展出玉女劍法的險惡家數，" + HIG + you->name()+"施展出全真劍法的厲害劍招，\n" + HIR +
		 "雙劍合璧，威力立時大得驚人，$n無法齊擋雙劍擊刺，向後急退，嗤嗤兩聲，身上兩劍齊中！\n"NOR;

		message_combatd(msg, me, target);
		me->add_temp("apply/attack",(skl_you+skl_me)/5);
		me->add_temp("apply/damage",(extra_you+extra_me));
		you->add_temp("apply/attack",(skl_you+skl_me)/5);
		you->add_temp("apply/damage",(extra_you+extra_me));
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
		COMBAT_D->do_attack(you,target, you->query_temp("weapon"), TYPE_REGULAR,msg);
		you->add_temp("apply/attack",-(skl_you+skl_me)/5);
		you->add_temp("apply/damage",-(extra_you+extra_me));
		me->add("neili",-300);
		you->add("neili",-300);
		me->add_temp("apply/attack",-(skl_you+skl_me)/5);
		me->add_temp("apply/damage",-(extra_you+extra_me));
//		you->kill_ob(target);
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
		if( (int)me->query("neili") < 350 )
			return notify_fail("你的真氣不足，無法使出雙劍合壁。\n");
		if( (int)me->query_skill(pskill, 1) < 100 )
			return notify_fail("你的全真劍法不夠嫺熟，不能使用雙劍合璧。\n");
		if( (int)me->query_skill("hubo", 1) < 100 )
			return notify_fail("你的雙手互搏不夠嫺熟，不能一人獨使雙劍合璧。\n");
		msg = HIY "$N左手帶以全真劍法劍意，右手"+weapon->name()+HIY"化玉女劍法劍式，雙式合璧同時刺出。\n"NOR;
		if (random(me->query_skill("force")) > target->query_skill("force")/2 )
		{
			damage = (int)me->query_skill("yunv-jian", 1) + (int)me->query_skill("quanzhen-jian",1);
			damage = damage + (int)me->query_skill("force",1) ;
			//(玉女劍法+全真劍法級別+基本內功)
			damage = damage/2 + random(damage);
			target->receive_wound("qi", damage);
			target->start_busy(random(4));
			me->start_busy(2+random(2));
			me->add("neili", -350);

			msg += HIR "$n"HIR"看到$N"HIR"劍招飛舞，招式中所有破綻都爲另一劍招補去，竟不知如何是好！\n"NOR;
			msg += HIR "一呆之下，$N"HIR"的劍招已經破式而入！\n"NOR;
		}
		else
		{
			me->start_busy(3);
			msg += CYN"可是$p看破了$P的企圖，將自己的全身上下護得密不透風，令$P無計可施。\n"NOR;
		}
		message_combatd(msg, me, target);
	}	
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		大增己方攻擊力和防禦力，共同出手一招
		如果沒有夥伴，則需100級左右互搏方能出招

	出手要求：
		女性
		玉女心法100級
		玉女劍法100級
		內力100
	夥伴要求：
		男性
		先天氣功100級
		全真劍法100級
		內力100
HELP
	);
	return 1;
}

