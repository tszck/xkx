// zhong.c 種生死符
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <xiaoyao.h>

inherit F_SSERVER;
#define PNAME "「生死符」"
int perform(object me, object target)
{
	object obj;
	string msg;
  int eff_jing=me->query("eff_jing");
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
		return notify_fail("生死符只能種在對手身上。\n");

	if( me->query_temp("weapon") )
		return notify_fail("只有空手才能施展「生死符」。\n");

	fskill = "bahuang-gong";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(fskill)+"不夠嫺熟，不能種"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"還不夠嫺熟，不能種"+PNAME+"。\n");

	if( !me->query_temp("murong/xingyi") )
	{
    if (me->query_skill_mapped("force") != "bahuang-gong"&& userp(me))
      return notify_fail("你沒有激發八荒六合唯我獨尊功，難以使出生死符。\n");
	}

	if( me->query("neili") < 500 )
		return notify_fail("你的內力不足，不能種生死符。\n");

	if( me->query("max_neili") < 500 )
		return notify_fail("你的內力修爲不足，不能種生死符。\n");
	
	if( userp(me) && ((me->query("spi")) + (me->query("cps"))) > 40)
                return notify_fail("你的天賦不適合種生死符。\n");

	if (!objectp(obj=present("jiudai", me)))
		return notify_fail("你身上沒有酒袋，不能化水爲冰。\n");
		
	if (me->query("owner")) return notify_fail("任務npc不能使用生死符。\n");

	msg = HIC "$N"HIC"左掌掌心中暗運內功，逆轉北冥真氣，不多時已將掌中酒水化成七八
片寒冰，右掌颼颼颼連拍三掌。 \n";

	me->start_busy(1);
	me->add("neili", -400);
	if((random( (int)me->query_skill("strike", 1))*1.5) > random(target->query_skill("dodge") ) )
	{
// 有個想法： 每次中的穴位都是不固定的，解毒的時候需要找對正確的穴位纔行
//            當然中生死府的穴位可以累加，
//            如果我中毒在 缺盆穴 志室穴 兩處穴道
//            那麼如果解毒的人不知道穴位亂解，反而有損身體
//            - by qingyun
		msg += RED " 結果$p猛地裏肩間“缺盆穴”上微微一寒，便如碰上了一片雪花，跟着小腹“天樞穴”、大腿“伏兔穴”、上臂“天泉穴”三處也覺涼颼颼地。忽然間後頸“天柱穴”、背心“神道穴”
、後腰“志室穴”三處也是微微一涼。\n" NOR;
		target->receive_damage("qi",(int)me->query_skill("force", 1),me);
		target->receive_wound("qi",15 + random(10),me);
		if (fam_type(me)=="lingjiu")
		target->receive_wound("jing",2+eff_jing/3+random(eff_jing/3),me);
		target->apply_condition("ss_poison", random(me->query_skill(bskill, 1)/8) + 1 + target->query_condition("ss_poison"));
		me->start_busy(random(3));
	} else {
		msg += "可是$p急忙閃在一旁，躲了開去。\n" NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);
	target->start_busy(1 + random(3));
	if(!target->is_fighting(me)) target->fight_ob(me);
	if ( target->query_condition("ss_poison")) target->kill_ob(me);
	if (userp(me)) destruct(obj);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		給對手種上靈鷲宮生死符
		遲滯對方出手
		

	出手要求：
		八荒六合唯我獨尊功40級
		適當的天賦
		天山六陽掌60級
		身上帶着酒袋
		內力400
HELP
	);
	return 1;
}

