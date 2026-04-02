// taiji.c 「太極心法」
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
void remove_effect(object me);

int exert(object me)
{
	object weapon = me->query_temp("weapon");
	string prepare;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/taiji") &&
  !me->query("can_perform/taiji-shengong/taiji") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if( !objectp(weapon) &&
		me->query_skill_mapped("unarmed") == "taiji-quan" &&
		me->query_skill_mapped("parry") == "taiji-quan" &&
		me->query_skill_mapped("force") == "taiji-shengong" )
		prepare = "tjq"; // player is using tjq.
	else
		if( objectp(weapon) &&
			weapon->query("skill_type") == "sword" &&
			me->query_skill_mapped("sword") == "taiji-jian" &&
			me->query_skill_mapped("parry") == "taiji-jian" &&
			me->query_skill_mapped("force") == "taiji-shengong" )
			prepare = "tjj"; // player is using tjj. 
		else prepare = "notj";
	if( me->query_temp("taiji") )
		return notify_fail("你已經將太極心法融會入武功之中。\n");
	if( prepare == "notj" )
		return notify_fail("你現在無法將太極心法融會在武功內。\n");
	if( prepare == "tjj" && me->query_skill("taiji-jian", 1) < 300 )
		return notify_fail("你尚未領會到太極劍意。\n");
	if( prepare == "tjq" && me->query_skill("taiji-quan", 1) < 300 )
		return notify_fail("你尚未領會到太極拳旨。\n");
	if( me->query_skill("taiji-shengong", 1) < 300 )
		return notify_fail("你的太極修為尚未登峯造極，無法領悟到其心法。\n");
	if( me->query_skill("taoism", 1) < 150 )
		return notify_fail("你的道學修為尚未豁然貫通，無法領會太極心法。\n");
	if( userp(me) && me->query_int() < 50 )
		return notify_fail("你的悟性太低，無法領會到太極心法。\n");
  if( me->query_temp("wudang/raozhi"))
    return notify_fail("你正在施展「繞指柔劍」，沒有太多精力再運太級心法！\n");
	if( prepare == "tjj" )
		message_combatd( "\n$N微微一笑，身子緩緩右轉，左手持劍向上提起，劍身橫於胸前，\n左右雙掌掌心相對，如抱圓球。" + weapon->name() + "未出，已然蓄勢無窮。\n", me);
	else
		message_combatd( "\n$N緩緩站起身來，雙手下垂，手背向外，手指微舒，兩足分開平行，\n接着兩臂慢慢提起至胸前，左臂半環，掌與面對成陰掌，右掌翻過成陽掌。\n", me);

  if (userp(me))
	me->receive_damage("jing", 500, "精力透支過度死了");
	me->add_temp("taiji", (int)me->query_skill("taiji-shengong", 1)/2);

	call_out("checking", 1, me, prepare);

	return 1;
}

void checking(object me, string prepare)
{
	object weapon = me->query_temp("weapon");
	string tjjzhao, tjqzhao1, tjqzhao2, tjqzhao3;

	tjjzhao = SKILL_D("taiji-jian")->query_skill_name(random(140));
	tjqzhao1 = SKILL_D("taiji-quan")->query_skill_name(random(150));
	tjqzhao2 = SKILL_D("taiji-quan")->query_skill_name(random(150));
	tjqzhao3 = SKILL_D("taiji-quan")->query_skill_name(random(150));

	if( me->query_temp("taiji") < 1 )
	{
		remove_effect(me);
		tell_object(me, "\n你大周天搬運完畢，將內力合於丹田，入竅歸元。\n");
		return;
	}
	else if( !living(me) || me->is_ghost() )
	{
		remove_effect(me);
		return;
	}
	else if( prepare == "tjq" && objectp(weapon) )
	{
		remove_effect(me);
		return;
	}
	else if( prepare == "tjj" && (!objectp(weapon) ||
		weapon->query("skill_type") != "sword") )
	{
		if( me->query_temp("taiji_fight") )
			message_combatd(CYN"\n$N手中無劍，劍意頓失！\n"NOR, me);
		remove_effect(me);
		return;
	}
	else if( me->query_skill_mapped("force") != "taiji-shengong")
	{
		remove_effect(me);
		tell_object(me, HIR"\n你忽覺胸口一陣煩惡，原來所用內功與太極心法相逆！\n" NOR);
		me->receive_damage("qi", 1000, "內功走火入魔死了");
		return;
	}
	else if( !me->is_busy() )
	{
		if( me->query_temp("taiji_fight") && !me->is_fighting() )
		{
			remove_effect(me);
			if( prepare == "tjj" )
				message_combatd("\n$N使到" + tjjzhao + "，雙手同時畫圓，覆成第五十四式「持劍歸原」。\n"NOR, me);
			else
				message_combatd("\n$N使到上步"+ tjqzhao1 + "，上步" + tjqzhao2 + "，" + tjqzhao3 + "而合太極，神定氣閒的站在當地。\n"NOR, me);
			return;
		}
		else if( prepare == "tjj" &&
			(me->query_skill_mapped("sword") != "taiji-jian" ||
			me->query_skill_mapped("parry") != "taiji-jian") )
		{
			if( me->query_temp("taiji_fight") )
				message_combatd(CYN"\n$N圈轉" + weapon->name() + CYN"，突然變招，使出與太極劍意不同的劍法！\n"NOR, me);
			remove_effect(me);
			return;
		}
		else if( prepare == "tjq" &&
			(me->query_skill_prepared("unarmed") != "taiji-quan" ||
			me->query_skill_mapped("unarmed") != "taiji-quan" ||
			me->query_skill_mapped("parry") != "taiji-quan") )
		{
			if( me->query_temp("taiji_fight") )
				message_combatd(CYN"\n$N雙手一錯，突然使出與太極拳旨相反的招數！\n"NOR, me);
			remove_effect(me);
			return;
		}
	}

	if( !me->query_temp("taiji_fight") ) me->add_temp("taiji", -1);
	call_out("checking", 1, me, prepare);
} 

void remove_effect(object me)
{
	me->delete_temp("taiji");
	if( me->query_temp("taiji_fight") ) me->delete_temp("taiji_fight");
	me->start_busy(1);
}

int help(object me)
{
	write(WHT"\n太極神功之太極心法："NOR"\n");
	write(@HELP

	使用功效：
		太極心法的使用，將激發武當本門功夫的威力

	出手要求：
		太極神功300級
		太極拳300級
		太極劍法300級
		道學心法150級
		後天悟性不低於50
		空手時需激發太極拳為招架與基本拳腳
		持劍時需激發太極劍法為招架與基本劍法
HELP
	);
	return 1;
}

