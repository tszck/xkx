//hongtianza.c 奪命三斧之「轟天砸」
// Last Modified by winder on Mar. 10 2000
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
#define PNAME "轟天砸」"
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg,*limbs;
	int i,size,damage;
	int p;
	object my_w,target_w,piece;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	my_w = me->query_temp("weapon");
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
	target_w = target->query_temp("weapon");
//	if( target->is_busy() )
//		return notify_fail(target->name() +"目前正茫然不知所措，加緊攻擊吧。\n");

	if (!objectp(my_w = me->query_temp("weapon"))
		|| (string)my_w->query("skill_type") != "axe")
		return notify_fail("你使用的武器不對。\n");

	fskill = "kurong-changong";
	bskill = "axe";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"還使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"功力還使不出"+PNAME+"。\n");
	if( (int)me->query("neili") < 500 )
		return notify_fail("你的內力不夠。\n");
	me->add("neili", -300);
	msg = CYN"$N突然暴吼一聲：“我砸！我砸！我砸砸砸！”，手中巨斧竟然砸向$p手中兵刃！\n"NOR;

	if(target->query_temp("weapon")||target->query_temp("secondary_weapon"))
	{	
		me->start_busy(2);
		if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
		{
			if( target_w->weight() > 2 * random(my_w->weight()) )
			{
				msg += "結果$p手中的" +target_w->query("name") + "被$P的轟天砸砸個正着，再也把握不住，立即脫手飛出！\n" NOR;
				target_w->unequip();
				target_w->move(environment(target));
				target->reset_action();
				if (!target->is_busy())
				target->start_busy((int)me->query_skill(bskill, 1) / 30);
			}
			else
			{
				msg += HIC"只見$n手中的"+target_w->query("name")+"竟然被砸斷作數段，並且受到$N的勁氣的激盪而向$n迅速射去！\n"NOR;
				target_w->unequip();
				target->reset_action();
      	seteuid(getuid());
      	piece = new("/clone/misc/piece");
      	piece->set("long", "一堆兵器的碎片。\n");
      	piece->set_name( target_w->query("name") + "的碎片", ({target_w->query("id"),"piece"}) );
      	piece->move(environment(target));
     		destruct(target_w);
				if (!target->is_busy())
				target->start_busy((int)me->query_skill(bskill, 1)/40);
				limbs=target->query("limbs");
				me->start_busy(1);
				size=(int)(me->query_skill(bskill, 1)/10);
				damage=random(size)+size;
				damage=damage+me->query_str()/3+random(me->query_temp("apply/damage"));
				for(i=0;i<=random(size);i++)
				{
					msg+=HIB"“嗤”，碎片射入$p"+limbs[random(sizeof(limbs))]+"！\n"NOR;
					target->receive_damage("qi",damage,me);
					target->receive_wound("qi",damage/3,me);
				}
				p = (int)target->query("qi")*100/(int)target->query("max_qi");
				msg += "( $n"+eff_status_msg(p)+" )\n";
//				COMBAT_D->report_status(target);
			}
		} else {
			msg+="可是$p將手中的"+target_w->query("name")+"一側，並沒有讓$P的砸着什麼。\n" NOR;
		}
		message_combatd(msg,me,target);
		return 1;
	}
	return notify_fail(target->name() + "目前是空手，你想砸什麼？\n");
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		摧毀對方兵器並利用兵器碎片傷人

	出手要求：
		枯榮禪功100級
		斷雲斧100級
		內力500
HELP
	);
	return 1;
}

