// Last Modified by winder on Jul. 15 2001
// yinyang.c

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "陰陽掌"
int perform(object me, object target)
{
	string msg;
	int skill, damage;
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

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");
		
	if ( me->query_temp("weapon"))
		return notify_fail("你只能空手出絕招。\n");

	fskill = "hanbing-zhenqi";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"修爲不夠，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"修爲不夠，不能使用"+PNAME+"。\n");

	if( (int)me->query("max_neili")< 600 )
		return notify_fail("你的內力修爲不夠。\n"); 

	if( (int)me->query("neili")< 400 )
		return notify_fail("你的內力不夠。\n"); 

	skill = me->query_skill(bskill, 1);
	msg = HIY"使出大嵩陽掌的絕技「陰陽掌」，雙掌遠遠一推一拉，$n頓覺一股\n"HIB"寒氣"HIY"襲上身來，登時機伶伶打了個冷戰。$n只一呆，一股"HIR"炙熱的掌風"HIY"跟着撲到，擊得$n幾乎窒息，身子晃了幾晃。\n";

	damage = me->query("jiali") * 3 + 100;

	if(random(me->query_skill(bskill, 1)) > target->query_skill("parry",1)/3)
	{
	  if( me->query("jiali") * 10 > (int)target->query("neili") ) 
	  {
			msg += HIR"掌力擊在$n胸口，打得$n身子飛了出去。\n"NOR;
			target->receive_damage("qi", damage,me);
			target->receive_damage("jing", damage,me);
			me->start_busy(1);
			me->add("neili", -100);
	  } 
	  else
	  {
			msg += HIB"這一陰一陽兩股掌力打在$n身上，$n體內真氣自然而然生出相應之力，護住心脈內臟，不受損傷。但霎時間全身劇震，說不出的難受。\n"NOR;
			target->receive_damage("qi", (int)(damage/2),me);
			target->receive_damage("jing", damage,me);
			me->start_busy(2);
			me->add("neili", -200);
	  }
	}
	else 
	  {     
	  	msg+=HIG "結果$p看破了$P的企圖，身行後躍，避開了$P的掌力。\n" NOR;
	        me->start_busy(3);
 	        me->add("neili", -200);
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
		損害敵手氣血

	出手要求：
		寒冰真氣120級
		大嵩陽掌120級
		內力修爲600
		內力400
HELP
	);
	return 1;
}

