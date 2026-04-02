// fen.c 焚心以火
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "「焚心以火」"

int perform(object me,object target)
{
	string msg;
	object weapon,  *inv,piece;
	int skill, ap, dp, equip;
	int neili_wound, qi_wound ;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("你所使用的外功中沒有這種功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必須空手運功。\n");

	fskill = "longxiang";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"等級不夠, 不能使出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"等級不夠, 不能使出"+PNAME+"。\n");

	if( me->query("neili") < 600 )
		return notify_fail("你的內力不夠，無法運功！\n");
 
	skill = me->query_skill(bskill, 1);
	msg = HIC "$N聚氣於掌，使出一招「焚心以火」，向$n"HIC"的胸口擊去。\n"NOR;

	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;

	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-600);

		neili_wound = 100 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");
		if(target->query("qi")>100)
			qi_wound = target->query("qi") - 100;
		else 
		{ 
			qi_wound= target->query("qi");
			qi_wound= qi_wound - target->query("qi")/10;
		}

		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound,me);
		target->add("neili", -neili_wound);
	 	target->start_busy(1);
		me->start_busy(1+random(3));

 		inv = all_inventory(target);
    msg += HIR"$n"HIR"只覺得眼前一黑，一陣熱焰撲面而來，“哇”的一聲噴出一口鮮血！\n"NOR;
		for(equip=0; equip<sizeof(inv); equip++)
		{
			if( inv[equip]->query("equipped") &&
				!inv[equip]->query("weapon_prop") )
			{
msg += HIR "$n"HIR"聞到一股焦味，發現身上的"+inv[equip]->query("name")+HIR"已被燒得殘破不堪，掉在了地上！\n"NOR;
			inv[equip]->unequip();
      	seteuid(getuid());
      	piece = new("/clone/misc/piece");
      	piece->set("long", "一堆破碎物事，好象是布片鐵片什麼的。\n");
      	piece->set_name( inv[equip]->query("name") + "的碎片", ({inv[equip]->query("id"),"piece"}) );
      	piece->move(environment(target));
     		destruct(inv[equip]);
			}
		}
		target->reset_action();
	}
	else
	{
msg += HIG "只見$n"HIG"不慌不忙，輕輕一閃，躲過了$N"HIG"的必殺一擊！\n"NOR;
		if(userp(me)) me->add("neili",-600);
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		損傷對方氣血和內力
		焚燬對方的裝備披掛

	出手要求：
		小無相功60級
		火焰刀120級
		內力600
HELP
	);
	return 1;
}

