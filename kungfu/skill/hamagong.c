// hamagong.c 蛤蟆功
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

mapping *action = ({
([	"action" : "$N忽而倒豎，一手撐地，身子橫挺，只以一掌向$n的$l拍出",
	"lvl" : 0,
	"skill_name" : "蛤蟆功"
]),
([	"action" : "$N雙手在地上一撐，身子忽地拔起，一躍三尺，落在$n的面前，單掌向$p直劈而下",
	"lvl" : 10,
	"skill_name" : "蛤蟆功"
]),
([	"action" : "$N突然伸手在自己臉上猛抓一把，又反足在自己腎上狠踢一腳，一掌擊出，中途方向必變，實不知將打何處",
	"lvl" : 20,
	"skill_name" : "蛤蟆功"
]),
([	"action" : "突然之間，$N俯身疾攻，上盤全然不守，微微側頭，一口唾沫往$n$l吐去",
	"lvl" : 30,
	"skill_name" : "蛤蟆功"
]),
([	"action" : "$N絲毫不動聲色，雙腿微曲，右掌平伸，左掌緩緩運起蛤蟆功的勁力，呼的一聲推向$n",
	"lvl" : 80,
	"skill_name" : "蛤蟆功"
]),
([	"action" : "$N默唸口訣運氣經脈，只覺愈轉愈是順遂，當下一個翻身躍起，咕的一聲叫喊，雙掌對着$n拍出",
	"lvl" : 110,
	"skill_name" : "蛤蟆功"
]),
([	"action" : "但見$N雙腿微曲，雙掌會收，然後向$n一上一下，一放一收，斗然擊出",
	"lvl" : 140,
	"skill_name" : "蛤蟆功"
]),
([	"action" : "$N閉眼逼住呼吸，過了片刻，猛躍而起，眼睛也不及睜開，雙掌便向$n的方向推了出去",
	"lvl" : 170,
	"skill_name" : "蛤蟆功"
]),
([	"action" : "$N腳步搖搖幌幌的看上去馬上就會跌倒，忽然雙腿一彎、一登，口中閣的一聲叫喝，手掌向$n猛然推出",
	"lvl" : 199,
	"skill_name" : "蛤蟆功"
]),
});
/*
mapping *action = ({
([	"action": "$N輕身一躍，使出一招" + HIY"「沙漠孤舟」"NOR + "，左掌橫，右掌帶，將$n逼開。",
	"force" : 200,
	"dodge" : 20,
	"damage": 240,
	"skill_name": "沙漠孤舟",
	"damage_type": "瘀傷"
]),
([	"action":"只見$N倏地向前跨出一步，一招" + WHT"「萬裏獨歸」"NOR + "，雙掌一錯，順勢攻向$n",	
	"force" : 220,
	"dodge" : 20,
	"damage": 250,
	"skill_name": "萬裏獨歸",
	"damage_type": "瘀傷"
]),
([	"action":"$N一招" + HIW"「鳴沙寒煙」"NOR + "，來勢曼妙無方，掌力微吐，罩向$n周身。",
	"force" : 400,
	"dodge" : 30,
	"damage": 250,
	"skill_name": "鳴沙寒煙",
	"damage_type": "瘀傷"
]),
([	"action":"$N低眉曲身，掌勢若有若無，恰恰將$n來招一一封住，並暗含反擊之意，正是一招" + HIR"「霓裳弄雪」"NOR + "。",
	"force" : 225,
	"dodge" : 30,
	"damage": 270,
	"skill_name": "霓裳弄雪",
	"damage_type": "瘀傷"
]),
([	"action":"$N一招" + HIB"「秋恨客途」"NOR + "，抽身提步，不退反進，雙掌平推，來如電閃，徑直拍向$n。",
	"force" : 530,
	"dodge" :-20,
	"damage": 300,
	"skill_name": "秋恨客途",
	"damage_type": "瘀傷"
]),
});
*/

int valid_enable(string usage) { return usage == "force"||usage == "strike"; }
int valid_combine(string combo) { return combo=="shexing-diaoshou"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("hamagong", 1);
	int t = 1, j;
	mapping myfam;
	
	myfam = (mapping)me->query("family");
/*
	if(!myfam || myfam["family_name"] != "白駝山派"|| myfam["master_id"] != "ouyang feng")
		return notify_fail("蛤蟆功乃不世神功，須向歐陽鋒親自求教。\n");
*/
	if( i <= 100) for (j = 1; j < i / 10; j++) t*= 2;

	if ( me->query("gender") == "無性" && i > 49)
		return notify_fail("你無根無性，陰陽不調，難以領會高深的蛤蟆功。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本內功火候不足，不能學蛤蟆功。\n");

	if(i<=100)
	{
		if (i > 10 && -(int)me->query("shen") < t * 100) 
			return notify_fail("學蛤蟆功，要心狠手辣，奸惡歹毒，你可做得不夠呀！\n");
	}
	else
	{
		if (-(int)me->query("shen") < (51200 + (i - 100) * 1000)) 
			return notify_fail("學蛤蟆功，要心狠手辣，奸惡歹毒，你可做得不夠呀！\n");
	}
	return valid_public(me);
}
int practice_skill(object me)
{
	return notify_fail("蛤蟆功只能用學(learn)的來增加熟練度。\n");
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
	int d_e1 = -40;
	int d_e2 = -20;
	int p_e1 = 0;
	int p_e2 = 30;
	int f_e1 = 190;
	int f_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("hamagong", 1);
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

string exert_function_file(string func)
{
	return __DIR__"hamagong/" + func;
}
string perform_action_file(string action)
{
	return __DIR__"hamagong/" + action;
}

int help(object me)
{
	write(HIC"\n蛤蟆功："NOR"\n");
	write(@HELP

    歐陽鋒創立此功，為白駝山派本門內功。此功也可作為掌法使
用，並能與蛇形刁手互備。
    這蛤蟆功純系以靜制動，他全身涵勁蓄勢，蘊力不吐，只要敵
人一施攻擊，立時便有猛烈無比的勁道反擊出來，剛猛無匹。

	學習要求：
		基本內功10級
		太監無法領悟50級以上的蛤蟆功
		相應的戾氣
HELP
	);
	return 1;
}

