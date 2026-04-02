// qianzhu-wandushou.c 千蛛萬毒手
// Last Modified by winder on May. 17 2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N身形一晃而至，一招"HIB"「小鬼勾魂」"NOR"，雙掌帶着一縷腥風拍向$n的前心",
	"lvl"    : 0,
	"skill_name" : "小鬼勾魂"
]),
([	"action" : "$N身形化做一縷輕煙繞着$n急轉，一招"MAG"「天網恢恢」"NOR"，雙掌幻出無數掌影罩向$n",
	"lvl"    : 20,
	"skill_name" : "天網恢恢"
]),
([	"action" : "$N大喝一聲，一招"BLU"「惡鬼推門」"NOR"，單掌如巨斧開山帶着一股腥風猛劈向$n的面門",
	"lvl"    : 30,
	"skill_name" : "惡鬼推門"
]),
([	"action" : "$N一聲冷笑，一招"HIR"「靈蛇九轉」"NOR"，身形一閃而至，一掌輕輕拍出，手臂宛若無骨，掌到中途竟連變九變，如鬼魅般印向$n的$l",
	"lvl"    : 40,
	"skill_name" : "靈蛇九轉"
]),
([	"action" : "$N側身向前，一招"BLU"「地府陰風」"NOR"，雙掌連環拍出，一縷縷徹骨的寒氣從掌心透出，將$n周圍的空氣都凝結了",
	"lvl"    : 50,
	"skill_name" : "地府陰風"
]),
([	"action" : "$N厲叫一聲，身形忽的蜷縮如球，飛身撞向$n，一招"YEL "「黃蜂吐刺」"NOR"單掌如劍，直刺$n的心窩",
	"lvl"    : 60,
	"skill_name" : "黃蜂吐刺"
]),
([	"action" : "$N一個急旋，飛身縱起，半空中一式"HIB"「毒龍擺尾」"NOR"，反手擊向$n的$l",
	"lvl"    : 70,
	"skill_name" : "毒龍擺尾"
]),
([	"action" : "$N大喝一聲，運起五毒神功，一招"RED"「毒火焚身」"NOR"，剎那間全身毛髮盡綠，一對碧綠的雙爪閃電般的朝$n的$l抓去",
	"lvl"    : 80,
	"skill_name" : "毒火焚身"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="wudu-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練千蛛萬毒手必須空手。\n");
	if ((int)me->query_skill("wudu-shengong", 1) < 10)
		return notify_fail("你五毒神功火候不夠，無法練千蛛萬毒手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的內力太弱，無法練千蛛萬毒手");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必須空手才能練習。\n");
	if ((int)me->query("qi") < 60)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 60)
		return notify_fail("你的內力不夠練千蛛萬毒手。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -30);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("qianzhu-wandushou",1)) > 30 )
		victim->receive_wound("qi", damage_bonus/3);
	if ( victim->query("family/family_name")!= "五毒教" && me->query_skill("wudu-shengong",1)>40)
	{
		switch( random(5) )
		{
			case 0:
				victim->apply_condition("snake_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("snake_poison"));
				break;
			case 1:
				victim->apply_condition("zhizhu_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("zhizhu_poison"));
				break;
			case 2:
				victim->apply_condition("wugong_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("wugong_poison"));
				break;
			case 3:
				victim->apply_condition("xiezi_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("xiezi_poison"));
				break;
			case 4:
				victim->apply_condition("chanchu_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("chanchu_poison"));
				break;
		}
		return HIR "$n只覺得傷處一陣發麻，似乎中毒了。\n" NOR;
	}
}
void skill_improved(object me)
{
	if(random(15) < 1 && me->query("per") > 5)
	{
		tell_object(me, HIR"你忽然覺得體內毒氣狂竄，面上頓時罩着一層黑氣！\n" NOR );
		me->add("per", -1);
	}
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = -55;
	int d_e2 = -20;
	int p_e1 = 10;
	int p_e2 = 35;
	int f_e1 = 190;
	int f_e2 = 290;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("qianzhu-wandushou", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 獲得招數序號上限 */
			break;
		}
	seq = random(seq);       /* 選擇出手招數序號 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : random(2) ? "內傷" : "瘀傷",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"qianzhu-wandushou/" + action;
}
int help(object me)
{
	write(HIC"\n千蛛萬毒手："NOR"\n");
	write(@HELP

    千蛛萬毒手是五毒教的獨門功夫，有獨門修煉方法。靠吸取毒
蟲身上的毒氣來練成毒功，雖然厲害，但毒氣會損壞自己的容貌，
使自己變的醜陋無比。

	學習要求：
		五毒神功20級
		內力100
HELP
	);
	return 1;
}

