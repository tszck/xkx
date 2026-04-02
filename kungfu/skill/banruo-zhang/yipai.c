// banruo-zhang's perform yipai(一拍兩散)
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#define PNAME "一拍兩散"
inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
	int damage, p,t_neili,m_neili,t_force,m_force,m_exp,t_exp,
	m_skill,t_skill,m_max_neili,t_max_neili;
	string msg;
	int flag;
	string fskill,sskill,bskill,pfname;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中沒有這種功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必須空手才能使用"PNAME"！\n");

	fskill = "yijinjing";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(bskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(bskill)+"不夠嫺熟，使不出"PNAME"！\n");
	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"還不夠熟練，不能使用"PNAME"絕招對敵！\n");
	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"還不夠熟練，不能使用"PNAME"絕招對敵！\n");
	if( (int)me->query("max_neili", 1) < 1500 )
		return notify_fail("你內力修為不足，使不出"+to_chinese(sskill)+"的絕招！\n");
	if( (int)me->query("neili", 1) < 1000 )
		return notify_fail("你現在內力不足，使不出"+to_chinese(sskill)+"的絕招！\n");

	t_neili=target->query("neili");
	m_neili=me->query("neili");
	t_max_neili=target->query("max_neili");
	m_max_neili=me->query("max_neili");
	t_force=target->query_skill("force",1);
	m_force=2*me->query_skill("force",1);
	m_exp=me->query("combat_exp");
	t_exp=target->query("combat_exp");
	m_skill=2*me->query("strike",1);
	t_skill=target->query_skill("parry",1);
	msg = WHT"\n$N"WHT"大聲喝道："HIY"“喫我一掌！”"WHT"雙掌自外向裏轉了個圓圈，緩緩向$n"WHT"推了過來。\n掌力未到，$n"WHT"已感胸囗呼吸不暢，頃刻之間，$N"WHT"的掌力如怒潮般洶湧而至！！\n\n"NOR;	
	if ((random(m_force) > t_force/2) && (random(m_exp)>t_exp/3))
	{
		me->start_busy(1);
		target->start_busy(1); 
		damage=(m_force+me->query("jiali")+m_skill+(m_max_neili-t_max_neili)/10); 
		damage = damage*3/2 + random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("jing", damage/3,me);
		me->add("neili", -1000);
		p =(int)target->query("qi")*100/(int)target->query("max_qi");
		msg += damage_msg(damage, "內傷");
		msg += "( $n"+eff_status_msg(p)+" )\n";
		call_out("perform2", 0, me, target, p);    
	} else 
	{
	msg += BLU "$p"BLU"撤招換掌，右掌迎了過去。兩股掌力相交，嗤嗤有聲，只聽見“砰”的一聲，\n雙方均退了三步。\n" NOR;
		if (t_neili>m_neili )
		{
			me->start_busy(2);
			target->start_busy(1);
			me->add("neili", -500);
			target->add("neili",-500);
		}
		else
		{
			me->start_busy(2);
			target->start_busy(1);
			me->add("neili", -t_neili/2);
			target->add("neili",-t_neili);
		}
	}
	message_combatd(msg, me, target);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		重創對手精氣和氣血

	出手要求：
		易筋經120級
		般若掌120級
		基本掌法120級
		內力1000
		內力修為1500
HELP
	);
	return 1;
}

