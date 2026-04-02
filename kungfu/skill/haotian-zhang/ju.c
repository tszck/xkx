// ju.c 三花聚頂
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "「三花聚頂」"
int perform(object me,object target)
{
	string msg;
	object weapon,  target_w, *inv;
	int skill, ap, dp, equip;
	int neili_wound, qi_wound ;
	object piece;
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

	if( me->query_temp("htz_ju"))
		return notify_fail(HIR"你已經在運「三花聚頂」了。\n"NOR);
		
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必須空手運功。\n");

	fskill = "xiantian-qigong";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 135 )
		return notify_fail("你的"+to_chinese(fskill)+"等級不夠, 不能使出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 135 )
		return notify_fail("你的"+to_chinese(sskill)+"等級不夠, 不能使出"+PNAME+"。\n");

	if( me->query("neili") < 800 )
		return notify_fail("你的內力不夠，無法運功！\n");

	if( me->query("max_neili") < 1000 )
		return notify_fail("你的內力修爲不夠，無法運功！\n");

	skill = me->query_skill(bskill,1);
 
	msg = HIC "$N"HIC"猛地提起內力，一股"HIB"青氣"HIC"直冒上臉前來，隨即大喝一
聲，聚氣於掌，一掌劈面而下，「三花聚頂」！\n"NOR;

	ap = me->query("combat_exp");
	dp = target->query("combat_exp") / 2;

	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-600);
		target_w = target->query_temp("weapon");
		msg += HIC"$N內力充滿全身，守得更是沉穩！\n"NOR;

		if (target->query_temp("weapon") ||
			target->query_temp("secondary_weapon"))
		{
			target_w->unequip();
			target->reset_action();
			msg += HIY"卻只聽得一陣丁當作響，兵器碎片丟了一地！\n"NOR;
      	seteuid(getuid());
      	piece = new("/clone/misc/piece");
      	piece->set("long", "一堆兵器的碎片。\n");
      	piece->set_name( target_w->query("name") + "的碎片", ({target_w->query("id"),"piece"}) );
      	piece->move(environment(target));
     		destruct(target_w);
		}
		me->add_temp("apply/attack", -skill/3);
		me->add_temp("apply/dodge", skill/4);
		me->set_temp("htz_ju", 1);

		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3, skill/4 :), skill/3);
//		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3, skill/3 :));

		me->start_busy(random(2));
	}
	else
	{
		msg += HIC"$n見$N脅下空門大露，疾速搶攻，迫得$N連忙收掌！\n"NOR;
		if(userp(me)) me->add("neili",-600);
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	me->add_temp("apply/attack", a_amount);
	me->add_temp("apply/dodge", -d_amount);
	me->delete_temp("htz_ju");
	tell_object(me, HIY "你的三花聚頂運行完畢，將內力收回丹田。\n"NOR);
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		增加自己的攻擊力和防護力
		有可能毀壞對方兵器

	出手要求：
		先天氣功135級
		昊天掌135級
		內力1000
HELP
	);
	return 1;
}

