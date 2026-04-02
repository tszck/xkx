// Last Modified by winder on May. 29 2001
#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「雷動九天」"
int perform(object me, object target)
{
	object weapon;
	int damage, club;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中沒有這種功能。\n");
/*
	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");
*/		
	if( !objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("skill_type") != "club" )
		return notify_fail("你手中無棍，怎能運用「雷動九天」？！\n");

	if( me->query_temp("sl_leidong") )
		return notify_fail("你剛使完「雷動九天」，目前氣血翻湧，無法再次運用！\n");

	fskill = "yijinjing";
	bskill = "club";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(fskill)+"修為火候未到，施展只會傷及自身！\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"修為還不夠，還未能領悟"+PNAME+"。\n");

	if( me->query_skill_mapped("force") != fskill)
		return notify_fail("你所用的內功與"PNAME"心法相悖！\n");

	if( (int)me->query_str() <=30 )
		return notify_fail("你的膂力現在無法使用"PNAME"。\n");

	if( me->query("max_neili") <= 2000 )
		return notify_fail("你的內力修為不足，勁力不足以施展"PNAME"！\n");

	if( me->query("neili") <= 600 )
		return notify_fail("你的內力不夠，勁力不足以施展"PNAME"！\n");

	message_combatd(BLU"\n突然$N"BLU"大喝一聲：「雷動九天」，面色唰的變得通紅，鬚髮皆飛，真氣溶入"+weapon->name()+BLU"當中，“嗡”的一聲，發出"HIW "閃閃光亮"BLU"！\n" NOR, me);
	damage = me->query_skill(bskill, 1)+me->query_skill("force", 1);
	damage /= 6;
	club = me->query_skill(bskill)/3;
	if ( userp(me) )
	{
		me->add("neili", -300);
		if ( damage > weapon->query("weapon_prop/damage") * 2)
			damage = weapon->query("weapon_prop/damage") * 2;
		else weapon->add("rigidity", 1);
	}
	me->set_temp("sl_leidong", 1); 
	me->add_temp("apply/damage", damage);
	me->add_temp("apply/attack", damage);
	call_out("remove_effect1", club/2, me, weapon, damage);
	call_out("remove_effect2", club*2/3, me);
	return 1;
}

void remove_effect1(object me, object weapon, int damage) 
{
	if (!me) return;
	me->add_temp("apply/attack", -damage);  
	if (!weapon)
	{
		me->set_temp("apply/damage", 0);
		return;
	}
	me->add_temp("apply/damage", -damage);
	message_combatd(HIY"\n$N一套「雷動九天」使完，手中"NOR+weapon->name()+HIY"上的光芒漸漸也消失了。\n"NOR, me);		
}

void remove_effect2(object me)
{
	if (!me) return;
	me->delete_temp("sl_leidong");
	tell_object(me, HIG"\n你經過一段時間調氣養息，又可以使用「雷動九天」了。\n"NOR); 
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		增大兵器傷害力

	出手要求：
		易筋經150級
		韋陀杵150級
		後天膂力30
		內力修為2000
		內力600
HELP
	);
	return 1;
}

