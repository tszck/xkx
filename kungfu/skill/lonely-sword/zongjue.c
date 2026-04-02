// zongjue.c 「總訣式」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
int perform(object me)
{
	string msg;
	object weapon;
	int skill, jing_cost, exp, myint;
	int skill_basic;
	mapping my_fam = me->query("family");

	skill = me->query_skill("lonely-sword",1);
	skill_basic = me->query_skill("sword",1);
	jing_cost = (int)me->query("int") - 45;

	if(!my_fam || my_fam["master_id"] != "feng qingyang")
		return notify_fail("你不是風清揚嫡傳弟子，不能使用總訣式。\n");
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/zongjue") &&
  !me->query("can_perform/lonely-sword/zongjue") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的外功中沒有這種功能。");
   	if(environment(me)->is_chat_room()) return notify_fail("這裏不準打鬥。\n");
	if( me->is_fighting() )
		return notify_fail("「總訣式」不能在戰鬥中演練。\n");
	myint = me->query("int");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你必須先去找一把劍。\n");

	if( !skill || (skill < 20))
		return notify_fail("你的獨孤九劍等級不夠, 不能演練總訣式！\n");
	if( me->query("neili") < 50 )
		return notify_fail("你的內力不夠，沒有力氣演練「總訣式」！\n");
	if( me->query("jing") < -jing_cost )
		return notify_fail("你現在太累了，無法集中精神演練總訣式！\n");

	exp= (int)me->query("combat_exp");
	if( skill*skill*skill/10>exp )
		return notify_fail("你的實戰經驗不夠，無法體會「總訣式」！\n");

	msg= HIG"$N使出獨孤九劍之「總訣式」，將手中"+weapon->name()+HIG"隨意揮舞擊刺。\n"NOR;
	message_combatd(msg, me);
	me->add("neili", -50);
	me->add("jing", jing_cost);
	if ( skill < 60) me->improve_skill("lonely-sword",10,skill_basic > skill? 0: 1);
	else if (skill < 90)
		me->improve_skill("lonely-sword",10+random(myint-9),skill_basic > skill? 0: 1);
	else if (skill < 140)
		me->improve_skill("lonely-sword",10+random(myint*2-9),skill_basic > skill? 0: 1);
	else if (skill < 200)
		me->improve_skill("lonely-sword",10+random(myint*4-9),skill_basic > skill? 0: 1);
	else me->improve_skill("lonely-sword",10+random(myint*8-9),skill_basic > skill? 0: 1);

	msg = MAG"$P的「獨孤九劍」進步了！\n"NOR;
	me->start_busy(random(2));
	message_combatd(msg, me);
	return 1;
}
int help(object me)
{
	write(WHT"\n獨孤九劍之總訣式："NOR"\n");
	write(@HELP

	使用功效：
		演示總訣，提高獨孤九劍的修為

	出手要求：
		身為風清揚嫡傳弟子
		獨孤九劍20級
		內力50
HELP
	);
	return 1;
}

